﻿#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <string.h>
#include <conio.h>
#include <iomanip>


using namespace std;


class PhoneBook
{

private:

	int number;
	char* FIO;
	char* MobPhone;

public:
	
	PhoneBook();
	PhoneBook(int _number, const char *_fio, const char* _mobphone);
	
	PhoneBook(const PhoneBook& obj);

	void SearchAbon(PhoneBook* p, char const* charsearch, int const countabon);

	void AddAbon(PhoneBook*& p, int* countabon, int* _number);

	void DelAbon(PhoneBook*& p, int* countabon, int* _number);

	~PhoneBook();

	void ShowPhoneBook();

	int Getnumber();
	char GetFIO();
	char GetMobPhone();

};





void MenuFun1();
void MenuFun2();
void MenuFun3();
void MenuFun4();

void ExitOption();
