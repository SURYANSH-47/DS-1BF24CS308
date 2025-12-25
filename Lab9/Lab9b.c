#include<stdio.h>
#include<stdlib.h>
int graph[20][20];
int n;int v[20];int c=0;
void dfs(int start){
    v[start]=1;c++;
    printf("%d ",start);
    for(int i=0;i<n;i++){
            if(graph[start][i]==1&&v[i]==0){
                v[i]=1;
                dfs(i);
            }
        }
}
int main(){
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    printf("Enter the adjacency matrix: ");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        v[i]=0;
    }
    printf("\nDFS TRAVERSAL\n ");
    dfs(0);
    if(c==n){
        printf("\nCONNECTED ");
    }
    return 0;
}