#ifndef AUTH_H
#define AUTH_H
//includes
#include <iostream>
#include <string>
#include "./Database.h"


Database db;

namespace Vendor{

class Auth{
private:
  std::string index;
  std::string pin;
  std::string user;
public:
  Auth(){
    std::cout << "Auth class called .." << std::endl;
  }

  string login(std::string index,std::string pin){
    this->index = index;
    this->pin = pin;
    if(this->Authenticate()){
      return "Yes";
    }
    return "No";
  }

  ~Auth(){
    std::cout << "Auth session closed" << std::endl;
  }

protected:
  bool Authenticate(){
    user = db.fetch(index);
    if(user.size() > 1){
      return true;
    }
    return false;
  }

};

}




#endif
