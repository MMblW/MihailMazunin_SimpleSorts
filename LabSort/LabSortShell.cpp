#include <iostream>
using namespace std;
void ShellSort(int *arr, int size)
{
    int j, k;
    int tmp;
    for (int step = size / 2; step > 0; step /= 2)
    {
        for (int i = step; i < size; i++)
        {
            tmp = arr[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp < arr[j - step])
                {
                    arr[j] = arr[j - step];
                    k = j;
                }
                else
                {
                    k = j;
                    j = -1;
                }
            }
            arr[k] = tmp;
        }
    }
}
int main()
{
    int arr[] = {0, 101, 78, 12, 55, 92, 1, 2, 4, 12, 7, 16, 34, 5, 6, 4, 23, 60, 28, 52, 11, 3, 43, 6, 2};
    for (int i = 0; i < (sizeof(arr) / sizeof(int)); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    ShellSort(arr, (sizeof(arr) / sizeof(int)));
    for (int i = 0; i < (sizeof(arr) / sizeof(int)); i++)
    {
        cout << arr[i] << " ";
    }
}