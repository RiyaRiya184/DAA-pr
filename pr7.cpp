#include<iostream>
using namespace std;

int q[100], front=0, rear=0;

int main()
{
    int n,i,j,start;
    int a[20][20], vis[20]={0};

    cout<<"Enter number of vertices: ";
    cin>>n;

    cout<<"Enter adjacency matrix:\n";
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin>>a[i][j];

    cout<<"Enter starting vertex: ";
    cin>>start;

    cout<<"BFS Traversal: ";

    q[rear++]=start;
    vis[start]=1;

    while(front<rear)
    {
        int v=q[front++];
        cout<<v<<" ";

        for(i=0;i<n;i++)
        {
            if(a[v][i]==1 && vis[i]==0)
            {
                q[rear++]=i;
                vis[i]=1;
            }
        }
    }

    return 0;
}