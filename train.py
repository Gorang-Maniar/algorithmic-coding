from fractions import gcd
a,b = raw_input().split()
a = int(a)
b = int(b)
g = gcd(a,b)

lcm = (a*b)/g 

if (lcm/a) > (lcm/b + 1):
	print "Dasha"
elif (lcm/b) > (lcm/a + 1):
	print "Masha"
else:
	print "Equal"		
