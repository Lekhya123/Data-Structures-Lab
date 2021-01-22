#include<stdio.h>
int source, V, E, visited[20], G[20][20];
void dfs(int i){
	int j;
	visited[i] = 1;
	printf("%d ->",i+1);
	for(j=0;j<V;j++)
	{
		if(G[i][j] == 1 && visited[j] == 0)
		dfs(j);
	}
}
int main(){
	int i,j,v1,v2;
	printf("\t\t\tGRAPHS\n);
	printf("ENTER THE NUMBER OF EDGES\n");
	scanf("%d",&E);
	printf("ENTER THE NUMBER OF VERTICES\n");
	scanf("%d",&V);
	for(i=0;i<V;i++){
		for(j=0;j<V;j++)
		G[i][j] = 0;
	}
	for(i=0;i<E;i++){
		printf("ENTER EDGE - FORMAT(V1 V2)");
		scanf("%d %d",&v1,&v2);
		G[v1-1][v2-1] = 1;
	}
	for(i=0;i<V;i++){
		for(j=0;j<V;j++)
		printf("%d\t",G[i][j]);
		printf("\n");
	}
	printf("ENTER THE SOURCE\n");
	scanf("%d",&source);
	dfs(source - 1);
}