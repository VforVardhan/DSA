#include <stdio.h>
#include <stdlib.h>

struct node
{
	int ID;
	struct node *takenFrom;
};

int main()
{
	int startID,passes,testcases;
	struct node *tmp=NULL,*tmp1=NULL,*player=NULL;
	int i,k;
	char ch;

	printf("Enter the no. of test cases : ");
    scanf("%d",&testcases);

    for(k=1;k<=testcases;++k)
	{
    printf("Enter the no. of passes and starting player ID : ");
	scanf("%d%d",&passes,&startID);
	
	int array[passes];

	tmp=(struct node*)malloc(sizeof(struct node));
	tmp->ID=startID;
	tmp->takenFrom=NULL;
	player=tmp;

	printf("Enter the passing scheme :\n");
	
	for(i=0;i<passes;++i)
	{
		scanf(" %c",&ch);  //Note this
		if(ch=='P')
			scanf("%d",&array[i]);
		if(ch=='B')
			array[i]=0;
	}
	
	for(i=0;i<passes;++i)
	{
	  if(array[i]!=0)
		{
			tmp1=(struct node*)malloc(sizeof(struct node));
	        tmp1->ID=array[i];
	        tmp1->takenFrom=player;
	        player=tmp1;
		}
	  else
		{
			tmp1=player;
			player=tmp1->takenFrom;
			player->takenFrom=tmp1;
		}
	}

	printf("Player %d\n",player->ID);

    }

	return 0;

}