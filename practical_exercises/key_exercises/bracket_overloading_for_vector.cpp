/* 中括号重载.cpp 
使用string替代 char* 
使用vector替代指针数组
修改遍历方式*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;
struct Person
{ // 职工基本信息的结构
    double salary;
    string name;
    Person(){}
    Person(double Salary, string Name) : salary(Salary), name(Name){}
};
class SalaryManaege
{
    vector<Person> emp; //存放职工信息的容器
public:
    SalaryManaege(){}
    // 返回引用特性是可以直接在放在左值，直接使用
    double &operator[](string Name)
    { // 重载[]，返回引用
        //如果存在
        for (auto p : emp) {
            if (p.name.compare(Name) == 0)
                return p.salary;
        }
        //不存在情况
        emp.push_back(Person(0, Name));
        return emp.back().salary;
    }

    void display()
    {
        for (auto e : emp)
            cout << e.name << " : " << e.salary << endl;
    }
};

int main()
{
    SalaryManaege s;
    s["zhangsan"] = 2188.88;
    s["lisi"] = 1230.07;
    s["wangwu"] = 3200.97;
    cout << "zhangsan\t" << s["zhangsan"] << endl;
    cout << "lisi\t" << s["lisi"] << endl;
    cout << "wangwu\t" << s["wangwu"] << endl;

    cout << "-------display--------\n\n";
    s.display();
}
