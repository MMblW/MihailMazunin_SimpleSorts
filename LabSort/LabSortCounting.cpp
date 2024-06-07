#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    int sizeA = 6;
    int *arr = new int[sizeA];
    int mx = 0, mn = 0;
    for (int i = 0; i < sizeA; i++)
    {
        arr[i] = rand() % 10-5;
        cout << arr[i] << " ";
        if (arr[i] < mn)
        {
            mn = arr[i];
        }
        if (arr[i] > mx)
        {
            mx = arr[i];
        }
    }
    int sizeB = mx - mn + 1;
    int *barr = new int[sizeB];
    for (int i = 0; i < sizeB; i++)
    {
        barr[i] = 0;
    }
    for (int i = 0; i < sizeA; i++)
    {
        barr[arr[i] - mn]++;
    }
    int index = 0;
    for (int i = 0; i < sizeB; i++)
    {
        for (int j = 0; j < barr[i]; j++)
        {
            arr[index++] = i + mn;
        }
    }
    cout << endl;
    for(int i = 0; i < sizeA; i++)
    {
        cout << arr[i] << " ";
    }
}