import random
random.seed(42)

def Partition(arr, start, finish, x):

    B, C, D = [], [], []
    for i in range(start, finish):
        t = arr[i]

        if t < x:
            B.append(t)
        elif t == x:
            C.append(t)
        else:
            D.append(t)

    b, c, d = 0, 0, 0
    for i in range(start, finish):
        if b < len(B):
            arr[i] = B[b]
            b += 1
        elif c < len(C):
            arr[i] = C[c]
            c += 1
        else:
            arr[i] = D[d]
            d += 1

    return len(B), len(C), len(D)

def QuikSort(arr, start, finish):
    if (finish - start) <= 1:
        return

    x = arr[random.randint(start, finish - 1)]
    l, m, n = Partition(arr, start, finish, x)

    QuikSort(arr, start, start + l)
    QuikSort(arr, start + l + m, start + l + m + n)

vec = [3, 8, 4, -4, 8, 7, 6, 5]
QuikSort(vec, 0, len(vec))
print(vec) # [-4, 3, 4, 5, 6, 7, 8, 8]

