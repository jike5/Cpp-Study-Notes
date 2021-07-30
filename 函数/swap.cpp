#include "swap.h"
#include<iostream>
using namespace std;

void swap(int a, int b) {
	int c;
	c = a;
	a = b;
	b = c;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
}