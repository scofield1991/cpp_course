#include <iostream>
#include <typeinfo>
#include <stdlib.h>
#include <math.h>
#include "geometry.h"

PointArray::PointArray()
{
    arr = new Point[0];
    arr_size = 0;
}

PointArray::PointArray(const Point points[], const int size_arr)
{
    arr_size = size_arr;
    arr = new Point[arr_size];
    for (int i=0; i< arr_size; i++)
    {
        arr[i] = points[i];
    }
}

PointArray::PointArray(const PointArray& pv)
{
    arr_size = pv.arr_size;
    arr = new Point[arr_size];
    for (int i=0; i < arr_size; i++)
    {
        arr[i] = pv.arr[i];
    }
}

PointArray::~PointArray()
{
    delete[] arr;
}

void PointArray::resize_arr(int n)
{
    Point *tmp = arr;
    delete[] arr;
    arr = new Point[n];
    int min_num_elements = std::min(arr_size, n);
    arr_size = min_num_elements;


    for (int i=0; i<min_num_elements; i++)
    {

        arr[i] = tmp[i];
    }
    delete[] tmp;
}

void PointArray::push_back(const Point &p)
{
    resize_arr(arr_size + 1);
    arr[arr_size - 1] = p;
}

void PointArray::insert(const int position, const Point &p)
{
    resize_arr(arr_size + 1);
    for (int i=(arr_size-1); i>position; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[position] = p;
}

void PointArray::remove(const int pos)
{
    if(pos >= 0 && pos < arr_size)
    {
        for (int i=pos; i<(arr_size-2); i++)
        {
            arr[i] = arr[i+1];
        }
        resize_arr(arr_size - 1);
    }
}

const int PointArray::getSize() const
{
    return arr_size;
}

void PointArray::clear()
{
    resize_arr(0);
}

Point *PointArray::get(const int position)
{
    if ( arr_size == 0 || position > (arr_size-1) || position < 0)
        return nullptr;
    return arr + position;
}

const Point *PointArray::get(const int position) const
{
    if ( arr_size == 0 || position > (arr_size-1) || position < 0)
        return nullptr;
    return arr + position;
}

int Polygon::num_polygons = 0;

Polygon::Polygon(const Point pnts[], const int numPoints)
{
    this->points = new PointArray(pnts, numPoints);
    ++num_polygons;
}

Polygon::Polygon()
{
    ++num_polygons;
    this->points = new PointArray();
    //points.~PointArray();
    //new(&points) PointArray();
}

Polygon::Polygon(const PointArray &pv)
{
    this->points = new PointArray(pv);
    ++num_polygons;
}

int Polygon::getNumSides() const
{
    return this->points->getSize();
}

Point constructorPoints[4];

Point *updateConstructorPoints(const Point &p1, const Point &p2,
    const Point &p3, const Point &p4 = Point(0,0))
{
    constructorPoints[0] = p1;
    constructorPoints[1] = p2;
    constructorPoints[2] = p3;
    constructorPoints[3] = p4;

    return constructorPoints;
}

Rectangle::Rectangle(Point &p1, Point &p2): Polygon(updateConstructorPoints(p1, p2,
     Point(p1.getX(), p2.getY()), Point(p2.getX(), p1.getY())), 4) {}

Rectangle::Rectangle(int p1_x, int p1_y, int p2_x, int p2_y):
    Polygon(updateConstructorPoints(Point(p1_x, p1_y), Point(p2_x, p2_y),
                                    Point(p1_x, p2_y), Point(p2_x, p1_y)), 4) {}

double Rectangle::area() const
{
    double side_1 = std::abs(points->get(1)->getX() - points->get(2)->getX());
    double side_2 = std::abs(points->get(0)->getY() - points->get(2)->getY());

    return (side_1 * side_2);
}

void Rectangle::PrintPoints()
{
    std::cout << "Point 1 X: "<<points->get(0)->getX() << std::endl;
    std::cout << "Point 1 Y: "<<points->get(0)->getY() << std::endl;
    std::cout << "Point 2 X: "<<points->get(1)->getX() << std::endl;
    std::cout << "Point 2 Y: "<<points->get(1)->getY() << std::endl;
    std::cout << "Point 3 X: "<<points->get(2)->getX() << std::endl;
    std::cout << "Point 3 Y: "<<points->get(2)->getY() << std::endl;
    std::cout << "Point 4 X: "<<points->get(3)->getX() << std::endl;
    std::cout << "Point 4 Y: "<<points->get(3)->getY() << std::endl;

}

Triangle::Triangle(Point &p1, Point &p2, Point &p3):
                    Polygon(updateConstructorPoints(p1, p2, p3), 3) {}

double Triangle::area() const
{
    int dx_01 = points->get(0)->getX() - points->get(1)->getX();
    int dx_12 = points->get(1)->getX() - points->get(2)->getX();
    int dx_20 = points->get(2)->getX() - points->get(0)->getX();
    int dy_01 = points->get(0)->getY() - points->get(1)->getY();
    int dy_12 = points->get(1)->getY() - points->get(2)->getY();
    int dy_20 = points->get(2)->getY() - points->get(0)->getY();

    double a = sqrt(dx_01 * dx_01 + dy_01 * dy_01);
    double b = sqrt(dx_12 * dx_12 + dy_12 * dy_12);
    double c = sqrt(dx_20 * dx_20 + dy_20 * dy_20);

    double s = (a + b + c) / 2;

    return sqrt(s * (s - a) * (s - b) * (s - c));


}

