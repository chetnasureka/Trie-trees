class node:
	def __init__(self,c):
		self.char=c
		self.end=False
		self.next=None
		self.down=None
root=None
def insert(string):
	global root
	if not root:
		i=1
		root=node(string[0])
		present=root
		while i<len(string)-1:
			present.down=node(string[i])
			present=present.down
			i+=1
		present.down=node(string[i])
		present.down.end=True
	else:
		i=0
		flag=0
		present=root	
		while i<len(string):
			while present.next!=None and present.char!=string[i]:
				present=present.next
			if present.char==string[i]:
				if i==len(string)-1:
					present.end=True	
				else:
					if present.down:
						present=present.down
					else:
						present.down=node(string[i+1])
						present=present.down
						if i+1==len(string)-1:
							present.end=True
						flag=1
						i+=2

			else:
				present.next=node(string[i])
				flag=1
				present=present.next
				if i==len(string)-1:
					present.end=True
				i+=1
			if flag:
				break
			i+=1
		if flag:		
			while i<len(string):
				present.down=node(string[i])
				present=present.down
				if i==len(string)-1:
					present.end=True
				i+=1
def isPresent(string):
	present=root
	i=0
	while i<len(string)-1:
		if present:
			while present.next!=None and present.char!=string[i]:
				present=present.next
			if present.char==string[i]:
				present=present.down
			else:
				return False
		else:
			return False
		i+=1
	while present:
		if present.char==string[-1] and present.end:
			return True
		present=present.next
				
	return False

def wordsFromNode(Node,word):
	words_list=[]
	while Node:
		if Node.next:
			words_list.extend(wordsFromNode(Node.next,word))
		word+=Node.char
		if Node.end==True:
			words_list.append(word)
		Node=Node.down
	return words_list

def wordsWithPrefix(prefix):
	i=0
	present=root
	include=0
	while i<len(prefix):
		if not present:
			return []
		while present and present.char!=prefix[i]:
			present=present.next
		if not present:
			return []
		else:
			if i==len(prefix)-1 and present.end:
				include=1
			present=present.down
		i+=1
	if include:
		answer=wordsFromNode(present,prefix)
		answer.append(prefix)
		return answer
	return wordsFromNode(present,prefix)			


with open("input_library.txt") as file:
	for line in file:
		insert(line.strip())

#Prompt
while(1):
	print("Enter any of the following options")
	print("1 | inserting a new word into library")
	print("2 | checking if a word is present in the library")
	print("3 | getting all the words from the library with a given prefix")
	print("4 | exit")
	option=input("Enter your option: ")
	if option=='1':
		st=input("Enter the word to be inserted: ")
		insert(st)
	elif option=='2':
		st=input("Enter the word to be checked: ")
		print(isPresent(st))
	elif option=='3':
		st=input("Enter the prefix: ")
		answer_list=wordsWithPrefix(st)
		if answer_list:
			print("-"*50)
			print("Words with the prefix '%s':"%st)

			for i in answer_list:
				print(i)
			#print("-"*50)
			print("%s entries found"%len(answer_list) if len(answer_list)!=1 else "1 entry found")
		else:
			print("No words found")
			
	elif option=='4':
		break
	else:
		print("Invalid option")
	print("-"*50)
	 
