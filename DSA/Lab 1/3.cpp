#include <bits/stdc++.h>
using namespace std;

class Point
{
private:
    double x, y;

public:
    Point()
    {
        x = 0;
        y = 0;
    }
    Point(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
    void setX(double x)
    {
        this->x = x;
    }
    void setY(double y)
    {
        this->y = y;
    }
    double getX() const
    {
        return x;
    }
    double getY() const
    {
        return y;
    }
    /*
     * STUDENT ANSWER
     * TODO: using code template in previous question
     */
};

class Circle
{
private:
    Point center;
    double radius;

public:
    Circle()
    {
        /*
         * STUDENT ANSWER
         * TODO: set zero center's x-y and radius
         */
        this->center.setX(0);
        this->center.setY(0);
        radius = 0;
    }

    Circle(Point center, double radius)
    {
        /*
         * STUDENT ANSWER
         */
        this->center.setX(center.getX());
        this->center.setY(center.getY());
        this->radius = radius;
    }

    Circle(const Circle &circle)
    {
        /*
         * STUDENT ANSWER
         */
        this->radius = circle.getRadius();
        this->center.setX(circle.center.getX());
        this->center.setY(circle.center.getY());
    }

    void setCenter(Point point)
    {
        /*
         * STUDENT ANSWER
         */
        this->center.setX(point.getX());
        this->center.setY(point.getY());
    }

    void setRadius(double radius)
    {
        /*
         * STUDENT ANSWER
         */
        this->radius = radius;
    }

    Point getCenter() const
    {
        /*
         * STUDENT ANSWER
         */
        return center;
    }

    double getRadius() const
    {
        /*
         * STUDENT ANSWER
         */
        return radius;
    }

    void printCircle()
    {
        printf("Center: {%.2f, %.2f} and Radius %.2f\n", this->center.getX(), this->center.getY(), this->radius);
    }
};

int main()
{
    Circle A;
    A.printCircle();
}