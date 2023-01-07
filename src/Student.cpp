#include "Student.h"
#include <sstream>

using std::stringstream;

Student::Student(string name, long long num, unsigned maths,
				 unsigned english, unsigned discrete, unsigned languageC,
				 int average, long total)
{ // ���ڲ��Ե��ֶ����죬����ѧ����Ϣ������ƽ�����Լ��ܷ֣�������
	this->name = name;
	this->num = num;
	this->maths = maths;
	this->english = english;
	this->discrete = discrete;
	this->languageC = languageC;
	this->average = (maths + english + discrete + languageC) / 4;
	this->total = maths + english + discrete + languageC;
}
void Student::InitData() // �Ӽ��̻�ȡѧ����Ϣ
{
	cout << "������ѧ������:";
	cin >> name;
	cout << "������ѧ��ѧ��:";
	cin >> num;
	cout << "������ѧ�������ɼ�:";
	cin >> maths;
	cout << "������ѧ��Ӣ��ɼ�:";
	cin >> english;
	cout << "������ѧ����ɢ��ѧ�ɼ�:";
	cin >> discrete;
	cout << "������ѧ��C���Գɼ�:";
	cin >> languageC;
	average = (maths + english + discrete + languageC) / 4;
	total = maths + english + discrete + languageC;
}

void Student::show() // ��ӡѧ��������Ϣ
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
	return fileout; // ����ofstream������<<
}

ostream &operator<<(ostream &c, Student &s)
{
	cout << s.name << "  " << s.num << "     "
		 << s.maths << "     " << s.english << "     "
		 << s.discrete << "     " << s.languageC << "     "
		 << s.average << "     " << s.total << endl;
	return c; // ����ostream������<<
}
