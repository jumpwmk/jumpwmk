x = int(input())
s = ""

if x == 0:
	s = "zero "
elif x > 0:
	s = "positive "
else:
	s = "negative "

if x % 2 == 0:
	s = s + "even"
else:
	s = s + "odd"

print(s)