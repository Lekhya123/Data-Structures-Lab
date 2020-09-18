#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*link;
};
struct node*f= NULL,*r=NULL,*cur;
void enqueue(){
	cur = (struct node*)malloc(sizeof(struct node));
	printf("ENTER THE DATA TO BE INSERTED\n");
	scanf("%d",&cur->data);
	cur->link = NULL;
	if(f==NULL)
	f=r=cur;
	else{
	r->link = cur;
	r=cur;}
}
void dequeue(){	
	if(f==NULL)
	printf("QUEUE UNDERFLOW\n");
	else if(f==r){
		printf("DELETED DATA %d\n",f->data);
		f=r=NULL;}
	else{
		cur=f;
		f=f->link;
		printf("DELETED DATA %d\n",cur->data);
		free(cur);
	}
}
void display(){
	if(f==NULL)
	printf("QUEUE IS EMPTY\n");
	else{
		cur = f;
		while(cur !=NULL){
		printf("%d->",cur->data);
		cur=cur->link;
		}
	}
}
int main(){
	int ch;
	while(1){
	printf("\n1-ENQUEUE\n2-DEQUEUE\n3-DISPLAY\n4-QUIT\n");
	printf("ENTER YOUR CHOICE\n");
	scanf("%d",&ch);
	switch(ch){
	case 1:enqueue();
		break;
	case 2:dequeue();
		break;
	case 3:display();
		break;
	case 4:exit(0);
	}
}
}