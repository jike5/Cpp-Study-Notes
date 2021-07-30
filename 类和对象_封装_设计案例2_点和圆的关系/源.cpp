// 设计案例 点和圆的关系
#include<iostream>
#include"circle.h"
#include"point.h"
using namespace std;

//class Point
//{
//public:
//    int getX() { return m_x; }
//    int getY() { return m_y; }
//    void setX(int x) { m_x = x; }
//    void setY(int y) { m_y = y; }
//private:
//    int m_x;
//    int m_y;
//};


//class Circle
//{
//public:
//    void setR(int r) { m_R = r; }
//    void setCenter(Point center) { m_Center = center; }
//    Point getCenter() { return m_Center; }
//    int getR() { return m_R; }
//private:
//    int m_R;
//    Point m_Center;
//};

void isInCircle(Circle& c, Point& p)
{
    int  distance =
        (c.getCenter().getX() - p.getX()) ^ 2 + (c.getCenter().getY() - p.getY()) ^ 2;
    int rDistance = c.getR() ^ 2;
    if (distance > rDistance) { cout << "圆外" << endl; }
    else if (distance < rDistance) { cout << "圆内" << endl; }
}
int main() {
    Circle c;
    c.setR(10);
    Point center;
    center.setX(10);
    center.setY(10);
    c.setCenter(center);

    Point p;
    p.setX(0);
    p.setY(0);

    isInCircle(c, p);

    system("pause");
    return 0;
}