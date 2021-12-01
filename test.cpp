#include<iostream>
#include<iomanip>
#include<string>
#include<map>
#include<random>

using namespace std;

int main(){
    
    std::random_device rd;
    std::mt19937 e2(rd());
    std::normal_distribution<> dist(0, 100);
    
    for(int i = 0; i < 100; i++)
    {
        double a = dist(e2);
        a = a < -100 ? -100 : a;
        a = a > 100 ? 100 : a;
        std::cout <<"a" << i <<" = " << a << endl;
    }
    
    system("pause");
    return 0;
}