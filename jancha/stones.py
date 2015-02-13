t = raw_input()
t = int(t)
for q in range(0,t):
	n,k = raw_input().split()
	n = int(n)
	k = int(k)
	a = []
	b = []
	maxi = 0
	c = raw_input()
	a = c.split()
	for i in range(0,n):
		a[i] = int(a[i])
		a[i] = k/a[i]

	c = raw_input()
	b = c.split()
	for i in range(0,n):
		b[i] = int(b[i])
		t = a[i]*b[i]
		if(t > maxi):
			maxi = t

	print maxi

