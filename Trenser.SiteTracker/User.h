//<------ Author : Ashlin Babu--------->
//<------ Date   : 23-02-2026---------->
#pragma once
#include<iostream>
#include<vector>
using namespace std;

class User
{
protected:
	string m_name,m_id;
	string m_username;
	string m_password;
	string m_userType;
	string m_phone;
	bool m_isActive;
public:
	User() :m_username{}, m_password{}, m_userType{}, m_name{}, m_phone{}, m_isActive{true} {}
	User(string username, string password, string userType, string name,string phone,bool isActive) 
		:m_username{ username }, m_password{ password }, m_userType{ userType }, m_name{ name }, m_phone{ phone }, m_isActive{isActive} {}
	string getUsername();
	string getPassword();
	string getName();
	string getPhone();
	bool isActive();
	void deactive();
	string getUserType();
	virtual string menu()= 0;
};