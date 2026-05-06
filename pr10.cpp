#include<iostream>
using namespace std;

int main()
{
    int n,i,j,u,min,count=0;
    int cost[10][10],dist[10],visit[10]={0};

    cout<<"Enter number of vertices: ";
    cin>>n;

    cout<<"Enter cost matrix:\n";
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin>>cost[i][j];

    cout<<"Enter source vertex: ";
    cin>>u;

    for(i=0;i<n;i++)
        dist[i]=cost[u][i];

    visit[u]=1;
    dist[u]=0;

    while(count<n-1)
    {
        min=999;
        for(i=0;i<n;i++)
        {
            if(dist[i]<min && visit[i]==0)
            {
                min=dist[i];
                j=i;
            }
        }

        visit[j]=1;

        for(i=0;i<n;i++)
        {
            if(visit[i]==0 && dist[j]+cost[j][i]<dist[i])
                dist[i]=dist[j]+cost[j][i];
        }

        count++;
    }

    cout<<"Shortest distances:\n";
    for(i=0;i<n;i++)
        cout<<"To "<<i<<" = "<<dist[i]<<"\n";

    return 0;
}