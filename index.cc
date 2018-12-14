#include <iostream>
#include "Vendor\Database.h"
using namespace std;


int main(int argc, char const *argv[]) {
  struct User user;
  struct User test_user;
  user.first_name = "Frank";
	user.last_name = "Ampong";
	user.level = "200";
	user.index = "010101";
	user.pin = "1234";
	user.department = "ComputerEngineering";
  Database db;
  db.update(user);
  return 0;
}
