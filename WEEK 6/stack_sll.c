#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*link;
};
struct node* top = NULL,*temp;
void push(int data){
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->link = top;
	top = temp;
}
void pop(){
	if(top == NULL)
	printf("STACK IS EMPTY\n");
	else{
		printf("DELETED ELEMENT IS : %d\n",top->data);
		top=top->link;
	}
}
void display(){
	if(top==NULL)
	printf("STACK UNDERFLOW\n");
	else{
		temp = top;
		while(temp->link !=NULL){
			printf("%d->",temp->data);
			temp = temp->link;}
		printf("%d->NULL",temp->data);
	}
	printf("\n");
}
void peek(){
	temp = top;
	top = top->link;
	printf("TOPMOST ELEMENT IS %d\n",temp->data);
}	
int main()
{
   int ch, value;
   printf("STACK USING SINGLE LINKED LIST\n");
   while(1){
      printf("--------------------\n");
      printf("1. Push\n2. Pop\n3. Display\n4. Peek\n5. Exit\n");
      printf("--------------------\n");
      printf("Enter your choice: ");
      scanf("%d",&ch);
      switch(ch){
	 case 1: printf("ENTER THE VALUE TO BE INSERTED : ");
		 scanf("%d", &value);
		 push(value);
		 break;
	 case 2: pop(); 
		 break;
	 case 3: display(); 
		 break;
	 case 4: peek();
		 break;
	 case 5: exit(0);
	
      }
   }
}

		

	
 
