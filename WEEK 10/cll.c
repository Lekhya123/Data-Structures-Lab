#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*link;
};
struct node*head=NULL,*cur, *temp,*t1,*t2;
void create()
{
	cur=(struct node*)malloc(sizeof(struct node));
	printf("ENTER CURRENT DATA\n");
	scanf("%d",&cur->data);
	cur->link=cur;
	if(head==NULL)
		head=cur;
	else
	{
		temp=head;
		while(temp->link!=head)
			temp=temp->link;
		temp->link=cur;
		cur->link=head;
	}
}

void insertatbegin()
{
	cur=(struct node*)malloc(sizeof(struct node));
	printf("ENTER CURRENT DATA\n");
	scanf("%d",&cur->data);
	temp=head;
	while(temp->link!=head)
		temp=temp->link;
	temp->link=cur;
	cur->link=head;
	head=cur; //not required for insert at end 
}
void insertatpos()
{
	int c=1,pos;
	printf("ENTER POSITION OF INSERTION\n");
	scanf("%d",&pos);
	cur=(struct node*)malloc(sizeof(struct node));
	printf("ENTER CURRENT DATA\n");
	scanf("%d",&cur->data);
	t1=head;
	while(c<pos)
	{
		t2=t1;
		t1=t1->link;
		c++;
	}
	t2->link=cur;
	cur->link=t1;
}
void deleteatbegin()
{
	cur=temp=head;
	while(temp->link!=head)
		temp=temp->link;
	temp->link=cur->link;
	head=cur->link;
	cur->link=NULL;
	printf("deleted element %d",cur->data);
	free(cur);
}
void deleteatend()
{
	t1=head;
	while(t1->link!=head)
	{
		t2=t1;
		t1=t1->link;
	}
		t2->link=head;
		t1->link=NULL;
		printf("DELETED ELEMENT %d\n",t1->data);
		free(t1);
}
void deleteatpos()
{
	int c=1,pos;
	printf("ENTER POSITION OF DELETION\n");
	scanf("%d",&pos);
	t1=head;
	while(c<pos)
	{
		t2=t1;
		t1=t1->link;
		c++;
	}
	t2->link=t1->link;
	t1->link=NULL;
	printf("DELETED ELEMENT %d\n",t1->data);
	free(t1);
}
void display()
{
	if(head==NULL)
	printf("CLL is empty");
	else
	{
		temp=head;
		while(temp->link!=head)
		{
			printf("%d->",temp->data);
			temp=temp->link;
		}
			printf("%d",temp->data);
	}
}	
int main()
{
	int ch;
	while(1)
	{
	printf("1-Create\n2-Insert at begin\n3-Insert at position\n4-Delete at begin\n5-Delete at end\n6-Delete at position\n7-Traversal\n8-exit\n");
	printf("ENTER YOUR CHOICE\n");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1: create();
		break;
	case 2: insertatbegin();
		break;
	case 3: insertatpos();
		break;
	case 4: deleteatbegin();
		break;
	case 5: deleteatend();
		break;
	case 6: deleteatpos();
		break;
	case 7:display();
		break;
	case 8: exit(0);
	}
	}
}




























