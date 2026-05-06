//Write a program to sort the elements of an array using Heap sort.
#include<iostream>
using namespace std;

int c=0;

void heapify(int a[], int n, int i)
{
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;

    if(l<n)
    {
        c++;
        if(a[l]>a[largest]) largest=l;
    }

    if(r<n)
    {
        c++;
        if(a[r]>a[largest]) largest=r;
    }

    if(largest!=i)
    {
        swap(a[i],a[largest]);
        heapify(a,n,largest);
    }
}

int main()
{
    int n,i;
    cin>>n;

    int a[100];

    for(i=0;i<n;i++)
        cin>>a[i];

    for(i=n/2-1;i>=0;i--)
        heapify(a,n,i);

    for(i=n-1;i>0;i--)
    {
        swap(a[0],a[i]);
        heapify(a,i,0);
    }

    cout<<"Sorted Array: ";
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";

    cout<<"\nComparisons="<<c;

    return 0;
}