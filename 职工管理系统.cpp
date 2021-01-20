#include<iostream>
using namespace std;
#include"workerManager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

int main() {
	//test though
	/*Worker* worker = NULL;
	worker = new Employee(1, 1, "zhangsan");
	worker->showInfo();
	delete worker;

	worker = new Manager(1, 1, "lisi");
	worker->showInfo();
	delete worker;

	worker = new Boss(1, 1, "wangwu");
	worker->showInfo();
	delete worker;*/
	////////////////////////////////////////////
	WorkerManager wm;
	
	int choice = 0;
	while (true)
	{
		wm.showMenu();
		cout << "please input your choice" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			wm.exitSystem();
			break;
		case 1:
			wm.addEmp();
			break;
		case 2:
			wm.showEmp();
			break;
		case 3:
			wm.deleteEmp();
			break; 		
		case 4:
			wm.modityEmp();
			break;
		case 5:
			wm.findEmp();
			break;
		case 6:
			wm.sortEmp();
			break;
		case 7:
			wm.cleanFile();
			break;
		default:
			system("cls");
			break;
		}
	}



	system("pause");
	return 0;
}
//p153