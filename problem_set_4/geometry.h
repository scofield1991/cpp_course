#ifndef GEOMETRY_H_INCLUDED
#define GEOMETRY_H_INCLUDED

class Point
{
    int x, y;
public:
    Point(int p1=0, int p2=0): x(p1), y(p2) {};

    int getX() const { return x; }
    int getY() const { return y; }

    void setX(const int new_x) { x = new_x; };
    void setY(const int new_y) { y = new_y; };
};

class PointArray
{
    Point *arr;
    int arr_size;

    void resize_arr(int n);
public:
    PointArray();
    PointArray(const Point points[], const int size_arr);
    PointArray(const PointArray& pv);
    ~PointArray();
    void push_back(const Point &p);
    void insert(const int position, const Point &p);
    void remove(const int pos);
    const int getSize() const;
    void clear();
    Point* get(const int position);
    const Point* get(const int position) const;

};

class Polygon
{
protected:
    PointArray* points;
    static int num_polygons;
public:
    Polygon();
    Polygon(const Point points[], const int numPoints);
    Polygon(const PointArray& pv);
    virtual double area() const = 0;
    static int getNumPolygons() { return num_polygons; }
    int getNumSides() const;
    PointArray* getPoints() const{ return this->points; }

};

class Rectangle: public Polygon
{
public:
    Rectangle(Point &p1, Point &p2);
    Rectangle(int p1_x, int p1_y, int p2_x, int p2_y);
    void PrintPoints();
    double area() const;
};

class Triangle: public Polygon
{
public:
    Triangle(Point &p1, Point &p2, Point &p3);
    double area() const;
};


#endif // GEOMETRY_H_INCLUDED
