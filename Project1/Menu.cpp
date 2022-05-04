#include"PhoneBook.h"


int countabon = 3;

int number = 1;

PhoneBook* p = new PhoneBook[countabon]
{
	{number++, "Melnychuk Artem", "+380977345826"},
	{number++, "Bekas Oleksander","+380999999999"},
	{number++, "Zelensky Volodymyr", "+380666666666"}
};



string* MenuItems() 
{
	string* item = new string[5];
	item[0] = "1. Phone book";
	item[1] = "2. Add contact";
	item[2] = "3. Delete contact";
	item[3] = "4. Search contact";
	item[4] = "5. Exit";

	return item;
}



void MenuFun1()
{
	system("cls"); 


	cout << "Phone book" << endl;

	for (size_t i = 0; i < countabon; i++)
	{
		p[i].ShowPhoneBook();
	}	
	
	_getch();
	system("cls");
}

void MenuFun2()
{
	system("cls"); 

	p->AddAbon(p, &countabon, &number);
	
	_getch();
	system("cls");
}

void MenuFun3()
{
	system("cls"); 

	p->DelAbon(p, &countabon, &number);

	_getch();
	system("cls");
}

void MenuFun4()
{
	system("cls"); 

	char charsearch[30] = "";

	cout << "Enter name or surname: ";
	cin.getline(charsearch, 30);

	p->SearchAbon(p, charsearch, countabon);
	
	_getch();
	system("cls");
}

void ExitOption()
{
	delete[]p;
	cout << "Exitting..." << endl;
	_getch();
	exit(0);
}

