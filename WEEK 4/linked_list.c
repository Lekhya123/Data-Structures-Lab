#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*link;
};
struct node *head = NULL,*tail = NULL,*cur,*next,*prev;
void create(){
	int n;
	printf("ENTER THE NUMBER OF NODES\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
	cur = (struct node*)malloc(sizeof(struct node));
	printf("ENTER CURRENT NODE DATA\n");
	scanf("%d", &(cur->data));
	cur->link = NULL;
	if(head == NULL)
		head = tail = cur;
	else{
		tail->link = cur;
		tail = cur;}
	}
}
	
void insert_at_begin(){
	cur = (struct node*)malloc(sizeof(struct node));
	printf("ENTER THE DATA\n");
	scanf("%d", &(cur->data));
	cur->link = head;
	head = cur;}

void insert_at_end(){
	cur = (struct node*)malloc(sizeof(struct node));
	printf("ENTER THE DATA\n");
	scanf("%d", &(cur->data));
	cur->link = NULL;
	tail->link = cur;
	tail = cur;}
void insert_at_position(){
	cur = (struct node*)malloc(sizeof(struct node));
	printf("ENTER THE DATA\n");
	scanf("%d", &(cur->data));
	int pos;
	printf("ENTER THE POSITION\n");
	scanf("%d", &pos);
	int c = 1;
	next = head;
	while(c < pos){
		prev = next;
		next = next->link;
		c++;}
	prev->link = cur;
	cur->link = next;}

void insert_before_node(){
	cur = (struct node*)malloc(sizeof(struct node));
	printf("ENTER THE DATA\n");
	scanf("%d", &(cur->data));
	int value;
	printf("ENTER THE NODE VALUE TO INSERT BEFORE \n");
	scanf("%d", &value);
	next = head;
	while(next->data != value && next != NULL){
		prev = next;
		next = next->link;}
	prev->link = cur;
	cur->link = next;}

void insert_after_node(){
	cur = (struct node*)malloc(sizeof(struct node));
	printf("ENTER THE DATA\n");
	scanf("%d", &(cur->data));
	int value;
	printf("ENTER THE NODE VALUE TO INSERT AFTER\n");
	scanf("%d", &value);
	next = head;
	while(next->data != value && next != NULL){
		next = next->link;}
	cur->link = next->link;
	next->link = cur;}

void display(){
	if(head == NULL)
	printf("LIST IS EMPTY\n");
	else{
		next = head;
		while(next != NULL){
			printf("%d->",next->data);
			next = next->link;}
		}
	}

void delete_at_begin(){
	cur = head;
	head = cur->link;
	cur->link = NULL;
	printf("DELETED ELEMENT IS %d\n",cur->data);
	free(cur);}

void delete_at_end(){
	cur = head;
	while(cur->link != tail) 
		cur = cur->link;
	cur->link = NULL;
	next = tail;
	printf("DELETED ELEMENT IS %d\n",next->data);
	free(next);
	tail = cur;}

void delete_at_position(){
	next = head;
	int pos;
	printf("ENTER THE POSITION\n");
	scanf("%d", &pos);
	int c = 1;
	while(c < pos){
		prev = next;
		next = next->link;
		c++;}
	prev->link = next->link;
	next->link = NULL;
	free(next);}

void delete_before_node(){
	int value;
	printf("ENTER THE NODE VALUE TO DELETE BEFORE\n");
	scanf("%d", &value);
	next = head;
	while(next->link->data != value){
		prev = next;
		next = next->link;}
	prev->link = next->link;
	next->link = NULL;
	printf("DELETED ELEMENT IS %d\n",next->data);
	free(next);}

void delete_after_node(){
	int value;
	printf("ENTER THE NODE VALUE TO DELETE AFTER\n");
	scanf("%d", &value);
	next = head;
	while(next->data != value){
		prev = next;
		next = next->link;}
	prev = next->link;
	next->link = prev->link;
	prev->link = NULL;
	printf("DELETED ELEMENT IS %d\n",prev->data);
	free(prev);}

void bubble_sorting()
{
	struct node *p1,*p2; int t;
	int c = 0;
	p1 = head;
	while(p1 != NULL){
		c++;
		p1 = p1->link;}
	for(int i=0;i<c;i++){
		p2 = head;
		while(p2->link !=NULL){
			if(p2->data > p2->link->data){
				t = p2->data;
				p2->data = p2->link->data;
				p2->link->data = t;}
		p2 = p2->link;}
	}
}

void reverse_sll(struct node*head){
	if(head != NULL){
	reverse_sll(head->link);
	printf("%d ",head -> data);}
}

void reverse_array(){
	int a[100], i = 0;
	cur = head;
	while(cur != NULL){
		a[i] = cur->data;
		cur = cur->link;
		i += 1;}
		i -= 1;
		while(i>= 0){
			printf("%d ",a[i]);
			i--;
		}
}

void searching(){
	int value,flag =0;
	printf("ENTER THE VALUE TO BE SEARCHED\n");
	scanf("%d", &value);
	int c=0;
	next = head;
	while(next != NULL){
	if(next->data == value){
		flag = 1;
		break;
		}
		next = next->link;
		c++;}
	if(flag == 1)
	printf("ELEMENT PRESENT IN LIST AT POSITION %d\n",c);
	else
	printf("ELEMENT NOT FOUND\n");
} 

void sorting()
{
	struct node *p1,*p2,*last =NULL; int t;
	int c ;
	do{
		c=0;
		p1 = head;
		while(p1->link != last){
			if(p1->data > p1->link->data){
				t = p1->data;
				p1->data = p1->link->data;
				p1->link->data = t;
				c = 1;}
		p1 = p1->link;
	}
	last = p1;
}while(c);
}



int main()
{
	int ch;
	while(1)
	{
	printf("PROGRAM FOR SINGLE LINKED LIST\n");
	printf("---------------------------------\n");
	printf("1- create\n2- insert at begin\n3 - insert at end\n4 - insert at position\n5 - insert before");
	printf("\n6 - insert after\n7 - display\n8 - delete at begin\n9 - delete at end\n10 - delete at position\n");
	printf("11 - delete before\n12 - delete after\n13 - display in reverse\n14 - reverse array\n15 - search\n16 - sorting\n17 - bubble sort\n");
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
		 	case 5:insert_before_node();
				   break;
		 	case 6:insert_after_node();
				   break;
		 	case 7:display();
				   break;
		 	case 8:delete_at_begin();
				   break;
		 	case 9:delete_at_end();
				   break;
		 	case 10:delete_at_position();
				    break;
		 	case 11:delete_before_node();
				    break;
		 	case 12:delete_after_node();
				    break;
		 	case 13:reverse_sll(head);
				    break;
			case 14:reverse_array();
					break;
		 	case 15:searching();
				    break;
		 	case 16:sorting();
				    break;
			case 17:bubble_sorting();
					break;
			case 18:exit(0);
}
}
}
		 
