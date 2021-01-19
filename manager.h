#pragma once
#include"worker.h"

class Manager :public Worker {
public:
	Manager(int id, int deptId, string name);

	//显示个人信息
	void showInfo();

	//获得岗位名称
	string getDeptName();
};