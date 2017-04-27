import sys

# sys.stdin = open("D:\\Computer\\TestingArea\\test.in", "r")
# sys.stdout = open("D:\\Computer\\TestingArea\\test.out", "w")

import numpy as np

def read_matrix():
	r,c = [int(e) for e in input().split()]
	m = [[int(e) for e in input().split()] for i in range(r)]
	return np.array(m)

def dot_row_column(m):
	return m.dot(m);

def mul_submatrix(m,n):
	ans = numpy(m)
	for i in range(0, m.shape[0], n.shape[0]):
		for j in range(0, m.shape[1], n.shape[1]):
			ans[i:i+n.shape[0], j:j+n.shape[1]] = ans[i:i+n.shape[0], j:j+n.shape[1]].dot(n)
	return ans

def mul_submatrix(m,n):
	s = np.shape(n)
	ss = np.shape(m)
	l = np.array([],int)
	for i in range(ss[0]//s[0]):
		e = m[i*s[0]:i*s[0]+s[0],0:s[1]].dot(n)
		for j in range(1,ss[1]//s[0]):
			temp = m[i*s[0]:i*s[0]+s[0],j*s[0]:j*s[0]+s[1]]
			if np.shape(temp)[0]%s[0]==0 and np.shape(temp)[1]%s[0]==0:
				e = np.append(e,temp.dot(n),axis = 1 )
		l = np.append(l,e)
	return l.reshape(ss[0],-1)

def resize(m,x,y):
	if m.shape[0] >= x and m.shape[1] >= y:
		return m[:x, :y]
		
	a = m.shape[0]
	b = m.shape[1]

	if m.shape[0] < x and m.shape[1] >= y:
		w = np.zeros((2*a, b), np.int)
		w[:a,:] = w[a:,:] = m
		return resize(w,x,y)

	if m.shape[1] < y and m.shape[0] >= x:
		w = np.zeros((a, 2*b), np.int)
		w[:,:b] = w[:,b:] = m
		return resize(w,x,y)

	w = np.zeros((2*a, 2*b), np.int)
	w[:a,:b] = w[:a,b:] = w[a:,:b] = w[a:,b:] = m
	return resize(w,x,y)

exec(input().strip()) # do not remove this line