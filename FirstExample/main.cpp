#include <iostream>
#include <string>
#include <array>
#include <new>
#include <sstream>
using namespace std;

class Tool
{
protected:
    int strength;
    char type;
public:
    void setStrength(int);
    virtual const char getType();
};

class Rock: public Tool
{
public:
    Rock();
    Rock(int);
    bool fight(Tool other);
};

class Paper: public Tool
{
public:
    Paper();
    Paper(int);
    bool fight(Tool other);
};

class Scissors: public Tool
{
public:
    Scissors();
    Scissors(int);
    bool fight(Tool other);
};

void Tool::setStrength(int myStr)
{
    strength = myStr;
}


char const Tool::getType()
{
    return type;
}



Rock::Rock(int strength)
{
    Tool::setStrength(strength);
    type = 'r';
}

Rock::Rock()
{
    type = 'r';
}

bool Rock::fight(Tool other)
{
    if(other.getType() == 's')
        strength *= 2;
    else if(other.getType() == 'p')
        strength /= 2;
}

Paper::Paper()
{
    type = 'p';
}

Paper::Paper(int strength)
{
    setStrength(strength);
    type = 'p';
}

bool Paper::fight(Tool other)
{
    if(other.getType() == 'r')
        strength *= 2;
    else if(other.getType() == 's')
        strength /= 2;
}

Scissors::Scissors()
{
    type = 's';
}

Scissors::Scissors(int strength)
{
    setStrength(strength);
    type = 's';
}

bool Scissors::fight(Tool other)
{
    if(other.getType() == 'p')
        strength *= 2;
    else if(other.getType() == 'r')
        strength /= 2;
}

template<class T, size_t N>
void * myMap(T (*func)(T), T (&arr)[N])
{
    //cout << 'arr_size' << sizeof(arr) << endl;
    //cout << 'arr_size' << sizeof(*arr) << endl;
    //int arr_size = sizeof(arr) / sizeof(arr[0]);
    //cout << "arr_size " << arr_size << endl;
    //int new_arr[3];


    for(int i=0; i < N; i++)
    {
        arr[i] = func(arr[i]);
        //cout << "new_arr[i] " << arr[i] << ' ' << new_arr[i] << endl;
    }

}

void printarr(int arg[])
{
    for (int i=0; i < 4; i++)
    {
        cout << arg[i] << ' ';
    }
    cout << "\n";
}

int MyDouble(int a)
{
    return a * 2;
}

int main()
{

/*
    Tool tool_1;
    Rock rock_1(2);
    Rock rock_2;
    Paper paper_1(3);
    Scissors scissors_1(4);
    rock_1.fight(paper_1);
    */

    int arr[] = {1, 2, 3, 4};

    char arr_1[] = {'a', 'b', 'c', 'd'};

    printarr(arr);
    myMap<char, 4>(MyDouble, arr_1);

    for(int i: arr_1)
    {
        cout << i << ' ';
    }
/*
    for(int i=0; i < 3; i++)
    {
        cout << (new_arr[i]) << ' ';
    }
    */

    return 0;
}
