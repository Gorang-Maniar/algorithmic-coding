n = raw_input()
n = int(n)
for a in range(n):	
	
	str1 = raw_input()
	str2 = raw_input()
	
	len1 = len(str1)
	len2 = len(str2)
	arr = [0] * len1
	c=0
	for i in range(0,len1):
		if arr[i]!=1:
			for j in range(0,len2):
		    		if str1[i] == str2[j]:
		 			arr[i] = 1
		        		c+=1
		      			break
	print c		
