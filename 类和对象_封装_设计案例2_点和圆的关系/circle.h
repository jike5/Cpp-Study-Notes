#pragma once
#include<iostream>
#include"point.h"
class Circle
{
public:
    void setR(int r);
    void setCenter(Point center);
    Point getCenter();
    int getR();
private:
    int m_R;
    Point m_Center;
};