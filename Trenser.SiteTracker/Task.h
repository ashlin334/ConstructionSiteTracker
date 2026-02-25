//<------ Author : Ashlin Babu--------->
//<------ Date   : 23-02-2026---------->
#pragma once
#include<iostream>
#include<string>
using namespace std;
class Task
{
private:
	string m_id, m_description, m_deadline, m_status,m_siteID;
	static int m_counter;
public:
	Task(string description, string deadline, string status,string siteID);
	string getId();
	string getDescription();
	string getDeadline();
	string getStatus();
	string getSiteID();
	void updateStatus(string newStatus);
};