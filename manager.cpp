#include"manager.h"

Manager::Manager(int id, int deptId, string name) {
	this->id = id;
	this->deptId = deptId;
	this->name = name;
}

//显示个人信息
void Manager::showInfo() {
	cout << "id: " <<this->id << endl;
	cout << "name: " << this->name << endl;
	cout << "deptNO: "<<this->getDeptName() << endl;
	cout << "job: " << "finish the job from boss,manage employees" << endl;
	cout <<"-----------------------------------" << endl;
}

//获得岗位名称
string Manager::getDeptName() {
	return "manager";
}