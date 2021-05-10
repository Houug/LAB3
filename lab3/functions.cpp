#define _CRT_SECURE_NO_WARNINGS

#include "functions.h"
#include <cstring>
#include <iostream>
#include "Clinic.h"
using namespace std;

int checkInput(int n, int mode)
{
	if (mode == 0)
	{
		switch (n)
		{
		case 1:
			return 0;
		case 2:
			return 0;
		case 3:
			return 0;
		default:
			return 1;
		}
	}
	if (mode == 1)
	{
		switch (n)
		{
		case 0:
			return 0;
		case 1:
			return 0;
		case 2:
			return 0;
		default:
			return 1;
		}
	}

}
void printHeader()
{
	printf("\n========================================================================\n");
	printf("%40s %15s %15s\n", "�.�.� �����", "C������������", "������������");
	printf("========================================================================\n");
}
void printMenu()
{
	printf("\n\n***************����**************\n");
	printf("1 - �������� ����� � ����\n2 - ����� ����� �� �.�.�\n3 - ����� ������ �� ������������� � ������������\n4 - ���������� ���� �� ��������\n5 - ����� ���� � �������\n6 - ��������� ������\n7 - ����� �� ���������");
	printf("\n*********************************\n");
}
bool checkInput()
{
	using namespace std;
	if (!cin)
	{
		cout << endl << "�������������� ������ �����!" << endl;
		cin.clear();
		cin.ignore(255, '\n');
		return true;
	}
	return false;
}
Clinic findDoctor(Clinic* m)
{
	char bufSurname[20], bufName[20], bufFather[20];
	int count = 0;
	Clinic foundDoctor;

	printf("����� ����� �� �.�.�\n");
	printf("\n������� �������: ");
	scanf("%20s", bufSurname);
	printf("\n������� ���: ");
	scanf("%20s", bufName);
	printf("\n������� ��������: ");
	scanf("%20s", bufFather);

	for (int i = 0; i < m->getCount() - 1; i++)
	{
		if ((strncmp(bufSurname, m[i].fio.getSurname(), strlen(bufSurname)) == 0) &&
			(strncmp(bufName, m[i].fio.getName(), strlen(bufName)) == 0) &&
			(strncmp(bufFather, m[i].fio.getFather(), strlen(bufFather)) == 0))
		{
			count++;
			equate(foundDoctor, m[i]);
			//foundDoctor = m[i];
			break;
		}
	}
	if (count == 0) printf("����� �� ����� ���������\n");
	else
	{
		printHeader();
		foundDoctor.printDoctor(0);
		return foundDoctor;
	}
}

void equate(Clinic& obj1, Clinic& obj2)
{
	obj1.fio.setSurname(obj2.fio.getSurname());
	obj1.fio.setName(obj2.fio.getName());
	obj1.fio.setFather(obj2.fio.getFather());
	obj1.setQualificationId(obj2.getQualificationId());
	obj1.setSpecialtyId(obj2.getSpecialtyId());
}

std::istream& operator>>(std::istream& in, Clinic& obj)
{
	char buf[20];

	cout << "������� �������: ";
	in >> buf;
	obj.fio.setSurname(buf);
	cout << "������� ���: ";
	in >> buf;
	obj.fio.setName(buf);
	cout << "������� ��������: ";
	in >> buf;
	obj.fio.setFather(buf);

	cout << "������� ������������� (1-3): ";
	do
	{
		in >> obj.specialty;
	} while (checkInput(obj.specialty, 0));

	cout << "������� ������������ (0-2): ";
	do
	{
		in >> obj.qualification;
	} while (checkInput(obj.qualification, 1));

	return in;
}
