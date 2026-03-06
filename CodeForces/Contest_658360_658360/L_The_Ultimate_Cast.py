a=int(input())
b=int(input())
c=int(input())
if a==1 and b==1 and c==1:
    print(a+b+c)
elif a==1 and b==1:
    print((a+b)*c)
elif a==1 and c==1:
    print(a+c+b)
elif b==1 and c==1:
    print((b+c)*a)
elif a==1:
    print((a+b)*c)
elif c==1:
    print((b+c)*a)
elif b==1:
    print((b+(min(a,c)))*max(a,c))
else:
    print(a*b*c)