//Implementing of predictive texts.
//Candidate 1: Chetna Sureka 
//Candidate 2: Deepika Joshi
//Candidate 3: Ganesh S M
//Candidate 4: Gururaj Kulkarni
#include<stdio.h>
#include<string.h>

#include<stdlib.h>

struct node
{
	char c;
	struct node *parent;
	struct node *child;
	struct node *next;
};

void insert(struct node **, char *);
void display(struct node *);
void push(char *, char , int *);//The only stack operation used for this algo.
void autocomplete(char *, struct node *);