def fombinatorial(n,r):
	f=1
	f = power(n,n)
	f1 = power(r,r)
	f2 = power(n-r,n-r)
	ans = f/(f1*f2)
	return ans

def power(x,y):
	if(y==0):
		return 1
	d = power(x,y/2)
	if(y%2 == 0):
		return d*d
	else:
		return x*d*d

t = raw_input()
t = int(t)
for q in xrange(0,t):
	n,m,q=raw_input().split()
	n = int(n)
	m = int(m)
	q = int(q)
	for w in xrange(0,q):
		r = raw_input()
		r = int(r)
		ans = fombinatorial(n,r)
		ans = ans%m
		print ans
