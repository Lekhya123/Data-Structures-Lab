#include<stdio.h>
void insertion_sort(int a[100] , int n)
{
	int j,index;
	for(int i=1;i<n;i++){
		index = a[i];
		j=i;
		while((j>0) && (a[j-1]>index))
		{
			a[j] = a[j-1];
			j -= 1;
		}
		a[j] = index;
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	insertion_sort(a,n);
	printf("ELEMENTS AFTER SORTING\n");
	for(int i=0;i<n;i++)
	printf("%d ",a[i]);
}
	