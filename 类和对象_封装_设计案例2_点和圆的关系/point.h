#pragma once
#include<iostream>
using namespace std;

class Point
{
public:
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
private:
    int m_x;
    int m_y;
};