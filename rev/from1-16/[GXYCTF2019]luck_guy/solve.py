import random

# Giả lập rand() % 200
rand_val = random.randint(0, 199)

f1 = "GXY{do_not_"
f2 = ""

choice = [4, 5, 1]
for rand_val in choice:
    if rand_val == 1:
        print("OK, it's flag:")
        s = f1 + f2
        print(s)

    elif rand_val == 2:
        print("Solar not like you")

    elif rand_val == 3:
        print("Solar want a girlfriend")

    elif rand_val == 4:
        s = '\x7Ffo`guci'
        f2 += s

    elif rand_val == 5:
        f2 = list(f2.ljust(8, '\x00'))  # Đảm bảo f2 có ít nhất 8 ký tự
        for j in range(8):
            if j % 2 == 1:
                f2[j] = chr(ord(f2[j]) - 2)
            else:
                f2[j] = chr(ord(f2[j]) - 1)
        f2 = ''.join(f2)

    else:
        print("emmm, you can't find flag 23333")
