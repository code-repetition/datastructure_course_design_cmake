#include "BSTree.h"
#include "Student.h"
#include "fileHandle.h"
#include "userReaction.h"

int main()
{
	int input;
	while (true)
	{

		cout << "��ѡ��ؼ���:" << endl;
		cout << "                                                0���˳�|1������|2��ѧ ��|3����  ��" << endl;
		cout << "                                                4��Ӣ��|5����ɢ|6��c����|7��ƽ����" << endl;
		cout << "                                                8���ܷ�|" << endl;
		cin >> input;
		switch (input)
		{
		case 0:
			return 0;
		case 1:
			system("cls");
			nameModel(); // ����ģʽ
			break;
		case 2:
			system("cls");
			numModel(); // ѧ��ģʽ
			break;
		case 3:
			system("cls");
			mathsModel(); // �����ɼ�ģʽ
			break;
		case 4:
			system("cls");
			englishModel(); // Ӣ��ɼ�ģʽ
			break;
		case 5:
			system("cls");
			discreteModel(); // ��ɢ��ѧģʽ
			break;
		case 6:
			system("cls");
			cModel(); // c���Գɼ�ģʽ
			break;
		case 7:
			system("cls");
			aveModel(); // ƽ����ģʽ
			break;
		case 8:
			system("cls");
			totalModel(); // �ܷ�ģʽ
			break;
		default:
			cout << "ѡ����Ч,������";
			break;
		}
	}

	system("pause");
}