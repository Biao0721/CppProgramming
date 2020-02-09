#include<iostream>
#include<stdio.h>
#include"employee.h"
#include"function.h"
#include"print.h"
using namespace std;

int main() {
	listpoint1 *temp1, *head1;
	listpoint2 *temp2, *head2;

	temp1 = head1 = (listpoint1*)malloc(sizeof(listpoint1));
	temp2 = head2 = (listpoint2*)malloc(sizeof(listpoint2));

	while (true) {
		readCsv(temp1);
		readCsv(temp2);

		printFunction();
		
		int flag;
		cin >> flag;
		
		system("cls");

		if (flag == 8) {
			exit(1);
		}

		int i, j;
		switch (flag)
		{
		case 1://ƥ������
			printFunction1();
			cin >> i;
			system("cls");
			if (i == 1 || i == 2) {
				printFunction1(head1, i);
				printFunction1(head2, i);
			}
			else
			{
				cout << "                                                       �����������������\n";
			}
			cout << "                                                 ";
			system("pause");
			break;
		case 2://����ʵ�������������
			printFunction2(head1, head2);
			cout << "                                                 ";
			system("pause");
			break;
		case 3://������Ա��
			printFunction3();
			cin >> i;
			if (i == 1) {
				addEmployee(temp1);
			}
			else if (i == 2) {
				addEmployee(temp2);
			}
			else {
				cout << "                                                       �����������������\n";
			}
			break;
		case 4://��ѯ����
			printFunction4();
			cin >> i;//ѡ����Ҫ��ѯ��Ա������
			system("cls");
			printFunction4(" ");
			cin >> j;//ѡ����Ĳ�ѯ��ʽ
			printEmplpoyee(i, j, head1, head2);
			cout << "\n                                                   ";
			system("pause");
			break;
		case 5://�޸ļ�¼
			printFunction4();
			cin >> i;
			system("cls");
			changeEmplpoyee(i, head1, head2);
			cout << "\n                                                   ";
			system("pause");
			break;
		case 6://ɾ����¼
			printFunction4();
			cin >> i;//Ҫѡ��ɾ����Ա������
			printFunction6();
			cin >> j;//Ҫѡ��ɾ���ķ�ʽ
			deleteEmplpoyee(i, j, head1, head2);
			cout << "\n                                                   ";
			system("pause");
			break;
		case 7:
			cout << "                                **********************************************************\n";
			cout << endl;
			cout << "                                                   ��ʽԱ����" << endl;
			printEmployees(head1);
			cout << endl;
			cout << "                                **********************************************************\n" << endl;
			cout << "                                                   ��ʱԱ����" << endl;
			printEmployees(head2);
			cout << endl;
			cout << "                                **********************************************************\n";
			cout << "                                                   ";
			system("pause");
			break;
		default:
			cout << "                                                       �����������������\n";
			break;
		}
		system("cls");
		saveEmployee(head1);
		saveEmployee(head2);
	}

	return 0;
}