n, t = map(int,input().split())
a = 10**(n - 1)
b = 10**n - 1
k = a//t
ans = k*t
if ans < a:
    ans += t
if ans <= b:
    print(ans)
else:
    print(-1)