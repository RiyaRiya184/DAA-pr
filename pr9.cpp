#include<iostream>
using namespace std;

int main()
{
    int n,i,j,min,u=0,v=0,total=0;
    
    cout<<"Enter number of vertices: ";
    cin>>n;

    int cost[10][10],visited[10]={0};

    cout<<"Enter adjacency matrix:\n";
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin>>cost[i][j];

    visited[0]=1;

    cout<<"\nEdges in MST:\n";

    for(int e=1;e<n;e++)
    {
        min=999;

        for(i=0;i<n;i++)
        {
            if(visited[i]==1)
            {
                for(j=0;j<n;j++)
                {
                    if(visited[j]==0 && cost[i][j]<min && cost[i][j]!=0)
                    {
                        min=cost[i][j];
                        u=i;
                        v=j;
                    }
                }
            }
        }

        cout<<u<<" - "<<v<<" = "<<min<<endl;
        total=total+min;
        visited[v]=1;
    }

    cout<<"Minimum Cost = "<<total;

    return 0;
}