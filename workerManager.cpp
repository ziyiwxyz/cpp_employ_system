#include "workerManager.h"
using namespace std;
// 构造函数
WorkerManager::WorkerManager():m_EmpNum(0)
{
	// 判断存储文件状态

	ifstream ifs;
	ifs.open(FILENAME, ios::in); // 读文件

	// 1、文件不存在的情况
	if (!ifs.is_open())//is_open()这个函数用于判断文件是否成功打开
	{
		cout << "文件不存在" << endl;
		// 初始化属性
		// 初始化人数
		this->m_EmpNum = 0;
		// 初始化数组指针
		this->m_EmpArray = NULL;
		// 初始化文件是否为空
		this->m_FileIsEmpty = true;

		ifs.close();
		return;
	}

	// 2、文件存在，数据为空，没有记录任何员工信息
	// 判断文件是否为空
	string ch;
	ifs >> ch;
	if (ifs.eof()) // end of file，文件结尾
	{
		cout << "文件为空" << endl;
		// 初始化属性
		// 初始化人数
		this->m_EmpNum = 0;
		// 初始化数组指针
		this->m_EmpArray = NULL;
		// 初始化文件是否为空
		this->m_FileIsEmpty = true;

		ifs.close();
		return;
	}

	// 3、文件存在，并且已有员工消息
	int num = this->get_EmpNum();
	// 测试代码
	/*cout << "员工人数为：" << num << endl;*/
	this->m_EmpNum = num;

	// 申请空间，存放各个员工指针的数组
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	// 将文件中的员工数据,存到数组中
	this->init_Emp();

}

// 展示菜单
void WorkerManager::ShowMenu()
{
	cout << "============[欢迎来到公司员工考勤管理系统！]============" << endl;
	cout << "========================[主菜单]========================" << endl;
	cout << "====================[0.退出管理系统]====================" << endl;
	cout << "====================[1.增加员工信息]====================" << endl;
	cout << "====================[2.显示员工信息]====================" << endl;
	cout << "====================[3.删除员工信息]====================" << endl;
	cout << "====================[4.修改员工信息]====================" << endl;
	cout << "====================[5.查找员工信息]====================" << endl;
	cout << "====================[6.排序员工信息]====================" << endl;
	cout << "====================[7.统计员工信息]====================" << endl;
	cout << endl;
}

// 添加员工
void WorkerManager::Add_Emp()
{
	cout << "请输入添加员工的数量：" << endl;
	int addNum = 0; // 保存用户的输入数量
	cin >> addNum;

	if (addNum > 0)
	{
		// 计算添加新空间的大小
		int newSize = this->m_EmpNum + addNum+8; // 新空间人数 = 原来记录的人数 + 新增人数

		// 开辟新空间
		Worker** newSpace = new Worker * [newSize];//Worker** m_EmpArray ==Worker *m_EmpArray[]

		// 将原来空间下的数据，拷贝到新空间下
		if (this->m_EmpArray != NULL) // 判断原数组是否为空
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		
		// 批量添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id; // 员工编号
			string name; // 员工姓名
			string gender;
			string dep;
			string level;
			double days;
			double leavedays;
			int dSelect; // 选择

			cout << "请输入第" << i + 1 << "个新员工编号：" << endl;
			cin >> id;
			if (isExist(id) == -1)
			{
				cout << "请输入第" << i + 1 << "个新员工姓名：" << endl;
				cin >> name;
				cout << "请输入第" << i + 1 << "个新员工性别：" << endl;
				cin >> gender;
				cout << "请输入第" << i + 1 << "个新员工部门：" << endl;
				cin >> dep;
				cout << "请输入第" << i + 1 << "个新员工级别：" << endl;
				cin >> level;
				cout << "请输入第" << i + 1 << "个新员工工作时间：" << endl;
				cin >> days;
				cout << "请输入第" << i + 1 << "个新员工休假时间：" << endl;
				cin >> leavedays;
				cout << "请选择该员工的岗位：" << endl;
				cout << "1、经理" << endl;
				cout << "2、技术人员" << endl;
				cout << "3、销售人员" << endl;
				cout << "4、销售经理" << endl;
				cin >> dSelect;

				
				Worker* worker = NULL;
				switch (dSelect)
				{
				case 1:
					worker = new manager(id,name, gender, dep,level,1,days,leavedays);
					break;
				case 2:
					worker = new technologist(id, name, gender, dep, level, 1, days, leavedays);
					break;
				case 3:
					worker = new salesman(id, name, gender, dep, level, 1, days, leavedays);
					break;
				case 4:
					worker = new salesmanager(id, name, gender, dep, level, 1, days, leavedays);
					break;
				default:
					cout << "请输入正确的数字选项！";
					return;
				}
				// 将创建员工的指针，保存在数组中
				if (this->m_EmpNum + i <= newSize)
				{
					newSpace[this->m_EmpNum + i] = worker;
				}
			
				
			}
			else
			{
				cout << "输入的编号["<<id<<"]已存在，请重新输入！" << endl;
	
				system("pause");
				system("cls");
				return;
			}
		}
		// 释放原有空间
		delete[] this->m_EmpArray;

		// 更改新空间指向
		this->m_EmpArray = newSpace;

		// 更新新的职工人数
		this->m_EmpNum = newSize;

		// 提示添加成功
		cout << "成功添加" << addNum << "名新职工!" << endl;

		// 保存员工信息为文件
		this->save();

		// 更新职工不为空标志
		this->m_FileIsEmpty = false;
	}
	else
	{
		cout << "输入数据有误" << endl;
	}

	// 按任意键清屏，回到上级目录
	system("pause");
	system("cls");
}

// 保存文件
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);	// 用写文件的方式打开文件
	if (!ofs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;	// 失败结束
	}

	// 将每个人数据写入到文件中
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_Gender << " "
			<< this->m_EmpArray[i]->m_Dep << " "
			<< this->m_EmpArray[i]->m_Level << " "
			<< this->m_EmpArray[i]->m_JobId
			<< this->m_EmpArray[i]->m_Days 
			<< this->m_EmpArray[i]->m_LeaveDays << endl;
	}

	// 关闭文件
	ofs.close();
}

// 统计文件中总人数 并用来判断文件中人员的存储情况
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in); // 打开文件 读

	int id;
	string name;
	string gender;
	string dep;
	string level;
	int jId;
	double days;
	double leavedays;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> gender && ifs >> dep &&ifs>>level&& ifs >> jId&&ifs>>days && ifs >> leavedays)
	{
		num++;
	}

	return num;
}

int WorkerManager::get_JobNum(int i)
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in); // 打开文件 读

	int id;
	string name;
	string gender;
	string dep;
	string level;
	int jId;
	double days;
	double leavedays;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> gender && ifs >> dep && ifs >>level&&ifs>> jId && ifs >> days && ifs >> leavedays)
	{
			if(jId==i)
			num++;
	}
	return num;
}

//统计功能
void WorkerManager::count_Emp()
{
	cout << "1.统计四类人员数量及总数" << endl;
	cout << "2.统计任一员工的休假天数"<<endl;
	cout << "请选择需要使用的统计功能:" << endl;
	int temp; cin >> temp;
	switch (temp)
	{
	case 1:
		cout << "四类人员总数为：" <<get_EmpNum()<< endl;
		cout << "四类人员的数量分别为：" << endl;
		cout << "经理的人数为：" <<get_JobNum(1)<< endl;
		cout << "技术人员的人数为：" << get_JobNum(2) << endl;
		cout << "销售人员的人数为：" << get_JobNum(3) << endl;
		cout << "销售经理的人数为：" << get_JobNum(4) << endl;
		break;

	case 2:
		Find_Emp();//使用查找函数
		break;
	
	default:
		cout << "请输入正确的数字选项！" << endl;
		break;
	}

}

// 初始化员工，从文件中读取所有员工
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	string gender;
	string dep;
	string level;
	int jId;
	double days;
	double leavedays;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> gender&&ifs>>dep&&ifs>>level&&ifs>>jId && ifs >> days&& ifs >> leavedays)
	{
		Worker* worker = NULL;

		if (jId == 1) // 经理
		{
			worker = new manager(id, name,gender,dep,level,jId,days,leavedays);
		}
		else if (jId == 2) // 技术人员
		{
			worker = new technologist(id, name, gender, dep, level, jId, days, leavedays);
		}
		else if (jId == 3) // 销售人员
		{
			worker = new salesman(id, name, gender, dep, level, jId, days, leavedays);
		}
		else // 销售经理
		{
			worker = new salesmanager(id, name, gender, dep, level, jId, days, leavedays);
		}

		this->m_EmpArray[index] = worker;
		index++;
	}
	// 关闭文件
	ifs.close();
}

// 显示员工
void WorkerManager::show_Emp()
{
	// 判断文件是否为空
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			// 利用多态调用程序接口
			this->m_EmpArray[i]->showInfo();
		}
	}
	// 按任意键清屏
	system("pause");
	system("cls");
}

// 判断员工是否存在。若存在，返回数组中的位置，不存在返回-1
int WorkerManager::isExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			// 找到员工
			index = i;
			break;
		}
	}
	return index;
}

// 删除员工
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请输入删除的员工编号(若已知姓名可先使用5.查找功能查找员工编号)：" << endl;
		int id = 0;
		cin >> id;

		int index = this->isExist(id);
		if (index != -1) // 说明员工存在，并且要删除index位置数组上的员工
		{
			cout << "要删除员工的信息：" << endl;
			// 利用多态调用程序接口显示员工信息
			this->m_EmpArray[index]->showInfo();
			//确认是否要修改
			cout << "确认是否要删除员工的信息？是：\"1\"或者否：\"2\"：" << endl;
			int temp; cin >> temp;
			if (temp == 1)
			{
				// 释放删除掉的员工的内存
				delete this->m_EmpArray[index];
				// 数组前移
				for (int i = index; i < this->m_EmpNum; i++)
				{
					this->m_EmpArray[i] = this->m_EmpArray[i + 1];
				}
				this->m_EmpNum--; // 更新数组中记录人员个数
				// 数据同步更新到文件中
				this->save();
				cout << "删除成功！" << endl;
			}
			else if (temp == 2)
			{
				return;
			}
			else
				cout << "请输入是：\"1\"或者否：\"2\"：" << endl;
		}
		else
		{
			cout << "删除失败，未找到员工" << endl;
		}
	}

	// 按任意键清屏
	system("pause");
	system("cls");
}

// 修改员工
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请输入要修改的员工编号：" << endl;
		int id = 0;
		cin >> id;

		int index = this->isExist(id);
		if (index != -1)
		{
			

			// 新信息 初始化
			int newId = 0;
			string newName = "";
			string newGender ="";
			string newDep="";
			string newLevel = "";
			int newjId = 0;
			double newDays=0;
			double newLeaveDays = 0;

			cout << "要修改的员工原来的信息：" << endl ;
			// 利用多态调用程序接口显示员工信息
			this->m_EmpArray[index]->showInfo();
			//确认是否要修改
			cout << "确认是否要修改该员工的信息？是：\"1\"或者否：\"2\"："<<endl;
			int temp; cin >> temp;
			if (temp == 1)
			{ 	// 查找到员工编号
				// 释放删除掉的员工的内存
				delete this->m_EmpArray[index];
				cout << "请输入新编号：";
				cin >> newId;
				if(this->isExist(newId)==-1)
				{
				cout << "请输入姓名：" << endl;
				cin >> newName;
				cout << "请输入性别：" << endl;
				cin >> newGender; 
				cout << "请输入部门：" << endl;
				cin >> newDep;
				cout << "请输入级别：" << endl;
				cin >> newLevel;
				cout << "请输入工作时间：" << endl;
				cin >> newDays;
				cout << "请输入休假时间：" << endl;
				cin >> newLeaveDays;
				cout << "请选择该员工的岗位：" << endl;
				cout << "1、经理" << endl;
				cout << "2、技术人员" << endl;
				cout << "3、销售人员" << endl;
				cout << "4、销售经理" << endl;
				cin >> newjId;

				Worker* worker = NULL;
				switch (newjId)
				{
				case 1:
					worker = new manager(newId, newName,newGender,newDep,newLevel,newjId,newDays,newLeaveDays);
					break;
				case 2:
					worker = new technologist(newId, newName, newGender, newDep, newLevel, newjId, newDays, newLeaveDays);
					break;
				case 3:
					worker = new salesman(newId, newName, newGender, newDep, newLevel, newjId, newDays, newLeaveDays);
					break;
				case 4:
					worker = new salesmanager(newId, newName, newGender, newDep, newLevel, newjId, newDays, newLeaveDays);
					break;
				default:
					cout << "请输入正确的数字选项！";
					return;
				}

				// 更新数据到数组中
				this->m_EmpArray[index] = worker;

				cout << "修改成功！" << endl;

				// 数据保存到文件中
				this->save();
				}
				else if (this->isExist(newId) != -1)
				{
					cout << "该id已存在,请重新操作！" << endl;
					return; 
				}
			}
			else if (temp ==2)
				return;
			else
				cout << "请输入是：\"1\"或者否：\"2\"："<<endl;
			
		}
		else
		{
			cout << "修改失败，查无此人" << endl;
		}
	}

	// 按任意键清屏
	system("pause");
	system("cls");
}

// 查找员工
// 提供两种查找方式，一种按照员工编号，一种按照员工姓名。编号不能重名，姓名可以重名
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请输入查找的方式：" << endl;
		cout << "1、按照员工编号查找" << endl;
		cout << "2、按照员工姓名查找" << endl;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			// 按编号查找
			int id;
			cout << "请输入员工编号：" << endl;
			cin >> id;

			int index = isExist(id);
			if (index != -1)
			{
				// 找到员工
				cout << "查找成功！该员工信息如下：" << endl;
				this->m_EmpArray[index]->showInfo();
			}
			else
			{
				cout << "查找失败！查无此人" << endl;
			}
		}
		else if (select == 2)
		{
			// 按姓名查找
			string name;
			cout << "请输入查找的姓名：" << endl;
			cin >> name;

			bool flag = false; // 查找到标志：0-未找到；1-查找到
							   // 没有用break去计i溢出的方法，是为了在名字重复时也能全部显示
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (m_EmpArray[i]->m_Name == name)
				{
					cout << "查找成功，员工编号为："
						<< this->m_EmpArray[i]->m_Id
						<< " ，信息如下：" << endl;

					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if (!flag)
			{
				cout << "查找失败！查无此人" << endl;
			}
		}
		else
		{
			// 输入错误
			cout << "输入选项有误！" << endl;
		}
	}

	// 按任意键清屏
	system("pause");
	system("cls");
}

// 排序，选择排序
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
		// 按任意键清屏
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式：" << endl;
		cout << "1、按员工编号升序" << endl;
		cout << "2、按员工编号降序" << endl;

		int select = 0;
		cin >> select;

		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrmax = i;
			for (int j = i + 1; j < m_EmpNum; j++)
			{
				if (select == 1) // 升序
				{
					if (m_EmpArray[minOrmax]->m_Id > m_EmpArray[j]->m_Id)
					{
						minOrmax = j;
					}
				}
				else // 降序
				{
					if (m_EmpArray[minOrmax]->m_Id < m_EmpArray[j]->m_Id)
					{
						minOrmax = j;
					}
				}
			}

			if (i != minOrmax)
			{
				Worker* temp = m_EmpArray[i];
				m_EmpArray[i] = m_EmpArray[minOrmax];
				m_EmpArray[minOrmax] = temp;
			}
		}

		cout << "排序成功，排序后结果为：" << endl;
		this->save();
		this->show_Emp();
	}

}

// 析构函数
WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
	//
	// 因为有了 更改新空间指向，所以释放 this->m_EmpArray 等于释放 newSpace。
}