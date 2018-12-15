#include <iostream>
#include "Vendor\Database.h"
#include "Vendor\Renderer.h"
#include "Vendor\Auth.h"
using namespace std;
using namespace Vendor;

//global variables
char input;
string login_input,input_arr[2],login_response;
Database database;
Auth auth;
User user;

int main(int argc, char const *argv[]) {
  input = first_layout();
  switch(input){
    case '1':
      login_input = user_login_layout("Student");
      database.splitString(input_arr,login_input);
      login_response = auth.login(input_arr[0],input_arr[1],"student");
      if(login_response == "Yes"){
        char choice_1 = student_UI(input_arr[0]);

        switch (choice_1) {
          case '1':

            break;
        }
      }
      break;
    case '2':
      login_input = user_login_layout("Staff");
      database.splitString(input_arr,login_input);
      login_response = auth.login(input_arr[0],input_arr[1],"staff");
      if(login_response == "Yes"){
        staff_UI();
      }
      break;
    case '3':
      login_input = user_login_layout("Admin");
      database.splitString(input_arr,login_input);
      login_response = auth.login(input_arr[0],input_arr[1],"admin");
      if(login_response == "Yes"){
        char choice_3 = admin_UI();
        switch (choice_3) {
          case '1':
            collectStudentDetails(user);
            break;
        }
      }
      break;
  }
  return 0;
}
