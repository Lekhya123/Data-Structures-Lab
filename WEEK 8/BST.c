#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct BST{
	int data;
	struct BST *left, *right;
};
struct BST *root = NULL , *temp, *cur;
void create()
{
	temp = root;
	cur = (struct BST*)malloc(sizeof(struct BST));
	printf("ENTER DATA\n");
	scanf("%d",&cur->data);
	cur->left = NULL;
	cur->right = NULL;
	if(temp == NULL)
		root = cur;
	else{
		while(temp != NULL){
			if((cur->data) < (temp->data))
			{
				if(temp->left == NULL)
				{
				temp->left = cur;
				return;
				}
				else
					temp = temp->left;
			}
			else{
				if(temp->right == NULL)
				{
				temp->right = cur;
				return;
				}
				else
					temp = temp->right;}
		}
	}
}
void postorder(struct BST*temp)
{
	if(temp != NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		printf("%d ",temp->data);
	}
}
void preorder(struct BST*temp)
{
	if(temp != NULL)
	{
		printf("%d ",temp->data);
		preorder(temp->left);
		preorder(temp->right);
	}
}
void inorder(struct BST*temp)
{
	if(temp != NULL)
	{
		inorder(temp->left);
		printf("%d ",temp->data);
		inorder(temp->right);
	}
}
int main()
{
	int ch;
	while(1)
	{
		printf("\nPROGRAM FOR BINARY SEARCH TREE\n");
		printf("------------------------------\n");
		printf("1. Create\n2. Preorder\n3. Postorder\n4. Inorder\n5. Exit\n");
		printf("------------------------------\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch){
			case 1: create();
				break;
			case 2: preorder(root);
				break;
			case 3: postorder(root);
				break;
			case 4: inorder(root);
				break;
			case 5: exit(0);
			default : printf("INVALID CHOICE\n");
		}
	}
}

	