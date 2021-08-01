#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
#include<string>
#include<ctime>
using namespace std;

class Person
{
public:
    Person(string name, int score)
    {
        m_Name = name;
        m_Score = score;
    }

    string m_Name;
    int m_Score;
};

void printPerson(vector<Person> & v)
{
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << (*it).m_Name << " " << (*it).m_Score << endl;
    }
    cout << endl;
}
void createPerson(vector<Person> &v)
{
    string nameSpeed = "ABCDE";
    for (int i = 0; i < 5; i++)
    {
        string name = "选手";
        name += nameSpeed[i];
        int score = 0;
        Person p(name, score);
        v.push_back(p);
    }
}
void setScore(vector<Person> &v)
{
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        deque<int> d;
        for (int i = 0; i < 10; i++)
        {
            int score = rand() % 41 + 60;
            d.push_back(score);
        }
        sort(d.begin(), d.end());
        d.pop_back();
        d.pop_front();
        int sum = 0;
        for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
        {
            sum += *it;
        }
        int avg = sum / d.size();
        it->m_Score = avg;
    }
}

int main()
{
    // 随机数种子
    srand((unsigned int) time(NULL));
    vector<Person> v;
    createPerson(v);
    printPerson(v);
    setScore(v);
    printPerson(v);
    system("pause");
    return 0;
}