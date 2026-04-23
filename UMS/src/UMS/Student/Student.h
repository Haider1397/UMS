#pragma once
#include<UMS/Core/Core.h>
#include<UMS/Core/Person.h>
namespace UMS
{
	class Student: public Person
	{
	public:
		Student();
		~Student();

		void inputData(std::string id);
		void deleteData();
		void displayData();
		void saveDataToFile(std::ofstream& file);
		void loadDataFromFile(std::ifstream& file);
	private:
		std::string m_enrollmentDate{};
		std::string m_program{};
		int m_semester{};
		float m_gpa{};
	};
}