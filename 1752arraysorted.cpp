#include <iostream>
using namespace std;

bool checkSortedRotated(int arr[], int n)
{
    int count = 0;

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            count++;
        }
    }

    // check last and first
    if (arr[n - 1] > arr[0])
    {
        count++;
    }

    if (count <= 1)
        return true;
    else
        return false;
}

int main()
{
    int arr[] = {3,4,5,1,2};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (checkSortedRotated(arr, n))
        cout << "True";
    else
        cout << "False";

    return 0;
}
