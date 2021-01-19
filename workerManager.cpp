#include"workerManager.h"

WorkerManager::WorkerManager() {

}

void WorkerManager::showMenu() {
	cout << "++++++++++++++++++++++" << endl;
	cout << "0.exit system" << endl;
	cout << "1.add employee" << endl;
	cout << "2.show employee data" << endl;
	cout << "3.delete employee" << endl;
	cout << "4.modify employee" << endl;
	cout << "5.find employee" << endl;
	cout << "6.sort by number" << endl;
	cout << "7.delete all files" << endl;
	cout << endl;
}

void WorkerManager::exitSystem() {
	cout << "thanks for using" << endl;
	system("pause");
	exit(0);
}

WorkerManager::~WorkerManager() {

}