#include <stdio.h>
#define INF 999
#define MAX 10

int main() {
    int n, i, j, k, updated;
    int cost[MAX][MAX], dist[MAX][MAX];

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (999 for INF):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            dist[i][j] = cost[i][j];
    do {
        updated = 0;
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                for (k = 0; k < n; k++)
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        updated = 1;
                    }
    } while (updated);
    printf("\nFinal Distance Table:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", dist[i][j]);
        printf("\n");
    }

    return 0;
}















#include<stdio.h> 
#define INF 999 
#define MAX 20 
struct RoutingTable{ 
 int dist[MAX]; 
 int nextHop[MAX]; 
}; 
void main(){ 
 int n; int cost[MAX][MAX]; 
 char nodes[MAX][20]; 
 struct RoutingTable rt[MAX]; 
 printf("Enter number of nodes (hosts/roters): "); 
 scanf("%d",&n); 
 printf("Enter node names (e.g., H1, H2, ...):\n"); 
 for(int i=0;i<n;i++){ 
 printf("Node %d: ",i+1); 
 scanf("%s",nodes[i]); 
 } 
 printf("\nEnter adjacency matrix (delay cost, INF=999, 0 for self):\n");  for(int i=0;i<n;i++){ 
 for(int j=0;j<n;j++) 
 scanf("%d",&cost[i][j]); 
 } 
 for(int i=0;i<n;i++){ 
 for(int j=0;j<n;j++){ 
 rt[i].dist[j]=cost[i][j]; 
 if(cost[i][j]!=INF && i!=j) 
 rt[i].nextHop[j]=j; 
 else 
 rt[i].nextHop[j]=-1; 
 }
 } 
 int updated; 
 do{ 
 updated=0; 
 for(int i=0;i<n;i++){ 
 for(int j=0;j<n;j++){ 
 for(int k=0;k<n;k++){ 
 if(rt[i].dist[j]> cost[i][k] +rt[k].dist[j]){  rt[i].dist[j]=cost[i][k]+rt[k].dist[j];  updated=1; 
 } 
 } 
 } 
 } 
 }while(updated); 
 for(int i=0;i<n;i++){ 
 printf("\nRouting Table for Node %s:\n",nodes[i]);  printf("Destination\tNextHop\t\tCost\n");  for(int j=0;j<n;j++){ 
 if(i==j) continue; 
 printf("%s\t\t",nodes[j]); 
 if(rt[i].nextHop[j]!=-1) 
 printf("%s\t\t",nodes[rt[i].nextHop[j]]);  else 
 printf("-\t\t"); 
 if(rt[i].dist[j]==INF) 
 printf("INF\n"); 
 else 
 printf("%d\n",rt[i].dist[j]); 
 } 
 } 
}
