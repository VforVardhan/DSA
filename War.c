#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
} *bob=NULL,*alice=NULL;

struct node *newnode=NULL;

void createnodebob(struct node *headnode,int a);
void createnodealice(struct node *headnode,int a);
int findLargest(struct node *headnode);

int main()
{
	int t,n,a;
	
	//printf("Enter the no. of test-cases : ");
	scanf("%d",&t);
	int i;
	for(i=1;i<=t;++i)
	{
	scanf("%d",&n);
	
	int j;
	for(j=1;j<=n;++j)
	{
		scanf("%d",&a);
		createnodebob(bob,a);
    }

    newnode=NULL;
    
    for(j=1;j<=n;++j)
    {
        scanf("%d",&a);
		createnodealice(alice,a);
	}
	
	int bo=findLargest(bob);
	int al=findLargest(alice);
	printf("%d",bo);
	printf("\n%d",al);
	printf("\n");
	if(bo>al)
		printf("Bob\n");
	else if(bo<al)
		printf("Alice\n");
	else
		printf("Tie\n");

	bob=NULL;
	alice=NULL;
	newnode=NULL;
   }
}

void createnodebob(struct node *headnode,int a)
{
	struct node *tmp=(struct node*)malloc(sizeof(struct node));
	tmp->data=a;
	tmp->next=NULL;

	if(headnode==NULL)
	   headnode=tmp;
	else
       newnode->next=tmp;

	newnode=tmp;

	bob=headnode;
}

void createnodealice(struct node *headnode,int a)
{
	struct node *tmp=(struct node*)malloc(sizeof(struct node));
	tmp->data=a;
	tmp->next=NULL;

	if(headnode==NULL)
	   headnode=tmp;
	else
       newnode->next=tmp;

	newnode=tmp;

	alice=headnode;
}

int findLargest(struct node *headnode)
{
	struct node *tmp=headnode,*largest=headnode;
	while(tmp->next!=NULL)
	{
		if(tmp->data > largest->data)
			largest=tmp;

		tmp=tmp->next;
	}

	return (largest->data);
}
