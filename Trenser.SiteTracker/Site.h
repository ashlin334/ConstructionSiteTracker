//<------ Author : Ashlin Babu--------->
//<------ Date   : 23-02-2026---------->
#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;
#include "Status.h"
class Site
{
private:
	string m_owner, m_location, m_engineer, m_id, m_siteName, m_status;;
	float m_area;
	int m_phase;
	Status status;
	static int m_counter;
	bool m_isActive;
public:
	Site(string siteName,string location, float area, string owner,int phase);
	Site(string siteName, string location, float area, string owner, int phase,string engineerName,string status);
	void setEngineer(string name);
	string getOwner();
	string getLocation();
	string getEngineer();
	string getId();
	string getSiteName();
	float getArea();
	int getPhase();
	void updateSiteStatus(string message);
	string getSiteStatusMessage();
	void setPhase(int phase);
	void deactiveSite();
	bool isActiveSite();
};