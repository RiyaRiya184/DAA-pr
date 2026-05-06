#include<iostream>
#include<algorithm>
using namespace std;

struct Job
{
    int s,f,w;
};

bool cmp(Job a, Job b)
{
    return a.f < b.f;
}

int main()
{
    int n,i,j;

    cout<<"Enter number of jobs: ";
    cin>>n;

    Job a[100];
    int dp[100];

    for(i=0;i<n;i++)
    {
        cout<<"Enter start finish weight of job "<<i+1<<": ";
        cin>>a[i].s>>a[i].f>>a[i].w;
    }

    sort(a,a+n,cmp);

    dp[0]=a[0].w;

    for(i=1;i<n;i++)
    {
        int incl=a[i].w;

        for(j=i-1;j>=0;j--)
        {
            if(a[j].f<=a[i].s)
            {
                incl+=dp[j];
                break;
            }
        }

        dp[i]=max(dp[i-1],incl);
    }

    cout<<"Maximum Profit = "<<dp[n-1];

    return 0;
}