#pragma once
#include <iostream>
#include <string>
using namespace std;

// 员工抽象类
class Worker
{public:
	//纯虚函数用于在子类中替代
	// 显示个人信息
	virtual void showInfo() = 0;
	// 获取岗位名称
	virtual string getJobtName() = 0;

	// 员工编号
	int m_Id;
	// 员工姓名
	string m_Name;
	//员工性别
	string m_Gender;
	//员工部门
	string m_Dep;
	//员工级别
	string m_Level;
	// 岗位编号
	int m_JobId;
	//工作时间
	double m_Days; 
	int m_hours;
	//休假时间
	double m_LeaveDays;
	//工作薪资
	double m_wages;


};

// 经理类
class manager :public Worker
{
public:

	// 构造函数
	manager(int id, string name, string gender, string dep, string level, int jId,double days,double leavedays);
	// 显示个人信息
	virtual void showInfo();
	// 获取岗位名称
	virtual string getJobtName();
};

// 技术人员类
class technologist :public Worker
{
public:

	// 构造函数
	technologist(int id, string name, string gender, string dep, string level, int jId, double days, double leavedays);
	// 显示个人信息
	virtual void showInfo();
	// 获取岗位名称
	virtual string getJobtName();
};

// 销售人员类
class salesman:public Worker
{
public:

	// 构造函数
	salesman(int id, string name, string gender, string dep, string level, int jId, double days, double leavedays);
	// 显示个人信息
	virtual void showInfo();
	// 获取岗位名称
	virtual string getJobtName();
};

// 销售经理类
class salesmanager :public Worker
{
public:

	// 构造函数
	salesmanager(int id, string name, string gender, string dep, string level, int jId, double days, double leavedays);
	// 显示个人信息
	virtual void showInfo();
	// 获取岗位名称
	virtual string getJobtName();
};