#include <iostream>
using namespace std;
void QuickSort (int *arr, int size)
{
    int l = 0, r = size - 1;
    int mid = arr[size/2];
    do
    {
        while (arr[l] < mid)
        {
            l++;
        }
        while (arr[r] > mid)
        {
            r--;
        }
        if (l <= r)
        {
            int tmp = arr[l];
            arr[l] = arr[r];
            arr[r] = tmp;
            l++;
            r--;
        }
        if (r > 0)
        {
            QuickSort(arr, r + 1);
        }
        if (l < size)
        {
            QuickSort(&arr[l], size - l);
        }
    }
    while (l <= r);
}
int main()
{
    int arr[] = {1, 101, 78, 12, 55, 92, 0, 2, 4, 12, -7, 16, 34, 5, 6, 4, 23, 60, 28, 52, 11, 3, 43, 6, 2};
    for (int i = 0; i < (sizeof(arr) / sizeof(int)); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    QuickSort(arr, (sizeof(arr) / sizeof(int)));
    for (int i = 0; i < (sizeof(arr) / sizeof(int)); i++)
    {
        cout << arr[i] << " ";
    }
}