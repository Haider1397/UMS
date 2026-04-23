#include<UMS/Student/Student.h>

UMS::Student::Student()
{
}

UMS::Student::~Student()
{
}

void UMS::Student::inputData(std::string id)
{
	UMS::Person::inputData(id);
	std::cout << "\n Enter Enrollment Date = ";
	std::cin >> m_enrollmentDate;
	std::cout << "\n Enter Enrolled Program = ";
	std::cin >> m_program;
	std::cout << "\n Enter Semeister = ";
	std::cin >> m_semester;
	std::cout << "\n Enter GPA = ";
	std::cin >> m_gpa;
	std::cout << "\n";
}

void UMS::Student::deleteData()
{
	Person::deleteData();
	m_enrollmentDate = {""};
	m_program = {""};
	m_semester = 0;
	m_gpa = 0;
}

void UMS::Student::displayData()
{
	UMS::Person::displayData();

	std::cout << "\n Enrollment Date = " << m_enrollmentDate;
	std::cout << "\n Enrolled Program = " << m_program;
	std::cout << "\n Semester = " << m_semester;
	std::cout << "\n GPA = " << m_gpa<<"\n";
}

void UMS::Student::saveDataToFile(std::ofstream& file)
{
	if (!file) return;

	file<< "{";
	Person::saveDataToFile(file);
	file << "," <<m_enrollmentDate<<","<<m_program<<","<<m_semester<<"," << m_gpa << "}\n";
}

void UMS::Student::loadDataFromFile(std::ifstream& file)
{
	char ch;

	if (!file) return;

	file >> ch;

	Person::loadDataFromFile(file);

	file >> ch;
	std::getline(file, m_enrollmentDate, ',');
	std::getline(file, m_program, ',');
	file >> m_semester;
	file >> ch;
	file >> m_gpa; 
	file >> ch;
}
