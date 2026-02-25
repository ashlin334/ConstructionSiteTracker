//<------ Author : Ashlin Babu--------->
//<------ Date   : 23-02-2026---------->
#pragma once
#include<iostream>
#include<string>
using namespace std;
class Worker
{
private:
	static int m_counter;
	string m_workerName, m_role;
	string m_id, m_siteId;
	int m_age;
	bool m_isActive;
public:
	Worker(string name, string role, int age, string siteId,bool isActive);
	string getName();
	string getRole();
	string getId();
	string getSiteID();
	int getAge();
	bool isActive();
	void deactive();
};