// Write a program to sort the elements of an array using insertion sort.
#include <iostream>
using namespace std;

int main()
{
    int n, i, j, key;
    int comp = 0;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements:\n";
    for(i = 0; i < n; i++)
        cin >> arr[i];

    for(i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while(j >= 0)
        {
            comp++;

            if(arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            else
                break;
        }

        arr[j + 1] = key;
    }

    cout << "\nSorted Array: ";
    for(i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\nNumber of Comparisons = " << comp;

    return 0;
} 