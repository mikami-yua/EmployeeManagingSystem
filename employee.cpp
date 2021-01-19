#include"employee.h"

Employee::Employee(int id, int deptId, string name) {
	this->id = id;
	this->deptId = deptId;
	this->name = name;
}

//显示个人信息
void Employee::showInfo() {
	cout <<"id: "<< this->id << endl;
	cout <<"name: "<<this->name <<endl;
	cout << "deptNO: "<<this->getDeptName() << endl;
	cout <<"job: " <<"just work" << endl;
	cout << "-----------------------------------" << endl;
}

//获得岗位名称
string Employee::getDeptName() {
	return "employee";
}