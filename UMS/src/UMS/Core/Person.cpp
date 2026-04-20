#include<UMS/Core/Person.h>

UMS::Person::Person(PersonDesc& desc)
{
	std::strcpy(m_name, desc.name);
}

UMS::Person::~Person()
{
}

void UMS::Person::inputData()
{
	std::cout << "\n Enter Name = ";
	std::cin >> m_name;
}

void UMS::Person::displayData()
{
	std::cout << "\n Name = " << m_name;
}
