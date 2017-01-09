#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void print_piramid(int height)
{
    int num_stars, num_spaces;
    int num_symbols = 2 + 2 * height;
    for(int i=0; i < height; i++)
    {
        num_stars = 2 + 2 * i;
        num_spaces = (num_symbols - num_stars) / 2;
        string spaces (num_spaces, ' ');
        string stars (num_stars, '*');
        cout << spaces << stars << spaces << endl;
    }
}

void selection_sort(int arr[], int length)
{
    for (int i=0; i<length-1; i++)
    {
        int min_num_indx = i + 1;

        for (int j=i+1; j<length; j++)
        {
            if (arr[j] < arr[min_num_indx])
            {
                min_num_indx = j;
            }
        }
        swap(arr[i], arr[min_num_indx]);
    }
}

int main()
{
    //print_piramid(15);
    int arr[] = {2, 4, 6, 2, 3, 27, 5};
    selection_sort(arr, 7);
    for(int i=0; i < 7; i++)
    {
        cout << arr[i] << ' ';
    }
    return 0;
}
