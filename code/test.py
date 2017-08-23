class piggybank:
​def __init__(self):
​​self.coins = {}
 
​def add(self, v, n):
​​if n + sum(self.coins.values()) > 100:
​​​return False
​​self.coins[float(v)] = self.coins.get(float(v), 0) + n
​​return True
 
​def __float__(self):
​​if self.coins == {}:
​​​return 0.0
​​return sum([float(i * self.coins[i]) for i in self.coins])
 
​def __str__(self):
​​lst = []
​​for each in self.coins:
​​​lst.append((each, self.coins[each]))
​​lst.sort()
​​s = '{'
​​for i in range(len(lst)):
​​​if i != 0:
​​​​s += ', '
​​​s += str(lst[i][0]) + ':' + str(lst[i][1])
​​s += '}'
​​return s
 
cmd1 = input().split(';')
cmd2 = input().split(';')
p1 = piggybank(); p2 = piggybank()
for c in cmd1: eval(c)
for c in cmd2: eval(c)