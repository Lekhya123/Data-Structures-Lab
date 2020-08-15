#include<stdio.h>
int binarysearch(int first,int last, int a[30], int key)
{
	int pos= -1;
	while(first <= last)
	{
		int mid = (first + last) / 2;
		if(a[mid] == key)
		{
			pos = mid;
			break;
		}
		else if(a[mid] < key){
		first = mid + 1;}
		else{
		last = mid - 1;}
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
	pos = binarysearch(0,n-1,a,key);
	if(pos == -1)
	printf("Element not found");
	else
	printf("Element found at position %d", pos + 1);
}
