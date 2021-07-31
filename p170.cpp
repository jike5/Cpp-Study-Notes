// 函数模板案例 -数组排序
#include<iostream>
using namespace std;

template<class T>
void mySort(T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int max = i; // 
        for (int j = i+1; j<len;j++)
        {
            if(arr[max] < arr[j])
            {
                max = j;
            }
        }
        if (max != i)
        {
            T temp = arr[max];
            arr[max] = arr[i];
            arr[i] = temp;

        }
    }
}
// 打印函数的模板
template<class T>
void printArray(T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void test1()
{
    char charArr[] = "bcefa";
    int len = sizeof(charArr) / sizeof(charArr[0]);
    mySort(charArr, len);
    printArray(charArr, len);

    int intArr[]={1,3,2,4,5,7,5};
    int num = sizeof(intArr) / sizeof(intArr[0]);
    mySort(intArr, len);
    printArray(intArr, len);
}

int main(){
    test1();
    system("pause");
    return 0;
}