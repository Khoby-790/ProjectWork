#ifndef DATABASE_H
#define DATABASE_H
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
// #include <ifstream>
// #include <ofstream>

struct  User{
	std::string first_name;
	std::string last_name;
  std::string department;
  std::string pin;
  std::string index;
	std::string level;
};


class Database{
protected:
  //file pointer
  std::fstream file;
  std::string user_line;
public:
  Database(){
    std::cout << "Database class called.." << std::endl;
  }

  bool create(User user){
    file.open("database.txt",std::ios::out);
    user_line = user.first_name + " " + user.last_name + " " + user.department + " " + user.pin + " " + user.index + " " + user.level;
    file << user_line << std::endl;
    file.close();
    return true;
  }

  void fetch(std::string user_id){
    int i = 0;
    char *data_u;
    file.open("database.dat",std::ios::out);
    char collectible[100];
    while(!file.eof()){
      file.getline(collectible,100);
      std::cout << collectible << std::endl;
      std::string user_collected(collectible);
      std::stringstream ssin(user_collected);
      while (ssin.good() && i < 6){
        ssin >> data_u[i];
        std::cout << data_u[i] << std::endl;
        ++i;
      }
    }
    file.close();
  }

  ~Database(){

  }
};




#endif
