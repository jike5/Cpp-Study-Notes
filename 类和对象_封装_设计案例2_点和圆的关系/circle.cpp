#include"circle.h"

void Circle::setR(int r) { m_R = r; }
void Circle::setCenter(Point center) { m_Center = center; }
Point Circle::getCenter() { return m_Center; }
int Circle::getR() { return m_R; }