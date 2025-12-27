ans = 0

def merge(a, b, to):
    global ans
    i, j = 0, 0

    while (i < len(a)) or (j < len(b)):
        if (j == len(b)) or ((i < len(a)) and (a[i] <= b[j])):
            to[i + j] = a[i]
            ans += j
            i += 1
        else:
            to[i + j] = b[j]
            j += 1

def MergeSort(arr):
    if len(arr) <= 1:
        return

    k = len(arr) // 2
    l = arr[0:k]
    r = arr[k:]
    MergeSort(l)
    MergeSort(r)
    merge(l, r, arr)

m = [3, 8, 4, -4, 8, 7, 6, 5]
MergeSort(m)
print(m) # [-4, 3, 4, 5, 6, 7, 8, 8]
print(ans) # 13