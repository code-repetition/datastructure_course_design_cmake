#include "fileHandle.h"

int getDataNum()
{
	ifstream infile("StudentFile.txt"); // 此处默认的文件打开方式为“以输出的方式打开”
	char str[1024];						// N是定义的常数，目的是为了读取足够长的行
	int n = 0;							// 用来表示说读/写文本的行数
	while (!infile.eof())
	{
		infile.getline(str, sizeof(str)); // 此处默认的终止标识符为‘\n’
		n++;
	}
	return n;
}

void loadInfo(vector<Student> &v)
{ // 从文件读取学生信息
	ifstream fin("StudentFile.txt");
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			Student stu;			   // 临时学生对象
			char buffer[1024] = {0};   // 缓存
			fin.getline(buffer, 1024); // 获取一行
			stringstream ss(buffer);   // 使用stringstream解析buffer
			ss >> stu.name;
			if (stu.name == "" || stu.name == "科目均分" || stu.name == "最高分" || stu.name == "最低分")
				continue; // 过滤信息
			ss >> stu.num >> stu.maths >> stu.english >> stu.discrete >> stu.languageC >> stu.average >> stu.total;
			/*stu.average = (stu.maths + stu.english + stu.discrete + stu.languageC) / 4;
			stu.total = stu.maths + stu.english + stu.discrete + stu.languageC;*/
			v.push_back(stu); // 将获取到的信息存储
		}
	}
	fin.close();
}

void globalSave(const vector<Student> &v) // 从vector直接写入文件,已弃用
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

void spawnStatistics() // 弃用
{
	ofstream fout("Statistics.txt");
}
