//NOTE THAT FIRST OF ALL YOU HAVE TO ADD ) AT THE END OF THE INFIX EXPRESSION
//THIS HAS NOT BEEN DONE HERE. SEE LINE 23. PLEASE TRY TO DO IT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	char data;
	struct node *next;
} *headOfStack=NULL,*headOfPostfix=NULL;

void pushIntoStack(struct node *headnode,char item);
char popFromStack(struct node *headnode);
char peekIntoStack(struct node *headnode);
void addToPostfix(struct node *headnode,char item);
void printPostfix(struct node *headnode);

int main()
{
	char infix[100];
	printf("Enter the infix expression (adding the '(' at the end) here : ");
	gets(infix);

    struct node *tmp=(struct node*)malloc(sizeof(struct node));
	tmp->data='(';
	tmp->next=NULL;
	headOfStack=tmp;

	char topOfStack='\0',charPopped='\0';

	int i;
	for(i=0;i<strlen(infix);++i)
	{
		topOfStack=peekIntoStack(headOfStack);

		if(infix[i]=='+' || infix[i]=='-')
        {
           if(topOfStack=='+' || topOfStack=='-'  || topOfStack=='*' || topOfStack=='/' || topOfStack=='%')
            {
             while(topOfStack=='+' || topOfStack=='-'  || topOfStack=='*' || topOfStack=='/' || topOfStack=='%')
              {
                charPopped=popFromStack(headOfStack);
                addToPostfix(headOfPostfix,charPopped);
                topOfStack=peekIntoStack(headOfStack);
              }
             pushIntoStack(headOfStack,infix[i]);
            }
           else
            pushIntoStack(headOfStack,infix[i]);
        }

        else if(infix[i]=='*' || infix[i]=='/' || infix[i]=='%')
        {
           if(topOfStack=='*' || topOfStack=='/'  || topOfStack=='%')
            {
             while(topOfStack=='*' || topOfStack=='/'  || topOfStack=='%')
              {
                charPopped=popFromStack(headOfStack);
                addToPostfix(headOfPostfix,charPopped);
                topOfStack=peekIntoStack(headOfStack);
              }
             pushIntoStack(headOfStack,infix[i]);
            }

           else
            pushIntoStack(headOfStack,infix[i]);
        }

	    else if(infix[i]=='(')
		{
		 pushIntoStack(headOfStack,infix[i]);
	    }

	    else if(infix[i]==')')
        {
          topOfStack=peekIntoStack(headOfStack);
          while(topOfStack!='(')
          {
            charPopped=popFromStack(headOfStack);
            addToPostfix(headOfPostfix,charPopped);
            topOfStack=peekIntoStack(headOfStack);
          }
          charPopped=popFromStack(headOfStack);
        }

        else  //anything other than an operator or '(' or ')' , so assumedly an operand
        {
         addToPostfix(headOfPostfix,infix[i]);
        }
	}
    printf("The postfix notation is : \n");
    printPostfix(headOfPostfix);
    printf("\n");
    return 0;
}

void pushIntoStack(struct node *headnode,char item)
{
	struct node *tmp=(struct node*)malloc(sizeof(struct node));
	tmp->data=item;
	tmp->next=NULL;

	tmp->next=headnode;
	headnode=tmp;

	headOfStack=headnode;
}

char popFromStack(struct node *headnode)
{
	char val=headnode->data;
	headOfStack=headnode->next;
	free(headnode);
	return val;
}

char peekIntoStack(struct node *headnode)
{
	return headnode->data;
}

void addToPostfix(struct node *headnode,char item)
{
	struct node *tmp=NULL,*tmp1=headnode;

    tmp=(struct node*)malloc(sizeof(struct node));
	tmp->data=item;
	tmp->next=NULL;

	if(headnode==NULL)
		headnode=tmp;
	else
	{
		while(tmp1->next!=NULL)
			tmp1=tmp1->next;
        tmp1->next=tmp;
	}

	headOfPostfix=headnode;
}

void printPostfix(struct node *headnode)
{
	struct node *tmp1=headnode;
	while(tmp1!=NULL)
	{
		printf("%c",tmp1->data);
		tmp1=tmp1->next;
	}
}
