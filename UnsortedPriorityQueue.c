//AN UNSORTED PRIORITY QUEUE HAS O(1) COMPLEXITY OF INSERTION


#include <stdio.h>
#include <stdlib.h>

struct node
{
	char proname;
	int pri;
	struct node *next;
} *head=NULL;

void createNode(struct node *headnode,char name,int prinumber);

int main()
{
	int n;
	printf("We will create an unsorted priority queue.Enter the no. of processes in the queue : ");
	scanf("%d",&n);

	int i;
	for(i=1;i<=n;++i)
	{
	  char name;
	  int prinumber;
      printf("Enter your process name (an english alphabet) : ");
      scanf(" %c",&name);                                  //Can you tell why have I used %c with a space before it ? Hint : See the input at line 14
      printf("Enter your process priority number : ");
      scanf("%d",&prinumber);
      createNode(head,name,prinumber);
	}

	printf("Your Unsorted Priority Queue :\n");
	display(head);

	printf("\nThe processes will be executed in this order :\n");
	bubblesort(head,n);
	display(head);
}

void createNode(struct node *headnode,char name,int prinumber)
{
	struct node *tmp=NULL,*tmp1=head;

	tmp=(struct node*)malloc(sizeof(struct node));
	tmp->proname=name;
	tmp->pri=prinumber;
	tmp->next=NULL;

	if(headnode==NULL)
		headnode=tmp;
	else
	{
		while(tmp1->next!=NULL)
			tmp1=tmp1->next;
		tmp1->next=tmp;
	}

	head=headnode;
}

void bubblesort(struct node *headnode,int n)
{
	int i,j,k;
    for(i=n-1;i>=1;i--)
    {
      int swapPriority=0,flag=0;
      char swapName;
      
      for(j=1;j<=i;++j)
    	{
    	 struct node* tmp1=headnode;

    	 for(k=1;k<=j-1;++k)
    	 tmp1=tmp1->next;

    	 if((tmp1->next)->pri < tmp1->pri)
    	  {
    		swapPriority=(tmp1->next)->pri;
    		(tmp1->next)->pri=tmp1->pri;
    		tmp1->pri=swapPriority;
            
            swapName=(tmp1->next)->proname;
    		(tmp1->next)->proname=tmp1->proname;
    		tmp1->proname=swapName;


    		flag=1;
    	  }
    	}

    	if(flag==0)
        break;
    }
}

void display(struct node *headnode)
{
    struct node *tmp1=head;
    while(tmp1!=NULL)
	{
		printf("%c%d ",tmp1->proname,tmp1->pri);
		tmp1=tmp1->next;
	}
}