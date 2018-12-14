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

int main(int argc, char const *argv[]) {
  input = first_layout();
  switch(input){
    case '1':
      login_input = user_login_layout("Student");
      database.splitString(input_arr,login_input);
      login_response = auth.login(input_arr[0],input_arr[1]);
      if(login_response == "Yes"){
        student_UI(input_arr[0]);
      }
      break;
    case '2':
      login_input = user_login_layout("Staff");
      database.splitString(input_arr,login_input);
      login_response = auth.login(input_arr[0],input_arr[1]);
      if(login_response == "Yes"){
        staff_UI();
      }
      break;
  }
  return 0;
}
