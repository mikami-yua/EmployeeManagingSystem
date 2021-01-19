#include"workerManager.h"

WorkerManager::WorkerManager() {
	//1.文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open()) {
		cout << "file is not exit!" << endl;
		//初始化数据
		this->empNum = 0;
		this->empArray = NULL;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	//2.文件存在，数据空（右移一个字符看是否为空）
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "file is empty!" << endl;
		//初始化数据
		this->empNum = 0;
		this->empArray = NULL;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	//3.文件存在且也有数据
	int num = this->getEmpNum();
	//cout << "the number of employees is: " << num << endl;
	this->empNum = num;

	//开辟空间
	this->empArray = new Worker * [this->empNum];
	//文件中的数据传入数组中
	this->initEmp(); 
	
	return;
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

void WorkerManager::addEmp() {
	cout << "input the number of employees you want to add" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0) {
		//计算需要添加的空间大小
		int newSize = this->empNum + addNum;

		//开辟新空间
		Worker** newSpace = new Worker * [newSize];
		//将原来空间下的数据拷贝到新的数组
		if (this->empArray != NULL) {
			for (int i = 0; i < this->empNum; i++) {
				newSpace[i] = this->empArray[i];
			}
		}
		//添加新的数据
		for (int i = 0; i < addNum; i++) {
			int id;
			string name;
			int deptId;
			cout << "please input No."<<i+1<<" employee you want to add" << endl;
			cout << "please input id: " ;
			cin >> id;
			cout << "please input name: ";
			cin >> name;
			cout << "please input deptId(1:employee  2:manager  3:boss): ";
			cin >> deptId;
			Worker* worker = NULL;
			switch (deptId)
			{
			case 1:
				worker = new Employee(id, deptId, name);
				break;
			case 2:
				worker = new Manager(id, deptId, name);
				break;
			case 3:
				worker = new Boss(id, deptId, name);
				break;
			default:
				break;
			}
			//将创建的worker*保存到数组中
			newSpace[this->empNum + i] = worker;

		}
		//原有的空间已经拷贝，需要释放
		delete[] this->empArray;
		//更改新空间的指向
		this->empArray = newSpace;
		this->empNum = newSize;
		//更新文件是否为空的标志
		this->fileIsEmpty = false;
		cout << "succsee add " << addNum << " employees!" <<endl;
		//添加成功保存到文件中------程序执行结束堆区也会释放，写到磁盘进行持久化
		this->saveFile();

	}
	else
	{
		cout<<"hte number is error"<<endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::saveFile() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->empNum; i++) {
		ofs << this->empArray[i]->id << " "
			<< this->empArray[i]->name << " "
			<< this->empArray[i]->deptId << endl;
	}
	ofs.close();
}

int WorkerManager::getEmpNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;
	while (ifs>>id && ifs>>name && ifs>>dId)
	{
		num++;
	}
	ifs.close();
	return num;
}

void WorkerManager::initEmp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		if (dId == 1) {
			worker = new Employee(id, dId, name);
		}
		else if (dId == 2) {
			worker = new Manager(id, dId, name);
		}
		else
		{
			worker = new Boss(id, dId, name);
		}
		this->empArray[index] = worker;
		index++;
	}
	ifs.close();
}

void WorkerManager::showEmp() {
	if (this->fileIsEmpty) {
		cout << "file is empty or not exit" << endl;
		return;
	}
	//不用读文件了，因为已经在构造函数中吧文件内容初始化到内存中
	for (int i = 0; i < this->empNum; i++) {
		this->empArray[i]->showInfo();
	}
	system("pause");
	system("cls");
}

int WorkerManager::empIsExit(int id) {
	int index = -1;
	for (int i = 0; i < this->empNum; i++) {
		if (this->empArray[i]->id == id) {
			index = i;
			break;
		}
	}
	return index;
}

void WorkerManager::deleteEmp() {//数据前移
	if (this->fileIsEmpty) {
		cout << "file is empty or not exit" << endl;
		return;
	}
	else {
		cout << "please input the id you want to delete" << endl;
		int id;
		cin >> id;
		int index = this->empIsExit(id);
		if (index != -1) {
			for (int i = index; i < this->empNum - 1; i++) {
				this->empArray[i] = this->empArray[i + 1];
			}
			this->empNum--;//更新数组中记录人员的个数
			//同步到文件
			this->saveFile();
			cout << "delete successful!" << endl;
		}
		else
		{
			cout << "fail to delete cannot find this id! " << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::modityEmp() {
	if (this->fileIsEmpty) {
		cout << "file is empty or not exit" << endl;
		return;
	}
	else {
		cout << "please input the id you want to modify" << endl;
		int id;
		cin >> id;
		int index = this->empIsExit(id);
		if (index != -1) {
			delete this->empArray[index];//释放原有堆区的数据
			int newid;
			string newname;
			int newDId;
			cout << "find id:" << id << " please input new info" << endl;
			cout << "please input new id:";
			cin >> newid;
			cout << "please input new name:";
			cin >> newname;
			cout << "please input new deptid(1.employee 2.manager 3.boss):";
			cin >> newDId;
			Worker* worker = NULL;
			switch (newDId)
			{
			case 1:
				worker = new Employee(newid, newDId, newname);
				break;
			case 2:
				worker = new Manager(newid, newDId, newname);
				break;
			case 3:
				worker = new Boss(newid, newDId, newname);
				break;
			default:
				break;
			}
			//更新数据到数组中
			this->empArray[index] = worker;
			cout << "modify successful" << endl;
			//保存到文件中
			this->saveFile();
		}
		else
		{
			cout << "fail to modify cannot find this id! " << endl;
		}

	}
	system("pause");
	system("cls");
}

void WorkerManager::findEmp() {
	if (this->fileIsEmpty) {
		cout << "file is empty or not exit" << endl;
		return;
	}
	else{
		cout << "please input the type fining employee(1.byId  2.byName):";
		int select;
		cin >> select;
		if (select == 1) {
			int id;
			cout << "please input id:" << endl;
			cin >> id;
			int index = this->empIsExit(id);
			if (index != -1) {
				cout << "successfully find" << endl;
				this->empArray[index]->showInfo();
				cout << "------------" << endl;
			}
			else {
				cout << "cannot find this person" <<endl;
			}
		}
		else if (select == 2) {
			string name;
			cout << "please input name:" << endl;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < this->empNum; i++) {
				if (this->empArray[i]->name == name) {
					cout << "successful find this one id:" << this->empArray[i]->id << endl;
					this->empArray[i]->showInfo();
					flag = true;
				}
			}
			if (flag == false) {
				cout << "cannot find this person" << endl;
			}
		}
		else {
			cout << "erroe type!" << endl;
		}

	}
	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager() {
	if (this->empArray != NULL) {//可以不写
		delete[] this->empArray;
		this->empArray = NULL;
	}
}