#ifndef RENDERER_H
#define RENDERER_H

#include <iostream>
#include <string>
#include "Datatype.h"
using namespace std;

namespace Vendor{

  char first_layout(){
    system("cls");
    char input;
    cout << "##-------- Welcome to MIS --------##" << endl;
    cout << "Enter as :\n1.Student\n2.Staff\n3.Admin\nSelect an option (1 or 2 or 3) :";
    cin >> input;
    return input;
  }

  string user_login_layout(string input){
    system("cls");
    string index;
    string pin;
    cout << "##-------- Login Credentials --------##" << endl;
    cout << "Enter ('q' or 'Q') to quit" << endl;
    cout << " Enter a valid "<< input << " ID(MAX:8): ";
    cin >> index;
    if(index == "q"){
      exit(1);
    }
    cout << " Enter assciated pin to Index(" << index << ") : ";
    cin >> pin;
    return index + " " + pin;
  }

  char student_UI(string id){
    system("cls");
    //variables if needed
    char input;
    cout << "INDEX :: " << id << endl;
    cout << "##-------- MENU --------##" << endl;
    cout << "1.Add Course(s)\n2.Edit Course\n3.Delete Course\n4.View Courses\nEnter ('q' or 'Q') to quit\nMake a selection (1 or 2 or 3 or 4) :";
    cin >> input;
    return input;
  }


  char staff_UI(){
    system("cls");
    char input;
    cout << "##-------- MENU --------##" << endl;
    cout << "1. Record Student IA marks \n2.Record Student Exam score \nSelect your choice (1 or 2): ";
    cin >> input;
    return input;
  }

  char admin_UI(){
    system("cls");
    char input;
    cout << "##-------- MENU --------##" << endl;
    cout << "1.Add User\n2.Edit User\n3.Delete User\nMake a choice (1 to 3) : ";
    cin >> input;
    return input;
  }

  string int_to_string(int a){
    return std::to_string(a);
  }

  void collectUserDetails(User& user){
    system("cls");
    cout << "##-------- Enter Details --------##" << endl;
    cout << "Enter ('q' or 'Q') to quit" << endl;
    cout << "Enter User's First Name : ";
    cin >> user.first_name;
    cout << "Enter User's Last Name : ";
    cin >> user.last_name;
    cout << "Enter User's Department(keep words together) : ";
    cin >> user.department;
    cout << "Enter User's level(enter * if not student) : ";
    cin >> user.level;
    if(user.level == "*"){
      user.level = "NA";
    }
    cout << "Enter User's preferred Index Number(8) : ";
    cin >> user.index;
    cout << "Enter User's preferred PIN(4) : ";
    cin >> user.pin;
    cout << "Enter the type of User (student|staff|admin) : ";
    cin >> user.type;
  }

  void collectCourseDetails(StdCourse& course){
    system("cls");
    cout << "Enter ('q' or 'Q') to quit" << endl;
    cout << "Enter Course Code : ";
    cin >> course.course_code;
    cout << "Enter course Title : ";
    cin >> course.course_title;
  }

  void collectUserToEdit(User& user){
    system("cls");
    cout << "##-------- Enter Details --------##" << endl;
    cout << "Enter ('q' or 'Q') to quit" << endl;
    cout << "Enter User's First Name : ";
    cin >> user.first_name;
    cout << "Enter User's Last Name : ";
    cin >> user.last_name;
    cout << "Enter User's preferred PIN(4) : ";
    cin >> user.pin;
  }


  void collectScoreDetails(string& user_id,string& course_code,string& iA_marks,int one = 1){
    cout << "Enter ('q' or 'Q') to quit" << endl;
    cout << "Enter the ID of Student : ";
    cin >> user_id;
    cout << "Enter the Course Code : ";
    cin >> course_code;
    if(one == 2){
      cout << "Enter IA marks (70%) : ";
    }else{
      cout << "Enter IA marks (30%) : ";
    }
    cin >> iA_marks;
  }

  void assignment_response(bool& check,string type,string user_id){
    if(check){
      cout << type <<" marks assigned for " << user_id << endl;
    }else{
      cout << "Probably student with ID:(" << user_id << ") did not take the course ";
    }
    system("pause");
  }

}




#endif
