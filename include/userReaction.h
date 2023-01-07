#pragma once
#ifndef USERREACTION_H_
#define USERREACTION_H_

#include "Student.h"
#include <vector>
#include "BSTree.h"
#include "fileHandle.h"

using std::vector;

void globalInsert(vector<Student> &); // 在函数内构造student并插入到vector中，测试使用，已弃用

void globalShow(const vector<Student> &); // 从vector直接打印所有学生信息，测试，已弃用

void globalInsert(vector<Student> &, Student); // 将构造好的student插入到vector中，已弃用

void numModel(); // 以学号为关键字,构造二叉树

void nameModel(); // 以姓名为关键字

void mathsModel(); // 以高数为关键字

void englishModel(); // 英语关键字

void discreteModel(); // 离散关键字

void cModel(); // c语言关键字

void aveModel(); // 平均分关键字

void totalModel(); // 总分关键字

template <typename T>
void showModel(BSTree<T> &tree) // 选择打印模式，正序/逆序
{
	// 定义各科平均，最大与最小临时存储变量
	unsigned mathsave, enave, discreteave, clangave;
	unsigned mathsh, enh, discreteh, clangh;
	unsigned mathsl, enl, discretel, clangl;
	// 使用std::tie对std::tuple进行解包(返回值传递)
	std::tie(mathsave, enave, discreteave, clangave,
			 mathsh, enh, discreteh, clangh,
			 mathsl, enl, discretel, clangl) = tree.Statistics(tree.getRoot());
	system("cls");
	cout << "1、正序|2、逆序" << endl;
	cout << "请选择:" << endl;
	int listchoice;
	cin >> listchoice;
	cout << "姓名"
		 << "       "
		 << "学号"
		 << "       "
		 << "高数"
		 << "   "
		 << "英语"
		 << "   "
		 << "离散"
		 << "   "
		 << "C语言"
		 << " "
		 << "平均分"
		 << "  "
		 << "总分" << endl;
	switch (listchoice)
	{
	case 1:
		// 正序打印，并打印统计信息
		tree.InOrder(tree.getRoot());
		cout << "      科目均分         ";
		cout << mathsave << "     " << enave << "     " << discreteave << "     " << clangave << endl;
		cout << "       最高分          ";
		cout << mathsh << "     " << enh << "     " << discreteh << "     " << clangh << endl;
		cout << "       最低分          ";
		cout << mathsl << "     " << enl << "     " << discretel << "     " << clangl << endl;
		return;
	case 2:
		// 逆序打印，并打印统计信息
		tree.Reverse();
		cout << "      科目均分         ";
		cout << mathsave << "     " << enave << "     " << discreteave << "     " << clangave << endl;
		cout << "       最高分          ";
		cout << mathsh << "     " << enh << "     " << discreteh << "     " << clangh << endl;
		cout << "       最低分          ";
		cout << mathsl << "     " << enl << "     " << discretel << "     " << clangl << endl;
		return;
	}
}

template <typename T>
void saveModel(BSTree<T> &tree) // 保存模式选择，正序/逆序
{
	system("cls");
	cout << "1、正序|2、逆序" << endl;
	cout << "请选择:" << endl;
	int listchoice;
	cin >> listchoice;
	switch (listchoice)
	{
	case 1:
		tree.Save();
		return;
	case 2:
		tree.ReserveSave();
		return;
	}
}

#endif
