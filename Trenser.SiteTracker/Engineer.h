//<------ Author : Ashlin Babu--------->
//<------ Date   : 23-02-2026---------->
#pragma once
#include<iostream>
#include<string>
using namespace std;
#include "User.h"
#include "Material.h"
#include "Worker.h"
#include "Task.h"
#include "Status.h"
#include "Site.h"
class Engineer: public User
{
private:
	static int m_counter;
	vector<Worker*> worker;
	vector<Material*> m_material;
	vector<Task*> m_task;
	string m_name;
	string m_phone,m_id;
	vector<string> m_siteId;
public:
	Engineer()=default;
	Engineer(string name, string phone, string username, string password);
	Engineer(string name, string phone, string username, string password,vector<string> ids,bool status);
	string getName();
	string getPhone();
	string getId();
	vector<string> getSiteId();
	string menu() override;
	void setSiteId(string id);
	void addWorker(string name, string role, int age, string siteID);
	void addWorker(string name, string role, int age, string siteID, string isActive);
	vector<Worker*> displayWorker();
	void addMetrial(string name, string siteID, int quantity);
	vector<Material*> displayMatrial();
	void addTask(string description, string deadline, string status, string siteID);
	vector<Task*> displayTask();
	string addSiteStatus(string id,string message,vector<Site*>& sites);
	string viewSiteStatus(string id, vector<Site*>& sites);
	string updateSitePhase(string Id, int phase, vector<Site*>& sites);
	string updateTaskStatus(string id, string status);
	bool checkSiteID(string id, vector<Site*>& sites); 
	vector<string> getAssignedSites();
	void addSite(string id);
	bool hasSite(string siteId);
	~Engineer();
};

