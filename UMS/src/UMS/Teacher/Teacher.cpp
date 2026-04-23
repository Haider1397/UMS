#include <UMS/Teacher/Teacher.h>

UMS::Teacher::Teacher()
{
}

UMS::Teacher::~Teacher()
{
}


void UMS::Teacher::inputData(std::string id)
{
	UMS::Person::inputData(id);
	std::cout << "\n Enter Salary = ";
	std::cin >> m_salary;
	std::cout << "\n Enter Experience = ";
	std::cin >> m_experience;
	std::cout << "\n Enter Hiring Date = ";
	std::cin >> m_hiringData;
	std::cout << "\n Enter Qualification = ";
	std::cin >> m_qualification;
	std::cout << "\n Enter Department = ";
	std::cin >> m_department;
	std::cout << "\n";
}

void UMS::Teacher::deleteData()
{
	Person::deleteData();
	m_salary = 0;
	m_experience = 0;
	m_hiringData = "";
	m_qualification = "";
	m_department = "";
}

void UMS::Teacher::displayData()
{
	UMS::Person::displayData();
	std::cout << "\n Salary = " << m_salary;
	std::cout << "\n Experience = " << m_experience ;
	std::cout << "\n Hiring Date = " << m_hiringData ;
	std::cout << "\n Qualification = " << m_qualification ;
	std::cout << "\n Department = " << m_department << "\n";
}

void UMS::Teacher::saveDataToFile(std::ofstream& file)
{
	if (!file) return;

	file << "{";
	Person::saveDataToFile(file);
	file << "," << m_salary;
	file << "," << m_experience;
	file << "," << m_hiringData;
	file << "," << m_qualification;
	file << "," << m_department << "}\n";
}

void UMS::Teacher::loadDataFromFile(std::ifstream& file)
{
	char ch;

	if (!file) return;

	file >> ch;

	Person::loadDataFromFile(file);

	file >> ch;
	file >> m_salary;
	file >> ch;
	file >> m_experience;
	file >> ch;
	std::getline(file, m_hiringData, ',');
	std::getline(file, m_qualification, ',');
	std::getline(file, m_department, '}');
}
