text = 'killshadow'
key = 'adsfkndcls'
idx = 0
str2 = [0]*10
n = 10
flag = ''
while idx < 10:
    for i in range(0, 128):
        if ( i <= 96 or i > 122 ):
            if ( i > 64 and i <= 90 ):
                str2[idx] = (i - 39 - ord(key[n % len(key)]) + 97) % 26 + 97
        else:
            str2[idx] = (i - 39 - ord(key[n % len(key)]) + 97) % 26 + 97
        if chr(str2[idx]) == text[idx]:
            flag += chr(i)
            n += 1
            break
    idx += 1
print(flag)