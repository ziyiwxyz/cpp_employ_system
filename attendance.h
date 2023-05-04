/*#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

class hoursconverttodays:public Worker
{public:
	
	void converttohours(double days);
	void converttodays(int hours);
	int gethours();
	double getdays();
};

class sickandleave:public hoursconverttodays
{public:
	double sickleave;//员工生病没工作的天数
	double sickleaveMax=2;//生病可以不工作的天数 16小时
	double paidleave;//员工已经带薪休假的天数 
	double paidleaveMax=3;//员工可以带薪休假的天数 24小时
	double paiddays;//员工可以算工资的天数 paiddays=sickleave+paidleave
};*/