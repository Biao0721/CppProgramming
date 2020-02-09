#include<iostream>
#include<stdio.h>
#include<fstream> 
#include<vector>
#include<sstream> 
#include<string>
#include"function.h"
#include"employee.h"
#include"print.h"
using namespace std;

void addEmployee(listpoint1 *head) {
	while (head->next != NULL) {
		head = head->next;
	}
	listpoint1 *flag = (listpoint1*)malloc(sizeof(listpoint1));
	head->next = flag;
	flag->last = head;
	flag->next = NULL;
	flag->fireEmployee = false;
	flag->e = new fullTimeEmployee();
	head = flag;
}
void addEmployee(listpoint2 *head) {
	while (head->next != NULL) {
		head = head->next;
	}
	listpoint2 *flag = (listpoint2*)malloc(sizeof(listpoint2));
	head->next = flag;
	flag->last = head;
	flag->next = NULL;
	flag->fireEmployee = false;
	flag->e = new temporaryEmployee();
	head = flag;
}

void writeCsv(fullTimeEmployee e){
	ofstream outFile;
	outFile.open("C:\\Users\\87776\\Desktop\\fullTimeEmployee.csv", ios::app);
	outFile << e.getNum() << "," << e.getName() << "," << e.getGender() << "," << e.getAge() << "," << e.getAddress() << "," << e.getWages() << ","
		<< e.getMoney1() << "," << e.getMoney2() << "," << e.getMoney3() << "," << e.getMoney4() << "," << e.getMoney5() << "," << e.getSumMoney() << endl;
	outFile.close();
}
void writeCsv(temporaryEmployee e) {
	ofstream outFile;
	outFile.open("C:\\Users\\87776\\Desktop\\temporaryEmployee.csv", ios::app);
	outFile << e.getNum() << "," << e.getName() << "," << e.getGender() << "," << e.getAge() << "," << e.getAddress() << "," << e.getWages() << ","
		<< e.getMoney1() << "," << e.getMoney2() << "," << e.getSumMoney() << endl;
	outFile.close();
}

void readCsv(listpoint1 *temp) {
	temp->last = NULL;
	temp->next = NULL;
	vector<vector<string>> strArray;

	//��ȡ��ʽԱ��
	ifstream inFile("C:\\Users\\87776\\Desktop\\fullTimeEmployee.csv", ios::in||ios::out);
	string lineStr;
	
	while (getline(inFile, lineStr)) {
		stringstream ss(lineStr);       //��ȡcsv��һ�����ݲ�ȫ������ss��
		string str;
		vector<string> lineArray;
		while (getline(ss, str, ','))
			lineArray.push_back(str);   //һ��������vector����
		strArray.push_back(lineArray);  //ÿһ��vector����strArray��
	}

	if (strArray.size() <= 1) {
	}
	else {
		for (int i = 1; i < strArray.size(); i++) {
			listpoint1 *flag = (listpoint1*)malloc(sizeof(listpoint1));
			fullTimeEmployee *employee = new fullTimeEmployee(0);
			employee->setNum(stoi(strArray[i][0]));
			employee->setName(strArray[i][1]);
			employee->setGender(strArray[i][2]);
			employee->setAge(stoi(strArray[i][3]));
			employee->setAddress(strArray[i][4]);
			employee->setWages(stoi(strArray[i][5]));
			employee->setMoney1(stoi(strArray[i][6]));
			employee->setMoney2(stoi(strArray[i][7]));
			employee->setMoney3(stoi(strArray[i][8]));
			employee->setMoney4(stoi(strArray[i][9]));
			employee->setMoney5(stoi(strArray[i][10]));
			employee->setSumMoney();
			flag->e = employee;
			if (flag->e->getNum() < 0) {
				flag->fireEmployee = true;
			}
			else {
				flag->fireEmployee = false;
			}
			flag->last = temp;
			flag->next = NULL;
			temp->next = flag;
			temp = flag;
		}
		update(temp);
	}
	inFile.close();
}
void readCsv(listpoint2 *temp) {
	temp->last = NULL;
	temp->next = NULL;
	vector<vector<string>> strArray;

	//��ȡ��ʱԱ��
	ifstream inFile("C:\\Users\\87776\\Desktop\\temporaryEmployee.csv", ios::in);
	string lineStr;

	while (getline(inFile, lineStr)) {
		stringstream ss(lineStr);       //��ȡcsv��һ�����ݲ�ȫ������ss��
		string str;
		vector<string> lineArray;
		while (getline(ss, str, ','))
			lineArray.push_back(str);   //һ��������vector����
		strArray.push_back(lineArray);  //ÿһ��vector����strArray��
	}

	if (strArray.size() <= 1) {
	}
	else {
		for (int i = 1; i < strArray.size(); i++) {
			listpoint2 *flag = (listpoint2*)malloc(sizeof(listpoint2));
			temporaryEmployee *employee = new temporaryEmployee(0);
			employee->setNum(stoi(strArray[i][0]));
			employee->setName(strArray[i][1]);
			employee->setGender(strArray[i][2]);
			employee->setAge(stoi(strArray[i][3]));
			employee->setAddress(strArray[i][4]);
			employee->setWages(stoi(strArray[i][5]));
			employee->setMoney1(stoi(strArray[i][6]));
			employee->setMoney2(stoi(strArray[i][7]));
 			employee->setSumMoney();
			flag->e = employee;
			if (flag->e->getNum() < 0) {
				flag->fireEmployee = true;
			}
			else {
				flag->fireEmployee = false;
			}
			flag->last = temp;
			flag->next = NULL;
			temp->next = flag;
			temp = flag;
		}
		update(temp);
	}
	inFile.close();
}

void update(listpoint1 *temp) {
	listpoint1 *p = (listpoint1*)malloc(sizeof(listpoint1*));
	listpoint1 *q = (listpoint1*)malloc(sizeof(listpoint1*));
	listpoint1 *flag = (listpoint1*)malloc(sizeof(listpoint1*));
	listpoint1 *note = p;

	int i, j;
	for (p = temp; p->last; p = p->last) {
		for (q = p->last; q->last; q = q->last) {
			i = p->e->getSumMoney();
			j = q->e->getSumMoney();
			if (i < j) {
				flag->e = p->e;
				p->e = q->e;
				q->e = flag->e;
			}
		}
	}


}
void update(listpoint2 *temp) {
	listpoint2 *p = (listpoint2*)malloc(sizeof(listpoint2*));
	listpoint2 *q = (listpoint2*)malloc(sizeof(listpoint2*));
	listpoint2 *flag = (listpoint2*)malloc(sizeof(listpoint2*));

	int i, j;
	for (p = temp; p->last; p = p->last) {
		for (q = p->last; q->last; q = q->last) {
			i = p->e->getSumMoney();
			j = q->e->getSumMoney();
			if (i < j) {
				flag->e = p->e;
				p->e = q->e;
				q->e = flag->e;
			}
		}
	}
}

void printWages(listpoint1 *temp, int i) {
	listpoint1 *flag = temp->next;
	int num = 1;
	int sum = 0;
	for (; flag; flag = flag->next) {
		if (flag->fireEmployee) {
			continue;
		}
		sum += flag->e->getSumMoney();
		num++;
	}
	num--;
	if (i == 1) {
		cout << "                                **********************************************************\n\n";
		cout << "                                               ��ʽԱ�����ܹ���Ϊ��" << sum << endl;
		cout << "\n                                **********************************************************\n\n";
	}
	else{
		cout << "                                **********************************************************\n\n";
		cout << "                                               ��ʽԱ����ƽ������Ϊ��" << (sum / num) << endl;
		cout << "\n                                **********************************************************\n\n";
	}
}
void printWages(listpoint2 *temp, int i) {
	listpoint2 *flag = temp->next;
	int num = 1;
	int sum = 0;
	for (; flag; flag = flag->next) {
		if (flag->fireEmployee) {
			continue;
		}
		sum += flag->e->getSumMoney();
		num++;
	}
	num--;
	if (i == 1) {
		cout << "                                **********************************************************\n\n";
		cout << "                                               ��ʱԱ�����ܹ���Ϊ��" << sum << endl;
		cout << "\n                                **********************************************************\n\n";
	}
	else {
		cout << "                                **********************************************************\n\n";
		cout << "                                               ��ʱԱ����ƽ������Ϊ��" << (sum / num) << endl;
		cout << "\n                                **********************************************************\n\n";
	}
}

void printEmployee(listpoint1 *temp) {
	listpoint1 *flag = temp->next;
	for (; flag; flag = flag->next) {
		if (flag->fireEmployee) {
			continue;
		}
		cout << "                                            "<< flag->e->getName() << " " << flag->e->getSumMoney() << endl;
	}
}
void printEmployee(listpoint2 *temp) {
	listpoint2 *flag = temp->next;
	for (; flag; flag = flag->next) {
		if (flag->fireEmployee) {
			continue;
		}
		cout << "                                            " << flag->e->getName() << " " << flag->e->getSumMoney() << endl;
	}
}

listpoint1* findEmplpoyee(listpoint1 *head, int i) {
	listpoint1 *temp = head->next;
	string name;

	switch (i)
	{
	case 1:
		int num;
		cout << "                                                   �������ţ�";
		cin >> num;
		for (; temp; temp = temp->next) {
			if (abs(temp->e->getNum()) == num) {
				return temp;
			}
		}
		break;
	case 2:
		cout << "                                                   ������������";
		cin >> name;
		for (; temp; temp = temp->next) {
			if (temp->e->getName() == name) {
				return temp;
			}
		}
		break;
	case 3:
		int money;
		cout << "                                                   �����빤�ʣ�";
		cin >> money;
		for (; temp; temp = temp->next) {
			if (temp->e->getSumMoney() == money) {
				return temp;
			}
		}
		break;
	default:
		cout << "                                                   �����ʽ��������������";
		break;
	}

	return NULL;
}
listpoint2* findEmplpoyee(listpoint2 *head, int i) {
	listpoint2 *temp = head->next;
	string name;

	switch (i)
	{
	case 1:
		int num;
		cout << "                                                   �������ţ�";
		cin >> num;
		for (; temp; temp = temp->next) {
			if (abs(temp->e->getNum()) == num) {
				return temp;
			}
		}
		break;
	case 2:
		cout << "                                                   ������������";
		cin >> name;
		for (; temp; temp = temp->next) {
			if (temp->e->getName() == name) {
				return temp;
			}
		}
		break;
	case 3:
		int money;
		cout << "                                                   �����빤�ʣ�";
		cin >> money; 
		for (; temp; temp = temp->next) {
			if (temp->e->getSumMoney() == money) {
				return temp;
			}
		}
		break;
	default:
		cout << "                                                   �����ʽ��������������";
		break;
	}

	return NULL;
}

void printEmplpoyee(int i, int j, listpoint1 *head1, listpoint2 *head2) {
	if (i == 1) {
		listpoint1 *flag = findEmplpoyee(head1, j);
		if (flag == NULL) {
			cout << "                                                   δ�ҵ�Ŀ��ְԱ��Ŀ����ȫ�����";
		}
		else{
			print(flag);
		}
		if (j == 3 && flag->next) {
			printEmplpoyee(1, 3, flag, head2);
		}
	}
	else if(i == 2){
		listpoint2 *flag = findEmplpoyee(head2, j);
		if (flag == NULL) {
			cout << "                                                   δ�ҵ�Ŀ��ְԱ��Ŀ����ȫ�����";
		}
		else {
			print(flag);
		}
		if (j == 3 && flag->next) {
			printEmplpoyee(1, 3, head1, flag);
		}
	}
	else{
		cout << "                                                   ����Ա����������";
	}
}

void print(listpoint1 *flag) {
	cout << "                                                   ��ţ�" << abs(flag->e->getNum()) << endl;
	cout << "                                                   ������" << flag->e->getName() << endl;
	cout << "                                                   �Ա�" << flag->e->getGender() << endl;
	cout << "                                                   ���䣺" << flag->e->getAge() << endl;
	cout << "                                                   ��ͥסַ��" << flag->e->getAddress() << endl;
	cout << "                                                   ʵ�����ʣ�" << flag->e->getSumMoney() << endl << endl;

}
void print(listpoint2 *flag) {
	cout << "                                                   ��ţ�" << abs(flag->e->getNum()) << endl;
	cout << "                                                   ������" << flag->e->getName() << endl;
	cout << "                                                   �Ա�" << flag->e->getGender() << endl;
	cout << "                                                   ���䣺" << flag->e->getAge() << endl;
	cout << "                                                   ��ͥסַ��" << flag->e->getAddress() << endl;
	cout << "                                                   ʵ�����ʣ�" << flag->e->getSumMoney() << endl << endl;
}

void printEmployees(listpoint1 *head) {
	listpoint1 *temp = head->next;
	for (; temp; temp = temp->next) {
		if (temp->fireEmployee) {
			continue;
		}
		cout << endl;
		print(temp);
	}
}
void printEmployees(listpoint2 *head) {
	listpoint2 *temp = head->next;
	for (; temp; temp = temp->next) {
		if (temp->fireEmployee) {
			continue;
		}
		cout << endl;
		print(temp);
	}
}


void changeEmplpoyee(int i, listpoint1 *head1, listpoint2 *head2) {
	int j;//ѡ��Ҫ�޸�����
	string judge;
	int x;
	string y;

	if (i == 1) {
		listpoint1 *flag = findEmplpoyee(head1, 1);
		print(flag);
		printFunction5(head1);
		cin >> j;

		switch (j)
		{
		case 1:
			cout << "                                                   ԭ��ţ�" << flag->e->getNum() << endl;
			cout << "                                                   �޸ı�ţ�";
			cin >> x;
			cout << "                                                   �Ƿ�ȷ���޸�(�ǡ���";
			cin >> judge;
			if (judge == "��") {
				flag->e->setNum(x);
			}
			break;
		case 2:
			cout << "                                                   ԭ������" << flag->e->getName() << endl;
			cout << "                                                   �޸�������";
			cin >> y;
			cout << "                                                   �Ƿ�ȷ���޸�(�ǡ���";
			cin >> judge;
			if (judge == "��") {
				flag->e->setName(y);
			}
			break;
		case 3:
			cout << "                                                   ԭ�Ա�" << flag->e->getGender() << endl;
			cout << "                                                   �޸��Ա�";
			cin >> y;
			cout << "                                                   �Ƿ�ȷ���޸�(�ǡ���";
			cin >> judge;
			if (judge == "��") {
				flag->e->setGender(y);
			}
			break;
		case 4:
			cout << "                                                   ԭ���䣺" << flag->e->getAge() << endl;
			cout << "                                                   �޸����䣺";
			cin >> x;
			cout << "                                                   �Ƿ�ȷ���޸�(�ǡ���";
			cin >> judge;
			if (judge == "��") {
				flag->e->setAge(x);
			}
			break;
		case 5:
			cout << "                                                   ԭ��ͥסַ��" << flag->e->getAddress() << endl;
			cout << "                                                   �޸ļ�ͥסַ��";
			cin >> y;
			cout << "                                                   �Ƿ�ȷ���޸�(�ǡ���";
			cin >> judge;
			if (judge == "��") {
				flag->e->setAddress(y);
			}
			break;
		case 6:
			cout << "                                                   ԭ����ְ�����ʣ�" << flag->e->getWages() << endl;
			cout << "                                                   �޸Ļ���ְ�����ʣ�";
			cin >> x;
			cout << "                                                   �Ƿ�ȷ���޸�(�ǡ���";
			cin >> judge;
			if (judge == "��") {
				flag->e->setWages(x);
			}
			break;
		case 7:
			cout << "                                                   ԭ��λ������" << flag->e->getMoney1() << endl;
			cout << "                                                   �޸ĸ�λ������";
			cin >> x;
			cout << "                                                   �Ƿ�ȷ���޸�(�ǡ���";
			cin >> judge;
			if (judge == "��") {
				flag->e->setMoney1(x);
			}
			break;
		case 8:
			cout << "                                                   ԭ���Ͻ�" << flag->e->getMoney2() << endl;
			cout << "                                                   �޸����Ͻ�";
			cin >> x;
			cout << "                                                   �Ƿ�ȷ���޸�(�ǡ���";
			cin >> judge;
			if (judge == "��") {
				flag->e->setMoney2(x);
			}
			break;
		case 9:
			cout << "                                                   ԭס��������" << flag->e->getMoney3() << endl;
			cout << "                                                   �޸�ס��������";
			cin >> x;
			cout << "                                                   �Ƿ�ȷ���޸�(�ǡ���";
			cin >> judge;
			if (judge == "��") {
				flag->e->setMoney3(x);
			}
			break;
		case 10:
			cout << "                                                   ԭס��������" << flag->e->getMoney4() << endl;
			cout << "                                                   �޸�ס��������";
			cin >> x;
			cout << "                                                   �Ƿ�ȷ���޸�(�ǡ���";
			cin >> judge;
			if (judge == "��") {
				flag->e->setMoney4(x);
			}
			break;
		case 11:
			cout << "                                                   ԭס��������" << flag->e->getMoney5() << endl;
			cout << "                                                   �޸�ס��������";
			cin >> x;
			cout << "                                                   �Ƿ�ȷ���޸�(�ǡ���";
			cin >> judge;
			if (judge == "��") {
				flag->e->setMoney5(x);
			}
			break;
		default:
			cout << "                                                   �����޸���Ŵ�������������\n";
			break;
		}
	}
	else if (i == 2) {
	    listpoint2 *flag = findEmplpoyee(head2, 1);
		print(flag);
		printFunction5(head2);
		cin >> j;
		switch (j)
		{
		case 1:
			cout << "                                                   ԭ��ţ�" << flag->e->getNum() << endl;
			cout << "                                                   �޸ı�ţ�";
			cin >> x;
			cout << "                                                   �Ƿ�ȷ���޸�(�ǡ���";
			cin >> judge;
			if (judge == "��") {
				flag->e->setNum(x);
			}
			break;
		case 2:
			cout << "                                                   ԭ������" << flag->e->getName() << endl;
			cout << "                                                   �޸�������";
			cin >> y;
			cout << "                                                   �Ƿ�ȷ���޸�(�ǡ���";
			cin >> judge;
			if (judge == "��") {
				flag->e->setName(y);
			}
			break;
		case 3:
			cout << "                                                   ԭ�Ա�" << flag->e->getGender() << endl;
			cout << "                                                   �޸��Ա�";
			cin >> y;
			cout << "                                                   �Ƿ�ȷ���޸�(�ǡ���";
			cin >> judge;
			if (judge == "��") {
				flag->e->setGender(y);
			}
			break;
		case 4:
			cout << "                                                   ԭ���䣺" << flag->e->getAge() << endl;
			cout << "                                                   �޸����䣺";
			cin >> x;
			cout << "                                                   �Ƿ�ȷ���޸�(�ǡ���";
			cin >> judge;
			if (judge == "��") {
				flag->e->setAge(x);
			}
			break;
		case 5:
			cout << "                                                   ԭ��ͥסַ��" << flag->e->getAddress() << endl;
			cout << "                                                   �޸ļ�ͥסַ��";
			cin >> y;
			cout << "                                                   �Ƿ�ȷ���޸�(�ǡ���";
			cin >> judge;
			if (judge == "��") {
				flag->e->setAddress(y);
			}
			break;
		case 6:
			cout << "                                                   ԭ����ְ�����ʣ�" << flag->e->getWages() << endl;
			cout << "                                                   �޸Ļ���ְ�����ʣ�";
			cin >> x;
			cout << "                                                   �Ƿ�ȷ���޸�(�ǡ���";
			cin >> judge;
			if (judge == "��") {
				flag->e->setWages(x);
			}
			break;
		case 7:
			cout << "                                                   ԭ����" << flag->e->getMoney1() << endl;
			cout << "                                                   �޸Ľ���";
			cin >> x;
			cout << "                                                   �Ƿ�ȷ���޸�(�ǡ���";
			cin >> judge;
			if (judge == "��") {
				flag->e->setMoney1(x);
			}
			break;
		case 8:
			cout << "                                                   ԭ����˰��" << flag->e->getMoney2() << endl;
			cout << "                                                   �޸�����˰��";
			cin >> x;
			cout << "                                                   �Ƿ�ȷ���޸�(�ǡ���";
			cin >> judge;
			if (judge == "��") {
				flag->e->setMoney2(x);
			}
			break;
		default:
			cout << "                                                   �����޸���Ŵ�������������\n";
			break;
		}
	}
	else {
		cout << "                                                   ����Ա����������";
	}
}

void deleteEmplpoyee(int i, int j, listpoint1 *head1, listpoint2 *head2) {
	if (i == 1) {
		
		if (j == 1) {
			printEmployees(head1);
			cout << endl;
			listpoint1 *flag = findEmplpoyee(head1, 1);
			flag->fireEmployee = true;
		}
		else if (j == 2) {
			printEmployees(head1);
			cout << endl;
			listpoint1 *flag = findEmplpoyee(head1, 1);
			if (flag->next == NULL) {
				flag->last->next = NULL;
			}
			else {
				flag->last->next = flag->next;
				flag->next->last = flag->last;
			}
			delete(flag);
		}
		else if (j == 3) {
			printEmployees(head1);
			cout << endl;
			listpoint1 *flag = findEmplpoyee(head1, 1);
			flag->fireEmployee = false;
		}
		else{
			cout << "                                                   ����ɾ����������";
		}
	}
	else if(i == 2){
		if (j == 1) {
			printEmployees(head2);
			cout << endl;
			listpoint2 *flag = findEmplpoyee(head2, 1);
			flag->fireEmployee = true;
		}
		else if (j == 2) {
			printEmployees(head2);
			cout << endl;
			listpoint2 *flag = findEmplpoyee(head2, 1);
			if (flag->next == NULL) {
				flag->last->next = NULL;
			}
			else {
				flag->last->next = flag->next;
				flag->next->last = flag->last;
			}
			delete(flag);
		}
		else if (j == 3) {
			printEmployees(head2);
			cout << endl;
			listpoint2 *flag = findEmplpoyee(head2, 1);
			flag->fireEmployee = false;
		}
		else {
			cout << "                                                   ����ɾ����������";
		}
	}
	else {
		cout << "                                                   ����Ա����������";
	}
}

void saveEmployee(listpoint1 *head) {
	ofstream outFile1;
	outFile1.open("C:\\Users\\87776\\Desktop\\fullTimeEmployee.csv", ios::out);  //��ʽԱ��
	//������ͷ
	//������Ϣ��������š��������Ա����䡢��ͥסַ������ְ����
	outFile1 << "���" << ',' << "����" << "," << "�Ա�" << "," << "����" << "," << "��ͥסַ" << "," << "����ְ����" << ",";
	//���ӵ����԰�������λ���������Ͻ�ס������������˰��ҽ�Ʊ��ա�ʵ������
	outFile1 << "��λ����" << "," << "���Ͻ�" << "," << "ס��������" << "," << "����˰" << "," << "ҽ�Ʊ���" << "," << "ʵ������" << endl;
	

	listpoint1 *flag = head->next;
	for (; flag; flag = flag->next) {
		if (flag->fireEmployee) {
			flag->e->setNum(0 - flag->e->getNum());
		}
		writeCsv(*flag->e);
	}
}
void saveEmployee(listpoint2 *head) {
	ofstream outFile2;
	outFile2.open("C:\\Users\\87776\\Desktop\\temporaryEmployee.csv", ios::out); //��ʱԱ��
	//������Ϣ��������š��������Ա����䡢��ͥסַ������ְ����
	outFile2 << "���" << ',' << "����" << "," << "�Ա�" << "," << "����" << "," << "��ͥסַ" << "," << "����ְ����" << ",";
	//���ӵ����԰�������������˰��ʵ������
	outFile2 << "����" << "," << "����˰" << "," << "ʵ������" << endl;

	listpoint2 *flag = head->next;
	for (; flag; flag = flag->next) {
		if (flag->fireEmployee) {
			flag->e->setNum(0 - flag->e->getNum());
		}
		writeCsv(*flag->e);
	}
}