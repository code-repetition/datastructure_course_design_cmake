#include "fileHandle.h"

int getDataNum()
{
	ifstream infile("StudentFile.txt"); // �˴�Ĭ�ϵ��ļ��򿪷�ʽΪ��������ķ�ʽ�򿪡�
	char str[1024];						// N�Ƕ���ĳ�����Ŀ����Ϊ�˶�ȡ�㹻������
	int n = 0;							// ������ʾ˵��/д�ı�������
	while (!infile.eof())
	{
		infile.getline(str, sizeof(str)); // �˴�Ĭ�ϵ���ֹ��ʶ��Ϊ��\n��
		n++;
	}
	return n;
}

void loadInfo(vector<Student> &v)
{ // ���ļ���ȡѧ����Ϣ
	ifstream fin("StudentFile.txt");
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			Student stu;			   // ��ʱѧ������
			char buffer[1024] = {0};   // ����
			fin.getline(buffer, 1024); // ��ȡһ��
			stringstream ss(buffer);   // ʹ��stringstream����buffer
			ss >> stu.name;
			if (stu.name == "" || stu.name == "��Ŀ����" || stu.name == "��߷�" || stu.name == "��ͷ�")
				continue; // ������Ϣ
			ss >> stu.num >> stu.maths >> stu.english >> stu.discrete >> stu.languageC >> stu.average >> stu.total;
			/*stu.average = (stu.maths + stu.english + stu.discrete + stu.languageC) / 4;
			stu.total = stu.maths + stu.english + stu.discrete + stu.languageC;*/
			v.push_back(stu); // ����ȡ������Ϣ�洢
		}
	}
	fin.close();
}

void globalSave(const vector<Student> &v) // ��vectorֱ��д���ļ�,������
{
	ofstream fout("StudentFile.txt");
	if (fout.is_open())
	{
		for (auto e : v)
		{
			fout << e;
		}
	}
	fout.close();
}

void spawnStatistics() // ����
{
	ofstream fout("Statistics.txt");
}
