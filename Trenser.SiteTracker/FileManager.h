//<------ Author : Ashlin Babu--------->
//<------ Date   : 23-02-2026---------->
#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include<string>
#include <sstream>
using namespace std;
#include "Admin.h"
#include "Engineer.h"
#include "Owner.h"
#include "Site.h"
#include "Worker.h"
#include "Material.h"
#include "Task.h"
#include "User.h"

class FileManager
{
private:
    string m_name, m_phone, m_username, m_password, m_role,m_id,m_phase,m_location,m_area,m_owner, m_engineer, m_SiteName;
    
    const string USER = "User.txt";
    const string SITE = "Site.txt";
    const string TASK = "Task.txt";
    const string MATERIAL = "Material.txt";
    const string SITESTATUS = "Status.txt";
    const string WORKER = "Worker.txt";
    const string OWNER = "Owner.txt";
    const string ENGINEER = "Engineer.txt";
    const string ADMIN = "Admin.txt";
public:
    void loadUser(vector<User*>& user, Admin& admin);
    void loadSite(vector<Site*>& site);
    void loadSiteStatus(vector<Site*>& sites);
    void loadWorker(Engineer& engineer);
    void loadTask(Engineer& engineer);
    void loadMaterial(Engineer& engineer);

    void saveUser(vector<User*> user);
    void saveSite(vector<Site*>& sites);
    void saveSiteStatus(vector<Site*>& sites);
    void saveWorker(Engineer& engineer);
    void saveTask(Engineer& engineer);;;
    void saveMaterial(Engineer& engineer);
};