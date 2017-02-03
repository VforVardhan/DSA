#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *prev,*next;
}* head=NULL;

void createNode(struct node* headnode,int i,int n);   //can't use head as local variable coz readjustment of head is done
void printNode(struct node* headnode);

void insertNodeAtBeginning(struct node* headnode);    //can't use head as local variable coz readjustment of head is done
void insertNodeInMiddle(struct node* headnode);

void deleteNodeFromBeginning(struct node* headnode);  //can't use head as local variable coz readjustment of head is done
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

    printf("Your circular circular doubly linked list is:\n");
	printNode(head);

    insertNodeAtBeginning(head);
    printf("Your new circular doubly linked list is:\n");
	printNode(head);

	insertNodeInMiddle(head);
    printf("Your new circular doubly linked list is:\n");
	printNode(head);

	deleteNodeFromBeginning(head);
    printNode(head);

    deleteNodeFromMiddle(head);
    printNode(head);

    bubbleSort(head,n);
    printNode(head);

    return 0;
}

void createNode(struct node* headnode,int i,int n)
{
	struct node *tmp=NULL,*tmp1=headnode;

	tmp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data for the node : ");
	scanf("%d",&tmp->data);
	tmp->prev=NULL;
	tmp->next=NULL;

	if(headnode==NULL)
		headnode=tmp;
	else
	{
		while(tmp1->next!=NULL)
			tmp1=tmp1->next;
		tmp1->next=tmp;
		tmp->prev=tmp1;

		if(i==n)
		{
		   tmp->next=headnode;
		   headnode->prev=tmp;
		}
    }

    head=headnode;
}

void printNode(struct node* headnode)
{
	struct node *tmp1=headnode;

	int c=0;
	while(c<2)
	{
		if(headnode==tmp1)
			++c;
		printf("%d ",tmp1->data);   // 1 2 3 4 5 1
		tmp1=tmp1->next;
    }
    printf(" <==> ");               // Now tmp1 is at 1

    tmp1=tmp1->prev;                // Bringing it to 5

    c=0;
    while(c<2)
    {
    	if(headnode==tmp1)
    		++c;
		printf("%d ",tmp1->data);   // 5 4 3 2 1 5
		tmp1=tmp1->prev;
    }
}

void insertNodeAtBeginning(struct node* headnode)
{
	struct node *tmp=NULL;
    tmp=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data for the node to be inserted in beginning : ");
	scanf("%d",&tmp->data);
	tmp->prev=NULL;
	tmp->next=NULL;

	tmp->next=headnode;
	tmp->prev=headnode->prev;

    (headnode->prev)->next=tmp;
	headnode->prev=tmp;         //the order of these two statements is crucial.Observe that if second would've benn written first then the first becomes tmp->next=tmp; !!

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
	printf("Enter the data for the node to be inserted in middle : ");
	scanf("%d",&tmp->data);
	tmp->prev=NULL;
	tmp->next=NULL;

	int i;
	for(i=1;i<=(m-1)-1;++i)
		tmp1=tmp1->next;

	tmp->prev=tmp1;
	tmp->next=tmp1->next;

	(tmp1->next)->prev=tmp;
	tmp1->next=tmp;
}

void deleteNodeFromBeginning(struct node* headnode)
{
	printf("\nNow the node from beginning is deleted.\n");
	(headnode->prev)->next=headnode->next;
	(headnode->next)->prev=headnode->prev;

	head=headnode->next;

	free(headnode);
}

void deleteNodeFromMiddle(struct node* headnode)
{
	struct node *tmp1=headnode;

	int m;
	printf("\nEnter the position no. from which you want to delete the node : ");
	scanf("%d",&m);

    int i;
    for(i=1;i<=m-1;++i)
    	tmp1=tmp1->next;
    
    (tmp1->next)->prev=tmp1->prev;
    (tmp1->prev)->next=tmp1->next;

    free(tmp1);
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

