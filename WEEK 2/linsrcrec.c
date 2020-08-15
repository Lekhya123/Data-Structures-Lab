#include<stdio.h>
int linearsearch(int a[30], int n, int key)
{
	static int i;
	if(a[i] == key)
	return i;
	else if(i<n)
	{
		i++;
		linearsearch(a,n,key);
}
else
return -1; 
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