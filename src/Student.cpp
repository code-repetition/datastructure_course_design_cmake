#include "Student.h"
#include <sstream>

using std::stringstream;

Student::Student(string name, long long num, unsigned maths,
				 unsigned english, unsigned discrete, unsigned languageC,
				 int average, long total)
{ // 用于测试的手动构造，给定学生信息，计算平均分以及总分，已弃用
	this->name = name;
	this->num = num;
	this->maths = maths;
	this->english = english;
	this->discrete = discrete;
	this->languageC = languageC;
	this->average = (maths + english + discrete + languageC) / 4;
	this->total = maths + english + discrete + languageC;
}
void Student::InitData() // 从键盘获取学生信息
{
	cout << "请输入学生姓名:";
	cin >> name;
	cout << "请输入学生学号:";
	cin >> num;
	cout << "请输入学生高数成绩:";
	cin >> maths;
	cout << "请输入学生英语成绩:";
	cin >> english;
	cout << "请输入学生离散数学成绩:";
	cin >> discrete;
	cout << "请输入学生C语言成绩:";
	cin >> languageC;
	average = (maths + english + discrete + languageC) / 4;
	total = maths + english + discrete + languageC;
}

void Student::show() // 打印学生所有信息
{
	cout << name << " " << num << " "
		 << maths << " " << english << " "
		 << discrete << " " << languageC << " "
		 << average << " " << total << endl;
}

string Student::getName()
{
	return this->name;
}

long long Student::getNum()
{
	return this->num;
}

unsigned Student::getMaths()
{
	return this->maths;
}

unsigned Student::getEnglish()
{
	return this->english;
}

unsigned Student::getDiscrete()
{
	return this->discrete;
}

unsigned Student::getLanguageC()
{
	return this->languageC;
}

ofstream &operator<<(ofstream &fileout, Student &s)
{
	fileout << s.getName() << "  " << s.getNum() << "  "
			<< s.getMaths() << "  " << s.getEnglish() << "  "
			<< s.getDiscrete() << "  " << s.getLanguageC() << "  "
			<< s.average << "  " << s.total << endl;
	return fileout; // 重载ofstream操作符<<
}

ostream &operator<<(ostream &c, Student &s)
{
	cout << s.name << "  " << s.num << "     "
		 << s.maths << "     " << s.english << "     "
		 << s.discrete << "     " << s.languageC << "     "
		 << s.average << "     " << s.total << endl;
	return c; // 重载ostream操作符<<
}
