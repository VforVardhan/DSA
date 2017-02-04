#include <stdio.h>

int max,top=-1;

void push(int stack[],int item);
int pop(int stack[]);
int peek(int stack[]);
void display(int stack[]);

int main()
{
	printf("Enter the size of your stack of integers : ");
	scanf("%d",&max);

	int stack[max];
    printf("Your stack of %d integers has been created !!\n",max);

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
    		push(stack,item);
    		display(stack);
    		break;
    	}

    	case 2:
    	{
    		int item=pop(stack);
    		printf("%d popped out.\n",item);
    		display(stack);
    		break;
    	}

    	case 3:
    	{
    		int item=peek(stack);
    		if(top!=-1)
    		{
    		 printf("The TOP of stack has %d.\n",item);
    		 display(stack);
    		}
    		break;
    	}

    	case 4:
    	{
    		exit(0);
    	}

    	default:
    	printf("You can only enter 1/2/3/4");
     }
    printf("\nEnter your choice of push/pop/peek/exit : ");
    scanf("%d",&ch);
   }
}

void display(int stack[])
{
	printf("Your stack is : ");
	int i;
	for(i=0;i<=top;++i)
		printf("%d ",stack[i]);
}

void push(int stack[],int item)
{
	if(top==max-1)
	{
		printf("OVERFLOW !!\n");
		exit(0);
	}
	else
	{
		top++;
		stack[top]=item;
	}
}

int pop(int stack[])
{
	if(top==-1)
	{
		printf("UNDERFLOW !!\n");
		exit(0);
	}
	else
	{
		int val=stack[top];
		top--;
		return val;
	}
}

int peek(int stack[])
{
	if(top==-1)
		printf("Your stack is empty.");
	else
	    return stack[top];
}

