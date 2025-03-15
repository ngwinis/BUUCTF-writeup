#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char Str2[] = "e3nifIH9b_C@n@dH";
int byte_93A144[] = {0, 0, 0};

const char aAbcdefghijklmn[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";

void *encrypt(char *inp, unsigned int inp_len, int *a3)
{
  int v4, v5, v6, v7;
  int i;
  unsigned int v9;
  int v10, v11;
  void *v12;
  char *v13;

  if (!inp || !inp_len)
    return 0;

  v9 = (inp_len + 2) / 3;
  v10 = 4 * v9;
  *a3 = v10;
  v12 = malloc(v10 + 1);
  if (!v12)
    return 0;

  memset(v12, 0, v10 + 1);
  v13 = inp;
  v11 = inp_len;
  v4 = 0;

  while (v11 > 0)
  {
    byte_93A144[2] = 0;
    byte_93A144[1] = 0;
    byte_93A144[0] = 0;

    for (i = 0; i < 3 && v11 >= 1; ++i)
    {
      byte_93A144[i] = *v13;
      --v11;
      ++v13;
    }
    
    switch (i)
    {
      case 1:
        *((char *)v12 + v4) = aAbcdefghijklmn[(byte_93A144[0] >> 2) & 0x3F];
        v5 = v4 + 1;
        *((char *)v12 + v5) = aAbcdefghijklmn[((byte_93A144[0] & 3) << 4)];
        *((char *)v12 + ++v5) = '=';
        *((char *)v12 + ++v5) = '=';
        v4 = v5 + 1;
        break;

      case 2:
        *((char *)v12 + v4) = aAbcdefghijklmn[(byte_93A144[0] >> 2) & 0x3F];
        v6 = v4 + 1;
        *((char *)v12 + v6) = aAbcdefghijklmn[((byte_93A144[0] & 3) << 4) | ((byte_93A144[1] >> 4) & 0xF)];
        *((char *)v12 + ++v6) = aAbcdefghijklmn[(byte_93A144[1] & 0xF) << 2];
        *((char *)v12 + ++v6) = '=';
        v4 = v6 + 1;
        break;

      case 3:
        *((char *)v12 + v4) = aAbcdefghijklmn[(byte_93A144[0] >> 2) & 0x3F];
        v7 = v4 + 1;
        *((char *)v12 + v7) = aAbcdefghijklmn[((byte_93A144[0] & 3) << 4) | ((byte_93A144[1] >> 4) & 0xF)];
        *((char *)v12 + ++v7) = aAbcdefghijklmn[((byte_93A144[1] & 0xF) << 2) | ((byte_93A144[2] >> 6) & 3)];
        *((char *)v12 + ++v7) = aAbcdefghijklmn[byte_93A144[2] & 0x3F];
        v4 = v7 + 1;
        break;
    }
  }

  *((char *)v12 + v4) = 0;
  return v12;
}

int main()
{
  size_t inp_len;
  const char *res;
  size_t v5;
  int j, i, v11;
  char Destination[108] = {0};
  char inp[28] = {0};
  char v14[8] = {0};

  printf("please enter the flag: ");
  scanf("%20s", inp);
  
  inp_len = strlen(inp);
  res = (const char *)encrypt(inp, inp_len, (int *)v14);
  
  if (!res)
  {
    printf("Encryption failed.\n");
    return 1;
  }

  strncpy(Destination, res, 40);
  free((void *)res);

  v11 = strlen(Destination);
  for (j = 0; j < v11; ++j)
    Destination[j] += j;

  v5 = strlen(Destination);
  if (!strncmp(Destination, Str2, v5))
    printf("right flag!\n");
  else
    printf("wrong flag!\n");

  return 0;
}
