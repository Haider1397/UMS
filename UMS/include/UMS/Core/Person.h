#pragma once
#include<UMS/Core/Core.h>
namespace UMS
{
	class Person
	{
	public:
		Person(PersonDesc& desc);
		virtual ~Person();

	protected:
		virtual void inputData();
		virtual void displayData();

		char m_id[10]{};
	private:

		char m_name[50]{};
	};
}
