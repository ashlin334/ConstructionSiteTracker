//<------ Author : Ashlin Babu--------->
//<------ Date   : 23-02-2026---------->
#pragma once
#include<iostream>
#include<vector>
using namespace std;
#include "User.h"
#include "Site.h"
#include "Status.h"
#include "Engineer.h"
#include "Owner.h"
class Admin:
	public User
{
private:
	string m_name;
	string m_phone;
	vector<Site*> m_site;
	vector<Task*> m_task;
	vector<Engineer*> m_engineers;
	bool m_isActive;
public:
	Admin() :m_name{}, m_phone{} {}
	Admin(string name, string phone, string username, string password, string status);
	string getName();
	string getPhone();
	string menu() override;
	void addNewSite(string siteName,string location, float area, string owner, int phase);
	Engineer* createEngineer(string name, string phone, string username, string password);
	Engineer* createEngineer(string name, string phone, string username, string password, vector<string> ids, bool status);
	string assignEngineerToSite(string siteId,string engineerId);
	vector<Engineer*>& getEngineersList();
	vector<Site*>& getSite();
	vector<Task*>& getTask();
	string viewSiteStatus(string siteID);
	bool deleteSite(string id, vector<Task*>& tasks);
	vector<Site*> findSitesByName(string name);
	vector<Engineer*> findEngineersByName(string name);
	vector<Site*> getSitesByOwner(string ownerName);
	bool deleteEngineer(string name, vector<Engineer*>& engineers);
	bool isActiveAdmin();
	~Admin();
};

