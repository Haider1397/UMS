#include<UMS/Core/Core.h>
#include<UMS/Management/Management.h>
#include<UMS/Student/Student.h>
#include<UMS/Teacher/Teacher.h>
namespace UMS
{
	class Base
	{
	public:
		Base();
		~Base();

	private:
		std::string STUDENT_FILE_PATH
		{ "C:\\Users\\Public\\Documents\\UMS\\UMS\\data\\UMS\\StudentData.txt" };
		std::string TEACHER_FILE_PATH
		{ "C:\\Users\\Public\\Documents\\UMS\\UMS\\data\\UMS\\TeacherData.txt" };

	public:
		Management<Student>* m_studentManagement;
		Management<Teacher>* m_teacherManagement;

	};

}
