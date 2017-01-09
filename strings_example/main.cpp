#include <iostream>
#include <cstring>

using namespace std;

const int MAXIMUM_LENGTH = 80;

int main()
{
    char first_string[MAXIMUM_LENGTH];
    char second_string[MAXIMUM_LENGTH];

    cout << "Enter first string: ";
    cin.getline(first_string, MAXIMUM_LENGTH);
    cout << "Enster second string: ";
    cin.getline(second_string, MAXIMUM_LENGTH);

    cout << "Before copying the string were ";
    if (strcmp(first_string, second_string))
        cout << "not ";
    cout << "the same.\n";

    strcpy(first_string, second_string);

    cout << "After copying the strings were ";
    if(strcmp(first_string, second_string))
        cout << "not ";
    cout << "the same.\n";

    strcat(first_string, second_string);

    cout << "After concatenating, the first string is: ";
    cout << first_string;

    return 0;
}
