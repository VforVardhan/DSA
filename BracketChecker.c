#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node
{
	char data;
	struct node *next;
}* top=NULL;

void push(struct node *headnode,char item);    //push has been done as is done in a linked list i.e. insertion at the beginning
char pop(struct node *headnode);

int main()
{
  char exp[100];
  printf("Enter your expression (less than 100 characters) here : ");
  gets(exp);

  int flag,i;
  char popped;
  
  for(i=0;i<strlen(exp);++i)
   {
   if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
   	push(top,exp[i]);

   if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
    {
   	 flag=0;
   	 popped=pop(top);
     
     if( (popped=='(' && exp[i]==')') || (popped=='{' && exp[i]=='}') || (popped=='[' && exp[i]==']') )
   	   flag=1;
     else
   	  {
   	   	printf("INVALID EXPRESSION !!\n");
   		  exit(0);
   	  }
   	}
   }
  
  if(flag==1)
  printf("VALID EXPRESSION !!\n");
}

void push(struct node *headnode,char item)
{
	struct node *tmp=(struct node*)malloc(sizeof(struct node));
	tmp->data=item;
	tmp->next=NULL;

    tmp->next=headnode;
    headnode=tmp;

    top=headnode;
}

char pop(struct node *headnode)
{
	char val=headnode->data;
	top=headnode->next;
	free(headnode);
	return val;
}
