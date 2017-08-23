# # n = int(input())
# # tmp = []
# # data = []
# # for i in range(n):
# # 	s = input().strip().split(',')
# # 	tmp += [s[2:]]
# # for s in tmp:
# # 	temp = s[:8]
# # 	s = s[7:]
# # 	print(s)
# # 	for i in range(1,8):
# # 		for j in range(1,8):
# # 			if int(s[j]) == i:
# # 				temp += [j]
# # 	data += [temp]
# # print(data[0])

a, b = map(int,input().split())
print(a,b)

# hour, minute, second = map(int,input().split())
# if hour < 3:
# 	print(19, end = ' ')
# 	second = second + minute*60 + hour*60*60
# 	second = 3*60*60 - second
# 	hour = second//(60*60)
# 	second = second%(60*60)
# 	minute = second//60
# 	second = second%60
# elif hour - 3 < 24:
# 	hour -= 3
# 	print(18,end = ' ')
# 	second = second + minute*60 + hour*60*60
# 	second = 24*60*60 - second
# 	hour = second//(60*60)
# 	second = second%(60*60)
# 	minute = second//60
# 	second = second%60
# else:
# 	hour -= 27
# 	print(17,end = ' ')
# 	second = second + minute*60 + hour*60*60
# 	second = 24*60*60 - second
# 	hour = second//(60*60)
# 	second = second%(60*60)
# 	minute = second//60
# 	second = second%60

# print(hour, minute, second)

# # data = []
# # datastaff = []
# # data1 = []
# # n = int(input().strip())
# # for i in range(n):
# # 	s = input().strip().split()
# # 	data += [s[0:2]]
# # n = int(input().strip())
# # for i in range(n):
# # 	s = input().strip().split()
# # 	datastaff += [s]
# # 	data1 += [s[0:2]]
# # n = int(input().strip())
# # for i in range(n):
# # 	s = input().strip().split()
# # 	datastaff += [s]
# # for s in datastaff:
# # 	x = s[0:2]
# # 	if x not in data:
# # 		if x in data1:
# # 			print(s[0],s[1],s[2],s[3])
