import random
random.seed(42)

# генерация отсортированного массива
last_number = random.randint(1, 100)
arr = [last_number]
for i in range(99):
    new_number = random.randint(last_number, last_number+10)
    arr.append(new_number)
    last_number = new_number

# arr = [82, 83, 83, 87, 90, 93, 95, 96, 106, 114, 115, 124, 130, 130, 130, 131, 134, 137, 145, 154, 154, 162, 165, 175, 183, 189, 192, 199, 208, 212, 212, 214, 220, 225, 229, 231, 234, 239, 240, 241, 247, 248, 253, 258, 267, 271, 271, 278, 286, 287, 293, 294, 302, 306, 316, 325, 330, 339, 342, 343, 343, 353, 356, 360, 361, 364, 365, 371, 375, 382, 392, 397, 399, 404, 409, 412, 422, 426, 436, 446, 447, 456, 466, 468, 476, 479, 481, 488, 494, 498, 508, 516, 519, 529, 534, 534, 537, 537, 542, 548]


# бинарный поиск
def binary_search(arr, x):
        left = 0
        right = len(arr)
        mid = 0

        while right - left > 1: # пока длина отрезка от left до right больше 1
            mid = (left + right) // 2  # целая часть округляется вниз

            if arr[mid] > x:
                right = mid
            else:
                left = mid


        print(left)
        if arr[left] == x:
            print(left)
        else:
            print('No')


binary_search(arr, 90)
print(arr)