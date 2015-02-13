n = raw_input()
n = int(n)	
count = 0
for i in range(0,n):
	p,q = raw_input().split()
	p = int(p)
	q = int(q)

	if(q-p>=2):
		count+=1
	else:
	 	continue
print count	 

