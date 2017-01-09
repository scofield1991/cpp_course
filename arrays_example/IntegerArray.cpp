#include <iostream>

using namespace std;

void unput_array(int arr[], int n)
{
    for (int i=0; i<n; i++)
    {
        cout << "Enter a number: ";
        cin >> arr[i];
    }
}

template<typename T>
void display_array(T arr[], int n)
{
    for (int i=0; i<n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << "\n";
}

void copy_array(int arr1[], int arr2[], int n)
{
    for (int i=0; i<n; i++)
    {
        arr1[i] = arr2[i];
    }
}

void string_sort(char arr[], int length)
{
    for (int i=0; i<length-1; i++)
    {
        int min_num_indx = i + 1;

        for (int j=i+1; j<length; j++)
        {
            if (int(arr[j]) < int (arr[min_num_indx]))
            {
                min_num_indx = j;
            }
        }
        swap(arr[i], arr[min_num_indx]);
    }
}

template void display_array<char>(char arr[], int length);
