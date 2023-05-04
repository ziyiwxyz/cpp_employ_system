#include "worker.h"
#include<iomanip>

// 构造函数
manager::manager(int id, string name, string gender, string dep, string level, int jId,double days,double leavedays)
{	this->m_Id = id;
	this->m_Name = name;
	this->m_Gender = gender;
	this->m_Dep = dep;
	this->m_Level = level;
	this->m_JobId = jId;
	this->m_Days = days;
	this->m_LeaveDays = leavedays;
}

// 显示个人信息
void manager::showInfo()
{
	cout << "编号： " << this->m_Id
		<< "\t姓名： " << this->m_Name
		<< setw(15) << "\t性别： " << this->m_Gender
		<< setw(10) << "\t部门： " << this->m_Dep
		<< setw(10) << "\t级别：" << this->m_Level
		<< setw(10) << "\t岗位： " << this->getJobtName()
		<< setw(10) << "\t工作时间： " << this->m_Days
		<< setw(10) << "\t休假时间： " << this->m_LeaveDays << endl;
}

// 获取岗位名称
string manager::getJobtName()
{
	return string("经理");//类型转换为string
}





// 构造函数
technologist::technologist(int id, string name, string gender, string dep, string level, int jId, double days, double leavedays)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Gender = gender;
	this->m_Dep = dep;
	this->m_Level = level;
	this->m_JobId = jId;
	this->m_Days = days;
	this->m_LeaveDays = leavedays;
}
// 显示个人信息
void technologist::showInfo()
{
	cout << "编号： " << this->m_Id
		<< "\t姓名： " << this->m_Name
		<< setw(15) << "\t性别： " << this->m_Gender
		<< setw(10) << "\t部门： " << this->m_Dep
		<< setw(10) << "\t级别：" << this->m_Level
		<< setw(10) << "\t岗位： " << this->getJobtName()
		<< setw(10) << "\t工作时间： " << this->m_Days
		<< setw(10) << "\t休假时间： " << this->m_LeaveDays << endl;
}
// 获取岗位名称
string technologist::getJobtName()
{
	return string("技术人员");//类型转换为string
}





// 构造函数
salesman::salesman(int id, string name, string gender, string dep, string level, int jId, double days, double leavedays)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Gender = gender;
	this->m_Dep = dep;
	this->m_Level = level;
	this->m_JobId = jId;
	this->m_Days = days;
	this->m_LeaveDays = leavedays;
}
// 显示个人信息
void salesman::showInfo()
{
	cout << "编号： " << this->m_Id
		<< "\t姓名： " << this->m_Name
		<< setw(15) << "\t性别： " << this->m_Gender
		<< setw(10) << "\t部门： " << this->m_Dep
		<< setw(10) << "\t级别：" << this->m_Level
		<< setw(10) << "\t岗位： " << this->getJobtName()
		<< setw(10) << "\t工作时间： " << this->m_Days
		<< setw(10) << "\t休假时间： " << this->m_LeaveDays << endl;
		
}
// 获取岗位名称
string salesman::getJobtName()
{
	return string("销售人员");//类型转换为string
}





// 构造函数
salesmanager::salesmanager(int id, string name, string gender, string dep, string level, int jId, double days, double leavedays)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Gender = gender;
	this->m_Dep = dep;
	this->m_Level = level;
	this->m_JobId = jId;
	this->m_Days = days;
	this->m_LeaveDays = leavedays;
}

// 显示个人信息
void salesmanager::showInfo()
{
	cout << "编号： " << this->m_Id
		<< "\t姓名： " << this->m_Name
		<< setw(15) << "\t性别： " << this->m_Gender
		<< setw(10) << "\t部门： " << this->m_Dep
		<< setw(10) << "\t级别：" << this->m_Level
		<< setw(10) << "\t岗位： " << this->getJobtName()
		<< setw(10) << "\t工作时间： " << this->m_Days
		<< setw(10) << "\t休假时间： " <<this->m_LeaveDays<< endl;
}

// 获取岗位名称
string salesmanager::getJobtName()
{
	return string("销售经理");//类型转换为string
}



