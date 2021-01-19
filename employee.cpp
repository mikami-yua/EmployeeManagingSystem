#include"employee.h"

Employee::Employee(int id, int deptId, string name) {
	this->id = id;
	this->deptId = deptId;
	this->name = name;
}

//显示个人信息
void Employee::showInfo() {
	cout << this->id << "\t" << this->name << "\t" << this->getDeptName()
		<< "\t" << "just work" << endl;
}

//获得岗位名称
string Employee::getDeptName() {
	return "employee";
}