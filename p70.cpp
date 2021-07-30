#include<iostream>
using namespace std;
#include<string>

struct  Hero
{
    string name;
    int age;
    string sex;
};

void bubbleSort(Hero arr[], int len) // 这里传入的是数组首地址，即为指针，因此，形参为arr[]
{
    for (int i = 0; i < len; i++)
    {
        for(int j = 0; j < len-i-1; j++)
        {
            if (arr[j].age > arr[j+1].age)
            {
                Hero temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    Hero heroArray[5] = 
    {
        {"LiuBei", 23, "Male"},
        {"Guanyu", 22, "Male"},
        {"Zhangfei", 20, "Male"},
        {"Zhaoyun", 21, "Male"},
        {"Diaochan", 19, "Female"}
    };
    int len = sizeof(heroArray) / sizeof(heroArray[0]);
    bubbleSort(heroArray, len);
    for(int i = 0; i < len; i++)
    {
        cout << "Name:" << heroArray[i].name << "age" << heroArray[i].age << endl;
    }
    system("pause");
    return 0;
}
