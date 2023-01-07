#pragma once
#ifndef STUDENT_H_
#define STUDENT_H_
#include <string>
#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::ios;
using std::ofstream;
using std::ostream;
using std::string;

class Student // 学生类
{
public:
    string name;        // 姓名
    long long num;      // 学号，为避免字符串“8”>“3210”此类情况，需要比较学号绝对字面量，故定义为long long，同时防止过大溢出
    unsigned maths;     // 高数
    unsigned english;   // 英语
    unsigned discrete;  // 离散数学
    unsigned languageC; // C语言
    int average;        // 平均分
    long total;         // 总分

    Student() {}                                                                   // 默认空构造函数
    Student(string, long long, unsigned, unsigned, unsigned, unsigned, int, long); // 手动构造，用于测试

    ~Student() {} // 默认析构函数

    void InitData(); // 初始化学生信息，显式调用

    void show(); // 打印学生全部信息,遗留函数，未弃用，对ostream的重载可替代

    string getName(); // 获取姓名

    long long getNum(); // 获取学号

    unsigned getMaths(); // 获取高数成绩

    unsigned getEnglish(); // 获取英语成绩

    unsigned getDiscrete(); // 获取离散成绩

    unsigned getLanguageC(); // 获取c语言成绩

    friend ofstream &operator<<(ofstream &, Student &); // 对ofstream对象操作符<<进行重载，下类似

    friend ostream &operator<<(ostream &, Student &);

    bool operator==(Student &s) // 重载了student对象的==运算符，用于判断两个student对象是否对等，测试使用(弃用)
    {
        if (this->name == s.name &&
            this->num == s.num &&
            this->maths == s.maths &&
            this->english == s.english &&
            this->discrete == s.discrete &&
            this->languageC == s.languageC &&
            this->average == s.average &&
            this->total == s.total)
        {
            return true;
        }
        return false;
    }
};

#endif
