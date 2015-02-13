def factors(n):
	return reduce(list.__add__,([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0))
import math
t = raw_input()
t = int(t)
for q in xrange(0,t):
	d,p = raw_input().split()
	d = int(d)
	p = int(p)
	if(d<0):
		print 0
	else:	
		arr = []
		count = 0
		arr = factors(p)
		l = len(arr)
#	print arr
		for j in xrange(1,l):
			for k in xrange(0,j):
				if(arr[j]-arr[k]==d):
					count+=1
		if(d!=0):
			print count*4
		else:
	 		print count*2
