#include "userReaction.h"

void globalInsert(vector<Student> &v) // ����,����ԭ����˵��
{
	Student s;
	s.InitData();
	v.push_back(s);
}

void globalInsert(vector<Student> &v, Student s) // ����,����ԭ����˵��
{
	v.push_back(s);
}

void globalShow(const vector<Student> &v) // ����,����ԭ����˵��
{
	for (auto e : v)
	{
		e.show();
	}
}

void numModel()
{							// ����ģʽ����ģ�����������ʱ�������Ͳ�ͬ�Լ��������Ĺؼ��ֲ�ͬ����������ƣ�ע�ͽ��ڴ˺����и������·�������
	vector<Student> slist;	// ��ʱ����vector
	loadInfo(slist);		// ���ļ���ȡ
	BSTree<long long> tree; // ʵ����ģ����long long(ѧ��)
	Student s;				// ��ʱѧ������
	node<long long> *node;	// ��ʱ�ڵ�
	string str;				// ��ʱstring
	long long temp;			// ��ʱ����
	for (auto e : slist)
	{ // ��vector�е�ѧ���������β��뵽����
		tree.refreshRoot(tree.InsertBST(tree.getRoot(), e.num, e));
	}
	int choice;
	while (true)
	{
		cout << "                                    �ؼ���[ѧ��],����ѧ��Ϊ��׼����ɾ��,���ҵȲ���" << endl;
		cout << "                                           1����Ϣ����|2����Ϣչʾ|3����Ϣ�޸�" << endl;
		cout << "                                           4����Ϣɾ��|5����Ϣ����|6����ȷ����" << endl;
		cout << "                                           7��ģ������|           |0���˳�ϵͳ" << endl;

		cin >> choice;
		switch (choice)
		{
		case 0:
			system("cls"); // ѡ��Ϊ0ʱ�˳�
			return;
		case 1:
			saveModel(tree); // ѡ�񱣴�ģʽ
			break;
		case 2:
			showModel(tree); // ѡ���ӡģʽ
			break;
		case 3:
			system("cls");
			cout << "������Ҫ�޸�ѧ����ѧ��:" << endl;
			cin >> temp;
			tree.Modify(temp); // �޸�
			break;
		case 4: // ɾ��ѧ��
			system("cls");
			cout << "������Ҫɾ��ѧ����ѧ��:";
			cin >> temp;
			tree.DeleteNode(temp);
			break;
		case 5: // ������ѧ��
			system("cls");
			s.InitData();
			tree.refreshRoot(tree.InsertBST(tree.getRoot(), s.num, s)); // ˢ����״̬
			break;
		case 6: // ��ȷ����
			system("cls");
			cout << "���������ѧ����ѧ��:" << endl;
			cin >> temp;
			node = tree.Exactsearch(temp);
			if (node == nullptr)
				cout << "δ�ҵ�,����������!!!" << endl;
			else
				node->s.show();
			break;
		case 7: // ģ������
			system("cls");
			cout << "������ƥ�䴮:" << endl;
			cin >> str;
			tree.matchingEach(tree.getRoot(), str);
			break;
		default:
			cout << "ѡ����Ч,����������" << endl;
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
		cout << "                                    �ؼ���[����],��������Ϊ��׼����ɾ��,���ҵȲ���" << endl;
		cout << "                                           1����Ϣ����|2����Ϣչʾ|3����Ϣ�޸�" << endl;
		cout << "                                           4����Ϣɾ��|5����Ϣ����|6����ȷ����" << endl;
		cout << "                                           7��ģ������|           |0���˳�ϵͳ" << endl;

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
			cout << "������Ҫ�޸�ѧ��������:" << endl;
			cin >> temp;
			tree.Modify(temp);
			break;
		case 4: // ɾ��ѧ��
			system("cls");
			cout << "������Ҫɾ��ѧ��������:";
			cin >> temp;
			tree.DeleteNode(temp);
			break;
		case 5: // ������ѧ��
			system("cls");
			s.InitData();
			tree.refreshRoot(tree.InsertBST(tree.getRoot(), s.name, s));
			break;
		case 6: // ��ȷ����
			system("cls");
			cout << "���������ѧ��������:" << endl;
			cin >> temp;
			node = tree.Exactsearch(temp);
			if (node == nullptr)
				cout << "δ�ҵ�,����������!!!" << endl;
			else
				node->s.show();
			break;
		case 7: // ģ������
			system("cls");
			cout << "������ƥ�䴮:" << endl;
			cin >> str;
			tree.matchingEach(tree.getRoot(), str);
			break;
		default:
			cout << "ѡ����Ч,����������" << endl;
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
		cout << "                                    �ؼ���[����],���Ը���Ϊ��׼����ɾ��,���ҵȲ���" << endl;
		cout << "                                           1����Ϣ����|2����Ϣչʾ|         " << endl;
		cout << "                                           3����Ϣɾ��|4����Ϣ����|5����ȷ����" << endl;
		cout << "                                                      |           |0���˳�ϵͳ" << endl;

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
		case 3: // ɾ��ѧ��
			system("cls");
			cout << "������Ҫɾ��ѧ���ĸ����ɼ�:";
			cin >> temp;
			tree.DeleteNode(temp);
			break;
		case 4: // ������ѧ��
			system("cls");
			s.InitData();
			tree.refreshRoot(tree.InsertBST(tree.getRoot(), s.maths, s));
			break;
		case 5: // ��ȷ����
			system("cls");
			cout << "���������ѧ���ĸ����ɼ�:" << endl;
			cin >> temp;
			node = tree.Exactsearch(temp);
			if (node == nullptr)
				cout << "δ�ҵ�,����������!!!" << endl;
			else
				node->s.show();
			break;
		default:
			cout << "ѡ����Ч,����������" << endl;
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
		cout << "                                    �ؼ���[Ӣ��],����Ӣ��Ϊ��׼����ɾ��,���ҵȲ���" << endl;
		cout << "                                           1����Ϣ����|2����Ϣչʾ|         " << endl;
		cout << "                                           3����Ϣɾ��|4����Ϣ����|5����ȷ����" << endl;
		cout << "                                                      |           |0���˳�ϵͳ" << endl;

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
		case 3: // ɾ��ѧ��
			system("cls");
			cout << "������Ҫɾ��ѧ����Ӣ��ɼ�:";
			cin >> temp;
			tree.DeleteNode(temp);
			break;
		case 4: // ������ѧ��
			system("cls");
			s.InitData();
			tree.refreshRoot(tree.InsertBST(tree.getRoot(), s.english, s));
			break;
		case 5: // ��ȷ����
			system("cls");
			cout << "���������ѧ����Ӣ��ɼ�:" << endl;
			cin >> temp;
			node = tree.Exactsearch(temp);
			if (node == nullptr)
				cout << "δ�ҵ�,����������!!!" << endl;
			else
				node->s.show();
			break;
		default:
			cout << "ѡ����Ч,����������" << endl;
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
		cout << "                                    �ؼ���[��ɢ],������ɢΪ��׼����ɾ��,���ҵȲ���" << endl;
		cout << "                                           1����Ϣ����|2����Ϣչʾ|         " << endl;
		cout << "                                           3����Ϣɾ��|4����Ϣ����|5����ȷ����" << endl;
		cout << "                                                      |           |0���˳�ϵͳ" << endl;

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
		case 3: // ɾ��ѧ��
			system("cls");
			cout << "������Ҫɾ��ѧ������ɢ�ɼ�:";
			cin >> temp;
			tree.DeleteNode(temp);
			break;
		case 4: // ������ѧ��
			system("cls");
			s.InitData();
			tree.refreshRoot(tree.InsertBST(tree.getRoot(), s.discrete, s));
			break;
		case 5: // ��ȷ����
			system("cls");
			cout << "���������ѧ������ɢ�ɼ�:" << endl;
			cin >> temp;
			node = tree.Exactsearch(temp);
			if (node == nullptr)
				cout << "δ�ҵ�,����������!!!" << endl;
			else
				node->s.show();
			break;
		default:
			cout << "ѡ����Ч,����������" << endl;
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
		cout << "                                    �ؼ���[C],����CΪ��׼����ɾ��,���ҵȲ���" << endl;
		cout << "                                           1����Ϣ����|2����Ϣչʾ|         " << endl;
		cout << "                                           3����Ϣɾ��|4����Ϣ����|5����ȷ����" << endl;
		cout << "                                                      |           |0���˳�ϵͳ" << endl;

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
		case 3: // ɾ��ѧ��
			system("cls");
			cout << "������Ҫɾ��ѧ����C�ɼ�:";
			cin >> temp;
			tree.DeleteNode(temp);
			break;
		case 4: // ������ѧ��
			system("cls");
			s.InitData();
			tree.refreshRoot(tree.InsertBST(tree.getRoot(), s.languageC, s));
			break;
		case 5: // ��ȷ����
			system("cls");
			cout << "���������ѧ����C�ɼ�:" << endl;
			cin >> temp;
			node = tree.Exactsearch(temp);
			if (node == nullptr)
				cout << "δ�ҵ�,����������!!!" << endl;
			else
				node->s.show();
			break;
		default:
			cout << "ѡ����Ч,����������" << endl;
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
		cout << "                                    �ؼ���[ƽ����],����ƽ����Ϊ��׼����ɾ��,���ҵȲ���" << endl;
		cout << "                                           1����Ϣ����|2����Ϣչʾ|         " << endl;
		cout << "                                           3����Ϣɾ��|4����Ϣ����|5����ȷ����" << endl;
		cout << "                                                      |           |0���˳�ϵͳ" << endl;

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
		case 3: // ɾ��ѧ��
			system("cls");
			cout << "������Ҫɾ��ѧ����ƽ����:";
			cin >> temp;
			tree.DeleteNode(temp);
			break;
		case 4: // ������ѧ��
			system("cls");
			s.InitData();
			tree.refreshRoot(tree.InsertBST(tree.getRoot(), s.average, s));
			break;
		case 5: // ��ȷ����
			system("cls");
			cout << "���������ѧ����ƽ����:" << endl;
			cin >> temp;
			node = tree.Exactsearch(temp);
			if (node == nullptr)
				cout << "δ�ҵ�,����������!!!" << endl;
			else
				node->s.show();
			break;
		default:
			cout << "ѡ����Ч,����������" << endl;
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
		cout << "                                    �ؼ���[�ܷ�],�����ܷ�Ϊ��׼����ɾ��,���ҵȲ���" << endl;
		cout << "                                           1����Ϣ����|2����Ϣչʾ|         " << endl;
		cout << "                                           3����Ϣɾ��|4����Ϣ����|5����ȷ����" << endl;
		cout << "                                                      |           |0���˳�ϵͳ" << endl;

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
		case 3: // ɾ��ѧ��
			system("cls");
			cout << "������Ҫɾ��ѧ�����ܷ�:";
			cin >> temp;
			tree.DeleteNode(temp);
			break;
		case 4: // ������ѧ��
			system("cls");
			s.InitData();
			tree.refreshRoot(tree.InsertBST(tree.getRoot(), s.total, s));
			break;
		case 5: // ��ȷ����
			system("cls");
			cout << "���������ѧ�����ܷ�:" << endl;
			cin >> temp;
			node = tree.Exactsearch(temp);
			if (node == nullptr)
				cout << "δ�ҵ�,����������!!!" << endl;
			else
				node->s.show();
			break;
		default:
			cout << "ѡ����Ч,����������" << endl;
			break;
		}
	}
}