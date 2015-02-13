from fractions import gcd
t = raw_input()
for y in range(int(t)):
	n,q = raw_input().split()
	n = int(n)
	q = int(q)
	c = raw_input()
	arr = c.split()

	for i in range(n):
		arr[i] = int(arr[i])
	
	for j in range(q):
		l,r = raw_input().split()
		l = int(l)
		r = int(r)
		fl=0
		ans=0

		for i in range(0,l-1):
			w = gcd(arr[i],arr[i+1])
			if (w==1):
				fl=1
				break
			elif(w<ans and ans%w!=0):
				fl=1
				break
			elif(w<ans):
				ans = w

			for j in range(r+1,n-1):
				w=gcd(arr[j],arr[j+1])
		 		if(w==1):
					fl=1
					break
				elif(w<ans and ans%w!=0):
					fl=1
					break
				elif(w<ans):
					ans = w
		if fl==1:
		   	print 1
		else:
		   	print ans
