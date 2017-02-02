#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
}* head=NULL;

void createNode(struct node* headnode,int i,int n);               
void printNode(struct node* headnode);

void insertNodeAtBeginning(struct node* headnode,int n);    
void insertNodeInMiddle(struct node* headnode);

void deleteNodeFromBeginning(struct node* headnode,int n);
void deleteNodeFromMiddle(struct node* headnode);

void bubbleSort(struct node* headnode,int n);

int main()
{
	int n;
	printf("Enter the no. of nodes : ");
	scanf("%d",&n);

	int i;
	for(i=1;i<=n;++i)
		createNode(head,i,n);

	printf("Your circular linked list is:\n");
	printNode(head);

    insertNodeAtBeginning(head,n);
	printf("Your new circular linked list is:\n");
	printNode(head);


    insertNodeInMiddle(head);
    printf("Your new circular linked list is:\n");
    printNode(head);


    deleteNodeFromBeginning(head,n+2);
    printf("Your new circular linked list is:\n");
    printNode(head);


    deleteNodeFromMiddle(head);
    printf("Your new circular linked list is:\n");
    printNode(head);

    bubbleSort(head,n);
    printNode(head);

	return 0;
}

void createNode(struct node* headnode,int i,int n)
{
	struct node *tmp=NULL,*tmp1=headnode;

    tmp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data for node : ");
	scanf("%d",&tmp->data);
	tmp->next=NULL;

	if(headnode==NULL)
		headnode=tmp;
	else
	{
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
   struct node* tmp1=headnode;
   int c=0;
   while(c<2)
   {
   	if(headnode==tmp1)
   		++c;
   	printf("%d ",tmp1->data);
   	tmp1=tmp1->next;
   }
}

void insertNodeAtBeginning(struct node* headnode,int n)
{
	struct node *tmp=NULL,*tmp1=headnode;

	tmp=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data for node to be inserted at beginning : ");
	scanf("%d",&tmp->data);
	tmp->next=NULL;

    int i;
	for(i=1;i<=n-1;++i)
	  tmp1=tmp1->next;

	tmp->next=headnode;
	tmp1->next=tmp;
	headnode=tmp;

	head=headnode;
}

void insertNodeInMiddle(struct node* headnode)
{
	struct node *tmp=NULL,*tmp1=headnode;
	int m;
	printf("\nEnter the position no. at which you want to insert the new node : ");
	scanf("%d",&m);

	tmp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data for node to be inserted in middle : ");
	scanf("%d",&tmp->data);
	tmp->next=NULL;

	int i;
	for(i=1;i<=(m-1)-1;++i)
		tmp1=tmp1->next;

	tmp->next=tmp1->next;
	tmp1->next=tmp;
}

void deleteNodeFromBeginning(struct node* headnode,int n)
{
	printf("\nThe node from beginning is deleted now.\n");
	struct node* tmp1=headnode;
	int i;
    for(i=1;i<=n-1;++i)
    	tmp1=tmp1->next;

    tmp1->next=headnode->next;
    head=headnode->next;
    
    free(headnode);
}

void deleteNodeFromMiddle(struct node* headnode)
{
	struct node *tmp1=headnode,*tmp2=NULL;
	int m;
	printf("\nEnter the position no. from which you want to delete the node : ");
	scanf("%d",&m);

    int i;
    for(i=1;i<=(m-1)-1;++i)
    	tmp1=tmp1->next;

    tmp2=tmp1->next;    //tmp2 is just used for freeing the memory

    tmp1->next=tmp2->next;  //tmp1->next=(tmp1->next)->next;
    free(tmp2);
}

void bubbleSort(struct node* headnode,int n)
{
	printf("\nThe sorted circular linked list is :\n");
	int i,j,k;
	for(i=n-1;i>=1;--i)
	{
		int swap=0,flag=0;
		for(j=1;j<=i;++j)
		{
			struct node *tmp1=headnode;
			for(k=1;k<=j-1;++k)
				tmp1=tmp1->next;

			if((tmp1->next)->data < tmp1->data)
    	     {
    		   swap=(tmp1->next)->data;
    		   (tmp1->next)->data=tmp1->data;
    		   tmp1->data=swap;
    		   flag=1;
    	     }
		}
		if(flag==0)
			break;
	}
}


