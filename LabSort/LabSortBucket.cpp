#include <iostream>
using namespace std;
void PrintArr(int **buckets, int bucket_count, int size, int mx)
{
    for (int i = 0; i < bucket_count; i++)
    {
        cout << endl;
        for (int j = 0; j < size; j++)
        {
            cout << buckets[i][j] << " ";

        }
    }
}
void BucketSort(int arr[], int size)
{
    int mx = arr[0];
    int mn = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > mx)
        {
            mx = arr[i];
        }
        if (arr[i] < mn)
        {
            mn = arr[i];
        }
    }
    int bucket_count = ((mx - mn) / size) + 1;
    int **buckets = new int*[bucket_count];
    for (int i = 0; i < bucket_count; i++)
    {
        buckets[i] = new int[size];
    }
    for (int i = 0; i < size; i++)
    {
        int bucket_index = ((arr[i] - mn) / size);
        buckets[bucket_index][i] = arr[i];
        for (int j = 0; j < bucket_count; j++)
        {
            if (j != bucket_index)
            {
                buckets[j][i] = -1;
            }
        }
    }
    for (int i = 0; i < bucket_count; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (buckets[i][j] != -1)
            {
                for (int k = j; k < size; k++)
                {
                    if (buckets[i][j] > buckets[i][k])
                    {
                        int tmp = buckets[i][j];
                        buckets[i][j] = buckets[i][k];
                        buckets[i][k] = tmp;
                    }
                }
            }
        }
    }
    int index = 0;
    for (int i = 0; i < bucket_count; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (buckets[i][j] != -1)
            {
                arr[index++] = buckets[i][j];
            }
        }
    }
    for (int i = 0; i < bucket_count; i++)
    {
        delete []buckets[i];
    }
    delete []buckets;
}
int main()
{
    int arr[] = {1, 101, 78, 12, 55, 92, 0, 2, 4, 12, 7, 16, 34, 5, 6, 4, 23, 60, 28, 52, 11, 3, 43, 6, 2};
    BucketSort(arr, sizeof(arr) / sizeof(int));
    cout << endl;
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        cout << arr[i] << " ";
    }
}