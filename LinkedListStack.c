#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
}* top=NULL;

void push(struct node *top,int item);
int pop(struct node *top);
int peek(struct node *top);
void display(struct node *top);

int main()
{
	printf("An empty stack has been created for you.\n");

	printf("1. push\n");
    printf("2. pop\n");
    printf("3. peek\n");
    printf("4. exit\n");
    printf("Enter your choice of push/pop/peek/exit : ");
    int ch;
    scanf("%d",&ch);

    while(ch!=4)
    {
    switch(ch)
     {
    	case 1:
    	{
    		int item;
    		printf("Enter the item to push : ");
    		scanf("%d",&item);
    		push(top,item);
    		display(top);
    		break;
    	}

    	case 2:
    	{
    		int item=pop(top);
    		printf("%d popped out.\n",item);
    		display(top);
    		break;
    	}

    	case 3:
    	{
    		int item=peek(top);
    		if(top!=NULL)
    		{
    		 printf("The TOP of stack has %d.\n",item);
    		 display(top);
    		}
    		break;
    	}

    	case 4:
    	{
    		exit(0);
    	}

    	default:
    	{
    	 printf("You can only enter 1/2/3/4");
    	}
     }
    printf("\nEnter your choice of push/pop/peek/exit : ");
    scanf("%d",&ch);
   }
}

void push(struct node* headnode,int item)
{
	struct node *tmp=(struct node*)malloc(sizeof(struct node));
	tmp->data=item;
	tmp->next=NULL;

	tmp->next=headnode;
	headnode=tmp;

	top=headnode;
}

void display(struct node* headnode)
{
	struct node *tmp1=headnode;
	printf("Your stack is : ");
	while(tmp1!=NULL)
	{
      printf("%d ",tmp1->data);
      tmp1=tmp1->next;
    }
}

int pop(struct node *headnode)
{
   if(headnode==NULL)
   {
   	printf("UNDERFLOW !!\n");
   	exit(0);
   }
   else
   {
   	int val=headnode->data;
    top=headnode->next;
   	free(headnode);

   	return val;
   }
}

int peek(struct node *headnode)
{
	if(headnode==NULL)
		printf("The stack is empty.\n");
	else
		return headnode->data;
}