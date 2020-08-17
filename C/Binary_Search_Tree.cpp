#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{ 
	int data; 
	node* left;         //"*"代表node的pointer// 
	node* right; 
	node* mommy;
};

node* array[77];

void insert();
void recursive();
node* head1;
int ID=1;

void delete();
int d;
node* find_the_biggest_in_left();

void left_child();
void right_child();
void is_leaf();
void postorder();
void postrecursive();
void preorder();
void prerecursive();

int main()
{
	
}
void insert()
{
	printf("Insert a number:");
	scanf("%d", &array[ID]->data);
	
	for(;array[ID]->data==NULL;ID++)
	{
		head1=array[ID];
	}
	
	if (ID>=2)
	{
		recursive();	
	}
	printf("Success!");
	
	ID++;
}

void recursive()
{
	if(array[ID]->data>=head1->data)
	{
		if(head1->right!=NULL)
		{
			head1=head1->right;
			recursive();
		}
		else
		{
			head1->right=array[ID];
			array[ID]->mommy=head1;
		}	
	}
	else
	{
		if(head1->left!=NULL)
		{
			head1=head1->left;
			recursive();
		}
		else
		{
			head1->left=array[ID]->data;
			array[ID]->mommy=head1;
		}	
	}
	head1=array[1];	
}

void delete()
{
	printf("Which number do U want to delete?");
	scanf("%d", &d);
	for(int i=1;array[i]->data==d||i>ID;i++)
	{
		;
	}
	if(i>ID)
	{
		printf("No this number.QQ");
	}
	else if(array[i]->left==NULL||array[i]->right==NULL)
	{
		if(array[i]->mommy->left->data==array[i])
		{
			array[i]->mommy->left==NULL;
		}
		if(array[i]->mommy->right->data==array[i])
		{
			array[i]->mommy->right==NULL;
		}
	}
	else if(array[i]->left==NULL&&array[i]->right!=NULL)
	{
		array[i]->mommy->right=array[i]->right;
		array[i]->right->mommy=array[i]->mommy;
	}
	else if(array[i]->left!=NULL)
	{
		node* a;
		a=find_the_biggest_in_left(array[i]->left);
		a->mommy->right==NULL;
		array[i]->data=a->data;
	}
}



node* find_the_biggest_in_left(node* head3)
{
	if(head3->right!=NULL)
	{
		find_the_biggest_in_left(head3->right);
	}
	else
	{
		return head3;
	}
}

void left_child()                   //隨便給一個數字，告訴他左邊的小孩是誰// 
{
	int x;
	printf("Give me a number and I'll tell U its left child.");
	scanf("%d", &x);
	
	for(int i=1;array[i]->data==x||i>ID;i++)
	{
		;
	}
	
	if(i>ID)
	{
		printf("No this number.");
	}
	else if(array[i]->left==NULL)
	{
		printf("It has no right child");
	}
	else
	{
		printf("%d", array[i]->left->data);
	}
}

void right_child()                   //隨便給一個數字，告訴他右邊的小孩是誰// 
{
	int x;
	printf("Give me a number and I'll tell U its right child.");
	scanf("%d", &x);
	
	for(int i=1;array[i]->data==x||i>ID;i++)
	{
		;
	}
	
	if(i>ID)
	{
		printf("No this number.");
	}
	else if(array[i]->right==NULL)
	{
		printf("It has no right child");
	}
	else
	{
		printf("%d", array[i]->right->data);
	}
}

void is_leaf()                       //隨便給一個數字，判斷是否為最後一個數// 
{
	int x;
	printf("Give me a number and I'll tell U whether it is a leaf.");
	scanf("%d", &x);
	
	head2
	for(int i=1;array[i]->data==x||i>ID;i++)
	{
		;
	}
	
	if(i>ID)
	{
		printf("No this number.");
	}
	else if(array[i]->right==NULL&&array[i]->left==NULL)
	{
		printf("I'm a leaf.");
	}
	else
	{
		printf("I'm still part of the tree.");
	}
}

void postorder()
{
	postrecursive(array[1]);
}

void postrecursive(node* head2)
{
	if(head2->left==NULL)
	{
		if(head2->right==NULL)
		{
			printf("%d", head2->data);	
		}
		else
		{
			postrecursive(head2->right);
			printf("%d", head2->data);
		}
	}
	else
	{
		if(head2->right==NULL)
		{
			postrecursive(head2->left);
			printf("%d", head2->data);
		}
		else
		{
			postrecursive(head2->left);
			postrecursive(head2->right);
			printf("%d", head2->data);
		}	
	}
}

void preorder()
{
	prerecursive(array[1]);
}

void prerecursive(node* head2)
{
	if(head2->left==NULL)
	{
		if(head2->right==NULL)
		{
			printf("%d", head2->data);	
		}
		else
		{
			printf("%d", head2->data);
			postrecursive(head2->right);
		}
	}
	else
	{
		if(head2->right==NULL)
		{
			printf("%d", head2->data);
			postrecursive(head2->left);	
		}
		else
		{
			printf("%d", head2->data);
			postrecursive(head2->left);
			postrecursive(head2->right);
		}	
	}
}
