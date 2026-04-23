#include<UMS/Core/Menus.h>
#include<UMS/Core/Base.h>

int main()
{
	UMS::Base m_UMS{};
	m_UMS.m_studentManagement->loadDataFromFile();
	m_UMS.m_teacherManagement->loadDataFromFile();
	std::string id{};
	char choice{};
	bool mainMenuRunning = true;

	while (mainMenuRunning)
	{
		Menus::mainMenu();
		std::cin >> choice;
		if (choice == '1')
		{
			bool MenuRunning = true;
			while (MenuRunning)
			{
				Menus::studentMenu();
				std::cin >> choice;
				if (choice == '1')
				{
					Menus::displayStudent();
					std::cin >> id;
					m_UMS.m_studentManagement->displayData(id);
					id = "";
				}
				else if (choice == '2')
				{
					Menus::addStudent();
					m_UMS.m_studentManagement->addData();
				}
				else if (choice == '3')
				{
					Menus::modifyStudent();
					std::cin >> id;
					m_UMS.m_studentManagement->updateData(id);
					id = "";
				}
				else if (choice == '4')
				{
					Menus::deleteStudent();
					std::cin >> id;
					m_UMS.m_studentManagement->deleteData(id);
					id = "";
				}
				else if (choice == '0')
				{
					MenuRunning = false;
				}
				else
					Menus::invalidChoice();

			}
		}
		else if (choice == '2')
		{
			bool MenuRunning = true;
			while (MenuRunning)
			{
				Menus::teacherMenu();
				std::cin >> choice;
				if (choice == '1')
				{
					Menus::displayTeacher();
					std::cin >> id;
					m_UMS.m_teacherManagement->displayData(id);
					id = "";
				}
				else if (choice == '2')
				{
					Menus::addTeacher();
					m_UMS.m_teacherManagement->addData();
				}
				else if (choice == '3')
				{
					Menus::modifyTeacher();
					std::cin >> id;
					m_UMS.m_teacherManagement->updateData(id);
					id = "";
				}
				else if (choice == '4')
				{
					Menus::deleteTeacher();
					std::cin >> id;
					m_UMS.m_teacherManagement->deleteData(id);
					id = "";
				}
				else if (choice == '0')
				{
					MenuRunning = false;
				}
				else
					Menus::invalidChoice();

			}
		}
		else if (choice == '0')
		{
			Menus::exitMenu();
			mainMenuRunning = false;
		}
		else
			Menus::invalidChoice();
	}
	m_UMS.m_studentManagement->saveDataToFile();
	m_UMS.m_teacherManagement->saveDataToFile();
}