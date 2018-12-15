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
    cout << " Enter a valid "<< input << " ID(MAX:8): ";
    cin >> index;
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
    cout << "1.Add Course(s)\n2.Edit Course\n3.Delete Course\n4.View Courses\nMake a selection (1 or 2 or 3 or 4) :";
    cin >> input;
    return input;
  }


  char staff_UI(){
    system("cls");
    char input;
    cout << "##-------- MENU --------##" << endl;
    cout << "1. Record Student grade \nSelect (1) to proceed : ";
    cin >> input;
    return input;
  }

  char admin_UI(){
    system("cls");
    char input;
    cout << "##-------- MENU --------##" << endl;
    cout << "1.Add Student\n2.Edit Student\n3.Delete Student\n4.Add Staff\n5.Edit Staff\n6.Delete Staff\nMake a choice (1 to 6) :";
    cin >> input;
    return input;
  }

  string int_to_string(int a){
    return std::to_string(a);
  }

  void collectStudentDetails(User& user){
    system("cls");
    cout << "##-------- Enter Details --------##" << endl;
  }

}




#endif
