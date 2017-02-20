#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node
{
  char data;
  struct node *left,*right;
} *root=NULL;

void createNode(int h,struct node *rootnode,int n,char val);
void printTree(int Nodes[],int noOfNodes,struct node *rootnode,int height);
void preOrder(struct node *tmp);
void inOrder(struct node *tmp);
void postOrder(struct node *tmp);
int heightOfTree(struct node *tmp);



int main()
{
	printf("We'll create and print a binary tree here.\n");
	printf("Imagine a binary tree in your mind and the position no. of the nodeswhich you want in your tree.\n\n");
	int height,n,noOfNodes=0;
	char val;

	printf("Now enter the height of your binary tree : ");
	scanf("%d",&height);

	int x=pow(2,height)-1;  //Eg. if height is 4 we will create an array named Nodes of 15 integers which have to hold node nos. entered by us.
	int Nodes[x];

	printf("Enter the node no. to create (enter -1 to escape) : ");
	scanf("%d",&n);
	Nodes[0]=n;


	while(n!=-1)
	{
		++noOfNodes;  //here noOfNodes acts as an index of the array Nodes which will increment as we enter more node nos.
		printf("Enter the data character of this node : ");
        scanf(" %c",&val);
		createNode(height,root,n,val);

		printf("Enter the node no. to create (enter -1 to escape) : ");
		scanf("%d",&n);
		Nodes[noOfNodes]=n;
    }
    printf("THE BINARY TREE IS : \n\n");
	printTree(Nodes,noOfNodes,root,height);
	
	printf("\nThe PREORDER traversal is  : ");
	preOrder(root);

	printf("\nThe INORDER traversal is   : ");
	inOrder(root);

	printf("\nThe POSTORDER traversal is : ");
	postOrder(root);

	printf("\nThe height of the tree is : ");
	printf("%d",heightOfTree(root));

	return 0;
}

void createNode(int height,struct node *rootnode,int n,char val)
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

void printTree(int Nodes[],int noOfNodes,struct node *rootnode,int height)  //noOfNodes is the total no. of nodes existing in your tree
{
  struct node *tmp1=NULL;

  int sb=pow(2,height-1)-1,sa=2*sb+1;  //sb is for the starting spaces and sa is for the spaces after each character in any line

  int i;
  for( i=0 ; i<=pow(2,height-1)-1 ; i=(i*2)+1)  //i goes as 0,1,3,7,15,etc.
  {
    int s;
  	for(s=1;s<=sb;++s)
  	    printf(" ");    //printing the starting spaces

    int j;
    for( j=i; j<=2*i ;++j)  //j goes as 0 and 1,2 and 3,4,5,6 and 7,8,9,10,11,12,13,14 etc.
    {
      tmp1=rootnode;

      int k,flag=0;
      for(k=0;k<noOfNodes;++k)
      {
        if(j==Nodes[k])
    	{
    		flag=1;
    		break;
    	}
      }                  //searching for an existing node

      if(flag==0)
    	 printf(" ");    //printing blank space in place of a 'vacant' node
      else
    	 {
    		int guide[height-1],z,l=height-2;
    		if(Nodes[k]%2!=0)
	         {
		       z=(Nodes[k]-1)/2;
		       guide[l]=-1;
	         }

	        else
	         {
		        z=(Nodes[k]-2)/2;
		        guide[l]=1;
	         }

	        while(z!=0 && Nodes[k]>0)
	         {
		       --l;

		       if(z%2!=0)
		         {
		            z=(z-1)/2;
		            guide[l]=-1;
		         }
		       else
	             {
		            z=(z-2)/2;
		            guide[l]=1;
	             }
	          }

	        while(l<=height-2 && Nodes[k]>0)
	          {
		         if(guide[l]==-1)
		           tmp1=tmp1->left;
		          else
		           tmp1=tmp1->right;
		         ++l;
	          }

	        printf("%c",tmp1->data);
	        
          }

         for(s=1;s<=sa;++s)
  		 printf(" ");        //printing the spaces after a character in a line
	}
    printf("\n");

    sb/=2;
  	sa=2*sb+1;
  }
}

void preOrder(struct node *tmp)  //rLR
{
	printf("%c ",tmp->data);

	if(tmp->left!=NULL)
	preOrder(tmp->left);

    if(tmp->right!=NULL)
	preOrder(tmp->right);
}

void inOrder(struct node *tmp)  //LrR
{
	if(tmp->left!=NULL)
	inOrder(tmp->left);

	printf("%c ",tmp->data);
	
    if(tmp->right!=NULL)
	inOrder(tmp->right);
}

void postOrder(struct node *tmp)  //LRr
{
	if(tmp->left!=NULL)
	postOrder(tmp->left);

    if(tmp->right!=NULL)
	postOrder(tmp->right);

    printf("%c ",tmp->data);
}

int heightOfTree(struct node *tmp)
{
	int lheight,rheight;
	if(tmp==NULL)
		return 0;
	else
	{
		lheight=heightOfTree(tmp->left);
		rheight=heightOfTree(tmp->right);
	if(lheight>rheight)
		return lheight+1;
	else
		return rheight+1;
    }
}









