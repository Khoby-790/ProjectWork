#ifndef DATATYPE_H
#define DATATYPE_H


struct User{
	std::string first_name;
	std::string last_name;
  std::string department;
  std::string pin;
  std::string index;
	std::string level;
	std::string type;
};

struct Course{
		std::string course_code;
		std::string course_title;
		std::string course_lecturer;
};

struct StdCourse{
  std::string std_index;
  std::string course_code;
  std::string std_mark_IA;
  std::string std_mark_EXAM;
  std::string grade;
};





#endif
