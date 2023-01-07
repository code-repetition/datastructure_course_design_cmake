#pragma once
#ifndef USERREACTION_H_
#define USERREACTION_H_

#include "Student.h"
#include <vector>
#include "BSTree.h"
#include "fileHandle.h"

using std::vector;

void globalInsert(vector<Student> &); // �ں����ڹ���student�����뵽vector�У�����ʹ�ã�������

void globalShow(const vector<Student> &); // ��vectorֱ�Ӵ�ӡ����ѧ����Ϣ�����ԣ�������

void globalInsert(vector<Student> &, Student); // ������õ�student���뵽vector�У�������

void numModel(); // ��ѧ��Ϊ�ؼ���,���������

void nameModel(); // ������Ϊ�ؼ���

void mathsModel(); // �Ը���Ϊ�ؼ���

void englishModel(); // Ӣ��ؼ���

void discreteModel(); // ��ɢ�ؼ���

void cModel(); // c���Թؼ���

void aveModel(); // ƽ���ֹؼ���

void totalModel(); // �ֹܷؼ���

template <typename T>
void showModel(BSTree<T> &tree) // ѡ���ӡģʽ������/����
{
	// �������ƽ�����������С��ʱ�洢����
	unsigned mathsave, enave, discreteave, clangave;
	unsigned mathsh, enh, discreteh, clangh;
	unsigned mathsl, enl, discretel, clangl;
	// ʹ��std::tie��std::tuple���н��(����ֵ����)
	std::tie(mathsave, enave, discreteave, clangave,
			 mathsh, enh, discreteh, clangh,
			 mathsl, enl, discretel, clangl) = tree.Statistics(tree.getRoot());
	system("cls");
	cout << "1������|2������" << endl;
	cout << "��ѡ��:" << endl;
	int listchoice;
	cin >> listchoice;
	cout << "����"
		 << "       "
		 << "ѧ��"
		 << "       "
		 << "����"
		 << "   "
		 << "Ӣ��"
		 << "   "
		 << "��ɢ"
		 << "   "
		 << "C����"
		 << " "
		 << "ƽ����"
		 << "  "
		 << "�ܷ�" << endl;
	switch (listchoice)
	{
	case 1:
		// �����ӡ������ӡͳ����Ϣ
		tree.InOrder(tree.getRoot());
		cout << "      ��Ŀ����         ";
		cout << mathsave << "     " << enave << "     " << discreteave << "     " << clangave << endl;
		cout << "       ��߷�          ";
		cout << mathsh << "     " << enh << "     " << discreteh << "     " << clangh << endl;
		cout << "       ��ͷ�          ";
		cout << mathsl << "     " << enl << "     " << discretel << "     " << clangl << endl;
		return;
	case 2:
		// �����ӡ������ӡͳ����Ϣ
		tree.Reverse();
		cout << "      ��Ŀ����         ";
		cout << mathsave << "     " << enave << "     " << discreteave << "     " << clangave << endl;
		cout << "       ��߷�          ";
		cout << mathsh << "     " << enh << "     " << discreteh << "     " << clangh << endl;
		cout << "       ��ͷ�          ";
		cout << mathsl << "     " << enl << "     " << discretel << "     " << clangl << endl;
		return;
	}
}

template <typename T>
void saveModel(BSTree<T> &tree) // ����ģʽѡ������/����
{
	system("cls");
	cout << "1������|2������" << endl;
	cout << "��ѡ��:" << endl;
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
