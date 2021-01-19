#pragma once
#include<iostream>
using namespace std;
#include<string>

//职工抽象类---不需要有cpp文件
class Worker {
public:
	int id;
	int deptId;
	string name;

	//显示个人信息
	virtual void showInfo() = 0;

	//获得岗位名称
	virtual string getDeptName() = 0;
};