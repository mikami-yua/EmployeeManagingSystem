#include<iostream>
using namespace std;
#include"workerManager.h"
#include"worker.h"
#include"employee.h"

int main() {
	//test though
	Worker* worker = NULL;
	worker = new Employee(1, 1, "zhangsan");
	worker->showInfo();

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
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		default:
			system("cls");
			break;
		}
	}



	system("pause");
	return 0;
}