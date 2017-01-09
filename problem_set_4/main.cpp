#include <iostream>
#include "geometry.h"
#include <typeinfo>

using namespace std;

void printAttributes(Polygon *poly)
{
    cout << "Polygon area: " << poly->area() << endl;
    cout << "Point 1 X: " << poly->getPoints()->get(0)->getX() << endl;
    cout << "Point 1 Y: " << poly->getPoints()->get(0)->getY() << endl;

}
int main()
{
    Point p, p1, p2;
    Point p_1(0, 0), p_2(3 ,4), p_3(7, 8);
    Point new_arr[] = {p, p1, p2};
    PointArray arr;
    Rectangle rec(3, 4, 5, 6);
    Triangle tr(p_1, p_2, p_3);
    cout << typeid(tr).name() << endl;
    //rec.PrintPoints();
    //cout << "Rectangle area: " << rec.area()<< endl;
    Polygon* pl;
    pl = &rec;
    printAttributes(pl);

    pl = &tr;
    cout << typeid(pl).name() << endl;
    printAttributes(pl);
    //Polygon pl;
    //cout << pl.points.getSize();
    //Polygon pl(new_arr, 3);
    //cout << pl.num_polygons << endl;
    //Polygon pl(new_arr, 3);
    //cout << pl.points.arr_size << "\n";
    return 0;
}
