#include<stdio.h>
int cost[10][10],n;
int i,j;

void kruskal()
{
int par[n];
int a=0,b=0,u=0,v=0,min, mincost = 0, ne = 0;
for(i=0;i<n;i++)
par[i]=-1;
printf("the minimum spanning tree edges are...");
while(ne < n-1)
{
//Find the least cost edge
min = 999;
for(i=0;i<n;i++)
for(j=0;j<n;j++)
if(cost[i][j] < min)
{
min=cost[i][j];
a=u=i;
b=v=j;
}
while(par[u]!=-1)
u=par[u];
while(par[v]!=-1)
v=par[v];
if(u!=v)
{
printf("From vertex %d to vertex %d and the cost = %d\n",a,b,min);
mincost+=min;
par[v]=u;
ne++;
}
//edge included in MST should not be considered for next iteration
cost[a][b]=cost[b][a]=999;
}
printf("Cost of MST = %d", mincost);
}
void main()
{
printf("Enter the no. of vertices:");
scanf("%d",&n);
printf("Enter the cost matrix\n");
for(i=0;i<n;i++)
for(j=0;j<n;j++)
scanf("%d",&cost[i][j]);
kruskal();
}
