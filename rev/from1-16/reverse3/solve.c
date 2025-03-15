#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char aAbcdefghijklmn[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";

int find_index(char c) {
    for (int i = 0; i < 64; i++) {
        if (aAbcdefghijklmn[i] == c)
            return i;
    }
    return -1;
}

void *decrypt(char *encoded, unsigned int enc_len, int *out_len) {
    if (!encoded || enc_len % 4 != 0) return NULL;
    
    *out_len = (enc_len / 4) * 3;
    char *decoded = (char *)malloc(*out_len + 1);
    if (!decoded) return NULL;
    
    memset(decoded, 0, *out_len + 1);
    int i, j, idx[4];
    int pos = 0;
    
    for (i = 0; i < enc_len; i += 4) {
        for (j = 0; j < 4; j++) {
            idx[j] = find_index(encoded[i + j]);
        }
        
        decoded[pos++] = (idx[0] << 2) | (idx[1] >> 4);
        if (idx[2] != 64) decoded[pos++] = ((idx[1] & 0xF) << 4) | (idx[2] >> 2);
        if (idx[3] != 64) decoded[pos++] = ((idx[2] & 0x3) << 6) | idx[3];
    }
    decoded[pos] = '\0';
    *out_len = pos;
    return decoded;
}

int main() {
    char input[108] = "e3nifIH9b_C@n@dH";
    int len;
    
    for (int i = 0; i < strlen(input); i++) {
        input[i] -= i;
    }
    
    char *decoded = decrypt(input, strlen(input), &len);
    if (decoded) {
        printf("Decrypted flag: %s\n", decoded);
        free(decoded);
    } else {
        printf("Decryption failed.\n");
    }
    return 0;
}
