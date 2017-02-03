#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *prev,*next;
}* head=NULL;

void createNode(struct node* headnode);               //can't use head as local variable coz readjustment of head is done
void printNode(struct node* headnode);

void insertNodeAtBeginning(struct node* headnode);    //can't use head as local variable coz readjustment of head is done
void insertNodeAtEnd(struct node* headnode);
void insertNodeInMiddle(struct node* headnode);

void deleteNodeFromBeginning(struct node* headnode);  //can't use head as local variable coz readjustment of head is done
void deleteNodeFromEnd(struct node* headnode);
void deleteNodeFromMiddle(struct node* headnode);
void bubbleSort(struct node* headnode,int n);

int main()
{
	int n;
	printf("Enter the no. of nodes : ");
	scanf("%d",&n);

	int i;
	for(i=1;i<=n;i++)
	createNode(head);

	printf("Your doubly linked list is:\n");
	printNode(head);

    insertNodeAtBeginning(head);
	printf("Your new doubly linked list is:\n");
    printNode(head);

    insertNodeAtEnd(head);
	printf("Your new doubly linked list is:\n");
    printNode(head);

    insertNodeInMiddle(head);
    printf("Your new doubly linked list is:\n");
    printNode(head);

    deleteNodeFromBeginning(head);
    printf("Your new doubly linked list is:\n");
    printNode(head);

    deleteNodeFromEnd(head);
    printf("Your new doubly linked list is:\n");
    printNode(head);

    deleteNodeFromMiddle(head);
    printf("Your new doubly linked list is:\n");
    printNode(head);

    bubbleSort(head,n);
    printf("\nYour sorted doubly linked list is:\n");
    printNode(head);

	return 0;
}

void createNode(struct node* headnode)
{
	struct node *tmp=NULL,*tmp1=headnode;

	tmp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data for node : ");
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
	}

	head=headnode;
}

void printNode(struct node* headnode)
{
	struct node* tmp1=headnode;

	while(tmp1!=NULL)
	{
		if(tmp1->next==NULL)
		{
		  printf("%d ",tmp1->data);
		  break;
		}
		printf("%d ",tmp1->data);
		tmp1=tmp1->next;
	}
	printf(" <==> ");

    while(tmp1!=NULL)
    {
    	printf("%d ",tmp1->data);
    	tmp1=tmp1->prev;
    }
}

void insertNodeAtBeginning(struct node* headnode)
{
	struct node *tmp=NULL;

	tmp=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data for node to be inserted at beginning : ");
	scanf("%d",&tmp->data);
	tmp->next=NULL;
	tmp->prev=NULL;

	tmp->next=headnode;
	headnode->prev=tmp;
	headnode=tmp;

	head=headnode;
}

void insertNodeAtEnd(struct node* headnode)
{
	struct node *tmp=NULL,*tmp1=headnode;

	tmp=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data for node to be inserted at end : ");
	scanf("%d",&tmp->data);
	tmp->next=NULL;
	tmp->prev=NULL;

	while(tmp1->next!=NULL)
		tmp1=tmp1->next;

	tmp1->next=tmp;
	tmp->prev=tmp1;
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
	tmp->prev=NULL;

	int i;
	for(i=1;i<=(m-1)-1;++i)
		tmp1=tmp1->next;

	tmp->next=tmp1->next;
	tmp->prev=tmp1;

	(tmp1->next)->prev=tmp;
	tmp1->next=tmp;           //the order of these two statements is crucial.Observe that if second would've benn written first then the first becomes tmp->next=tmp; !!
}

void deleteNodeFromBeginning(struct node* headnode)
{
    printf("\nNow the node from beginning is deleted.");

    head=headnode->next;
    (headnode->next)->prev=NULL;
    free(headnode);
}

void deleteNodeFromEnd(struct node* headnode)
{
	printf("\nNow the node from end is deleted.");
	struct node* tmp1=headnode;
	while(tmp1->next!=NULL)
        tmp1=tmp1->next;

    (tmp1->prev)->next=NULL;
    free(tmp1);
}

void deleteNodeFromMiddle(struct node* headnode)
{
	int m;
	printf("\nEnter the position no. of the node which you want to delete : ");
	scanf("%d",&m);

	struct node *tmp1=headnode;

    int i;
    for(i=1;i<=m-1;++i)
    	tmp1=tmp1->next;
    
    (tmp1->prev)->next = tmp1->next;
    (tmp1->next)->prev = tmp1->prev;

    free(tmp1);
}

void bubbleSort(struct node* headnode,int n)
{
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



