#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
#include "User.h"
#include "Admin.h"
#include "Owner.h"
#include "Engineer.h"
#include "Exception.h"

class FileManager;
class SiteTrackerController
{
private:
	User* m_currentUser = nullptr;
	FileManager* m_fileManager;
	Engineer m_engineer;
	vector<User*> m_user;
	Admin m_admin;
	string m_name, m_username, m_password, m_repassword, m_phone,m_role,m_description,m_deadline,m_status,m_message;
	string m_location,m_owner,m_id,m_engineerID,m_siteId, m_SiteName;
	float m_area;
	int m_type,m_phase, m_age,m_quantity,m_index;
	Exception m_exception;
	bool m_flag;
	vector<Status*> m_siteStatus;
public:
	SiteTrackerController(FileManager* fileManager);
	void loadFromFiles();
	void saveToFile();
	void controllerMenu();
	void addUser();
	void loginUser();
	void adminMenu(string name);
	void viewTaskByAdmin();
	void addTaskByAdmin();
	void viewWorkerByAdmin();
	void ownerMenu(string name);
	void addSiteByAdmin(string name);
	void engineerMenu(string name);
	void addSite();
	void addEngineer();
	void viewSite();
	void assignEngineerToSite();
	void viewEngineer();
	void viewWorkers();
	void addWorkers();
	void addMaterialToSite();
	void viewMaterials();
	void addTask();
	void viewTask();
	void addSiteStatus();
	void viewSiteStatus();
	void viewSiteStatus(string name);
	void updateSitePhase();
	void updateTaskStatus();
	void deleteSite();
	bool emailValidation(string email);
	bool phoneValidation(string phone);
	bool passwordValidation(string password,string re_password);
	void deleteEngineer();
	bool isUserNameExist(string username);
	void deleteWorkers();
	void deleteOwner();
	void viewAllOwners();
	void viewMaterialsByAdmin();
	void viewAllWorkersByAdmin();
	void addMaterialToSiteByAdmin();
};