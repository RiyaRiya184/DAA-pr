//Write a program to sort the elements of an array using Radix sort.
#include<iostream>
using namespace std;

int getMax(int a[],int n)
{
    int mx=a[0];
    for(int i=1;i<n;i++)
        if(a[i]>mx) mx=a[i];
    return mx;
}

void countSort(int a[],int n,int exp)
{
    int output[100],count[10]={0};

    for(int i=0;i<n;i++)
        count[(a[i]/exp)%10]++;

    for(int i=1;i<10;i++)
        count[i]+=count[i-1];

    for(int i=n-1;i>=0;i--)
    {
        output[count[(a[i]/exp)%10]-1]=a[i];
        count[(a[i]/exp)%10]--;
    }

    for(int i=0;i<n;i++)
        a[i]=output[i];
}

int main()
{
    int n,a[100];

    cout<<"Enter number of elements: ";
    cin>>n;

    cout<<"Enter elements: ";
    for(int i=0;i<n;i++)
        cin>>a[i];

    int mx=getMax(a,n);

    for(int exp=1; mx/exp>0; exp*=10)
        countSort(a,n,exp);

    cout<<"\nSorted Array: ";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

    return 0;
}