#ifndef DATABASE_H
#define DATABASE_H
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <sstream>
#include <iterator>
#include <string>
using namespace std;
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
	std::string arr[100];
public:
  Database(){
    std::cout << "Database class called.." << std::endl;
  }

  bool create(User user){
    file.open("database.txt",std::ios::app|std::ios::out);
    user_line = user.first_name + " " + user.last_name + " " + user.department + " " + user.pin + " " + user.index + " " + user.level;
    file << user_line << std::endl;
    file.close();
    return true;
  }

  string fetch(std::string user_id){
    int i = 0;
    char *data_u;
		std::string user_collected;
    file.open("database.txt",std::ios::in);
    char collectible[100];
    while(!file.eof()){
      file.getline(collectible,100);
			user_collected = std::string(collectible);
      splitString(arr,user_collected);
			if(arr[4] == "01010"){
				std::cout << "user found " << '\n';
				break;
			}
    }
    file.close();
		return
  }



		template <size_t N>
		void splitString(string (&arr)[N], string str){
		    int n = 0;
		    istringstream iss(str);
		    for (auto it = istream_iterator<string>(iss); it != istream_iterator<string>() && n < N; ++it, ++n)
		        arr[n] = *it;
		}

  ~Database(){

  }
};




#endif
