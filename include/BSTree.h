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
	Student s;			   // 学生本体
	T key;				   // 树节点标识(关键字)
	node *lchild, *rchild; // 左右孩子指针
};

template <typename T>
class BSTree // 二叉树类(模板容器)
{

private:
	node<T> *bt; // 私有成员变量，节点树根

public:
	BSTree() : bt(nullptr){}; // 默认构造函数，初始化列表指定树根为空

	~BSTree(); // 默认析构函数

	node<T> *InsertBST(node<T> *root, T k, Student stu); // 在bt中插入一个关键字为k的节点

	void InitBST(T *arr, int n); // 初始化树，已弃用

	void InOrder(node<T> *root); // 中序遍历二叉排序树

	node<T> *getRoot(); // 获取树根

	void refreshRoot(node<T> *); // 刷新树的状态

	void DeleteNode(T k); // 删除节点

	void Destroy(node<T> *&root); // 摧毁树用于析构

	void Savestream(node<T> *, ofstream &); // 正序保存，将节点依次输出到流中

	void Save(); // 打开文件输出流并进行保存

	node<T> *Exactsearch(T); // 精确查找

	void Modify(T); // 修改节点信息

	void Reverse(); // 逆序输出，基于中序遍历与stack

	void reverse_push(node<T> *, std::stack<Student> &); // 将中序遍历节点依次push到stack中

	void matchingEach(node<T> *, string &); // 模糊搜寻，字符串匹配

	void ReserveSave(); // 将stack的元素依次输出,函数中调用reverse_push(node<T> *, std::stack<Student> &)

	std::tuple<unsigned, unsigned, unsigned, unsigned,
			   unsigned, unsigned, unsigned, unsigned,
			   unsigned, unsigned, unsigned, unsigned>
	Statistics(node<T> *); // 生成各科统计信息并打包
};

template <typename T>
BSTree<T>::~BSTree()
{
	Destroy(bt);  // 调用摧毁函数(递归)
	bt = nullptr; // 将树置空
}

template <typename T>
node<T> *BSTree<T>::InsertBST(node<T> *bt, T k, Student stu)
{
	if (bt == nullptr) // 如果树为空
	{
		bt = new node<T>;
		bt->key = k; // 新建节点并设置标识
		bt->s = stu;
		bt->lchild = nullptr;
		bt->rchild = nullptr; // 初始化左右孩子
	}
	else if (k <= bt->key)							// 如果待插入节点标识值小于当前节点
		bt->lchild = InsertBST(bt->lchild, k, stu); // 向左子树搜寻,直到搜寻到nullptr处插入
	else if (k > bt->key)							// 如果待插入节点标识值大于当前节点
		bt->rchild = InsertBST(bt->rchild, k, stu);
	// 向右子树搜寻,为nullptr时插入
	return bt;
}

template <typename T>
void BSTree<T>::InitBST(T *arr, int n) // 创建二叉排序树
{
	int i = 0;
	while (i < n) // 将数组元素插入到二叉排序树中
	{
		bt = InsertBST(bt, *(arr + i));
		i++;
	}
}

template <typename T>
void BSTree<T>::InOrder(node<T> *bt) // 中序遍历二叉树
{
	if (bt != nullptr) // 当树不为空时执行操作
	{
		InOrder(bt->lchild);
		if (bt->s.name.size() == 4)
			cout << "  ";
		std::cout << bt->s;
		InOrder(bt->rchild);
	}
}

template <typename T>
node<T> *BSTree<T>::getRoot() // 获取私有成员变量树根
{
	return this->bt;
}

template <typename T>
void BSTree<T>::refreshRoot(node<T> *n) // 刷新当前树的状态
{
	bt = n;
}

template <typename T>
void BSTree<T>::DeleteNode(T k) // 在bt中删除关键字为k的节点
{
	if (bt == nullptr)
	{
		cout << "学生记录为空" << endl;
		return;
	}
	node<T> *q = bt, *f = nullptr; // f指向被删除节点q的双亲节点
	while (q != nullptr)		   // 查找节点q，匹配标识值
	{
		if (q->key == k)
			break; // 匹配标识值成功时退出
		f = q;
		if (k < q->key)
		{
			q = q->lchild;
		}
		else
		{
			q = q->rchild;
		} // 类似于二叉排序树的插入,搜索值小于当前节点向左子树搜索,大于当前节点值向右子树搜索
	}
	if (q == nullptr) // 未找到
	{
		cout << "没有此学生!!!" << endl;
		return;
	}
	// 如果始终未匹配成功,返回
	if (q->lchild == nullptr && q->rchild == nullptr) // 如果待删除的节点是叶子节点
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
	else if (q->rchild == nullptr) // 只有左子树
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
	else if (q->lchild == nullptr) // 只有右子树
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
	else // 左右孩子均存在
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
		delete root; // 递归删除每个节点
	}
}

template <typename T>
void BSTree<T>::Savestream(node<T> *bt, ofstream &fout)
{
	if (bt != nullptr) // 当树不为空时执行操作
	{
		Savestream(bt->lchild, fout);
		if (bt->s.name.size() == 4)
			fout << "   ";			  // 对二字姓名进行格式控制
		fout << bt->s;				  // 向流中写学生信息
		Savestream(bt->rchild, fout); // 中序递归
	}
}

template <typename T>
void BSTree<T>::Save()
{
	// 定义接受统计信息的临时变量
	unsigned mathsave, enave, discreteave, clangave;
	unsigned mathsh, enh, discreteh, clangh;
	unsigned mathsl, enl, discretel, clangl;
	// 解包，传递返回值(统计信息)
	std::tie(mathsave, enave, discreteave, clangave,
			 mathsh, enh, discreteh, clangh,
			 mathsl, enl, discretel, clangl) = Statistics(bt);
	ofstream fout("StudentFile.txt"); // 打开文件流
	Savestream(bt, fout);			  // 中序遍历保存
	// 保存统计信息
	fout << "      科目均分              ";
	fout << mathsave << "  " << enave << "  " << discreteave << "  " << clangave << endl;
	fout << "       最高分                ";
	fout << mathsh << "  " << enh << "  " << discreteh << "  " << clangh << endl;
	fout << "       最低分                ";
	fout << mathsl << "  " << enl << "  " << discretel << "  " << clangl << endl;
	fout.close();
}

template <typename T>
void BSTree<T>::ReserveSave()
{
	// 定义接受统计信息的临时变量
	unsigned mathsave, enave, discreteave, clangave;
	unsigned mathsh, enh, discreteh, clangh;
	unsigned mathsl, enl, discretel, clangl;
	// 解包，传递返回值(统计信息)
	std::tie(mathsave, enave, discreteave, clangave,
			 mathsh, enh, discreteh, clangh,
			 mathsl, enl, discretel, clangl) = Statistics(bt);
	ofstream fout("StudentFile.txt"); // 打开文件流
	std::stack<Student> st;			  // 临时栈
	reverse_push(bt, st);			  // 将中序遍历结果一次压栈
	while (!st.empty())				  // 全部出栈
	{
		if (st.top().name.size() == 4)
			fout << "   "; // 格式控制
		fout << st.top();
		st.pop();
	}
	// 写入统计信息
	fout << "      科目均分              ";
	fout << mathsave << "  " << enave << "  " << discreteave << "  " << clangave << endl;
	fout << "       最高分                ";
	fout << mathsh << "  " << enh << "  " << discreteh << "  " << clangh << endl;
	fout << "       最低分                ";
	fout << mathsl << "  " << enl << "  " << discretel << "  " << clangl << endl;
	fout.close();
}

template <typename T>
node<T> *BSTree<T>::Exactsearch(T k)
{
	if (bt == nullptr)
		return nullptr;
	node<T> *q = bt, *f = nullptr; // f指向被删除节点q的双亲节点
	while (q != nullptr)		   // 查找节点q，匹配标识值
	{
		if (q->key == k)
			break; // 匹配标识值成功时退出
		f = q;
		if (k < q->key)
		{
			q = q->lchild;
		}
		else
		{
			q = q->rchild;
		} // 类似于二叉排序树的插入,搜索值小于当前节点向左子树搜索,大于当前节点值向右子树搜索
	}
	if (q == nullptr)
		return nullptr;
	return q;
}

template <>
inline void BSTree<long long>::Modify(long long k) // 模板特化long long适用于关键字学号
{
	node<long long> *node; // 临时节点
	node = Exactsearch(k);
	if (node == nullptr)
	{
		cout << "未找到,请重试!!!" << endl;
		return;
	} // 未找到要修改的节点直接退出
	else
	{
		cout << endl;
		cout << "原始记录为:" << endl;
		cout << node->s;			  // 打印原始信息
		Student s;					  // 临时构造一个student
		s = node->s;				  // 制作副本
		DeleteNode(k);				  // 删除指定节点
		s.InitData();				  // 显式手动构造student
		bt = InsertBST(bt, s.num, s); // 将新student插入
	}
}

template <>
inline void BSTree<string>::Modify(string k) // 模板特化string，适用于关键字姓名
{											 // 下面注释同上
	node<string> *node;
	node = Exactsearch(k);
	if (node == nullptr)
	{
		cout << "未找到,请重试!!!" << endl;
		return;
	}
	else
	{
		cout << endl;
		cout << "原始记录为:" << endl;
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
	std::stack<Student> st; // 临时栈
	reverse_push(bt, st);	// 将中序遍历结果一次压栈
	while (!st.empty())		// 出栈至空
	{
		/*Student t = Exactsearch(st.top());*/
		if (st.top().name.size() == 4)
			cout << "  "; // 格式控制
		cout << st.top();
		st.pop();
	}
}

template <typename T>
void BSTree<T>::reverse_push(node<T> *root, std::stack<Student> &st)
{
	if (root != nullptr) // 当树不为空时执行操作
	{
		reverse_push(root->lchild, st);
		/*cout << bt->s;*/
		st.push(root->s); // 递归中序遍历，将结果压栈
		reverse_push(root->rchild, st);
	}
}

template <>
inline void BSTree<long long>::matchingEach(node<long long> *root, string &p)
{						 // 模板特化long long
	if (root != nullptr) // 当树不为空时执行操作
	{					 // 递归遍历二叉树
		matchingEach(root->lchild, p);
		string str = longltoString(root->s.num); // 将long long类型转换为string
		if (KmpSearch(str, p))					 // kmp匹配,匹配成功打印
		{
			if (root->s.name.size() == 4)
				cout << "  "; // 格式控制
			cout << root->s;
		}
		matchingEach(root->rchild, p);
	}
}

template <>
inline void BSTree<string>::matchingEach(node<string> *root, string &p)
{						 // 模板特化string,注释同上
	if (root != nullptr) // 当树不为空时执行操作
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
{																							// 生成统计信息,使用std::tuple打包
	static unsigned count = 0, mathsall = 0, englishall = 0, discreteall = 0, clangall = 0; // 各科最低分以及记录个数
	static unsigned mathsh = 0, enh = 0, discreteh = 0, clangh = 0;							// 各科最高分
	static unsigned mathsl = 100, enl = 100, discretel = 100, clangl = 100;					// 各科最低分
	if (root != nullptr)
	{ // 递归遍历二叉树
		Statistics(root->lchild);
		count++;
		mathsall += root->s.maths;
		englishall += root->s.english;
		discreteall += root->s.discrete;
		clangall += root->s.languageC; // 对各科成绩求和
		if (root->s.maths > mathsh)
			mathsh = root->s.maths; // 获取较大值,下同
		if (root->s.maths < mathsl)
			mathsl = root->s.maths; // 获取较小值,下同

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
				mathsl, enl, discretel, clangl}; // 返回统计信息
}
#endif
