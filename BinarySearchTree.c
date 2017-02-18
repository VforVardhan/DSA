#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node
{
	int data;
	struct node *left,*right;
} *root=NULL;

void createNode(int height,struct node *rootnode,int n,int val);
void inOrder(struct node *tmp);
void RrL_traversal(struct node *tmp);
int search(struct node *tmp,int item);
void insert(struct node *tmp,struct node *tmp1);
void delete(struct node *tmp,int item);
struct node* searchToDelete(struct node *tmp,int item);
struct node* findParentOf(struct node *tmp,struct node *tmp1);
struct node* getInorderSuccessor(struct node *tmp);
int findHeight(struct node *tmp);


int height=0,Lheight=0,Rheight=0;
    



int main()
{
	printf("We'll create a binary search tree here.\n");
	printf("Imagine a BST in your mind and the position no. of the nodes which you want in your BST.\n\n");
	int height,n,noOfNodes=0;
	int val;

	printf("Now enter the height of your BST : ");
	scanf("%d",&height);

	int x=pow(2,height)-1;  //Eg. if height is 4 we will create an array named Nodes of 15 integers which have to hold node nos. entered by us.
	int Nodes[x];

	printf("Enter the node no. to create (enter -1 to escape) : ");
	scanf("%d",&n);
	Nodes[0]=n;


	while(n!=-1)
	{
		++noOfNodes;  //here noOfNodes acts as an index of the array Nodes which will increment as we enter more node nos.
		printf("Enter the data of this node : ");
        scanf("%d",&val);
		createNode(height,root,n,val);

		printf("Enter the node no. to create (enter -1 to escape) : ");
		scanf("%d",&n);
		Nodes[noOfNodes]=n;
    }

    printf("\nThe BST inorder traversal is :\n");
    inOrder(root);
    printf("\nThe BST RrL traversal is :\n");
    RrL_traversal(root);


    int item;
    printf("\nEnter an item to search : \n");
    scanf("%d",&item);
    int pos = search(root,item);
    if(pos==-1)
    	printf("%d was NOT found !!",item);
    else
    	printf("%d was found !!",item);



    printf("\nEnter an item to insert : \n");
    scanf("%d",&item);
    struct node *tmp1=(struct node *)malloc(sizeof(struct node));
	tmp1->data=item;
	tmp1->left=NULL;
	tmp1->right=NULL;
    insert(root,tmp1);
    printf("\nThe BST inorder traversal after insertion is :\n");
    inOrder(root);



    /*printf("\nEnter a node to delete :");
    scanf("%d",&item);
    delete(root,item);
    printf("\nThe BST inorder traversal after insertion is :\n");
    inOrder(root);*/


    height=findHeight(root)+2;
    printf("The height is : %d",height);


}

void createNode(int height,struct node *rootnode,int n,int val)
{
	struct node *tmp=(struct node *)malloc(sizeof(struct node));
	tmp->data=val;
	tmp->left=NULL;
	tmp->right=NULL;

	struct node *tmp1=rootnode;
	if(n==0)   //i.e. if we have just the root node at present
	{
		rootnode=tmp;
		root=rootnode;  //both of these can be combined as root=tmp;
	}
	else
	{
	 int guide[height-1],t,i=height-2;  //THE guide ARRAY IS THE CORE CONCEPT OF TRAVERSAL USED HERE.It's size is height-1 i.e. maximum
	                                    //It will record paths to take from the root to reach the parent of the created node
	                                    //It is filled backwards to forwards


	  if(n%2!=0)
	   {
		t=(n-1)/2;   //left child
		guide[i]=-1;
	   }
	  else
	   {
		t=(n-2)/2;   //right child
		guide[i]=1;
	   }

	  while(t!=0)
	   {
		--i;

		if(t%2!=0)
		{
		  t=(t-1)/2;
		  guide[i]=-1;
		}
		else
	    {
		  t=(t-2)/2;
		  guide[i]=1;
	    }
	   }                     //You must understand the way i is being used as it goes from this while to the next while

	  while(i<height-2)
	   {
		if(guide[i]==-1)
		   tmp1=tmp1->left;
		else
		   tmp1=tmp1->right;

		++i;
	   }

	  if(guide[i]==-1)
		tmp1->left=tmp;
	  else
		tmp1->right=tmp;
    }
}

void inOrder(struct node *tmp)  //LrR
{
	if(tmp->left!=NULL)
    inOrder(tmp->left);

	printf("%d ",tmp->data);
	
    if(tmp->right!=NULL)
	inOrder(tmp->right);
}

void RrL_traversal(struct node *tmp)
{
	if(tmp->right!=NULL)
	RrL_traversal(tmp->right);

	printf("%d ",tmp->data);

	if(tmp->left!=NULL)
	RrL_traversal(tmp->left);
}

int search(struct node *tmp,int item)
{
	if(tmp==NULL)
    return -1;

    else if(item < tmp->data)
    		search(tmp->left,item);

    else if(item > tmp->data)
    		search(tmp->right,item);

    else
        return 1;  //when item was found
}

void insert(struct node *tmp,struct node *tmp1)
{
	if(tmp->left==NULL && tmp1->data < tmp->data)      //We've reached an external node whose leftchild is null and item to insert is less than its data
		tmp->left=tmp1;  //new node is inserted as the left child
	else if(tmp->right==NULL && tmp1->data > tmp->data)//We've reached an external node whose rightchild is null and item to insert is more than its data
		tmp->right=tmp1; //new node is inserted as the right child

	else if(tmp1->data < tmp->data)
		insert(tmp->left,tmp1);
                                      //these two conditions are just used to reach the appropriate external node to append to
	else
		insert(tmp->right,tmp1);
}

struct node* searchToDelete(struct node *tmp,int item) //this function returns the pointer to the search element
{
	if(item < tmp->data)
    		searchToDelete(tmp->left,item);

    else if(item > tmp->data)
    		searchToDelete(tmp->right,item);

    else
        return tmp;  //when item was found
}

struct node* findParentOf(struct node *tmp,struct node *tmp1)
{ 
	while(tmp->left!=tmp1 && tmp->right!=tmp1)
	{
	    if(tmp1->data < tmp->data)
    		tmp=findParentOf(tmp->left,tmp1);

        else
    		tmp=findParentOf(tmp->right,tmp1);
    }
    return tmp;
}

struct node* getInorderSuccessor(struct node *tmp)
{
	tmp=tmp->right;
	while(tmp->left!=NULL)
		tmp=tmp->left;

	return tmp;
}

void delete(struct node *tmp,int item)
{
	struct node *tmp1=searchToDelete(tmp,item); //here tmp is root and tmp1 is the pointer to the node to be deleted
	struct node *parent=NULL;
	

	if(tmp1->left==NULL && tmp1->right==NULL) //if tmp1 is the node with no children
	{
	  parent=findParentOf(root,tmp1);
	  (parent->left == tmp1) ? (parent->left=NULL) : (parent->right=NULL); 
	  printf("%d is a node with no children and its parent is %d\n",tmp1->data,parent->data);
		
	  printf("\nThe BST inorder traversal after deletion is :\n");
      inOrder(root);
    }



    else if(tmp1->left==NULL || tmp1->right==NULL) //if tmp1 is the node with one child
    {
       struct node *child=NULL;
       parent=findParentOf(root,tmp1);
       (tmp1->left==NULL) ? (child=tmp1->right) : (child=tmp1->left);

       printf("%d is a node with one child , its parent is %d and its child is %d\n",tmp1->data,parent->data,child->data);

       (parent->left == tmp1) ? (parent->left=child) : (parent->right=child);

       printf("\nThe BST inorder traversal after deletion is :\n");
       inOrder(root);
    }



    else  //if tmp1 is the node with  two children
    {
    	struct node *inorderSuccessor = getInorderSuccessor(tmp1);
    	printf("%d is a node with two children , its inorder successor is %d\n",tmp1->data,inorderSuccessor->data);

    	tmp1->data=inorderSuccessor->data;

    	//Now we have to delete the inorderSuccessor.Observe that it can have either no child or one child

    	if(inorderSuccessor->left==NULL && inorderSuccessor->right==NULL) //if inorderSuccessor is the node with no children
	    {
	       parent=findParentOf(root,inorderSuccessor);
	       (parent->left->data == tmp1->data) ? (parent->left=NULL) : (parent->right=NULL); 
	    }
		
	    else  //if inorderSuccessor is the node with one child
        {
           struct node *child=NULL;
           parent=findParentOf(root,inorderSuccessor);
           (inorderSuccessor->left==NULL) ? (child=inorderSuccessor->right) : (child=inorderSuccessor->left);

           (parent->left == inorderSuccessor) ? (parent->left=child) : (parent->right=child);
        }


    	printf("\nThe BST inorder traversal after deletion is :\n");
        inOrder(root);
    }
}

int findHeight(struct node *tmp)
{
	if(tmp==NULL)
	{
		if(Lheight>=Rheight)
	      return Lheight;
        else
	return Rheight;

	}
		
	if(tmp->left!=NULL)
		Lheight=findHeight(tmp->left) + 1;

	if(tmp->right!=NULL)
		Rheight=findHeight(tmp->right) + 1;

}

//(Lheight >= Rheight) ? return Lheight : return Rheight;

