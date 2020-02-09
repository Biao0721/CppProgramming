#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#include<string>
using namespace std;

/*
ְ���������������ʽְ������ʱ����
����һ��������ְ���࣬������Ϣ��������š��������Ա����䡢��ͥסַ������ְ���ʡ�
*/

class employee {
private:
	int num = 0;             //ְ�����
	string name = "";        //ְ������
	string gender = "";      //�Ա�
	int age = 0;             //����
	string address = "";     //��ͥסַ
	int wages = 0;           //����ְ����
public:
	void setNum(int _num);
	void setName(string _name);
	void setGender(string _gender);
	void setAge(int _age);
	void setAddress(string _address);
	void setWages(int _wages);
	void set();
	int getNum();
	string getName();
	string getGender();
	int getAge();
	string getAddress();
	int getWages();
	employee();

};

/*��������ʽְ���࣬���ӵ����԰�������λ���������Ͻ�ס������������˰��ҽ�Ʊ��ա�ʵ������*/
class fullTimeEmployee : public employee {
private:
	int moreMoney1 = 0;  //��λ����
	int moreMoney2 = 0;  //���Ͻ�
	int moreMoney3 = 0;  //ס��������
	int moreMoney4 = 0;  //����˰
	int moreMoney5 = 0;  //ҽ�Ʊ���
	int sumMoney = 0;    //ʵ������
public:
	void setMoney1(int _moreMoney1);
	void setMoney2(int _moreMoney2);
	void setMoney3(int _moreMoney3);
	void setMoney4(int _moreMoney4);
	void setMoney5(int _moreMoney5);
	void setSumMoney();
	void set();
	int getMoney1();
	int getMoney2();
	int getMoney3();
	int getMoney4();
	int getMoney5();
	int getSumMoney();
	fullTimeEmployee();
	fullTimeEmployee(int i);
};

/*��ʱ�����ӵ����԰�������������˰��ʵ������*/
class temporaryEmployee : public employee {
	int moreMoney1 = 0;   //����
	int moreMonry2 = 0;   //����˰
	int sumMoney = 0;     //ʵ������
public:
	void setMoney1(int _moreMoney1);
	void setMoney2(int _moreMoney2);
	void setSumMoney();
	void set();
	int getMoney1();
	int getMoney2();
	int getSumMoney();
	temporaryEmployee();
	temporaryEmployee(int i);
};

#endif // !EMPLOYEE_H_

#pragma once