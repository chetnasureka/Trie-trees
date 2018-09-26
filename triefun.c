#include "trie.h"
//Function used to insert the words.
 void insert(struct node **root, char *s)
{
	struct node *sib=NULL;//sib refers to previous sibling here.
	struct node *temp;
	struct node *par=*root;//par refers to parent.
		
	int i=0;//'i' always refers to the indexing of the string 

	if((*root)->child==NULL)//Inserts the first word in the form of a linear chain.
	{
		
		while(i<=strlen(s))
		{
			temp=(struct node *)malloc(sizeof(struct node ));
			temp->next=temp->child=NULL;
			temp->parent=par;
			par->child=temp;
			if (i==strlen(s))
			{
				temp->c='\0';
				break;
			}
			temp->c=s[i];
			par=par->child;
			i++;
		}
		
	}
	else
	{
		temp=par->child;
		while(temp!=NULL && i<=strlen(s))
		{

			if(temp->c==s[i])
			{
				par=temp;
				temp=temp->child;
	  			i++;
			}
			else
			{
				sib=temp;
				temp=temp->next;
			}
		}
		
		struct node *temp2;
		if(temp==NULL && i==strlen(s))
		{
			temp2=(struct node *)malloc(sizeof(struct node *));
			temp2->c='\0';
			temp2->parent=par;
			temp2->next=NULL;
			sib->next=temp2;
		}

	        if (temp==NULL && i<strlen(s))
		{
			int flag=0;
			while(i<=strlen(s))
			{
				temp=(struct node *)malloc(sizeof(struct node ));
				temp->next=temp->child=NULL;
				temp->parent=par;
			
				if(flag==1)
					par->child=temp;
				else
					sib->next=temp;
			
				if (i==strlen(s))
				{
					temp->c='\0';
					break;
				}
				flag=1;
				temp->c=s[i];
				par=temp;
				i++;
			}
		}	
	
	}
}

//Function used to display all the words from a particular node
void display(struct node *root)//Recursive function to print all the words possible, given the pointer to the last node(root) of a particular series of characters 
{
	if(root!=NULL)
	{
		struct node *temp=root;
		char *st=(char *)malloc(300*sizeof(char));//st is the stack which is used to insert all the characters included in the ancestor of root.
		int i,top=-1;

		while(temp->parent!=NULL || temp->c!='\0')
		{
		push(st,temp->c,&top);
		temp=temp->parent;
		}
		for(i=top;i>=0;i--)
			printf("%c",st[i]);//Prints the ancestor nodes' charactors in the correct order.
		if(root->child!=NULL)
		{
			temp=root->child;
			while(temp->c!='\0')
			{
			printf("%c",temp->c);//prints the following children's characters to complete the word
			temp=temp->child;
			}
		}
		printf("\n");
		while(root!=NULL)
		{
			display(root->next);//if root->next is equal to null, the function does nothing according to the first conditional statement.
			root=root->child;
		}
	}
	
}

//Function used to push characters into the stack used in Display.
void push(char *s,char c, int *top)
{
	(*top)++;
	s[*top]=c;
}

//Function used to traverse and fetch the particular node to the display function.
void autocomplete(char *s,struct node *root)
{
	int i;
	root=root->child;
	while(root!=NULL && s[i]!='\0')//ends up with the required pointer from which all words are to be printed or NULL. 
	{
		while(root!=NULL && root->c!=s[i])
			root=root->next;
		i++;
		if(root!=NULL)
		root=root->child;
	}
	if(root==NULL)
		printf("No words found\n");
	else
		display(root);
}