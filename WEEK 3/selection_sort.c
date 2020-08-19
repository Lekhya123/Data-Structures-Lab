#include<stdio.h>
void selection_sort(int a[100] , int n)
{
	int t,min;
	for(int i=0;i<n - 1;i++){
		min = i;
		for(int j=i+1;j<n;j++){
			if(a[j] < a[min])
				min = j;}
				t = a[i];
				a[i] = a[min];
				a[min] = t;
		
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	selection_sort(a,n);
	printf("ELEMENTS AFTER SORTING\n");
	for(int i=0;i<n;i++)
	printf("%d ",a[i]);
}
	