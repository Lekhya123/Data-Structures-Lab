#include<stdio.h>
int linearsearch(int a[30], int n, int key)
{
	int pos =-1;
	for(int i=0;i<n;i++)
	{
		if(a[i]==key)
		{
		pos = i;
		break;
	}
	}
	return pos;
}	
int main()
{
	int key,n,pos;
	scanf("%d%d",&n,&key);
	int a[30];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	pos = linearsearch(a,n,key);
	if(pos == -1)
	printf("Element not found");
	else
	printf("Element found at position %d", pos + 1);
}
