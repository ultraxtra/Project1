﻿#include "PhoneBook.h"

PhoneBook::PhoneBook()
{
	number = 0;
	FIO = new char[3]{"No"};
	MobPhone = new char[3]{ "No" };
}

PhoneBook::PhoneBook(int _number, const char* _fio, const char* _mobphone)
{
	int count_fio, count_mobphone;
	count_fio = strlen(_fio);
	count_mobphone = strlen(_mobphone);	
	
	FIO = new char[count_fio + 1];
	MobPhone = new char[count_mobphone + 1];

	number = _number;
	strcpy(FIO, _fio);
	strcpy(MobPhone, _mobphone);
}

PhoneBook::~PhoneBook()
{
	delete []FIO;
	delete []MobPhone;
}

void PhoneBook::AddAbon(PhoneBook* &p, int* countabon, int* _number)
{
	PhoneBook *temp = new PhoneBook [*countabon + 1];

	char _fio, _mobphone;

	int numbertmp = *_number;

	for (size_t i = 0; i < *countabon; i++)
	{
		temp[i].number = p[i].number;

		_fio = strlen(p[i].FIO);
		_mobphone = strlen(p[i].MobPhone);
		
		temp[i].FIO = new char[_fio + 1];
		temp[i].MobPhone = new char[_mobphone + 1];

		strcpy(temp[i].FIO, p[i].FIO);
		strcpy(temp[i].MobPhone, p[i].MobPhone);		
	}	


	temp[*countabon].number = numbertmp;	

	char buff[80];

	cout << "Enter surname and name: ";
	cin.getline(buff, 80);
	_fio = strlen(buff);
	temp[*countabon].FIO = new char[_fio + 1];
    strcpy (temp[*countabon].FIO, buff);

	cout << endl;

	cout << "Enter mobile phone: ";

	cin.getline(buff, 80);
	_mobphone = strlen(buff);
	temp[*countabon].MobPhone = new char[_mobphone + 1];
	strcpy(temp[*countabon].MobPhone, buff);
	
	(*countabon)++;
	(*_number)++;
		
	delete[]p;

	p = temp;

	cout << "Edited...\n";
	cout << "Press any key to enter menu...";
}


void PhoneBook::DelAbon(PhoneBook*& p, int* countabon, int* _number)
{
	char _fio, _mobphone;

	int numbertmp = *_number;

	int p_count = 0;

	int delnumber;

	int countdel= 0;

	cout << "Enter contact number for deleting: ";
	cin >> delnumber;
	cin.ignore();

	for (size_t i = 0; i < *countabon; i++)
	{
		if (p[i].number == delnumber)
		{
			(*countabon)--;
			countdel++;
		}	
	}

	PhoneBook* temp = new PhoneBook[*countabon];

	for (size_t i = 0; i < *countabon; i++)
	{
		if (p[p_count].number == delnumber)
		{
			p_count++;
			i--;
		}

		else if (p[p_count].number != delnumber)
		{
			temp[i].number = p[p_count].number;

			_fio = strlen(p[p_count].FIO);
			_mobphone = strlen(p[p_count].MobPhone);

			temp[i].FIO = new char[_fio + 1];
			temp[i].MobPhone = new char[_mobphone + 1];

			strcpy(temp[i].FIO, p[p_count].FIO);
			strcpy(temp[i].MobPhone, p[p_count].MobPhone);

			p_count++;
		}		
	}
 
	if (countdel)
	{		
		cout << "Edited...\n";		
	}
	
	delete[]p;
	p = temp;

	if (!countdel)
	{
		cout << "There is no such abonent\n";
		cout << "Enter any button to enter menu";
	}
}

PhoneBook::PhoneBook(const PhoneBook& obj)
{

	FIO = new char[strlen(obj.FIO) + 1];
	MobPhone = new char[strlen(obj.MobPhone) + 1];

	number = obj.number;
	strcpy(FIO, obj.FIO);
	strcpy(MobPhone, obj.MobPhone);	
}


void PhoneBook::SearchAbon(PhoneBook* p, char const* charsearch, int const countabon)
{
	int countsearch = 0;

	for (size_t i = 0; i < countabon; i++)
	{
		char* temp = strstr(p[i].FIO, charsearch);

		if (temp)
		{
			countsearch++;

		    if (countsearch == 1)
			{
				cout << "№" << " | " << "Contact" << endl;
			}

			cout << p[i].number << ". " << p[i].FIO << ". " << p[i].MobPhone << endl;
		}
	}

	if (countsearch < 1)
	{
		cout << "Contact does'nt exist" << endl;
		cout << "Enter any button to enter menu";		
	}
}

void PhoneBook::ShowPhoneBook()
{
	cout << number << ". ";	
	cout << "Surname, name: " << FIO;
	cout << endl;
	cout << "Phone: " << MobPhone;
	cout << endl;	
}

int PhoneBook::Getnumber()
{
	return number;
}

char PhoneBook::GetFIO()
{
	return *FIO;
}

char PhoneBook::GetMobPhone()
{
	return *MobPhone;
}