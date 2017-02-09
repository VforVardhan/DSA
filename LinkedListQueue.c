#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
} *front=NULL,*rear=NULL;

void enqueue(struct node *rearnode,int item);
int dequeue(struct node *frontnode);
int peek(struct node *frontnode);
void display(struct node *frontnode);

int  main()
{
	printf("Your queue is ready.");
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
    		int item;
    		printf("Enter the item to enqueue : ");
    		scanf("%d",&item);
    		enqueue(rear,item);
    		printf("Your queue is : ");
    		display(front);
    		break;
    	}

    	case 2:
    	{
    		if(front==NULL)   //at this moment rear is also null. See line no. 115
    		{
    			printf("UNDERFLOW !!\n");
    			exit(0);
    		}
    		else
    		{
    			int item=dequeue(front);
                printf("%d was dequeued.\n",item);
    			printf("Your queue is : ");
    		    display(front);
    		}
    		break;
    	}

    	case 3:
    	{
    		if(front==NULL)
    			printf("Your queue is empty !!");
    		else
    		{
    			int item=peek(front);
    			printf("The front element is %d\n",item);
    			printf("Your queue is : ");
    		    display(front);
    		}

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

    return 0;
}

void enqueue(struct node *rearnode,int item)
{
	struct node *tmp=(struct node*)malloc(sizeof(struct node));
	tmp->data=item;
	tmp->next=NULL;

	if(rearnode==NULL)
	{
		rearnode=tmp;
		front=tmp;
	}
		
    else
	{
        rearnode->next=tmp;
        rearnode=tmp;
    }

    rear=rearnode;
}

int dequeue(struct node *frontnode)
{
  int val=frontnode->data;
  front=frontnode->next;
  free(frontnode);

  if(front==NULL)
  	rear=NULL;     // i.e. when front and rear both point to same node it means that you have only one node in queue.Now when you dequeue, front becomes NULL
                   //      but rear doesn't. So you have to make it NULL on this condition so that when you enqueue this empty queue the next time,
                   //      rearnode==NULL becomes true and first node can be created

  return val;
}

int peek(struct node *frontnode)
{
	return frontnode->data;
}

void display(struct node *frontnode)
{
	struct node *tmp1=frontnode;
	while(tmp1!=NULL)
	{
		printf("%d ",tmp1->data);
		tmp1=tmp1->next;
	}
}