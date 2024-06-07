#include <iostream>
using namespace std;
void Merge(int *arr, int first, int last)
{
    int st, md, fl;
    st = first;
    md = (first+last)/2;
    fl = md + 1;
    int *barr = new int[256];
    for (int i = first; i <= last; i++)
    {
        if ((st <= md && ((fl > last) || arr[st] < arr[fl])))
        {
            barr[i] = arr[st];
            st++;
        }
        else
        {
            barr[i] = arr[fl];
            fl++;
        }
    }
    for (int i = first; i <= last; i++)
    {
        arr[i] = barr[i];
    }
    delete []barr;
}
void Sort(int *arr, int first, int last)
{
    if (first < last)
    {
        Sort(arr, first, (first + last) / 2);
        Sort(arr, (first + last) / 2 + 1, last);
        Merge(arr, first, last);
    }
}
int main()
{
    int arr[] = {1, 3, 78, 12, 55, 92, 0, 2, 4, 12, 7, 16, 34, 5, 6, 4, 23, 60, 28, 52, 11, 101, 43, 6, 2};
    for (int i = 0; i < (sizeof(arr) / sizeof(int)) - 1; i++)
    {
        cout << arr[i] << " ";
    }
    Sort(arr, 0, (sizeof(arr) / sizeof(int)) - 1);
    cout << endl;
    for (int i = 0; i < (sizeof(arr) / sizeof(int)); i++)
    {
        cout << arr[i] << " ";
    }
}