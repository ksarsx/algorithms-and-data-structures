# реализация функции, которая занимается слиянием двух отсортированных массивов a, b в отсортированный массив to
def merge(a, b, to):
    i, j = 0, 0

    while ((i < len(a)) or (j < len(b))):
        if ((i == len(a)) or ((j < len(b)) and (b[j] <= a[i]))):
            to[i + j] = b[j]
            j += 1
        else:
            to[i + j] = a[i]
            i += 1

# реализация алгоритма сортировки слиянием
def MergeSort(arr):
    if len(arr) <= 1:
        return

    k = len(arr) // 2
    l = arr[0:k]
    r = arr[k:]

    MergeSort(l)
    MergeSort(r)
    merge(l, r, arr)


arr = [3, 8, 4, -4, 8, 7, 6, 5]
MergeSort(arr)
print(arr) #  [-4, 3, 4, 5, 6, 7, 8, 8]