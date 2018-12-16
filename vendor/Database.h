#ifndef DATABASE_H
#define DATABASE_H
#define FILE_O "database.txt"
#define FILE_CO "database_course.txt"
#define FILE_T "temp.txt"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <iterator>
#include <string>
#include "File.h"
using namespace std;

std::string::size_type sz;


class Database : File{
protected:
  //file pointer
  std::fstream file;
	std::ofstream temp;
  std::string user_line;
	std::string arr[10];
public:
  Database(){
    std::cout << "Database class called.." << std::endl;
  }

	/*
	*@Database class for file handling
	*# Method overloading for method create to create
	*both the user and course perhaps the admin and lecturer
	*/
	//create methods
  bool create(User user){
    file.open(FILE_O,std::ios::app|std::ios::out);
    user_line = user.first_name + " " + user.last_name + " " + user.department + " " + user.pin + " " + user.index + " " + user.level + " " + user.type;
    file << user_line << std::endl;
    cout << "User added successfully .." << endl;
    file.close();
    return true;
  }

	bool create(StdCourse course){
    file.open(FILE_CO,std::ios::app|std::ios::out);
    user_line = course.std_index + " " + course.course_code + " " + course.course_title + " " + course.std_mark_IA + " " + course.std_mark_EXAM + " " + course.grade;
    file << user_line << std::endl;
    cout << "Course added successfully .." << endl;
    file.close();
    return true;
  }


	//fetch methods

  string fetch(std::string user_id){
		std::string user_collected;
    file.open(FILE_O);
    while(!file.eof()){
      getline(file,user_collected);
      splitString(arr,user_collected);
			if(arr[4] == user_id){
				break;
			}
    }
    file.close();
		return user_collected;
  }


  string fetch(std::string course_code,int one){
		std::string course_collected;
    file.open(FILE_CO);
    while(!file.eof()){
      getline(file,course_collected);
      splitString(arr,course_collected);
			if(arr[1] == course_code){
				break;
			}
    }
    file.close();
		return course_collected;
  }

  string fetch(std::string course_code,string user_id){
		std::string course_collected;
    file.open(FILE_CO);
    while(!file.eof()){
      getline(file,course_collected);
      splitString(arr,course_collected);
			if(arr[1] == course_code && arr[0] == user_id){
				break;
			}
    }
    file.close();
		return course_collected;
  }


  void fetch(std::string user_id,User& user){
		std::string user_collected;
    file.open(FILE_O);
    while(!file.eof()){
      getline(file,user_collected);
      splitString(arr,user_collected);
			if(arr[4] == user_id){
        user.first_name = arr[0];
        user.last_name = arr[1];
        user.department = arr[2];
        user.pin = arr[3];
        user.index = arr[4];
        user.level = arr[5];
        user.type = arr[6];
				break;
			}
    }
    file.close();
  }


  void fetch(string course_code,StdCourse& course){
    string course_collected;
    file.open(FILE_CO);
    while(!file.eof()){
      getline(file,course_collected);
      splitString(arr,course_collected);
      if(arr[1] == course_code){
        course.course_code;
        course.std_index;
        course.course_title;
        course.std_mark_IA;
        course.std_mark_EXAM;
        course.grade;
        break;
      }
    }
    file.close();
  }

  void view_courses(string user_id){
    string course_collected;
    file.open(FILE_CO);
    cout << "Courses offered by " << user_id << endl;
    while(!file.eof()){
      getline(file,course_collected);
      splitString(arr,course_collected);
      if(arr[0] == user_id){
        course_collected = arr[1] + " " + arr[2];
        cout << course_collected << endl;
      }
    }
    file.close();
  }

	//Add the
	string fetch(std::string user_id,std::string pin,std::string type){
		std::string user_collected;
    file.open(FILE_O);
    while(!file.eof()){
      getline(file,user_collected);
      splitString(arr,user_collected);
			if(arr[4] == user_id && arr[3] == pin && arr[6] == type){
				std::cout << "user found " << '\n';
				break;
			}
    }
    file.close();
		return user_collected;
  }


	//delete methods

	void _delete(string id){
		string user = this->fetch(id);
		string e_user;
		file.open(FILE_O);
		temp.open(FILE_T);
		while(!file.eof()){
			getline(file,e_user);
			if(e_user == user){
				continue;
			}else{
				temp << e_user << endl;
			}
		}
		temp.close();
		file.close();
		remove(FILE_O);
		rename(FILE_T,FILE_O);
		cout << "User deleted successfully .. " << endl;
	}


  void _delete(string course_code,string user_id){
		string course = this->fetch(course_code,1);
		string e_course;
		file.open(FILE_CO);
		temp.open(FILE_T);
		while(!file.eof()){
			getline(file,e_course);
      splitString(arr,e_course);
			if(e_course == course && arr[0] == user_id){
				continue;
			}else{
				temp << e_course << endl;
			}
		}
		temp.close();
		file.close();
		remove(FILE_CO);
		rename(FILE_T,FILE_CO);
		cout << "Course deleted successfully .. " << endl;
	}




	//update methods

	void update(User user){
		string e_user;
		string t_user;
		e_user = this->fetch(user.index);
		cout << "Existing User : " << e_user << endl;
		string n_user = user.first_name + " " + user.last_name + " " + user.department + " " + user.pin + " " + user.index + " " + user.level + " " + user.type;
		cout << "New User : " << n_user << endl;
		file.open(FILE_O);
		temp.open(FILE_T);
		while(!file.eof()){
			getline(file,t_user);
			if(t_user == e_user){
        t_user = n_user;
			}
      temp << t_user << endl;
		}
		temp.close();
		file.close();
		remove(FILE_O);
		rename(FILE_T,FILE_O);
	}


  //update the course

  void update(StdCourse course){
		string e_course;
		string t_course;
		e_course = this->fetch(course.course_code,1);
		cout << "Old Course : " << e_course << endl;
    string n_course = course.std_index + " " + course.course_code + " " + course.course_title + " " + course.std_mark_IA + " " + course.std_mark_EXAM + " " + course.grade;
		cout << "New Course : " << n_course << endl;
		file.open(FILE_CO);
		temp.open(FILE_T);
		while(!file.eof()){
			getline(file,t_course);
			if(t_course == e_course){
        t_course = n_course;
			}
      temp << t_course << endl;
		}
		temp.close();
		file.close();
		remove(FILE_CO);
		rename(FILE_T,FILE_CO);
	}


  //IA marks assingment

  bool assign_IA_marks(string user_id,string course_code,string IA_mark){
    string course = fetch(course_code,user_id);
    if(course.size() > 0){
      splitString(arr,course);
      arr[3] = IA_mark;
      StdCourse course;
      course.std_index = arr[0];
      course.course_code = arr[1];
      course.course_title = arr[2];
      course.std_mark_IA = arr[3];
      course.std_mark_EXAM = arr[4];
      course.grade = arr[5];
      this->update(course);
      return true;
    }
    return false;
  }

  bool assign_EXAM_marks(string user_id,string course_code,string EXAM_mark){
    int sum,ia,exam;
    string course = fetch(course_code,user_id);
    if(course.size() > 0){
      splitString(arr,course);
      arr[4] = EXAM_mark;
      StdCourse course;
      course.std_index = arr[0];
      course.course_code = arr[1];
      course.course_title = arr[2];
      course.std_mark_IA = arr[3];
      ia = std::stoi(arr[3],&sz);
      course.std_mark_EXAM = arr[4];
      exam = std::stoi(arr[4],&sz);
      sum = ia + exam;
      course.grade = this->grading(sum);
      this->update(course);
      return true;
    }
    return false;
  }

		template <size_t N>
		void splitString(string (&arr)[N], string str){
		    int n = 0;
		    istringstream iss(str);
		    for (auto it = istream_iterator<string>(iss); it != istream_iterator<string>() && n < N; ++it, ++n)
		        arr[n] = *it;
		}

    string grading(int sum){
      if(sum > 79 && sum < 100){
        return "A";
      }else if(sum > 74 && sum < 80){
        return "B+";
      }else if(sum > 69 && sum < 75){
        return "B";
      }else if(sum > 64 && sum < 70){
        return "C+";
      }else if(sum > 59 && sum < 65){
        return "C";
      }else if(sum > 54 && sum < 60){
        return "D+";
      }else if(sum > 49 && sum < 55){
        return "D";
      }else if(sum > 44 && sum < 50){
        return "E";
      }else if(sum > -1 && sum < 45){
        return "F";
      }else{
        return "NA";
      }
    }

  ~Database(){
		cout << "Database class terminated" << endl;
  }







};




#endif
