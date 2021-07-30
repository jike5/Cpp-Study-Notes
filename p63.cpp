// 冒泡排序的实现
#include<iostream>
using namespace std;

void bubbleSort(int *arr, int len)
{
    for (int i=0; i<len-1; i++)
    {
        for(int j=0; j<len-i-1;j++)
        {
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
}

int main()
{
    int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int len = sizeof(arr) / sizeof(arr[0]);
    cout << "len=" << len << endl;
    // 冒泡排序函数
    bubbleSort(arr, len);
    for (int i=0; i<len; i++)
    {
        cout << arr[i] << endl;
    }
    system("pause");
    return 0;
}