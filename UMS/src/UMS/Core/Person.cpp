#include <UMS/Core/Person.h>

UMS::Person::Person()
{
}

UMS::Person::~Person()
{
}

void UMS::Person::inputData(std::string id)
{
	m_id = id;
	std::cout << "\n Enter Name = ";
	std::cin >> m_name;
	std::cout << "\n Enter Age = ";
	std::cin >> m_age;
	std::cout << "\n Enter Email = ";
	std::cin >> m_email;
	std::cout << "\n Enter Phone No = ";
	std::cin >> m_phoneNo;
}

void UMS::Person::displayData()
{
	std::cout << "\n ID = " << m_id;
	std::cout << "\n Name = " << m_name;
	std::cout << "\n Age = " << m_age;
	std::cout << "\n Email = " << m_email;
	std::cout << "\n Phone No = " << m_phoneNo;
}

void UMS::Person::saveDataToFile(std::ofstream& file)
{
	if (!file) return;

	file << "(" << m_id << "," << m_name << "," << m_age << "," << m_email << "," << m_phoneNo << ")";

}

void UMS::Person::loadDataFromFile(std::ifstream& file)
{
    if (!file) return;

    char ch;

    file >> ch;
    std::getline(file, m_id, ',');
    std::getline(file, m_name, ',');
	file >> m_age;
	file >> ch;
    std::getline(file, m_email, ',');
    std::getline(file, m_phoneNo, ')');

}

void UMS::Person::deleteData()
{
	m_name = "";
	m_age = 0;
	m_email = "";
	m_phoneNo = "";
}
