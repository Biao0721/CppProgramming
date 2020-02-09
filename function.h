#ifndef FUNCTION_H_
#define FUNCTION_H_
#include<fstream>
#include"employee.h"
using namespace std;
//typedef struct listpoint1 listpoint1;//���������ʽ�ݴ���ʽԱ��
//typedef struct listpoint2 listpoint2;//���������ʽ�ݴ���ʱԱ��
typedef struct listpoint1 {
	fullTimeEmployee *e;
	bool fireEmployee = false;
	struct listpoint1 *next;
	struct listpoint1 *last;
}listpoint1;
typedef struct listpoint2 {
	temporaryEmployee *e;
	bool fireEmployee = false;
	struct listpoint2 *next;
	struct listpoint2 *last;
}listpoint2;
void addEmployee(listpoint1 *head);//������ʽԱ��
void addEmployee(listpoint2 *head);//������ʱԱ��
void writeCsv(fullTimeEmployee e);
void writeCsv(temporaryEmployee e);
void readCsv(listpoint1 *temp);//��ȡcsv�ļ�
void readCsv(listpoint2 *temp);//��ȡCsv�ļ�
void update(listpoint1 *temp);
void update(listpoint2 *temp);
void printWages(listpoint1 *temp, int i);
void printWages(listpoint2 *temp, int i);
void printEmployee(listpoint1 *temp);
void printEmployee(listpoint2 *temp);
void print(listpoint1 *flag);
void print(listpoint2 *flag);
void printEmployees(listpoint1 *head);
void printEmployees(listpoint2 *head);
listpoint1* findEmplpoyee(listpoint1 *head, int i);
listpoint2* findEmplpoyee(listpoint2 *head, int i);
void printEmplpoyee(int i, int j, listpoint1 *head1, listpoint2 *head2);
void changeEmplpoyee(int i,listpoint1 *head1,listpoint2 *head2);
void deleteEmplpoyee(int i, int j, listpoint1 *head1, listpoint2 *head2);
void saveEmployee(listpoint1 *head);
void saveEmployee(listpoint2 *head);
#endif // !FUNCTION_H_

#pragma once
