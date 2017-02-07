#include <stdio.h>

int max,front=-1,rear=-1;

void enqueue(int queue[],int item);
int dequeue(int queue[]);
int peek(int queue[]);
void display(int queue[]);

int main()
{
	printf("Enter the size of your queue of integers : ");
	scanf("%d",&max);

	int queue[max];
	printf("\nYour queue is ready !!");

    printf("\nSelect one of these options 1/2/3/4 :");
    printf("\n1. Enqueue");
    printf("\n2. Dequeue");
    printf("\n3. Peek");
    printf("\n4. Exit\n");
    int ch;
    scanf("%d",&ch);

    while(ch!=4)
    {
    switch(ch)
      {
    	case 1:
    	{
    		if(rear==max-1)
    		{
    			printf("OVERFLOW !!");
    			exit(0);
    		}
    		else
    		{
    			int item;
    			printf("Enter the item to enqueue : ");
                scanf("%d",&item);
    		    enqueue(queue,item);
    		}
            printf("Your queue is : ");
    		display(queue);
    		printf("\nFRONT = %d and REAR = %d",front,rear);

    		break;
    	}

    	case 2:
    	{
    		if(front==-1 || front>rear)  //rear = -1 if front = -1 i.e queue has just been declared and is empty
    		{
                printf("UNDERFLOW !!");
    			exit(0);
    		}	
    		else
    		{	
    			int item=dequeue(queue);
    			printf("%d was dequeued",item);
    		}
    		printf("\nYour queue is : ");
    		display(queue);
    		printf("\nFRONT = %d and REAR = %d",front,rear);

    		break;
    	}

    	case 3:
    	{
    		if(front==-1 || front>rear)  //rear = -1 if front = -1 i.e queue has just been declared and is empty
    		{
    		  printf("The queue is empty !!");
    		}
    		else
    		{
    		  int item=peek(queue);
    		  printf("The front element is %d",item);
    		  printf("Your queue is : ");
    		  display(queue);
    		}
    		printf("\nFRONT = %d and REAR = %d",front,rear);
    		  
    		break;
        }

    	default:
    	{
    		printf("You can only select 1/2/3/4 ");
            break;
    	}
      }

      printf("\nSelect one of these options 1/2/3/4 :");
      scanf("%d",&ch);
    }

    printf("You chose to exit. BYE BYE !!\n");
}

void enqueue(int queue[],int item)
{
	if(rear==-1)   //front = -1 if rear = -1 i.e queue has just been declared and is empty
	{
		front=0;
		rear=0;
	}
	else
	{
	    rear++;
	}

	queue[rear]=item;
}

int dequeue(int queue[])
{
	int val=queue[front];
    if(front==rear)       
    {
        front=-1;
        rear=-1;           //recreating this empty queue
    }
    else
	front++;

	return val;
}

int peek(int queue[])
{
	int val=queue[front];
	return val;
}

void display(int queue[])
{
	int i;
	for(i=front;i<=rear;++i)
		printf("%d ",queue[i]);
}