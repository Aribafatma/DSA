#include <iostream>
using namespace std;

void rotateArray(int arr[], int n, int k)
{
    int temp[100];

    k = k % n;

    int j = 0;

    // last k elements
    for (int i = n - k; i < n; i++)
    {
        temp[j] = arr[i];
        j++;
    }

    // first n-k elements
    for (int i = 0; i < n - k; i++)
    {
        temp[j] = arr[i];
        j++;
    }

    // copy back
    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    rotateArray(arr, n, k);

    cout << "Rotated array: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}