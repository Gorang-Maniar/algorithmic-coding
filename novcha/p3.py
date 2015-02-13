#fombinatorial
global arr
arr = []
def fombinatorial(n,r):
	f=1
	for i in xrange(0,n-1):
		if(n%2==0):
			f = f*power(n-i,n-i)
		else:
		  	f = f*power1(n-i,n-i)
		ans = f/(arr[r]*arr[n-r])
		return ans

def power(x,y):
	i=2
	if(y==0):
		arr[0]=1
		return 1
#	if(y==1):
#		return x
	d = power(x,y/2) 
	if(y%2 == 0):
		arr[i] = d*d
		i=i+1
		return arr[i]

	else:
		arr[i] = x*d*d
		i=i+1
		return arr[i]

def power1(x,y):
	i=1
	if(y==0):
		return 1
	if(y==1):
		return x
	d = power(x,y/2) 
	if(y%2 == 0):
		arr[i] = d*d
		i=i+1
		return arr[i]

	else:
		arr[i] = x*d*d
		i=i+1
		return arr[i]

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

