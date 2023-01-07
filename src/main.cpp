#include "BSTree.h"
#include "Student.h"
#include "fileHandle.h"
#include "userReaction.h"

int main()
{
	int input;
	while (true)
	{

		cout << "请选择关键字:" << endl;
		cout << "                                                0、退出|1、姓名|2、学 号|3、高  数" << endl;
		cout << "                                                4、英语|5、离散|6、c语言|7、平均分" << endl;
		cout << "                                                8、总分|" << endl;
		cin >> input;
		switch (input)
		{
		case 0:
			return 0;
		case 1:
			system("cls");
			nameModel(); // 姓名模式
			break;
		case 2:
			system("cls");
			numModel(); // 学号模式
			break;
		case 3:
			system("cls");
			mathsModel(); // 高数成绩模式
			break;
		case 4:
			system("cls");
			englishModel(); // 英语成绩模式
			break;
		case 5:
			system("cls");
			discreteModel(); // 离散数学模式
			break;
		case 6:
			system("cls");
			cModel(); // c语言成绩模式
			break;
		case 7:
			system("cls");
			aveModel(); // 平均分模式
			break;
		case 8:
			system("cls");
			totalModel(); // 总分模式
			break;
		default:
			cout << "选择无效,请重试";
			break;
		}
	}

	system("pause");
}