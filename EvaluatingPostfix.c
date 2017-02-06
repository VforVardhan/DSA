#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	double data;
	struct node *next;
}* top=NULL;

void push(struct node *top,int item);
int pop(struct node *top);
//void print(struct node *top);

int main()
{
	char exp[100];
    printf("A quite basic postfix evaluator here....Logic is perfect but handling inputs is limited :(");
	printf("\nEnter your postfix expression (less than 100 characters and having only single-digit whole numbers) here : ");
	gets(exp);

	int popped1,popped2,val,result;

    int i;
	for(i=0;i<strlen(exp);++i)
	{
		if(exp[i]!='+' && exp[i]!='-' && exp[i]!='*' && exp[i]!='/' && exp[i]!='%')
			push(top,exp[i]-48);
		else
		{
			popped1=pop(top);
			popped2=pop(top);
			
            switch(exp[i])
			{                                            // NOTE THAT WE HAVE TO APPLY POPPED2 (OPERATOR) POPPED1
				case '+':
				    val = popped2 + popped1;
					break;
				case '-':
				    val = popped2 - popped1;
				    break;
				case '*':
				    val = popped2 * popped1;
				    break;
				case '/':
				    val = popped2 / popped1;
				    break;
				case '%':
				    val = popped2 % popped1;
				    break;
			}
			push(top,val);
		}
		print(top);
	}
 
	result=pop(top);
	printf("The value is %d",result);
}

void push(struct node *headnode,int item)
{
	struct node *tmp=(struct node*)malloc(sizeof(struct node));
	tmp->data=item;
	tmp->next=NULL;

    tmp->next=headnode;
    headnode=tmp;

    top=headnode;
}

int pop(struct node *headnode)
{
	int item=headnode->data;
	top=headnode->next;
	free(headnode);
	return item;
}

/*void print(struct node* headnode)
{
	struct node *tmp1=headnode;
	while(tmp1!=NULL)
	{
		printf("%c ",tmp1->data);
		tmp1=tmp1->next;
	}
}*/

