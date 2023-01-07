#pragma once
#ifndef BSTREE_H_
#define BSTREE_H_

#include <iostream>
#include <stack>
#include <tuple>
#include "Student.h"
#include "strMatching.h"

template <typename T>
struct node
{
	Student s;			   // ѧ������
	T key;				   // ���ڵ��ʶ(�ؼ���)
	node *lchild, *rchild; // ���Һ���ָ��
};

template <typename T>
class BSTree // ��������(ģ������)
{

private:
	node<T> *bt; // ˽�г�Ա�������ڵ�����

public:
	BSTree() : bt(nullptr){}; // Ĭ�Ϲ��캯������ʼ���б�ָ������Ϊ��

	~BSTree(); // Ĭ����������

	node<T> *InsertBST(node<T> *root, T k, Student stu); // ��bt�в���һ���ؼ���Ϊk�Ľڵ�

	void InitBST(T *arr, int n); // ��ʼ������������

	void InOrder(node<T> *root); // �����������������

	node<T> *getRoot(); // ��ȡ����

	void refreshRoot(node<T> *); // ˢ������״̬

	void DeleteNode(T k); // ɾ���ڵ�

	void Destroy(node<T> *&root); // �ݻ�����������

	void Savestream(node<T> *, ofstream &); // ���򱣴棬���ڵ��������������

	void Save(); // ���ļ�����������б���

	node<T> *Exactsearch(T); // ��ȷ����

	void Modify(T); // �޸Ľڵ���Ϣ

	void Reverse(); // ����������������������stack

	void reverse_push(node<T> *, std::stack<Student> &); // ����������ڵ�����push��stack��

	void matchingEach(node<T> *, string &); // ģ����Ѱ���ַ���ƥ��

	void ReserveSave(); // ��stack��Ԫ���������,�����е���reverse_push(node<T> *, std::stack<Student> &)

	std::tuple<unsigned, unsigned, unsigned, unsigned,
			   unsigned, unsigned, unsigned, unsigned,
			   unsigned, unsigned, unsigned, unsigned>
	Statistics(node<T> *); // ���ɸ���ͳ����Ϣ�����
};

template <typename T>
BSTree<T>::~BSTree()
{
	Destroy(bt);  // ���ôݻٺ���(�ݹ�)
	bt = nullptr; // �����ÿ�
}

template <typename T>
node<T> *BSTree<T>::InsertBST(node<T> *bt, T k, Student stu)
{
	if (bt == nullptr) // �����Ϊ��
	{
		bt = new node<T>;
		bt->key = k; // �½��ڵ㲢���ñ�ʶ
		bt->s = stu;
		bt->lchild = nullptr;
		bt->rchild = nullptr; // ��ʼ�����Һ���
	}
	else if (k <= bt->key)							// ���������ڵ��ʶֵС�ڵ�ǰ�ڵ�
		bt->lchild = InsertBST(bt->lchild, k, stu); // ����������Ѱ,ֱ����Ѱ��nullptr������
	else if (k > bt->key)							// ���������ڵ��ʶֵ���ڵ�ǰ�ڵ�
		bt->rchild = InsertBST(bt->rchild, k, stu);
	// ����������Ѱ,Ϊnullptrʱ����
	return bt;
}

template <typename T>
void BSTree<T>::InitBST(T *arr, int n) // ��������������
{
	int i = 0;
	while (i < n) // ������Ԫ�ز��뵽������������
	{
		bt = InsertBST(bt, *(arr + i));
		i++;
	}
}

template <typename T>
void BSTree<T>::InOrder(node<T> *bt) // �������������
{
	if (bt != nullptr) // ������Ϊ��ʱִ�в���
	{
		InOrder(bt->lchild);
		if (bt->s.name.size() == 4)
			cout << "  ";
		std::cout << bt->s;
		InOrder(bt->rchild);
	}
}

template <typename T>
node<T> *BSTree<T>::getRoot() // ��ȡ˽�г�Ա��������
{
	return this->bt;
}

template <typename T>
void BSTree<T>::refreshRoot(node<T> *n) // ˢ�µ�ǰ����״̬
{
	bt = n;
}

template <typename T>
void BSTree<T>::DeleteNode(T k) // ��bt��ɾ���ؼ���Ϊk�Ľڵ�
{
	if (bt == nullptr)
	{
		cout << "ѧ����¼Ϊ��" << endl;
		return;
	}
	node<T> *q = bt, *f = nullptr; // fָ��ɾ���ڵ�q��˫�׽ڵ�
	while (q != nullptr)		   // ���ҽڵ�q��ƥ���ʶֵ
	{
		if (q->key == k)
			break; // ƥ���ʶֵ�ɹ�ʱ�˳�
		f = q;
		if (k < q->key)
		{
			q = q->lchild;
		}
		else
		{
			q = q->rchild;
		} // �����ڶ����������Ĳ���,����ֵС�ڵ�ǰ�ڵ�������������,���ڵ�ǰ�ڵ�ֵ������������
	}
	if (q == nullptr) // δ�ҵ�
	{
		cout << "û�д�ѧ��!!!" << endl;
		return;
	}
	// ���ʼ��δƥ��ɹ�,����
	if (q->lchild == nullptr && q->rchild == nullptr) // �����ɾ���Ľڵ���Ҷ�ӽڵ�
	{
		if (q == bt)
		{
			bt = nullptr;
		}
		else
		{
			if (f->lchild == q)
			{
				f->lchild = nullptr;
			}
			else
			{
				f->rchild = nullptr;
			}
		}
		delete q;
	}
	else if (q->rchild == nullptr) // ֻ��������
	{
		if (f == nullptr)
		{
			bt = bt->lchild;
		}
		else
		{
			if (f->lchild = q->lchild)
			{
				f->lchild = q->lchild;
			}
			else
			{
				f->rchild = q->lchild;
			}
		}
		delete q;
	}
	else if (q->lchild == nullptr) // ֻ��������
	{
		if (f == nullptr)
		{
			bt = bt->rchild;
		}
		else
		{
			if (f->lchild == q)
			{
				f->lchild = q->rchild;
			}
			else
			{
				f->rchild = q->rchild;
			}
		}
		delete q;
	}
	else // ���Һ��Ӿ�����
	{
		node<T> *s = q->lchild;
		f = q;
		while (s->rchild != nullptr)
		{
			f = s;
			s = s->rchild;
		}
		q->key = s->key;
		if (s == f->lchild)
		{
			f->lchild = s->lchild;
		}
		else
		{
			f->rchild = s->lchild;
		}
		delete s;
	}
}

template <typename T>
void BSTree<T>::Destroy(node<T> *&root)
{
	if (root != nullptr)
	{
		Destroy(root->lchild);
		Destroy(root->rchild);
		delete root; // �ݹ�ɾ��ÿ���ڵ�
	}
}

template <typename T>
void BSTree<T>::Savestream(node<T> *bt, ofstream &fout)
{
	if (bt != nullptr) // ������Ϊ��ʱִ�в���
	{
		Savestream(bt->lchild, fout);
		if (bt->s.name.size() == 4)
			fout << "   ";			  // �Զ����������и�ʽ����
		fout << bt->s;				  // ������дѧ����Ϣ
		Savestream(bt->rchild, fout); // ����ݹ�
	}
}

template <typename T>
void BSTree<T>::Save()
{
	// �������ͳ����Ϣ����ʱ����
	unsigned mathsave, enave, discreteave, clangave;
	unsigned mathsh, enh, discreteh, clangh;
	unsigned mathsl, enl, discretel, clangl;
	// ��������ݷ���ֵ(ͳ����Ϣ)
	std::tie(mathsave, enave, discreteave, clangave,
			 mathsh, enh, discreteh, clangh,
			 mathsl, enl, discretel, clangl) = Statistics(bt);
	ofstream fout("StudentFile.txt"); // ���ļ���
	Savestream(bt, fout);			  // �����������
	// ����ͳ����Ϣ
	fout << "      ��Ŀ����              ";
	fout << mathsave << "  " << enave << "  " << discreteave << "  " << clangave << endl;
	fout << "       ��߷�                ";
	fout << mathsh << "  " << enh << "  " << discreteh << "  " << clangh << endl;
	fout << "       ��ͷ�                ";
	fout << mathsl << "  " << enl << "  " << discretel << "  " << clangl << endl;
	fout.close();
}

template <typename T>
void BSTree<T>::ReserveSave()
{
	// �������ͳ����Ϣ����ʱ����
	unsigned mathsave, enave, discreteave, clangave;
	unsigned mathsh, enh, discreteh, clangh;
	unsigned mathsl, enl, discretel, clangl;
	// ��������ݷ���ֵ(ͳ����Ϣ)
	std::tie(mathsave, enave, discreteave, clangave,
			 mathsh, enh, discreteh, clangh,
			 mathsl, enl, discretel, clangl) = Statistics(bt);
	ofstream fout("StudentFile.txt"); // ���ļ���
	std::stack<Student> st;			  // ��ʱջ
	reverse_push(bt, st);			  // ������������һ��ѹջ
	while (!st.empty())				  // ȫ����ջ
	{
		if (st.top().name.size() == 4)
			fout << "   "; // ��ʽ����
		fout << st.top();
		st.pop();
	}
	// д��ͳ����Ϣ
	fout << "      ��Ŀ����              ";
	fout << mathsave << "  " << enave << "  " << discreteave << "  " << clangave << endl;
	fout << "       ��߷�                ";
	fout << mathsh << "  " << enh << "  " << discreteh << "  " << clangh << endl;
	fout << "       ��ͷ�                ";
	fout << mathsl << "  " << enl << "  " << discretel << "  " << clangl << endl;
	fout.close();
}

template <typename T>
node<T> *BSTree<T>::Exactsearch(T k)
{
	if (bt == nullptr)
		return nullptr;
	node<T> *q = bt, *f = nullptr; // fָ��ɾ���ڵ�q��˫�׽ڵ�
	while (q != nullptr)		   // ���ҽڵ�q��ƥ���ʶֵ
	{
		if (q->key == k)
			break; // ƥ���ʶֵ�ɹ�ʱ�˳�
		f = q;
		if (k < q->key)
		{
			q = q->lchild;
		}
		else
		{
			q = q->rchild;
		} // �����ڶ����������Ĳ���,����ֵС�ڵ�ǰ�ڵ�������������,���ڵ�ǰ�ڵ�ֵ������������
	}
	if (q == nullptr)
		return nullptr;
	return q;
}

template <>
inline void BSTree<long long>::Modify(long long k) // ģ���ػ�long long�����ڹؼ���ѧ��
{
	node<long long> *node; // ��ʱ�ڵ�
	node = Exactsearch(k);
	if (node == nullptr)
	{
		cout << "δ�ҵ�,������!!!" << endl;
		return;
	} // δ�ҵ�Ҫ�޸ĵĽڵ�ֱ���˳�
	else
	{
		cout << endl;
		cout << "ԭʼ��¼Ϊ:" << endl;
		cout << node->s;			  // ��ӡԭʼ��Ϣ
		Student s;					  // ��ʱ����һ��student
		s = node->s;				  // ��������
		DeleteNode(k);				  // ɾ��ָ���ڵ�
		s.InitData();				  // ��ʽ�ֶ�����student
		bt = InsertBST(bt, s.num, s); // ����student����
	}
}

template <>
inline void BSTree<string>::Modify(string k) // ģ���ػ�string�������ڹؼ�������
{											 // ����ע��ͬ��
	node<string> *node;
	node = Exactsearch(k);
	if (node == nullptr)
	{
		cout << "δ�ҵ�,������!!!" << endl;
		return;
	}
	else
	{
		cout << endl;
		cout << "ԭʼ��¼Ϊ:" << endl;
		cout << node->s;
		Student s;
		s = node->s;
		DeleteNode(k);
		s.InitData();
		bt = InsertBST(bt, s.name, s);
	}
}

template <typename T>
void BSTree<T>::Reverse()
{
	std::stack<Student> st; // ��ʱջ
	reverse_push(bt, st);	// ������������һ��ѹջ
	while (!st.empty())		// ��ջ����
	{
		/*Student t = Exactsearch(st.top());*/
		if (st.top().name.size() == 4)
			cout << "  "; // ��ʽ����
		cout << st.top();
		st.pop();
	}
}

template <typename T>
void BSTree<T>::reverse_push(node<T> *root, std::stack<Student> &st)
{
	if (root != nullptr) // ������Ϊ��ʱִ�в���
	{
		reverse_push(root->lchild, st);
		/*cout << bt->s;*/
		st.push(root->s); // �ݹ���������������ѹջ
		reverse_push(root->rchild, st);
	}
}

template <>
inline void BSTree<long long>::matchingEach(node<long long> *root, string &p)
{						 // ģ���ػ�long long
	if (root != nullptr) // ������Ϊ��ʱִ�в���
	{					 // �ݹ����������
		matchingEach(root->lchild, p);
		string str = longltoString(root->s.num); // ��long long����ת��Ϊstring
		if (KmpSearch(str, p))					 // kmpƥ��,ƥ��ɹ���ӡ
		{
			if (root->s.name.size() == 4)
				cout << "  "; // ��ʽ����
			cout << root->s;
		}
		matchingEach(root->rchild, p);
	}
}

template <>
inline void BSTree<string>::matchingEach(node<string> *root, string &p)
{						 // ģ���ػ�string,ע��ͬ��
	if (root != nullptr) // ������Ϊ��ʱִ�в���
	{
		matchingEach(root->lchild, p);
		string str = root->s.name;
		if (KmpSearch(str, p))
		{
			if (root->s.name.size() == 4)
				cout << "  ";
			cout << root->s;
		}
		matchingEach(root->rchild, p);
	}
}

template <typename T>
auto BSTree<T>::Statistics(node<T> *root) -> std::tuple<unsigned, unsigned, unsigned, unsigned,
														unsigned, unsigned, unsigned, unsigned,
														unsigned, unsigned, unsigned, unsigned>
{																							// ����ͳ����Ϣ,ʹ��std::tuple���
	static unsigned count = 0, mathsall = 0, englishall = 0, discreteall = 0, clangall = 0; // ������ͷ��Լ���¼����
	static unsigned mathsh = 0, enh = 0, discreteh = 0, clangh = 0;							// ������߷�
	static unsigned mathsl = 100, enl = 100, discretel = 100, clangl = 100;					// ������ͷ�
	if (root != nullptr)
	{ // �ݹ����������
		Statistics(root->lchild);
		count++;
		mathsall += root->s.maths;
		englishall += root->s.english;
		discreteall += root->s.discrete;
		clangall += root->s.languageC; // �Ը��Ƴɼ����
		if (root->s.maths > mathsh)
			mathsh = root->s.maths; // ��ȡ�ϴ�ֵ,��ͬ
		if (root->s.maths < mathsl)
			mathsl = root->s.maths; // ��ȡ��Сֵ,��ͬ

		if (root->s.english > enh)
			enh = root->s.english;
		if (root->s.english < enl)
			enl = root->s.english;

		if (root->s.discrete > discreteh)
			discreteh = root->s.discrete;
		if (root->s.discrete < discretel)
			discretel = root->s.discrete;

		if (root->s.languageC > clangh)
			clangh = root->s.languageC;
		if (root->s.languageC < clangl)
			clangl = root->s.languageC;

		Statistics(root->rchild);
	}
	if (count != 0)
		return {mathsall / count, englishall / count, discreteall / count, clangall / count,
				mathsh, enh, discreteh, clangh,
				mathsl, enl, discretel, clangl}; // ����ͳ����Ϣ
}
#endif
