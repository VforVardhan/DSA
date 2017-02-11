//A SORTED PRIORITY QUEUE HAS O(n) COMPLEXITY OF INSERTION
//BUT HERE YOU HAVE JUST INSERTED THE NEW PROCESSES AT THE END OF THE QUEUE WHICH BECOMES O(1)


#include <stdio.h>
#include <stdlib.h>

struct node
{
	char proname;
	int pri;
	struct node *next;
} *head=NULL;

void display(struct node *headnode);
void insertProcess(struct node *headnode);
void bubblesort(struct node *headnode,int n);

int main()
{
	printf("Suppose there exists a sorted priority queue of these 6 processes with their respective priority numbers :\n");
	printf("A 1\n");
	printf("B 2\n");
	printf("C 3\n");
	printf("D 3\n");
	printf("E 5\n");
	printf("F 7\n\n");

	struct node *tmp=NULL,*tmp1=NULL;


	int i;
	for(i=1;i<=6;++i)
	{
      tmp=(struct node *)malloc(sizeof(struct node));
	  tmp->proname='\0';
	  tmp->pri=0;
	  tmp->next=NULL;

	  tmp1=head;

	  if(i==2)
	  {
	  	tmp->proname='B';
	  	tmp->pri=2;
	  }
      if(i==3)
	  {
	  	tmp->proname='C';
	  	tmp->pri=3;
	  }
      if(i==4)
	  {
	  	tmp->proname='D';
	  	tmp->pri=3;
	  }
      if(i==5)
	  {
	  	tmp->proname='E';
	  	tmp->pri=5;
	  }
      if(i==6)
	  {
	  	tmp->proname='F';
	  	tmp->pri=7;
      }

      if(i!=1)
      {
	  while(tmp1->next!=NULL)
	  		tmp1=tmp1->next;
      tmp1->next=tmp;
      }

	  if(i==1)
	  {
	  	tmp->proname='A';
	  	tmp->pri=1;
	  	head=tmp;
	  }
	}

  printf("Your Sorted Priority Queue :\n");
	display(head);

	printf("\nWould you like to insert your own process in this queue (y/n) ? : ");
	char ch;
	scanf("%c",&ch);

	int count=6;

    while(ch=='y')
    {
       count++;
       insertProcess(head);
       printf("Would you like to insert your own process in this queue (y/n) ? : ");
	   scanf(" %c",&ch);
    }

    printf("The processes will be executed in this order :\n");
    bubblesort(head,count);                                      //Since bubble sort is a stable sorting algo, you will have results in accordance with FCFS ;)
	display(head);
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

void insertProcess(struct node *headnode)
{
      struct node *tmp=NULL,*tmp1=headnode;

      tmp=(struct node *)malloc(sizeof(struct node));
	  tmp->next=NULL;

      printf("Enter your process name (an english alphabet) : ");
      scanf(" %c",&tmp->proname);                                  //Can you tell why have i used %c with a space before it ? Hint : See the input at line 83
      printf("Enter your process priority number : ");
      scanf("%d",&tmp->pri);

      while(tmp1->next!=NULL)
      		tmp1=tmp1->next;
      tmp1->next=tmp;
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
   









      /*int pos=-1,count=0;
      
      int i;
      for(i=1;i<=6;++i)
      {
      	count++;
      	if(tmp1->pri > tmp->pri)
      	{
      	   pos=count;
      	   break;
      	}
      	tmp1=tmp1->next;
      }
     
      tmp1=headnode;
      if(pos==1)
      {
      	tmp->next=headnode;
      	headnode=tmp;
      	head=headnode;
      }
      else if(pos==-1)
      {
      	while(tmp1->next!=NULL)
      		tmp1=tmp1->next;
      	tmp1->next=tmp;
      }
      else
      {
       int i;
       for(i=1;i<=(pos-1)-1;++i)
      	 tmp1=tmp1->next;

      tmp->next=tmp1->next;
      tmp1->next=tmp;
      }*/
