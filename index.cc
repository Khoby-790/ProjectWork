#include <iostream>
#include "Vendor\Database.h"
#include "Vendor\Renderer.h"
#include "Vendor\Auth.h"
using namespace std;
using namespace Vendor;

//global variables
char input,choice_1,choice_3,choice_2;
string login_input,input_arr[2],login_response,user_to_edit,user_id,course_code;
Database database;
Auth auth;
User user;
StdCourse course;
bool check;

int main(int argc, char const *argv[]) {
  input = first_layout();
  do{
  switch(input){
    case '1':
      login_input = user_login_layout("Student");
      database.splitString(input_arr,login_input);
      login_response = auth.login(input_arr[0],input_arr[1],"student");
      if(login_response == "Yes"){
        do{
          choice_1 = student_UI(input_arr[0]);

          switch (choice_1) {
            case '1':
              course.std_index = input_arr[0];
              collectCourseDetails(course);
              database.create(course);
              system("pause");
              break;
            case '2':
              cout << "Enter course code of course to edit : ";
              cin >> user_to_edit;
              database.fetch(user_to_edit,course);
              collectCourseDetails(course);
              database.update(course);
              system("pause");
              break;
            case '3':
              cout << "Enter course code of course to edit : ";
              cin >> user_to_edit;
              database._delete(user_to_edit,input_arr[0]);
              system("pause");
              break;
            case '4':
                database.view_courses(input_arr[0]);
                system("pause");
              break;
          }
        }while(choice_1 != 'q' || choice_1 != 'Q');
      }
      break;
    case '2':
      do{
        login_input = user_login_layout("Staff");
        database.splitString(input_arr,login_input);
        login_response = auth.login(input_arr[0],input_arr[1],"staff");
        if(login_response == "Yes"){
          do{
            choice_2 = staff_UI();
            switch (choice_2) {
              case '1':
                collectScoreDetails(user_id,course_code,user_to_edit);
                check = database.assign_IA_marks(user_id,course_code,user_to_edit);
                assignment_response(check,"IA",user_id);
                break;
              case '2':
                collectScoreDetails(user_id,course_code,user_to_edit,2);
                check = database.assign_EXAM_marks(user_id,course_code,user_to_edit);
                assignment_response(check,"EXAM",user_id);
                break;
            }
          }while(choice_2 != 'q' || choice_2 != 'Q');
        }
      }while(login_response != "Yes");
      break;
    case '3':
      login_input = user_login_layout("Admin");
      database.splitString(input_arr,login_input);
      login_response = auth.login(input_arr[0],input_arr[1],"admin");
      if(login_response == "Yes"){
        do{
          choice_3 = admin_UI();
          cout << choice_3 << endl;
          switch (choice_3) {
            case '1':
              collectUserDetails(user);
              cout << "User's first Name is :" << user.first_name << endl;
              database.create(user);
              system("pause");
              break;
            case '2':
              cout << "Enetr Id of User to Edit : ";
              cin >> user_to_edit;
              database.fetch(user_to_edit,user);
              collectUserToEdit(user);
              database.update(user);
              system("pause");
              break;
            case '3':
              cout << "Enetr Id of User to Delete : ";
              cin >> user_to_edit;
              database._delete(user_to_edit);
              system("pause");
              break;
          }
        }while(choice != 'q' || choice != 'Q');
      }
      break;
  }
}while(input != 'q' || input != 'Q');
  return 0;
}
