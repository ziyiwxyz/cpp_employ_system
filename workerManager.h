#pragma once
#include <iostream>
#include "worker.h"
#include <fstream>
using namespace std;

#define FILENAME "公司考勤管理系统.txt"

class WorkerManager
{
public:

	// 构造函数
	WorkerManager();

	// 展示菜单
	void ShowMenu();

	// 记录员工人数
	int m_EmpNum;

	// 员工指针数组
	Worker** m_EmpArray;//也可以写成Worker *m_EmpArray[]

	// 添加员工
	void Add_Emp();

	// 保存文件
	void save();

	// 判断文件释放为空 的标志
	bool m_FileIsEmpty;

	// 统计文件中的人数
	int get_EmpNum();

	//统计文件中各部门人数
	int get_JobNum(int i);

	//统计功能
	void count_Emp();

	// 初始化员工，从文件中读取所有员工
	void init_Emp();

	// 显示员工
	void show_Emp();

	// 判断员工是否存在。若存在，返回数组中的位置，不存在返回-1
	int isExist(int id);

	// 删除员工
	void Del_Emp();

	// 修改员工
	void Mod_Emp();

	// 查找员工
	void Find_Emp();

	// 排序，选择排序
	void Sort_Emp();

	// 析构函数
	~WorkerManager();
};