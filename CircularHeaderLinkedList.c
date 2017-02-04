#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
}* head;

void createNode(struct node* headnode,int i,int n);
void printNode(struct node* headnode);

void insertNodeAtBeginning(struct node* headnode);
void insertNodeInMiddle(struct node* headnode);

void deleteNodeFromBeginning(struct node* headnode);
void deleteNodeFromMiddle(struct node* headnode);

int main()
{
	int n;
	printf("Enter the no. of nodes in the Circular Header Linked List : ");
	scanf("%d",&n);

	int i;
	for(i=0;i<=n;++i)
		createNode(head,i,n);

	printf("\nYour circular header linked list is : ");
	printNode(head);

    insertNodeAtBeginning(head);
    head->data=n+1;
	printf("Your new circular header linked list is : ");
    printNode(head);

    insertNodeInMiddle(head);
    head->data=n+2;
	printf("Your new circular header linked list is : ");
    printNode(head);

    deleteNodeFromBeginning(head);
    head->data=n+1;
    printf("Your new circular header linked list is : ");
    printNode(head);
    
    deleteNodeFromMiddle(head);
    head->data=n;
    printf("Your new circular header linked list is : ");
    printNode(head);
}

void createNode(struct node* headnode,int i,int n)
{
	struct node *tmp=NULL,*tmp1=headnode;

	tmp=(struct node*)malloc(sizeof(struct node));
	tmp->next=NULL;

	if(headnode==NULL)
	{
	   tmp->data=n;
	   headnode=tmp;
    }
	else
	{
       printf("Enter the data for the node : ");
       scanf("%d",&tmp->data);
       while(tmp1->next!=NULL)
       	   tmp1=tmp1->next;
       	tmp1->next=tmp;

       if(i==n)
       	tmp->next=headnode;
    }

    head=headnode;
}

void printNode(struct node* headnode)
{
	int c=0;
	struct node *tmp1=headnode->next;

	while(c<=1)
	{
		if(tmp1==headnode)
		 {
		   printf("%d ",(tmp1->next)->data);
		   tmp1=tmp1->next;
		   c++; 
		 }
		else
		 {
		   printf("%d ",tmp1->data);
		 }  

	   tmp1=tmp1->next;
    }
    printf("\nThe no. of nodes are : %d",headnode->data);
}

void insertNodeAtBeginning(struct node* headnode)
{
	struct node* tmp=NULL;

	tmp=(struct node*)malloc(sizeof(struct node));
	tmp->next=NULL;
	printf("\nEnter the data for the node to be inserted in the beginning : ");
	scanf("%d",&tmp->data);

	tmp->next=headnode->next;
	headnode->next=tmp;

	head=headnode;
}

void insertNodeInMiddle(struct node* headnode)
{
	int m;
	struct node *tmp=NULL,*tmp1=headnode->next;

	tmp=(struct node*)malloc(sizeof(struct node));
	tmp->next=NULL;
	printf("\nEnter the position no. for the node to be inserted in the middle : ");
	scanf("%d",&m);
	printf("Enter the data for the node to be inserted in the middle : ");
	scanf("%d",&tmp->data);

    int i;
    for(i=1;i<=(m-1)-1;++i)
    	tmp1=tmp1->next;

    tmp->next=tmp1->next;
    tmp1->next=tmp;
}

void deleteNodeFromBeginning(struct node* headnode)
{
	printf("\nNow the node from the beginning is deleted.");

	struct node *tmp1=headnode->next;
	headnode->next=tmp1->next;
	free(tmp1);
	
	head=headnode;
}

void deleteNodeFromMiddle(struct node* headnode)
{
	int m;
	printf("\nEnter the position no. of the node to be deleted : ");
	scanf("%d",&m);

	struct node *tmp1=headnode->next,*tmp2=NULL;

	int i;
	for(i=1;i<=(m-1)-1;++i)
		tmp1=tmp1->next;
	tmp2=tmp1->next;

	tmp1->next=(tmp1->next)->next;
	free(tmp2);
}
