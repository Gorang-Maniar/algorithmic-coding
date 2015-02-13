def power(b,e):
	r=1
	while e:
		if(e&1):
			r *= b
		e >>=1
		b *= b
	return r
t = raw_input()
t = int(t)
for q in xrange(0,t):
	n,m=raw_input().split()
	m = int(m)
	n = int(n)
	s = n+m
	c = power(2,s)
	d = c*2
	arr = [[-2 for x in range(2)] for x in range(d)]
	arr[1][0] = n
	arr[1][1] = m
	i=1
	count =0
	while(c>1):
		if(arr[i][0]>0):
			arr[2*i][0]=arr[i][0]-1
			arr[2*i][1]=arr[i][1]
		elif(arr[i][0]==0):
		 	arr[2*i][0]=-1
			arr[2*i][1]=-1
		if(arr[i][1]>0):
			arr[(2*i)+1][0]=arr[i][0]
			arr[(2*i)+1][1]=arr[i][1]-1
		elif(arr[i][1]==0):
			arr[(2*i)+1][1]=-1
			arr[(2*i)+1][0]=-1
		i+=1
		c-=1
	for j in xrange(2,d):
		if(arr[j][0]==0 and arr[j][1]==0):
			count+=1

	print count
