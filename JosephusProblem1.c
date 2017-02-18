#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
} *head=NULL;

struct node* execute(struct node *tmpdie);
int main()
{
	int n,k,s;
	printf("Enter the no. of men in the circle : ");
	scanf("%d",&n);
	printf("Enter the value of k : ");
	scanf("%d",&k);
	printf("Enter the starting position : ");
    scanf("%d",&s);

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
    
    for(i=1;i<=s-1;++i)
	tmp1=tmp1->next;

    while(tmp1!=tmp1->next)  //i.e. when a single node is left then stop.That node will point to itself
    {
	for(i=1;i<=(k-1)-1;++i)
		tmp1=tmp1->next;     //tmp1 is the man just before the man to be executed
	
	tmp1=execute(tmp1);     
    }

    printf("The alive man is at position : %d\n",tmp1->data);
}

struct node* execute(struct node *tmp1)
{
	tmp1->next=(tmp1->next)->next;
	tmp1=tmp1->next;
	return tmp1;
}
