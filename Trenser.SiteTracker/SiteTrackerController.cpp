#include "SiteTrackerController.h"
#include "FileManager.h"
SiteTrackerController::SiteTrackerController(FileManager* fileManager)
{
	m_fileManager = fileManager;
	m_name = "";
	m_username = "";
	m_password = "";
	m_repassword = "";
	m_phone = "";
	m_role = "";
	m_description = "";
	m_deadline = "";
	m_status = "";
	m_message = "";
	m_location = "";
	m_owner = "";
	m_id = "";
	m_engineerID = "";
	m_siteId = "";
	m_area = 0.0;
	m_type = 0;
	m_phase = 0;
	m_age = 0;
	m_quantity = 0;
	m_index = 0;
	m_flag = false;
}
void SiteTrackerController::loadFromFiles()
{
	m_fileManager->loadUser(m_user,m_admin);
	m_fileManager->loadSite(m_admin.getSite());
	m_fileManager->loadSiteStatus(m_admin.getSite());
	m_fileManager->loadWorker(m_engineer);
	m_fileManager->loadTask(m_engineer);
	m_fileManager->loadMaterial(m_engineer);
}
void SiteTrackerController::saveToFile()
{
	m_fileManager->saveUser(m_user);
	m_fileManager->saveSite(m_admin.getSite());
	m_fileManager->saveSiteStatus(m_admin.getSite());
	m_fileManager->saveWorker(m_engineer);
	m_fileManager->saveTask(m_engineer);
	m_fileManager->saveMaterial(m_engineer);
}
void SiteTrackerController::controllerMenu()
{
	int choice = 1;
	while (choice != 3)
	{
		cout << "\nWelcome to ABC construction site tracker...\n";
		cout << "\n1.Registration\n2.Login\n3.Exit\n";
		choice = m_exception.checker();
		system("cls");
		switch (choice)
		{
		case 1:
			addUser();
			break;
		case 2:
			loginUser();
			break;
		case 3:
			cout << "\n=====Exit=====\n";
			break;
		default:
			cout << "Invalid input! try again\n";
			break;
		}
	}
}
void SiteTrackerController::ownerMenu(string name)
{
	system("cls");
	cout << "\nSite Owner: " << name << endl;
	int choice = 1;
	while (choice != 3)
	{
		cout << "\n1.Send site Request to Admin\n2.View Status of Site\n3.Logout\n  ";
		choice = m_exception.checker();
		switch (choice)
		{
		case 1:
			addSiteByAdmin(name);
			break;
		case 2:
			viewSiteStatus(name);
			break;
		case 3:
			cout << "\n=====Exit=====\n";
			break;
		default:
			cout << "Invalid input! try again";
			break;
		}
	}
}
void SiteTrackerController::adminMenu(string name)
{
	system("cls");
	cout << "\nAdmin: " << name << endl;
	int choice = 1;
	while (choice !=19)
	{
		cout << "\n1.Add new Site\n2.Add Engineers\n3.View Site\n4.View Engineers\n5.View Site Status\n6.Assign Engineer to Site\n7.Add Task\n8.Delete Site\n9.View Task\n10.View all workers\n11.Update Task Status\n12.Delete Engineer\n13.Delete Owner\n14.View All Site Owners\n15.View Materials\n16.view Workers\n17.Add Materials to Site\n18.Delete Workers\n19.Logout\n ";
		choice = m_exception.checker();
		switch (choice)
		{
		case 1:
			addSite();
			break;
		case 2:
			addEngineer();
			break;
		case 3:
			viewSite();
			break;
		case 4:
			viewEngineer();
			break;
		case 5:
			viewSiteStatus();
			break;
		case 6:
			assignEngineerToSite();
			break;
		case 7:
			addTaskByAdmin();
			break;
		case 8:
			deleteSite();
			break;
		case 9:
			viewTaskByAdmin();
			break;
		case 10:
			viewWorkerByAdmin();
			break;
		case 11:
			updateTaskStatus();
			break;
		case 12:
			deleteEngineer();
			break;
		case 13:
			deleteOwner();
			break;
		case 14:
			viewAllOwners();
			break;
		case 15:
			viewMaterialsByAdmin();
			break;
		case 16:
			viewAllWorkersByAdmin();
			break;
		case 17:
			addMaterialToSiteByAdmin();
			break;
		case 18:
			deleteWorkers();
			break;
		case 19:
			cout << "\n=====Exit=====\n";
			break;
		default:
			cout << "Invalid input! try again";
			break;
		}
	}
}
void SiteTrackerController::engineerMenu(string name)
{
	system("cls");
	cout << "\nEngineer: " << name << endl;
	int choice = 1;
	while (choice != 10)
	{
		cout << "\n1.Add workers\n2.Add Site status\n3.Add Materials\n4.Add Task\n5.View workers\n6.View site status\n7.View Materials\n8.View Task\n9.Update Site Phase\n10.Logout\n";
		choice = m_exception.checker();
		switch (choice)
		{
		case 1:
			addWorkers();
			break;
		case 2:
			addSiteStatus();
			break;
		case 3:
			addMaterialToSite();
			break;
		case 4:
			addTask();
			break;
		case 5:
			viewWorkers();
			break;
		case 6:
			viewSiteStatus();
			break;
		case 7:
			viewMaterials();
			break;
		case 8:
			viewTask();
			break;
		case 9:
			updateSitePhase();
			break;
		case 10:
			cout << "\n=====Exit=====\n";
			break;
		default:
			cout << "Invalid input! try again";
			break;
		}
	}
}
void SiteTrackerController::addSiteByAdmin(string name)
{
	system("cls");
	cout << "\nName of Site       :";
	cin >> m_SiteName;
	cout << "\nLocation           : ";
	cin >> m_location;
	cout << "Area of Square feet  : ";
	if (!(cin >> m_area))
	{
		cout << "\nEnter correct area!";
		return;
	}
	m_admin.addNewSite(m_SiteName, m_location, m_area, name, 1);
}
void SiteTrackerController::viewAllOwners()
{
	system("cls");
	cout << "\n---Owner Details---\n";
	for (auto user : m_user)
	{
		if (user->getUserType() == "Owner")
		{
			Owner* owner = dynamic_cast<Owner*>(user);
			if (owner->isActive())
			{
				cout << "\nID      : " << owner->getOwnerID() << "\n";
				cout << "Name      : " << owner->getName() << "\n";
				cout << "Phone     : " << owner->getPhone() << "\n";
				cout << "User Name : " << owner->getUsername() << "\n";
			}
		}
	}
}
void SiteTrackerController::deleteOwner()
{
	system("cls");
	string ownerName,ownerId;
	cout << "\nEnter the name of owner to delete: ";
	cin.ignore();
	getline(cin, ownerName);
	vector<Owner*> Owners;
	if (Owners.empty()) 
	{
		cout << "\nNo active owner found with that name!";
		return;
	}
	cout << "\nEnter Owner ID : ";
	cin >> ownerId;
	for (auto owner : Owners)
	{
		if(owner->getOwnerID() == ownerId)
		{
			owner->deactive();
			cout << "\nDeleted Successfully\n";
			return;
		}
	}
}
void SiteTrackerController::deleteEngineer()
{
	system("cls");
	string engineerName;
	cout << "\nName of Engineer to delete: ";
	cin.ignore();
	getline(cin, engineerName);
	vector<Engineer*> engineers = m_admin.findEngineersByName(engineerName);
	if (engineers.empty()) 
	{
		cout << "\nNo engineer found with this name\n";
		return;
	}
	cout << "\n---Engineers List---\n\n";
	for (auto engineer : engineers)
	{
		vector<string> assignedSite = engineer->getSiteId();
		cout << "ID: " << engineer->getId() << " | Name: " << engineer->getName() << " | Phone: " << engineer->getPhone();
		for (auto site : assignedSite)
		{
			cout << site << " ";
		}
		cout << "\n\n";
	}
	cout << "\nEngineer ID to delete: ";
	cin >> m_engineerID;
	bool result = m_admin.deleteEngineer(m_engineerID,m_admin.getEngineersList());
	if (result)
	{
		cout << "\n\nDeleted Successfully!\n\n";
	}
}
void SiteTrackerController::deleteSite()
{
	system("cls");
	viewSite();
	cout << "\nEnter the site ID to delete: ";
	cin >> m_id;
	bool isDeleted = m_admin.deleteSite(m_id, m_admin.getTask());
	if (isDeleted) { cout << "\n\nDeleted Successfully!\n\n"; }
}
bool SiteTrackerController::isUserNameExist(string username)
{
	for (auto user : m_user)
	{
		if (user->getUsername() == username)
		{
			return true;
		}
	}
	return false;
}
void SiteTrackerController::deleteWorkers()
{
	vector<Worker*> worker = m_engineer.displayWorker();
	for (auto user : worker)
	{
		if(user->isActive())
		{
			cout << "Id: " << user->getId() << " | ";
			cout << "Name: " << user->getName() << " | ";
			cout << "SiteID: " << user->getSiteID() << " | \n";
		}
	}
	cout << "\nEnter worker ID: ";
	cin >> m_id;
	for (auto user : worker)
	{
		if (user->isActive() && user->getId()==m_id)
		{
			user->deactive();
			cout << "\nWorker Has deleted!\n";
			return;
		}
	}
	cout << "\nCan't Delete!\n";
}
void SiteTrackerController::assignEngineerToSite()
{
	system("cls");
	string siteName, engineerName;
	cout << "\nEnter Site Name: ";
	cin >> siteName;
	vector<Site*> sites = m_admin.findSitesByName(siteName);
	if (sites.empty())
	{
		cout << "\nNo site found with this name\n";
		return;
	}
	cout << "\nMatching Sites:\n";
	for (auto site : sites)
	{
		if(site->isActiveSite())
		{
			cout << "ID: " << site->getId() << " | Location: " << site->getLocation() << " | Owner: " << site->getOwner() << endl;
		}
	}
	cout << "\nEnter Engineer Name: ";
	cin.ignore();
	getline(cin, engineerName);
	vector<Engineer*> engineers = m_admin.findEngineersByName(engineerName);
	if (engineers.empty())
	{
		cout << "\nNo engineer found with this name\n";
		return;
	}
	cout << "\nMatching Engineers:\n";
	for (auto engineer : engineers)
	{
		if(engineer->isActive())
		{
			cout << "ID: " << engineer->getId() << " | Name: " << engineer->getName() << " | Phone: " << engineer->getPhone() << endl;
		}
	}
	cout << "\nEnter the Site ID  : ";
	cin >> m_siteId;
	cout << "Enter the Engineer ID: ";
	cin >> m_engineerID;
	cout << endl;
	string result = m_admin.assignEngineerToSite(m_siteId, m_engineerID);
	cout << result << endl << endl;
}
void SiteTrackerController::viewTaskByAdmin()
{
	system("cls");
	vector<Task*> task = m_engineer.displayTask();
	if (task.empty())
	{
		cout << "\nNo Task Added!\n\n";
		return;
	}
	cout << "\n---Task Details---\n";
	for (auto details : task)
	{
		cout << "Task ID         : " << details->getId() << endl;
		cout << "Task Description: " << details->getDescription() << endl;
		cout << "Task dead line  : " << details->getDeadline() << endl;
		cout << "Task status     : " << details->getStatus() << endl;
		cout << "Site Id         : " << details->getSiteID() << endl << endl;
	}
}
void SiteTrackerController::addTaskByAdmin()
{
	cout << "Task Description: ";
	cin.ignore();
	getline(cin, m_description);
	cout << "Dead Line       : ";
	cin >> m_deadline;
	cout << "Site ID         :";
	cin >> m_siteId;
	bool result = m_engineer.checkSiteID(m_siteId, m_admin.getSite());
	if (result)
	{
		cout << "\nThe site is not in your data Base!";
		return;
	}
	cout << "Status          : ";
	cin.ignore();
	getline(cin, m_status);
	m_engineer.addTask(m_description, m_deadline, m_status, m_siteId);
	return;
}
void SiteTrackerController::viewWorkerByAdmin()
{
	vector<Worker*> worker = m_engineer.displayWorker();
	if (worker.empty())
	{
		cout << "\nNo Workers Added\n";
		return;
	}
	cout << "\n---Worker Details---\n";
	for (auto user : worker)
	{
		if(user->isActive())
		{
			cout << "\nName   : " << user->getName();
			cout << "\nRole   : " << user->getRole();
			cout << "\nID     : " << user->getId();
			cout << "\nSite ID: " << user->getSiteID();
			cout << "\nAge    : " << user->getAge() << endl;
		}
	}
}
bool SiteTrackerController::emailValidation(string email)
{
	if (isUserNameExist(email))
	{
		cout << "\nUsername is already exists!";
		return false;
	}
	int index = 0;
	while (email[index] != '\0')
	{
		if (email[index] == '@')
		{
			return true;
		}
		index++;
	}
	system("cls");
	cout << "\nEnter the correct email address\n\n\n";
	return false;
}
bool SiteTrackerController::passwordValidation(string password,string re_password)
{
	if (password != re_password)
	{
		system("cls");
		cout << "\nPassword mismatch! try again!\n\n\n";
		return false;
	}
	return true;
}
bool SiteTrackerController::phoneValidation(string phone)
{
	int index = 0;
	if (phone.length()!=10)
	{
		system("cls");
		cout << "\nPhone number must contain 10 digit!\n\n\n";
		return false;
	}
	while (phone[index] != '\0')
	{
		if (!(isdigit(phone[index])))
		{
			system("cls");
			cout << "\nPlease enter phone number!\n\n\n";
			return false;
		}
		index++;
	}
	return true;
}
void SiteTrackerController::addUser()
{
	system("cls");		
	cout << "Name                 : ";
	cin.ignore();
	getline(cin, m_name);
	cout << "Phone                : ";
	cin >> m_phone;
	m_flag = phoneValidation(m_phone);
	if (!m_flag) { return; }
	cout << "Email                : ";
	cin >> m_username;
	m_flag = emailValidation(m_username);
	if (!m_flag) { return; }
	cout << "Enter Password       : ";
	cin >> m_password;
	cout << "Re-Enter the Password: ";
	cin >> m_repassword;
	m_flag = passwordValidation(m_password, m_repassword);
	if (!m_flag) { return; }
	cout << "\n1.Admin\n2.Owner\n\nUser Type: ";
	cin >> m_type;
	if (m_type == 1) { m_user.push_back(new Admin(m_name, m_phone, m_username, m_password,"Active")); }
	if (m_type == 2) { m_user.push_back(new Owner(m_name, m_phone, m_username, m_password)); }
}
void SiteTrackerController::loginUser()
{
	system("cls");
	cout << "\nEmail   : ";
	cin >> m_username;
	cout << "Password  : ";
	cin >> m_password;
	if (m_user.empty())
	{
		cout << "\nNo Users are registered. Please register\n\n\n";
		return;
	}
	for (auto iterator = m_user.begin(); iterator != m_user.end(); iterator++)
	{
		if ((*iterator)->getUsername() == m_username && ((*iterator)->getPassword() == m_password))
		{
			if (!(*iterator)->isActive()) 
			{
				cout << "User has been deleted from Admin.";
				return; 
			}
			m_currentUser = *iterator;
			string type=(*iterator)->menu();
			if (type == "Owner")
			{
				ownerMenu((*iterator)->getName());
			}
			else if (type == "Admin")
			{
				adminMenu((*iterator)->getName());
			}
			else if (type == "Engineer")
			{
				engineerMenu((*iterator)->getName());
			}
			return;
		}
	}
}
void SiteTrackerController::updateTaskStatus()
{
	viewTask();
	cout << endl<<"\n Which Task you want to change!";
	cout << "\nEnter the Task ID: ";
	cin >> m_id;
	cout << "Status             : ";
	cin.ignore();
	getline(cin, m_status);
	string result = m_engineer.updateTaskStatus(m_id, m_status);
	cout << result << endl<<endl;
}
void SiteTrackerController::updateSitePhase()
{
	system("cls");
	Engineer* engineer = dynamic_cast<Engineer*>(m_currentUser);
	if (!engineer)
	{
		cout << "Access denied\n";
		return;
	}
	vector<string> sites = engineer->getAssignedSites();
	if (sites.empty())
	{
		cout << "Site is not assigned\n";
		return;
	}
	cout << "\nAssigned Sites:\n";
	for (string id : sites)
	{
		cout << id << endl;
	}
	string selectedSite;
	cout << "\nEnter site ID: ";
	cin >> selectedSite;
	if (!engineer->hasSite(selectedSite))
	{
		cout << "Invalid site\n";
		return;
	}
	cout << "Phase            : ";
	cin >> m_phase;
	string result= m_engineer.updateSitePhase(selectedSite, m_phase,m_admin.getSite());
	cout <<endl<< result<<endl<<endl;
}
void SiteTrackerController::addSiteStatus()
{
	system("cls");
	Engineer* engineer = dynamic_cast<Engineer*>(m_currentUser);
	if (!engineer)
	{
		cout << "Access denied\n";
		return;
	}
	vector<string> sites = engineer->getAssignedSites();
	if (sites.empty())
	{
		cout << "Site is not assigned\n";
		return;
	}
	cout << "\nAssigned Sites:\n";
	for (string id : sites)
	{
		cout << id << endl;
	}
	string selectedSite;
	cout << "\nEnter site ID: ";
	cin >> selectedSite;
	if (!engineer->hasSite(selectedSite))
	{
		cout << "Invalid site\n";
		return;
	}
	cout << "\nEnter the ReMark : ";
	cin.ignore();
	getline(cin, m_message);
	string result= m_engineer.addSiteStatus(selectedSite,m_message,m_admin.getSite());
	cout << "\n" << result << "\n\n";
}
void SiteTrackerController::viewSiteStatus()
{
	system("cls");
	cout << "\nEnter the site ID to view: ";
	cin >> m_siteId;
	m_message = m_engineer.viewSiteStatus(m_siteId, m_admin.getSite());
	if (m_message.empty())
	{
		cout << "\nNo Updates!\n\n";
		return;
	}
	cout << endl << "Here is the status : " << m_message << endl << endl;
}
void SiteTrackerController::viewSiteStatus(string name)
{
	system("cls");
	vector<Site*> mySites = m_admin.getSitesByOwner(name);
	if (mySites.empty())
	{
		cout << "\nYou have no sites registered.\n";
		return;
	}
	cout << "\nYour Sites:\n";
	for (auto s : mySites)
	{
		cout << "ID: " << s->getId()<< " | Location: " << s->getLocation() << endl;
	}

	cout << "\nEnter Site ID to view status: ";
	cin >> m_siteId;

	bool found = false;

	for (auto site : mySites)
	{
		if (site->getId() == m_siteId)
		{
			cout << "\nStatus: " << m_admin.viewSiteStatus(m_siteId) << endl<<endl;
			found = true;
			break;
		}
	}
	if (!found)
	{
		cout << "\nInvalid site ID or not your site!\n";
	}
}
void SiteTrackerController::addTask()
{
	system("cls");
	Engineer* engineer = dynamic_cast<Engineer*>(m_currentUser);
	if (!engineer)
	{
		cout << "Access denied\n";
		return;
	}
	vector<string> sites = engineer->getAssignedSites();
	if (sites.empty())
	{
		cout << "Site is not assigned\n";
		return;
	}
	cout << "\nAssigned Sites:\n";
	for (string id : sites)
	{
		cout << id << endl;
	}
	string selectedSite;
	cout << "\nEnter site ID: ";
	cin >> selectedSite;
	if (!engineer->hasSite(selectedSite))
	{
		cout << "Invalid site\n";
		return;
	}
	cout << "Task Description: ";
	cin.ignore();
	getline(cin, m_description);
	cout << "Dead Line       : ";
	cin >> m_deadline;
	cout << "Status          : ";
	cin.ignore();
	getline(cin, m_status);
	m_engineer.addTask( m_description, m_deadline, m_status, selectedSite);
	return;
}
void SiteTrackerController::viewTask()
{
	system("cls");
	Engineer* engineer = dynamic_cast<Engineer*>(m_currentUser);
	if (!engineer)
	{
		cout << "Access denied\n";
		return;
	}
	vector<string> sites = engineer->getAssignedSites();
	if (sites.empty())
	{
		cout << "Site is not assigned\n";
		return;
	}
	cout << "\nAssigned Sites:\n";
	for (string id : sites)
	{
		cout << id << endl;
	}
	string selectedSite;
	cout << "\nEnter site ID: ";
	cin >> selectedSite;
	if (!engineer->hasSite(selectedSite))
	{
		cout << "Invalid site\n";
		return;
	}
	vector<Task*> task = m_engineer.displayTask();
	if (task.empty())
	{
		cout << "\nNo Task Added!\n\n";
		return;
	}
	cout << "\n---Task Details---\n";
	for (auto details : task)
	{
		if(selectedSite== details->getSiteID())
		{
			cout << "Task ID         : " << details->getId() << endl;
			cout << "Task Description: " << details->getDescription() << endl;
			cout << "Task dead line  : " << details->getDeadline() << endl;
			cout << "Task status     : " << details->getStatus() << endl;
			cout << "Site Id         : " << details->getSiteID() << endl << endl;
		}
	}
}
void SiteTrackerController::addMaterialToSite()
{
	system("cls");
	Engineer* engineer = dynamic_cast<Engineer*>(m_currentUser);
	if (!engineer)
	{
		cout << "Access denied\n";
		return;
	}
	vector<string> sites = engineer->getAssignedSites();
	if (sites.empty())
	{
		cout << "Site is not assigned\n";
		return;
	}
	cout << "\nAssigned Sites:\n";
	for (string id : sites)
	{
		cout << id << endl;
	}
	string selectedSite;
	cout << "\nEnter site ID: ";
	cin >> selectedSite;
	if (!engineer->hasSite(selectedSite))
	{
		cout << "Invalid site\n";
		return;
	}
	cout << "\n Materials Name: ";
	cin >> m_name;
	cout << "Quantity         : ";
	cin >> m_quantity;
	m_engineer.addMetrial(m_name, selectedSite, m_quantity);
}
void SiteTrackerController::addMaterialToSiteByAdmin()
{
	for (auto site : m_admin.getSite())
	{
		if(site->isActiveSite())
		{
			cout << "\nID: " << site->getId();
			cout << "| Area: " << site->getArea();
			cout << "| Locarion: " << site->getLocation() << endl;
		}
	}
	cout << "\nEnter site ID: ";
	cin >> m_siteId;
	for (auto site : m_admin.getSite())
	{
		if (m_siteId == site->getId() && site->isActiveSite())
		{
			cout << "\n Materials Name: ";
			cin >> m_name;
			cout << "Quantity         : ";
			cin >> m_quantity;
			m_engineer.addMetrial(m_name, m_siteId, m_quantity);
			return;
		}
	}
	cout << "\nInvalid Site ID!\n";
}
void SiteTrackerController::viewMaterials()
{
	system("cls");
	Engineer* engineer = dynamic_cast<Engineer*>(m_currentUser);
	if (!engineer)
	{
		cout << "Access denied\n";
		return;
	}
	vector<string> sites = engineer->getAssignedSites();
	if (sites.empty())
	{
		cout << "Site is not assigned\n";
		return;
	}
	cout << "\nAssigned Sites:\n";
	for (string id : sites)
	{
		cout << id << endl;
	}
	string selectedSite;
	cout << "\nEnter site ID: ";
	cin >> selectedSite;
	if (!engineer->hasSite(selectedSite))
	{
		cout << "Invalid site\n";
		return;
	}
	vector<Material*> material = m_engineer.displayMatrial();
	if (material.empty())
	{
		cout << "\nNo Materials Are Added!";
		return;
	}
	cout << "\n---Materials Details---\n";
	for (auto details : material)
	{
		if(selectedSite== details->getSiteID())
		{
			cout << "\nMaterial Name: " << details->getName();
			cout << "\nMaterial ID  : " << details->getId();
			cout << "\nSite ID      : " << details->getSiteID();
			cout << "\nQuantity     : " << details->getQuantity() << endl;
		}
	}
}
void SiteTrackerController::viewMaterialsByAdmin()

{
	vector<Material*> material = m_engineer.displayMatrial();
	if (material.empty())
	{
		cout << "\nNo Materials Are Added!";
		return;
	}
	cout << "\n---Materials Details---\n";
	for (auto details : material)
	{
		cout << "\nMaterial Name: " << details->getName();
		cout << "\nMaterial ID  : " << details->getId();
		cout << "\nSite ID      : " << details->getSiteID();
		cout << "\nQuantity     : " << details->getQuantity() << endl;
			
	}
}
void SiteTrackerController::viewWorkers()
{
	system("cls");
	Engineer* engineer = dynamic_cast<Engineer*>(m_currentUser);
	if (!engineer)
	{
		cout << "Access denied\n";
		return;
	}
	vector<string> sites = engineer->getAssignedSites();
	if (sites.empty())
	{
		cout << "Site is not assigned\n";
		return;
	}
	cout << "\nAssigned Sites:\n";
	for (string id : sites)
	{
		cout << id << endl;
	}
	string selectedSite;
	cout << "\nEnter site ID: ";
	cin >> selectedSite;
	if (!engineer->hasSite(selectedSite))
	{
		cout << "Invalid site\n";
		return;
	}
	cout << "\n---Worker Details---\n";
	vector<Worker*> worker = m_engineer.displayWorker();
	if (worker.empty())
	{
		cout << "\nNo Workers Added\n";
		return;
	}
	for (auto user : worker)
	{
		if (user->getSiteID() == selectedSite)
		{
			if(user->isActive())
			{
				cout << "\nName   : " << user->getName();
				cout << "\nRole   : " << user->getRole();
				cout << "\nID     : " << user->getId();
				cout << "\nSite ID: " << user->getSiteID();
				cout << "\nAge    : " << user->getAge() << endl;
			}
		}
	}
}
void SiteTrackerController::viewAllWorkersByAdmin()
{
	cout << "\n---Worker Details---\n";
	vector<Worker*> worker = m_engineer.displayWorker();
	if (worker.empty())
	{
		cout << "\nNo Workers Added\n";
		return;
	}
	for (auto user : worker)
	{
	
		cout << "\nName   : " << user->getName();
		cout << "\nRole   : " << user->getRole();
		cout << "\nID     : " << user->getId();
		cout << "\nSite ID: " << user->getSiteID();
		cout << "\nAge    : " << user->getAge() << endl;
	}
}
void SiteTrackerController::addWorkers()
{
	system("cls");
	Engineer* engineer = dynamic_cast<Engineer*>(m_currentUser);
	if (!engineer)
	{
		cout << "Access denied\n";
		return;
	}
	vector<string> sites = engineer->getAssignedSites();
	if (sites.empty())
	{
		cout << "Site is not assigned\n";
		return;
	}
	cout << "\nAssigned Sites:\n";
	for (string id : sites)
	{
		cout << id << endl;
	}
	string selectedSite;
	cout << "\nEnter site ID: ";
	cin >> selectedSite;
	if (!engineer->hasSite(selectedSite))
	{
		cout << "Invalid site\n";
		return;
	}
	cout << "Worker Name : ";
	cin.ignore();
	getline(cin, m_name);
	cout << "Worker Role : ";
	cin >> m_role;
	cout << "Worker Age  : ";
	cin >> m_age;
	m_engineer.addWorker(m_name, m_role, m_age, selectedSite);
}
void SiteTrackerController::viewEngineer()
{
	system("cls");
	vector<Engineer*> engineerList=m_admin.getEngineersList();
	if (engineerList.empty())
	{
		cout << "\n---No engineers---\n";
		return;
	}
	cout << "\n---Engineer List---\n";
	for (auto user : engineerList)
	{
		if(user->isActive()==true)
		{
			cout << "Engineer ID              : " << user->getId() << endl;
			cout << "Engineer Name            : " << user->getName() << endl;
			cout << "Engineer Phone           : " << user->getPhone() << endl;
			cout << "Engineer Assigned Site ID: ";
			for (const auto& id : user->getSiteId())
			{
				cout << id << ",";
			}
			cout << "\n\n\n";
		}
	}
}
void SiteTrackerController::viewSite()
{
	system("cls");
	vector<Site*> sites = m_admin.getSite();
	if (sites.empty())
	{
		cout << "\nNo sites!\n";
		return;
	}
	cout << "\n---Sites List----\n";
	for (auto site : sites)
	{
		if (site->isActiveSite() == true)
		{
			cout << "\nSite ID            : " << site->getId();
			cout << "\nSite Name          : " << site->getSiteName();
			cout << "\nLocation           : " << site->getLocation();
			cout << "\nArea of Square feet: " << site->getArea();
			cout << "\nOwner Name         : " << site->getOwner();
			cout << "\nSite Phase         : " << site->getPhase();
			cout << "\nEngineer           : " << site->getEngineer() << endl << endl << endl;
		}
	}
}
void SiteTrackerController::addSite()
{
	system("cls");
	cout << "\nName of the Site :";
	cin >> m_name;
	cout << "Location           : ";
	cin >> m_location;
	cout << "Area of Square feet  : ";
	if (!(cin >> m_area))
	{
		cout << "\nEnter correct area!";
		return;
	}
	cout << "Owner Name         : ";
	cin.ignore();
	getline(cin,m_owner);
	cout << "Phase              : ";
	cin >> m_phase;
	m_admin.addNewSite(m_name,m_location, m_area, m_owner,m_phase);
}
void SiteTrackerController::addEngineer()
{
	system("cls");
	cout << "Name    : ";
	cin.ignore();
	getline(cin, m_name);
	cout << "Email   : ";
	cin >> m_username;
	m_flag = emailValidation(m_username);
	if (!m_flag) { return; }
	cout << "Password: ";
	cin >> m_password;
	cout << "Phone   : ";
	cin >> m_phone;
	m_flag = phoneValidation(m_phone);
	if (!m_flag) { return; }
	Engineer* engineer = m_admin.createEngineer(m_name, m_phone, m_username, m_password);
	m_user.push_back(engineer);
}