#include <iostream>
using namespace std;
void HoarSort(int *arr, int left, int right)
{
    int i = left, j = right;
    int pivot = arr[(i+j)/2];
    do
    {
        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i <= j)
        {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    } while (i <= j);
    if (left < j)
    {
        HoarSort(arr, left, j);
    }
    if (right > i)
    {
        HoarSort(arr, i, right);
    }
}
int main()
{
    int arr[] = {1, 101, 78, 12, 55, 92, 0, 2, 4, 12, 7, 16, 34, 5, 6, 4, 23, 60, 28, 52, 11, 3, 43, 6, 2};
    HoarSort(arr, 0, sizeof(arr) / sizeof(int));
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        cout << arr[i] << " ";
    }
}