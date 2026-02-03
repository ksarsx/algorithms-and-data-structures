import random
random.seed(42)

# в данной реализации Partition используются два указателя (i, j) на начало и конец массива, для сортировки

# что получает на вход:
# массив arr
# индекс начала используемого массива start
# индекс конца используемого массива finish
# pivot - x
#
# что делает:
# разбивает по x используемый массив
#
# что возвращает: (из используемого массива)
# 1. количество элементов меньше x
# 2. количество элементов равных x
# 3. количество элементов больших x
def Partition(arr, start, finish, x):
    i = start
    j = finish - 1

    # сортировка на (меньше x) | (больше либо равно x)
    while i < j:
        if arr[i] >= x:
            if arr[j] < x:
                arr[i], arr[j] = arr[j], arr[i]
            else:
                j -= 1
        else:
            i += 1

    # подготовка к сортировке правой части
    # выбираю место i где встречается первый элемент больший либо равный x
    if arr[i] < x:
        if arr[j] < x:
            i = j + 1
        else:
            i = j

    j = finish - 1

    # сортировка на ( == x) | ( > x)
    while i < j:
        if arr[i] > x:
            if arr[j] == x:
                arr[i], arr[j] = arr[j], arr[i]
            else:
                j -= 1
        else:
            i += 1

    l, m, n = 0, 0, 0
    for i in range(start, finish):
        l += (arr[i] < x)
        m += (arr[i] == x)
        n += (arr[i] > x)

    return l, m, n


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