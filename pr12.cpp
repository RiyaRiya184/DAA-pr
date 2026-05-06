#include<iostream>
using namespace std;

int main()
{
    int n,i,w;

    cout<<"Enter number of items: ";
    cin>>n;

    int wt[50], val[50];

    cout<<"Enter weights:\n";
    for(i=1;i<=n;i++)
        cin>>wt[i];

    cout<<"Enter profits:\n";
    for(i=1;i<=n;i++)
        cin>>val[i];

    cout<<"Enter knapsack capacity: ";
    cin>>w;

    int dp[50][50];

    for(i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(wt[i]<=j)
                dp[i][j]=max(val[i]+dp[i-1][j-wt[i]], dp[i-1][j]);
            else
                dp[i][j]=dp[i-1][j];
        }
    }

    cout<<"Maximum Profit = "<<dp[n][w];

    return 0;
}