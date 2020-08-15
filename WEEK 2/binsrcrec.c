#include<stdio.h>
int binarysearch(int first,int last, int a[30], int key)
{
	int mid;
	if(first <= last)
	{
		mid = (first + last) / 2;
		if(a[mid] == key){
			return mid;
		}
		else if(a[mid] < key){
			binarysearch(mid + 1,last,a,key);}
		else{
			binarysearch(first, mid - 1,a,key);}
	}
	else{	
		return -1;}
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
