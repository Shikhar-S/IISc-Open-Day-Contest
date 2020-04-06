n=int(input('Enter number of demons '))
f=input('Enter file name ')
with open(f,'w') as F:
	print(n,file=F)