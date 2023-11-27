count = int(input())
arr = []
sum = 0

for i in range(0, count):
    val = int(input())
    if val == 0 :
        del arr[- 1]
    else:
        arr.append(val)

for i in arr:
    sum += i

print(sum)
