#pragma once
#include<UMS/Core/Core.h>
#include<UMS/Core/Person.h>
namespace UMS
{
	class Student: public Person
	{
	public:
		Student(StudentDesc& desc);
		virtual void inputData();
		virtual void displayData();
	private:
	};
}