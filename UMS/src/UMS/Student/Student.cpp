#include<UMS/Stundent/Student.h>

UMS::Student::Student(StudentDesc& desc):
	Person(desc.person)
{
	std::strcpy(m_id, desc.id);
}

void UMS::Student::inputData()
{
	UMS::Person::inputData();
}

void UMS::Student::displayData()
{
	UMS::Person::displayData;
}

