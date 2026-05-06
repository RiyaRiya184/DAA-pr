#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n,i,j;

    cout<<"Enter number of elements: "<<endl;
    cin>>n;

    float a[100];

    cout<<"Enter elements (0 to 1): "<<endl;

    for(i=0;i<n;i++)
        cin>>a[i];

    vector<float> b[10];

    for(i=0;i<n;i++)
    {
        int index=a[i]*10;
        b[index].push_back(a[i]);
    }

    for(i=0;i<10;i++)
        sort(b[i].begin(),b[i].end());

    cout<<"Sorted Array: "<<endl;

    for(i=0;i<10;i++)
        for(j=0;j<b[i].size();j++)
            cout<<b[i][j]<<" ";

    return 0;
}