def power(b,e):
	r=1
	while e:
		if(e&1):
			r *= b
		e >>=1
		b *= b
	return r

def is_prime(n):
	if n == 2 or n == 3: return True
	if n < 2 or n%2 == 0: return False
	if n < 9: return True
	if n%3 == 0: return False
	r = int(n**0.5)
	f = 5
	while f <= r:
#print '\t',f
		if n%f == 0: return False
		if n%(f+2) == 0: return False
		f +=6
	return True

t = raw_input()
t = int(t)
for q in xrange(0,t):
	a,m = raw_input().split()
	a = int(a)
	m = int(m)
	if(a>m):
		print "NO"
	elif(is_prime(m)==False):
		print "NO"
	else:
		ans = power(a,(m-1)/2)
		ans = (1-ans)%m
		if(ans==0):
			print "YES"
		
		else:
			print "NO"

