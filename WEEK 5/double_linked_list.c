#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*prev;
	struct node*next;
};
struct node*head = NULL,*tail = NULL,*cur,*t1,*t2;
void create()
{
	cur = (struct node*)malloc(sizeof(struct node));
	int n;
	printf("ENTER THE NUMBER OF NODES\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
	cur = (struct node*)malloc(sizeof(struct node));
	printf("ENTER THE NODE DATA\n");
	scanf("%d",&(cur->data));
	cur->prev = NULL;
	cur->next = NULL;
	if(head == NULL)
		tail =head =cur;
	else{
		tail->next = cur;
		cur->prev = tail;
		tail = cur;}
	}
}
void insert_at_begin(){
	cur = (struct node*)malloc(sizeof(struct node));
	printf("ENTER THE NODE DATA TO BE INSERTED\n");
	scanf("%d",&(cur->data));
	cur->prev = NULL;
	cur->next = head;
	head->prev = cur;
	head = cur;
}

void insert_at_end(){
	cur = (struct node*)malloc(sizeof(struct node));
	printf("ENTER THE NODE DATA TO BE INSERTED\n");
	scanf("%d",&(cur->data));
	cur->next = NULL;
	cur->prev = tail;
	tail->next = cur;
	tail = cur;
}

void insert_at_position(){
	cur = (struct node*)malloc(sizeof(struct node));
	int pos;
	printf("ENTER THE POSITION TO INSERT\n");
	scanf("%d",&pos);
	printf("ENTER THE NODE DATA TO BE INSERTED\n");
	scanf("%d",&(cur->data));
	int c =1;
	t1 = head;
	while(c < pos && t1!=NULL){
		t2 = t1;
		t1 = t1->next;
		c++;}
	t2->next = cur;
	cur->prev = t2;
	cur->next = t1;
	t1->prev = cur;
}

void insert_before(){
	cur = (struct node*)malloc(sizeof(struct node));
	int val;
	printf("ENTER THE VALUE OF NODE\n"); 
	scanf("%d",&val);
	printf("ENTER THE NODE DATA TO BE INSERTED\n");
	scanf("%d",&(cur->data));
	t1 = head;
	while(t1->data != val && t1 != NULL){
		t2 = t1;
		t1 = t1 -> next;}
	t2->next = cur;
	cur->prev = t2;
	cur->next = t1;
	t1->prev = cur;
}

void insert_after(){
	cur = (struct node*)malloc(sizeof(struct node));
	int val;
	printf("ENTER THE VALUE OF NODE\n"); 
	scanf("%d",&val);
	printf("ENTER THE NODE DATA TO BE INSERTED\n");
	scanf("%d",&(cur->data));
	t1 = head;
	while(t1->data != val && t1 != NULL)
		t1 = t1 -> next;
	cur->next = t1->next;
	t1->next->prev = cur;
	t1->next = cur;
	cur->prev = t1;
}

void delete_at_begin(){
	cur = head;
	head = head->next;
	head->prev = NULL;
	printf("DELETED ELEMENT IS %d\n",cur->data);
	cur->next = NULL;
	free(cur);
}

void delete_at_end(){
	cur = tail;
	tail = cur->prev;
	tail->next = NULL;
	printf("DELETED ELEMENT IS %d\n",cur->data);
	cur->prev = NULL;
	free(cur);
}
void delete_at_position(){
	int pos;
	printf("ENTER THE POSITION OF NODE TO DELETE\n");
	scanf("%d",&pos);
	t1 = head;
	int c = 1;
	while(c<pos && t1!=NULL){
		t2 = t1;
		t1 = t1->next;
		c++;}		
	t2->next = t1->next;
	t1->next->prev = t2;
	printf("DELETED ELEMENT IS %d\n",t1->data);
	t1->next = t1->prev = NULL;
	free(t1);
}

void delete_before(){
	int val;
	printf("ENTER THE NODE DATA TO BE DELETED\n");
	scanf("%d",&val);
	t1 = head;
	while(t1->next->data != val && t1->next != NULL){
		t2 = t1;
		t1 = t1->next;}
	t2->next = t1->next;
	t1->next->prev = t2;
	printf("DELETED ELEMENT IS %d\n",t1->data);
	t1->next = t1->prev = NULL;
	free(t1);
}

void delete_after(){
	int val;
	printf("ENTER THE NODE DATA TO BE DELETED\n");
	scanf("%d",&val);
	t1 = head;
	while(t1->data != val && t1!= NULL)
		t1 = t1->next;
	t2 = t1->next;
	t1->next = t2->next;
	t2->next->prev = t1;
	printf("DELETED ELEMENT IS %d\n",t2->data);
	t2->next = t2->prev = NULL;
	free(t2);
}
void display_forward(){
	if(head == NULL)
	printf("DOUBLE LINKED LIST IS EMPTY\n");
	else{
		cur = head;
		printf("ELEMENTS OF DLL ARE\n");
		while(cur!=NULL){
			printf("%d<->",cur->data);
			cur = cur->next;}
	}
	printf("\n");
}
void display_reverse(){
	if(head == NULL)
	printf("DOUBLE LINKED LIST IS EMPTY\n");
	else{
		cur = tail;
		printf("ELEMENTS OF DLL IN REVERSE ARE\n");
		while(cur!=NULL){
			printf("%d<->",cur->data);
			cur = cur->prev;}
	}
	printf("\n");
}

void sorting()
{
	struct node *p1,*p2; int t;
	int c = 0;
	p1 = head;
	while(p1 != NULL){
		c++;
		p1 = p1->next;}
	for(int i=0;i<c;i++){
		p2 = head;
		while(p2->next !=NULL){
			if(p2->data > p2->next->data){
				t = p2->data;
				p2->data = p2->next->data;
				p2->next->data = t;}
		p2 = p2->next;}
	}
}

void searching(){
	int value,flag =0;
	printf("ENTER THE VALUE TO BE SEARCHED\n");
	scanf("%d", &value);
	int c=0;
	t1 = head;
	while(t1 != NULL){
	if(t1->data == value){
		flag = 1;
		break;
		}
		t1 = t1->next;
		c++;}
	if(flag == 1)
	printf("ELEMENT PRESENT IN LIST AT POSITION %d\n",c);
	else
	printf("ELEMENT NOT FOUND\n");
} 

int main()
{
	int ch;
	while(1)
	{
	printf("PROGRAM FOR DOUBLE LINKED LIST\n");
	printf("---------------------------------\n");
	printf("1- create\n2- insert at begin\n3 - insert at end\n4 - insert at position\n5 - insert before");
	printf("\n6 - insert after\n7 - display in forward\n8 - delete at begin\n9 - delete at end\n10 - delete at position\n");
	printf("11 - delete before\n12 - delete after\n13 - display in reverse\n14 - searching\n15 - sorting\n");
	printf("---------------------------------\n");
	printf("Enter your choice\n");
	scanf("%d",&ch);
	switch(ch){
		 	case 1:create();
				   break;
		 	case 2:insert_at_begin();
				   break;
		 	case 3:insert_at_end();
				   break;
		 	case 4:insert_at_position();
				   break;
		 	case 5:insert_before();
				   break;
		 	case 6:insert_after();
				   break;
		 	case 7:display_forward();
				   break;
		 	case 8:delete_at_begin();
				   break;
		 	case 9:delete_at_end();
				   break;
		 	case 10:delete_at_position();
				    break;
		 	case 11:delete_before();
				    break;
		 	case 12:delete_after();
				break;
			case 13:display_reverse();
					break;
			case 14:searching();
				    break;
		 	case 15:sorting();
				    break;
			case 16:exit(0);
}
}
}
	



