#include<stdio.h>
#include<stdlib.h>
#define maxsize 5
int f=-1,r=-1,cq[maxsize];
int isfull(){
	if(f ==(r+1)%maxsize)
	return 1;
	else
	return 0;
}
int isempty(){
	if(f == -1)
	return 1;
	else
	return 0;
}
void enqueue(int data){
	if(f == -1)
	f=0;
	r = (r+1) %maxsize;
	cq[r] = data;
}
int dequeue(){
	int x=cq[f];
	if(f==r)
	f=r=-1;
	else
	f = (f+1)%maxsize;
	return x;
}
void display(){
	if(f == -1)
	printf("CIRCULAR QUEUE IS EMPTY\n");
	else{
		int i;
		for(i=f;i !=r;i=(i+1)%maxsize)
		printf("%d\t",cq[i]);
		printf("%d\n",cq[i]);
	}
}
int main(){
	int ch,x;
	while(1){
	printf("\n1-ENQUEUE\n2-DEQUEUE\n3-DISPLAY\n4-QUIT\n");
	printf("ENTER YOUR CHOICE\n");
	scanf("%d",&ch);
	switch(ch){
	case 1:if(isfull())
		printf("CIRCULAR QUEUE OVERFLOW\n");
		else{
		printf("ENTER THE DATA TO BE INSERTED\n");
		scanf("%d",&x);
		enqueue(x);
		}
		break;
	case 2:if(isempty())
		printf("CIRCULAR QUEUE UNDERFLOW");
		else{
		printf("DELETED ELEMENT IS %d\n",dequeue());
		}
		break;
	case 3:display();
		break;
	case 4:exit(0);
	}
}
}