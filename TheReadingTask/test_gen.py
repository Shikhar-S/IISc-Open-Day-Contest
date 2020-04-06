from random import randint
N= int(input('Number of word '))
M= int(input('Ref length '))
K= int(input('sigma len words '))
K=max(K,2*N)
W_L= int(input('single word length max '))
S=set()
file_name=input('Test file name ')
with open(file_name,'w') as F:
	print(N,file=F)
	start=ord('a')

	letters=[chr(i) for i in range(ord('a'),ord('a')+26)]

	cur_len=2*N
	i=0
	while i<N:
		val=randint(2,max(min(W_L,K-cur_len),2))
		cur_len += val
		current_string=""
		for j in range(val):
			rndindx=randint(0,25)
			current_string=current_string+str(letters[rndindx])
		if(current_string in S):
			i-=1
		else:
			print(current_string,file=F)
			S.add(current_string)
		i+=1

	print(M,file=F)
	ref=""
	for i in range(M):
		ref+=str(letters[randint(0,25)])
	print(ref,file=F) 
