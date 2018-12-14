#ifndef DATABASE_H
#define DATABASE_H
#define FILE_O "database.txt"
#define FILE_T "temp.txt"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <iterator>
#include <string>
using namespace std;


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
	std::ofstream temp;
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
		std::string user_collected;
    file.open("database.txt");
    while(!file.eof()){
      getline(file,user_collected);
      splitString(arr,user_collected);
			if(arr[4] == user_id){
				std::cout << "user found " << '\n';
				break;
			}
    }
    file.close();
		return user_collected;
  }

	bool delete(string id){
		string user = this->fetch(id);
		string e_user;
		file.open(FILE_O);
		temp.open(FILE_T)
		while(!file.eof()){
			getline(file,e_user);
			if(e_user == user){
				continue;
			}else{
				temp << t_user << endl;
			}
		}
		temp.close();
		file.close();
		remove("database.txt");
		if(rename("temp.txt","database.txt")){
			return true;
		}
		return false;
	}


	void update(User user){
		string e_user;
		string t_user;
		e_user = this->fetch(user.index);
		cout << "Existing User : " << e_user << endl;
		string n_user = user.first_name + " " + user.last_name + " " + user.department + " " + user.pin + " " + user.index + " " + user.level;
		cout << "New User : " << n_user;
		file.open("database.txt");
		temp.open("temp.txt");
		while(!file.eof()){
			getline(file,t_user);
			t_user.replace(t_user.find(e_user),n_user.length(),n_user);
			temp << t_user << endl;
		}
		temp.close();
		file.close();
		// remove("database.txt");
		// rename("temp.txt","database.txt");
	}


		template <size_t N>
		void splitString(string (&arr)[N], string str){
		    int n = 0;
		    istringstream iss(str);
		    for (auto it = istream_iterator<string>(iss); it != istream_iterator<string>() && n < N; ++it, ++n)
		        arr[n] = *it;
		}

  ~Database(){
		cout << "Database class terminated" << endl;
  }
};




#endif
