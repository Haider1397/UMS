#pragma once
#include<UMS/Core/Core.h>
class Menus
{
public:
	Menus();
	~Menus();
	static void mainMenu();
	static void studentMenu();
	static void teacherMenu();

	static void displayStudent();
	static void addStudent();
	static void modifyStudent();
	static void deleteStudent();

	static void displayTeacher();
	static void addTeacher();
	static void modifyTeacher();
	static void deleteTeacher();

	static void exitMenu();
	static void invalidChoice();

};

