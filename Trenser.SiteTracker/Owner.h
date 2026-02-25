//<------ Author : Ashlin Babu--------->
//<------ Date   : 23-02-2026---------->
#pragma once
#include<iostream>
#include<string>
using namespace std;
#include "User.h"
class Owner:
	public User
{
private:
	vector<string> m_siteIds;
	string m_name;
	string m_phone;
	string m_ownerId;
	static int m_counter;
public:
	Owner() = default;
	Owner(string name, string phone, string username, string password);
	Owner(string name, string phone, string username, string password,bool status);
	string getOwnerID();
	string getName();
	string getPhone();
	string menu() override;
	vector<string> getSiteIds();
	void addSite(string id);
};

