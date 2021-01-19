#include"boss.h"

Boss::Boss(int id, int deptId, string name) {
	this->id = id;
	this->deptId = deptId;
	this->name = name;
}

//显示个人信息
void Boss::showInfo() {
	cout << "id: "<<this->id << endl;
	cout << "name: "<<this->name << endl;
	cout << "deptNO: "<<this->getDeptName() << endl;
	cout << "job: "<<"just do nothing" << endl;
	cout << "-----------------------------------" << endl;
}

//获得岗位名称
string Boss::getDeptName() {
	return "boss";
}