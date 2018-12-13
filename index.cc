#include <iostream>
#include "Vendor\Database.h"
using namespace std;


int main(int argc, char const *argv[]) {
  // struct User user;
  // struct User test_user;
	// user.first_name = "Frank";
	// user.last_name = "Gogomi";
	// user.level = "200";
	// user.index = "11111";
	// user.pin = "1234";
	// user.department = "ComputerScience";
  Database db;
  //
  // if(db.create(user)){
  //   cout << "Did something" << endl;
  // }
  // std::cout << "Hello there " << '\n';
  db.fetch("22222");
  // cout << "User's name is (from main) :" << test_user.first_name;
  return 0;
}
