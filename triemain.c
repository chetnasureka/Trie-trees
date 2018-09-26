#include "trie.h"
int main()
{
	struct node *root;
	root=(struct node *)malloc(sizeof(struct node));
	root->c='\0';
	root->next=root->child=root->parent=NULL;
	int c;
	FILE *fp;
 	char *ch;
 	ch=(char * )malloc(10*sizeof(char));
 	fp = fopen("test1.txt", "r");//Extracting words from a database.
 	while (fscanf(fp,"%s",ch)==1)
   	{
    	insert(&root,ch);
    }
 	fclose(fp);

 	char *s; //Input string used for passing words and prefix substring.   
	s=(char *)malloc(10*sizeof(char));
		
	while(1)
	{
		gotoxy(10,10);
		//system("clear");
		printf("1. Insert word.\n");
		printf("2.Display al words\n");
		printf("3. Autocomplete\n");
		printf("Enter your choice\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1: printf("Enter the word\n");
					scanf("%s",s);
					insert(&root,s);
					system("clear");
					break;
			case 2: display(root);
					break;
			case 3: printf("Enter the word to be completed\n");
					scanf("%s",s);
					system("clear");
					printf("The predicted texts are\n");
					autocomplete(s,root);
					
					break;
		}
	}
}