price=float(input())
coupon=input().strip()
card=input().strip()
discount=0
if coupon=='Y':
    discount+=5
    if card=='Y':
        discount+=15
elif card=='Y':
    discount+=10
pay=(100-discount)*0.01*price
print(pay)