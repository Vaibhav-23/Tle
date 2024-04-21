tc = int(input())
for l in range(0,tc):
    n, q = map(int, input().split())
    arr = []
    for i in range(0,n):
        b, x = map(int, input().split())
        if(b == 1):
            arr.append(x)
        if(b == 2):
            ar = arr
            for j in range(0,x):
                arr = arr + ar
    y = list(map(int, input().split()))
    for i in range(0,q):
        print(arr[y[i]-1], end=" ")
    print(" ", end="\n")