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

def QuickSelect(arr, start, finish, k):
    if finish - start == 1:
        return arr[start]

    x = arr[random.randint(start, finish - 1)]
    l, m, n = Partition(arr, start, finish, x)
    if k < l:
        return QuickSelect(arr, start, start + l, k)
    elif k < (l + m):
        return x
    else:
        return QuickSelect(arr, start + l + m, finish, k - l - m)

vec = [3, 8, 4, -4, 8, 7, 6, 5]
print(QuickSelect(vec, 0, len(vec), 0)) # -4