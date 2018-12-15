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
#include "File.h"
using namespace std;




class Database : File{
protected:
  //file pointer
  std::fstream file;
	std::ofstream temp;
  std::string user_line;
	std::string arr[10];
public:
  Database(){
    std::cout << "Database class called.." << std::endl;
  }

	/*
	*@Database class for file handling
	*# Method overloading for method create to create
	*both the user and course perhaps the admin and lecturer
	*/
	//create methods
  bool create(User user){
    file.open(FILE_O,std::ios::app|std::ios::out);
    user_line = user.first_name + " " + user.last_name + " " + user.department + " " + user.pin + " " + user.index + " " + user.level + " " + user.type;
    file << user_line << std::endl;
    file.close();
    return true;
  }

	bool create(Course course){
    file.open(FILE_O,std::ios::app|std::ios::out);
    user_line = "";
    file << user_line << std::endl;
    file.close();
    return true;
  }


	//fetch methods

  string fetch(std::string user_id){
		std::string user_collected;
    file.open(FILE_O);
    while(!file.eof()){
      getline(file,user_collected);
      splitString(arr,user_collected);
			if(arr[4] == user_id){
				break;
			}
    }
    file.close();
		return user_collected;
  }

	//Add the
	string fetch(std::string user_id,std::string pin,std::string type){
		std::string user_collected;
    file.open(FILE_O);
    while(!file.eof()){
      getline(file,user_collected);
      splitString(arr,user_collected);
			if(arr[4] == user_id && arr[3] == pin && arr[6] == type){
				std::cout << "user found " << '\n';
				break;
			}
    }
    file.close();
		return user_collected;
  }


	//delete methods

	void _delete(string id){
		string user = this->fetch(id);
		string e_user;
		file.open(FILE_O);
		temp.open(FILE_T);
		while(!file.eof()){
			getline(file,e_user);
			if(e_user == user){
				continue;
			}else{
				temp << e_user << endl;
			}
		}
		temp.close();
		file.close();
		remove(FILE_O);
		rename(FILE_T,FILE_O);
		cout << "User deleted successfully .. " << endl;
	}




	//update methods

	void update(User user){
		string e_user;
		string t_user;
		e_user = this->fetch(user.index);
		cout << "Existing User : " << e_user << endl;
		string n_user = user.first_name + " " + user.last_name + " " + user.department + " " + user.pin + " " + user.index + " " + user.level;
		cout << "New User : " << n_user << endl;
		file.open(FILE_O);
		temp.open(FILE_T);
		while(!file.eof()){
			getline(file,t_user);
			splitString(arr,t_user);
			if(arr[4] == user.index){
				t_user = n_user;
			}
			temp << t_user << endl;
		}
		temp.close();
		file.close();
		remove(FILE_O);
		rename(FILE_T,FILE_O);
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
