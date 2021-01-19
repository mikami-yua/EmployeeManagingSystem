#pragma once
#include"worker.h"

class Employee :public Worker {
public:

	Employee(int id,int deptId,string name);

	//显示个人信息
	void showInfo();

	//获得岗位名称
	string getDeptName();
};