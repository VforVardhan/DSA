#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
} *head=NULL;

struct node* execute(struct node *tmp1);

int main()
{
	int n,k,m;
	printf("Enter the no. of men in the circle : ");
	scanf("%d",&n);
	printf("Enter the value of k : ");
	scanf("%d",&k);
	printf("Enter the position of the man to be kept alive : ");
    scanf("%d",&m);

	struct node *tmp=NULL,*tmp1;

    int i;
	for(i=1;i<=n;++i)
	{
		tmp1=head;

		tmp=(struct node *)malloc(sizeof(struct node));
		tmp->data=i;
		tmp->next=NULL;

		if(head==NULL)
			head=tmp;
		else
		{
			while(tmp1->next!=NULL)
				tmp1=tmp1->next;
			tmp1->next=tmp;
		}

		if(i==n)
			tmp->next=head;
	}

    tmp1=head;

    while(tmp1!=tmp1->next) //i.e. when a single node is left then stop.That node will point to itself
    {
	for(i=1;i<=(k-1)-1;++i)
		tmp1=tmp1->next;    //tmp1 is the man just before the man to be executed

	tmp1=execute(tmp1);
    }

    int d=m-tmp1->data;
    
    if(d>0)
      printf("Please start at position : %d\n",d+1);
    
    else if(d<0)
      printf("Please start at position : %d\n",n+d+1);  //d is a negative no. here.You have to move |d-1| steps back.
    
    else
      printf("Please start at position : 1\n");
}

struct node* execute(struct node *tmp1)
{
	tmp1->next=(tmp1->next)->next;
	tmp1=tmp1->next;
	return tmp1;
}
