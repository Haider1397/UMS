#pragma once
#include<UMS/Core/Core.h>
namespace UMS
{
	class Person
	{
	public:
		Person();
		~Person();

		virtual void inputData(std::string id);
		virtual void displayData();
		virtual void saveDataToFile(std::ofstream& file);
		virtual void loadDataFromFile(std::ifstream& file);
		virtual void deleteData();
	protected:
		std::string m_name{};
		std::string m_id{};
		int m_age{};
		std::string m_email{};
		std::string m_phoneNo{};
	};
}