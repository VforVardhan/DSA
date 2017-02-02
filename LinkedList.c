#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node* next;
}* head=NULL;

void createNode(struct node* headnode);               //can't use head as local variable coz readjustment of head is done
void printNode(struct node* headnode);

void insertNodeAtBeginning(struct node* headnode);    //can't use head as local variable coz readjustment of head is done
void insertNodeAtEnd(struct node* headnode);
void insertNodeInMiddle(struct node* headnode);

void deleteNodeFromBeginning(struct node* headnode);  //can't use head as local variable coz readjustment of head is done
void deleteNodeFromEnd(struct node* headnode);
void deleteNodeFromMiddle(struct node* headnode);

void sortnode(struct node *headnode,int n);

int main()
{
	int n;
	printf("Enter the no. of nodes : ");
	scanf("%d",&n);

	int i;
	for(i=1;i<=n;i++)
	createNode(head);

	printf("Your linked list is:\n");
	printNode(head);

    insertNodeAtBeginning(head);
	printf("Your new linked list is:\n");
    printNode(head);

    insertNodeAtEnd(head);
	printf("Your new linked list is:\n");
    printNode(head);

    insertNodeInMiddle(head);
    printf("Your new linked list is:\n");
    printNode(head);

    deleteNodeFromBeginning(head);
    printf("Your new linked list is:\n");
    printNode(head);

    deleteNodeFromEnd(head);
    printf("Your new linked list is:\n");
    printNode(head);

    deleteNodeFromMiddle(head);
    printf("Your new linked list is:\n");
    printNode(head);

    sortnode(head,n);
    printf("\nYour new sorted linked list is:\n");
    printNode(head);

	return 0;
}

void createNode(struct node* headnode)
{
	struct node *tmp=NULL,*tmp1=headnode;
    int value;
	printf("Enter the data for node : ");
	scanf("%d",&value);
	tmp=(struct node*)malloc(sizeof(struct node));
	tmp->data=value;
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

void printNode(struct node* headnode)
{
	struct node* tmp1=headnode;
	while(tmp1!=NULL)
		{
			printf("%d ",tmp1->data);
			tmp1=tmp1->next;
		}
}

void insertNodeAtBeginning(struct node* headnode)
{
	int value;
	struct node *tmp=NULL;
    printf("\nEnter the data for node to be inserted in beginning: ");
	scanf("%d",&value);
	tmp=(struct node*)malloc(sizeof(struct node));
	tmp->data=value;
	tmp->next=NULL;

	tmp->next=headnode;
	headnode=tmp;

	head=headnode;
}

void insertNodeAtEnd(struct node* headnode)
{
	int value;
	struct node *tmp=NULL,*tmp1=headnode;
    printf("\nEnter the data for node to be inserted at end: ");
	scanf("%d",&value);
	tmp=(struct node*)malloc(sizeof(struct node));
	tmp->data=value;
	tmp->next=NULL;

	while(tmp1->next!=NULL)
	    tmp1=tmp1->next;
	tmp1->next=tmp;
}

void insertNodeInMiddle(struct node* headnode)
{
	int value,m,i;
	struct node *tmp=NULL,*tmp1=headnode,*agla=NULL;
    printf("\nEnter the data for node to be inserted in middle: ");
	scanf("%d",&value);
	tmp=(struct node*)malloc(sizeof(struct node));
	tmp->data=value;
	tmp->next=NULL;
	printf("Enter the position m at which you want to insert the new node : ");
	scanf("%d",&m);

	for(i=1;i<=(m-1)-1;++i)
		tmp1=tmp1->next;

    agla=tmp1->next;
    tmp->next=agla;
    tmp1->next=tmp;
}

void deleteNodeFromBeginning(struct node* headnode)
{
    printf("\nNow the node from beginning is deleted.");
    head=headnode->next;

    free(headnode);
}

void deleteNodeFromEnd(struct node* headnode)
{
	printf("\nNow the node from end is deleted.");
	struct node* tmp1=headnode,*secondlast=NULL;
	while(tmp1->next!=NULL)
        {
          secondlast=tmp1;
          tmp1=tmp1->next;
        }
    secondlast->next=NULL;
    free(tmp1);
}

void deleteNodeFromMiddle(struct node* headnode)
{
	struct node *tmp1=headnode,*tmp2=NULL;
	int m,i;

    printf("\nNow the node from middle will be deleted.");
    printf("Enter the position m from which you want to delete the node : ");
    scanf("%d",&m);

    for(i=1;i<=(m-1)-1;++i)
		tmp1=tmp1->next;

    tmp2=tmp1->next;

	tmp1->next=tmp2->next;
	free(tmp2);
}

void sortnode(struct node* headnode,int n)
{
	int i,j,k;
    for(i=n-1;i>=1;i--)
    {
      int swap=0,flag=0;
      for(j=1;j<=i;++j)
    	{
    	 struct node* tmp1=headnode;

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


