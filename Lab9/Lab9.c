#include<stdio.h>
#include<stdlib.h>
int graph[20][20];
int n;int v[20];
int queue[200];
void bfs(int start){
    int rear=0;int front=0;
    queue[rear++]=start;
    v[start]=1;
    while(front<rear){
        int p=queue[front++];
        printf("%d ",p);
        for(int i=0;i<n;i++){
            if(graph[p][i]==1&&v[i]==0){
                queue[rear++]=i;
                v[i]=1;
            }
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
    printf("\nBFS TRAVERSAL IS: \n");
    bfs(0);
    return 0;
}