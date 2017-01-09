#include <iostream>
#include "IntegerArray.h"

using namespace std;

int main()
{
    int arr[80], arr2[80];
    char letter;
    char arr_char[] = "My Char Array";
    int size_ch = sizeof(arr_char) / sizeof(arr_char[0]);
    string_sort(arr_char, size_ch);

    display_array(arr_char, size_ch);
    /*unput_array(arr, 5);
    display_array(arr, 4);
    copy_array(arr2, arr, 3);
    display_array(arr2, 3);


    cout << "Enter a letter: \n";
    cin >> letter;
    cout << int(letter);
    cout << "size of char array: " << size_ch;
    */
    return 0;
}
