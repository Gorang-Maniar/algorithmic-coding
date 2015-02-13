t = raw_input()
t = int(t)
for q in xrange(0,t):
	s = raw_input()
	s = int(s)
	t = s/21
	print ((s*2)+(t*2))%1000000007
