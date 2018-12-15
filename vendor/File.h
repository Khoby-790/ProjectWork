#ifndef FILE_H
#define FILE_H

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <iterator>
#include <string>
#include "Datatype.h"
using namespace std;


class File{
public:
//register all the methods
//methods for User
bool create(User user);
string fetch(std::string user_id);
string fetch(std::string user_id,std::string pin);
void _delete(string id);
void update(User user);

//methods for course
bool create(Course course);
string fetch_course(string course_code);
void update_course(Course couse);
void _delete_course(string course_code);

};







#endif
