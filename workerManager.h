#pragma once//防止头文件重复包含
#include <iostream>
using namespace std;
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
#define FILENAME "empFIle.txt"


class WorkerManager {
public:
	WorkerManager();

	void showMenu();

	void exitSystem();

	void addEmp();

	void saveFile();

	//初始化职工
	void initEmp();

	void showEmp();

	void deleteEmp();

	int empIsExit(int id);

	void modityEmp();

	void findEmp();

	void sortEmp();

	void cleanFile();
	////////////////////////////////////////////
	int getEmpNum();

	bool fileIsEmpty;

	//记录员工人数
	int empNum;
	//职工数组的指针（使用指向指针的指针）
	Worker** empArray;

	


	~WorkerManager();

};