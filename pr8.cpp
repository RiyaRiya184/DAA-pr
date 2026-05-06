#include<iostream>
using namespace std;

int a[10][10], visited[10], n;

void dfs(int v)
{
    cout<<v<<" ";
    visited[v]=1;

    for(int i=1;i<=n;i++)
        if(a[v][i]==1 && visited[i]==0)
            dfs(i);
}

int main()
{
    int i,j,start;

    cout<<"Enter number of vertices: ";
    cin>>n;

    cout<<"Enter adjacency matrix:\n";
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            cin>>a[i][j];

    cout<<"Enter starting vertex: ";
    cin>>start;

    cout<<"DFS Traversal: ";
    dfs(start);

    return 0;
}