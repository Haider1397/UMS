#pragma once
#include<UMS/Core/Core.h>
#include<UMS/Core/Person.h>
namespace UMS
{
	class Teacher : public Person
	{
	public:
		Teacher();
		~Teacher();

		void inputData(std::string id);
		void deleteData();
		void displayData();
		void saveDataToFile(std::ofstream& file);
		void loadDataFromFile(std::ifstream& file);
	private:
		int m_salary{};
		std::string m_qualification{};
		int m_experience{};
		std::string m_hiringData{};
		std::string m_department{};
	};
}