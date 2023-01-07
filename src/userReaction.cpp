#include "userReaction.h"

void globalInsert(vector<Student> &v) // 弃用,函数原型已说明
{
	Student s;
	s.InitData();
	v.push_back(s);
}

void globalInsert(vector<Student> &v, Student s) // 弃用,函数原型已说明
{
	v.push_back(s);
}

void globalShow(const vector<Student> &v) // 弃用,函数原型已说明
{
	for (auto e : v)
	{
		e.show();
	}
}

void numModel()
{							// 各个模式仅有模板类参数，临时变量类型不同以及插入树的关键字不同，其余均类似，注释仅在此函数中给出，下方均类似
	vector<Student> slist;	// 临时载入vector
	loadInfo(slist);		// 从文件读取
	BSTree<long long> tree; // 实例化模板类long long(学号)
	Student s;				// 临时学生对象
	node<long long> *node;	// 临时节点
	string str;				// 临时string
	long long temp;			// 临时变量
	for (auto e : slist)
	{ // 将vector中的学生对象依次插入到树中
		tree.refreshRoot(tree.InsertBST(tree.getRoot(), e.num, e));
	}
	int choice;
	while (true)
	{
		cout << "                                    关键字[学号],请以学号为基准进行删除,查找等操作" << endl;
		cout << "                                           1、信息保存|2、信息展示|3、信息修改" << endl;
		cout << "                                           4、信息删除|5、信息插入|6、精确查找" << endl;
		cout << "                                           7、模糊查找|           |0、退出系统" << endl;

		cin >> choice;
		switch (choice)
		{
		case 0:
			system("cls"); // 选择为0时退出
			return;
		case 1:
			saveModel(tree); // 选择保存模式
			break;
		case 2:
			showModel(tree); // 选择打印模式
			break;
		case 3:
			system("cls");
			cout << "请输入要修改学生的学号:" << endl;
			cin >> temp;
			tree.Modify(temp); // 修改
			break;
		case 4: // 删除学生
			system("cls");
			cout << "请输入要删除学生的学号:";
			cin >> temp;
			tree.DeleteNode(temp);
			break;
		case 5: // 插入新学生
			system("cls");
			s.InitData();
			tree.refreshRoot(tree.InsertBST(tree.getRoot(), s.num, s)); // 刷新树状态
			break;
		case 6: // 精确查找
			system("cls");
			cout << "请输入查找学生的学号:" << endl;
			cin >> temp;
			node = tree.Exactsearch(temp);
			if (node == nullptr)
				cout << "未找到,请重新输入!!!" << endl;
			else
				node->s.show();
			break;
		case 7: // 模糊查找
			system("cls");
			cout << "请输入匹配串:" << endl;
			cin >> str;
			tree.matchingEach(tree.getRoot(), str);
			break;
		default:
			cout << "选择无效,请重新输入" << endl;
			break;
		}
	}
}

void nameModel()
{
	vector<Student> slist;
	loadInfo(slist);
	BSTree<string> tree;
	Student s;
	node<string> *node;
	string str;
	string temp;
	for (auto e : slist)
	{
		tree.refreshRoot(tree.InsertBST(tree.getRoot(), e.name, e));
	}
	int choice;
	while (true)
	{
		cout << "                                    关键字[姓名],请以姓名为基准进行删除,查找等操作" << endl;
		cout << "                                           1、信息保存|2、信息展示|3、信息修改" << endl;
		cout << "                                           4、信息删除|5、信息插入|6、精确查找" << endl;
		cout << "                                           7、模糊查找|           |0、退出系统" << endl;

		cin >> choice;
		switch (choice)
		{
		case 0:
			system("cls");
			return;
		case 1:
			saveModel(tree);
			break;
		case 2:
			showModel(tree);
			break;
		case 3:
			system("cls");
			cout << "请输入要修改学生的姓名:" << endl;
			cin >> temp;
			tree.Modify(temp);
			break;
		case 4: // 删除学生
			system("cls");
			cout << "请输入要删除学生的姓名:";
			cin >> temp;
			tree.DeleteNode(temp);
			break;
		case 5: // 插入新学生
			system("cls");
			s.InitData();
			tree.refreshRoot(tree.InsertBST(tree.getRoot(), s.name, s));
			break;
		case 6: // 精确查找
			system("cls");
			cout << "请输入查找学生的姓名:" << endl;
			cin >> temp;
			node = tree.Exactsearch(temp);
			if (node == nullptr)
				cout << "未找到,请重新输入!!!" << endl;
			else
				node->s.show();
			break;
		case 7: // 模糊查找
			system("cls");
			cout << "请输入匹配串:" << endl;
			cin >> str;
			tree.matchingEach(tree.getRoot(), str);
			break;
		default:
			cout << "选择无效,请重新输入" << endl;
			break;
		}
	}
}

void mathsModel()
{
	vector<Student> slist;
	loadInfo(slist);
	BSTree<unsigned> tree;
	Student s;
	node<unsigned> *node;
	unsigned temp;
	for (auto e : slist)
	{
		tree.refreshRoot(tree.InsertBST(tree.getRoot(), e.maths, e));
	}
	int choice;
	while (true)
	{
		cout << "                                    关键字[高数],请以高数为基准进行删除,查找等操作" << endl;
		cout << "                                           1、信息保存|2、信息展示|         " << endl;
		cout << "                                           3、信息删除|4、信息插入|5、精确查找" << endl;
		cout << "                                                      |           |0、退出系统" << endl;

		cin >> choice;
		switch (choice)
		{
		case 0:
			system("cls");
			return;
		case 1:
			saveModel(tree);
			break;
		case 2:
			showModel(tree);
			break;
		case 3: // 删除学生
			system("cls");
			cout << "请输入要删除学生的高数成绩:";
			cin >> temp;
			tree.DeleteNode(temp);
			break;
		case 4: // 插入新学生
			system("cls");
			s.InitData();
			tree.refreshRoot(tree.InsertBST(tree.getRoot(), s.maths, s));
			break;
		case 5: // 精确查找
			system("cls");
			cout << "请输入查找学生的高数成绩:" << endl;
			cin >> temp;
			node = tree.Exactsearch(temp);
			if (node == nullptr)
				cout << "未找到,请重新输入!!!" << endl;
			else
				node->s.show();
			break;
		default:
			cout << "选择无效,请重新输入" << endl;
			break;
		}
	}
}

void englishModel()
{
	vector<Student> slist;
	loadInfo(slist);
	BSTree<unsigned> tree;
	Student s;
	node<unsigned> *node;
	unsigned temp;
	for (auto e : slist)
	{
		tree.refreshRoot(tree.InsertBST(tree.getRoot(), e.english, e));
	}
	int choice;
	while (true)
	{
		cout << "                                    关键字[英语],请以英语为基准进行删除,查找等操作" << endl;
		cout << "                                           1、信息保存|2、信息展示|         " << endl;
		cout << "                                           3、信息删除|4、信息插入|5、精确查找" << endl;
		cout << "                                                      |           |0、退出系统" << endl;

		cin >> choice;
		switch (choice)
		{
		case 0:
			system("cls");
			return;
		case 1:
			saveModel(tree);
			break;
		case 2:
			showModel(tree);
			break;
		case 3: // 删除学生
			system("cls");
			cout << "请输入要删除学生的英语成绩:";
			cin >> temp;
			tree.DeleteNode(temp);
			break;
		case 4: // 插入新学生
			system("cls");
			s.InitData();
			tree.refreshRoot(tree.InsertBST(tree.getRoot(), s.english, s));
			break;
		case 5: // 精确查找
			system("cls");
			cout << "请输入查找学生的英语成绩:" << endl;
			cin >> temp;
			node = tree.Exactsearch(temp);
			if (node == nullptr)
				cout << "未找到,请重新输入!!!" << endl;
			else
				node->s.show();
			break;
		default:
			cout << "选择无效,请重新输入" << endl;
			break;
		}
	}
}

void discreteModel()
{
	vector<Student> slist;
	loadInfo(slist);
	BSTree<unsigned> tree;
	Student s;
	node<unsigned> *node;
	unsigned temp;
	for (auto e : slist)
	{
		tree.refreshRoot(tree.InsertBST(tree.getRoot(), e.discrete, e));
	}
	int choice;
	while (true)
	{
		cout << "                                    关键字[离散],请以离散为基准进行删除,查找等操作" << endl;
		cout << "                                           1、信息保存|2、信息展示|         " << endl;
		cout << "                                           3、信息删除|4、信息插入|5、精确查找" << endl;
		cout << "                                                      |           |0、退出系统" << endl;

		cin >> choice;
		switch (choice)
		{
		case 0:
			system("cls");
			return;
		case 1:
			saveModel(tree);
			break;
		case 2:
			showModel(tree);
			break;
		case 3: // 删除学生
			system("cls");
			cout << "请输入要删除学生的离散成绩:";
			cin >> temp;
			tree.DeleteNode(temp);
			break;
		case 4: // 插入新学生
			system("cls");
			s.InitData();
			tree.refreshRoot(tree.InsertBST(tree.getRoot(), s.discrete, s));
			break;
		case 5: // 精确查找
			system("cls");
			cout << "请输入查找学生的离散成绩:" << endl;
			cin >> temp;
			node = tree.Exactsearch(temp);
			if (node == nullptr)
				cout << "未找到,请重新输入!!!" << endl;
			else
				node->s.show();
			break;
		default:
			cout << "选择无效,请重新输入" << endl;
			break;
		}
	}
}

void cModel()
{
	vector<Student> slist;
	loadInfo(slist);
	BSTree<unsigned> tree;
	Student s;
	node<unsigned> *node;
	unsigned temp;
	for (auto e : slist)
	{
		tree.refreshRoot(tree.InsertBST(tree.getRoot(), e.languageC, e));
	}
	int choice;
	while (true)
	{
		cout << "                                    关键字[C],请以C为基准进行删除,查找等操作" << endl;
		cout << "                                           1、信息保存|2、信息展示|         " << endl;
		cout << "                                           3、信息删除|4、信息插入|5、精确查找" << endl;
		cout << "                                                      |           |0、退出系统" << endl;

		cin >> choice;
		switch (choice)
		{
		case 0:
			system("cls");
			return;
		case 1:
			saveModel(tree);
			break;
		case 2:
			showModel(tree);
			break;
		case 3: // 删除学生
			system("cls");
			cout << "请输入要删除学生的C成绩:";
			cin >> temp;
			tree.DeleteNode(temp);
			break;
		case 4: // 插入新学生
			system("cls");
			s.InitData();
			tree.refreshRoot(tree.InsertBST(tree.getRoot(), s.languageC, s));
			break;
		case 5: // 精确查找
			system("cls");
			cout << "请输入查找学生的C成绩:" << endl;
			cin >> temp;
			node = tree.Exactsearch(temp);
			if (node == nullptr)
				cout << "未找到,请重新输入!!!" << endl;
			else
				node->s.show();
			break;
		default:
			cout << "选择无效,请重新输入" << endl;
			break;
		}
	}
}

void aveModel()
{
	vector<Student> slist;
	loadInfo(slist);
	BSTree<int> tree;
	Student s;
	node<int> *node;
	int temp;
	for (auto e : slist)
	{
		tree.refreshRoot(tree.InsertBST(tree.getRoot(), e.average, e));
	}
	int choice;
	while (true)
	{
		cout << "                                    关键字[平均分],请以平均分为基准进行删除,查找等操作" << endl;
		cout << "                                           1、信息保存|2、信息展示|         " << endl;
		cout << "                                           3、信息删除|4、信息插入|5、精确查找" << endl;
		cout << "                                                      |           |0、退出系统" << endl;

		cin >> choice;
		switch (choice)
		{
		case 0:
			system("cls");
			return;
		case 1:
			saveModel(tree);
			break;
		case 2:
			showModel(tree);
			break;
		case 3: // 删除学生
			system("cls");
			cout << "请输入要删除学生的平均分:";
			cin >> temp;
			tree.DeleteNode(temp);
			break;
		case 4: // 插入新学生
			system("cls");
			s.InitData();
			tree.refreshRoot(tree.InsertBST(tree.getRoot(), s.average, s));
			break;
		case 5: // 精确查找
			system("cls");
			cout << "请输入查找学生的平均分:" << endl;
			cin >> temp;
			node = tree.Exactsearch(temp);
			if (node == nullptr)
				cout << "未找到,请重新输入!!!" << endl;
			else
				node->s.show();
			break;
		default:
			cout << "选择无效,请重新输入" << endl;
			break;
		}
	}
}

void totalModel()
{
	vector<Student> slist;
	loadInfo(slist);
	BSTree<long> tree;
	Student s;
	node<long> *node;
	long temp;
	for (auto e : slist)
	{
		tree.refreshRoot(tree.InsertBST(tree.getRoot(), e.total, e));
	}
	int choice;
	while (true)
	{
		cout << "                                    关键字[总分],请以总分为基准进行删除,查找等操作" << endl;
		cout << "                                           1、信息保存|2、信息展示|         " << endl;
		cout << "                                           3、信息删除|4、信息插入|5、精确查找" << endl;
		cout << "                                                      |           |0、退出系统" << endl;

		cin >> choice;
		switch (choice)
		{
		case 0:
			system("cls");
			return;
		case 1:
			saveModel(tree);
			break;
		case 2:
			showModel(tree);
			break;
		case 3: // 删除学生
			system("cls");
			cout << "请输入要删除学生的总分:";
			cin >> temp;
			tree.DeleteNode(temp);
			break;
		case 4: // 插入新学生
			system("cls");
			s.InitData();
			tree.refreshRoot(tree.InsertBST(tree.getRoot(), s.total, s));
			break;
		case 5: // 精确查找
			system("cls");
			cout << "请输入查找学生的总分:" << endl;
			cin >> temp;
			node = tree.Exactsearch(temp);
			if (node == nullptr)
				cout << "未找到,请重新输入!!!" << endl;
			else
				node->s.show();
			break;
		default:
			cout << "选择无效,请重新输入" << endl;
			break;
		}
	}
}