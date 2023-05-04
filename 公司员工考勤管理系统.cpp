#include <iostream>
using namespace std;
#include <string>
#include "workerManager.h"
#include "worker.h"

int main()
{
	int choice = 0;	// 存储用户选项
	WorkerManager wm;

	while (true)
	{

		// 显示菜单
		wm.ShowMenu();

		// 获取用户输入的功能
		cout << "请输入您选择的功能：" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0:	// 退出系统
			cout << "欢迎您下次使用！";
			return 0;
		case 1:	// 添加员工
			wm.Add_Emp();
			break;
		case 2:	// 显示员工
			wm.show_Emp();
			break;
		case 3:	// 删除员工
			wm.Del_Emp();
			break;
		case 4:	// 修改员工
			wm.Mod_Emp();
			break;
		case 5:	// 查找员工
			wm.Find_Emp();
			break;
		case 6:	// 排序员工
			wm.Sort_Emp();
			break;
		case 7:	// 统计功能
			wm.count_Emp();
			break;
		//case 8：//员工
		
		default:
			cout << "请输入正确的数字选项！" << endl;	
			break;
		}
	}

	system("pause");
	return 0;
}