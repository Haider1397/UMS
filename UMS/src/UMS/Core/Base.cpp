#include <UMS/Core/Base.h>

UMS::Base::Base()
{
	m_studentManagement = new Management<Student>(STUDENT_FILE_PATH, "ST-");
	m_teacherManagement = new Management<Teacher>(TEACHER_FILE_PATH, "TC-");
}

UMS::Base::~Base()
{
	delete m_studentManagement;
	delete m_teacherManagement;
}
