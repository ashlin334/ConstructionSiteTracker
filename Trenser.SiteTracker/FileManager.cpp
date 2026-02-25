#include "FileManager.h"

void FileManager::loadUser(vector<User*>& users, Admin& admin)
{
	ifstream file("User.txt");
	if (!file)
	{
		return;
	}
	string line, m_status;
	while (getline(file, line))
	{
		bool isActive=false;
		stringstream ss(line);
		string m_name, m_phone, m_username, m_password, m_role, m_siteIds;
		getline(ss, m_name, '|');
		getline(ss, m_username, '|');
		getline(ss, m_password, '|');
		getline(ss, m_role, '|');
		getline(ss, m_phone, '|');
		getline(ss, m_status, '|');
		if (m_status == "Active") { isActive = true; }
		if (m_role == "Admin")
		{
			users.push_back(new Admin(m_name, m_phone, m_username, m_password, m_status));
		}
		else if (m_role == "Engineer")
		{
			getline(ss, m_siteIds, '|');
			vector<string> ids;
			string currentId;
			stringstream idStream(m_siteIds);
			while (getline(idStream, currentId, ','))
			{
				if (!currentId.empty()) {
					ids.push_back(currentId);
				}
			}
			users.push_back(admin.createEngineer(m_name, m_phone, m_username, m_password, ids, isActive));
		}
		else if (m_role == "Owner")
		{
			users.push_back(new Owner(m_name, m_phone, m_username, m_password, isActive));
		}
	}
	file.close();
}
void FileManager::saveUser(vector<User*> users)
{
	ofstream file(USER);
	ofstream adminFile(ADMIN);
	ofstream engineerFile(ENGINEER);
	ofstream ownerFile(OWNER);
	for (auto user : users)
	{
		string m_role = user->getUserType();
		file << user->getName() << "|"
		    << user->getUsername() << "|"
			<< user->getPassword() << "|"
			<< user->getUserType() << "|"
			<< user->getPhone() << "|"
			<< (user->isActive() ? "Active" : "Inactive") << "|";
		if (m_role == "Engineer")
		{
			engineerFile << user->getName() << "|"
				<< user->getUsername() << "|"
				<< user->getPassword() << "|"
				<< user->getUserType() << "|"
				<< user->getPhone() << "|"
				<< (user->isActive() ? "Active" : "Inactive") << "|";
		}
		if (m_role == "Admin")
		{
			adminFile << user->getName() << "|"
				<< user->getUsername() << "|"
				<< user->getPassword() << "|"
				<< user->getUserType() << "|"
				<< user->getPhone() << "|"
				<< (user->isActive() ? "Active" : "Inactive") << "|";
			adminFile << "\n";
		}
		if (m_role == "Owner")
		{
			ownerFile << user->getName() << "|"
				<< user->getUsername() << "|"
				<< user->getPassword() << "|"
				<< user->getUserType() << "|"
				<< user->getPhone() << "|"
				<< (user->isActive() ? "Active" : "InActive") << "|";
			ownerFile << "\n";
		}
		if (m_role == "Engineer")
		{
			auto engineer = dynamic_cast<Engineer*>(user);
			vector<string> siteIDS = engineer->	getSiteId();
			for (auto id : siteIDS)
			{
				if (id.empty())
				{
					file << "None" << ",";
					engineerFile << "None" << ",";
				}
				else
				{
					file << id << ",";
					engineerFile << id << ",";
				}
			}
			file << "|";
			engineerFile << "\n";
		}
		file << "\n";
	}
	file.close();
}
void FileManager::loadSite(vector<Site*>& site)
{
	ifstream file(SITE);
	if (!file)
	{
		return;
	}
	string line, m_status;
	while (getline(file, line))
	{
		stringstream ss(line);
		getline(ss, m_id, '|');
		getline(ss, m_SiteName, '|');
		getline(ss, m_owner, '|');
		getline(ss, m_location, '|');
		getline(ss, m_engineer, '|');
		getline(ss, m_area, '|');
		getline(ss, m_phase, '|');
		getline(ss, m_status, '|');
		float area = stof(m_area);
		int phase = stoi(m_phase);
		site.push_back(new Site(m_SiteName,m_location, area, m_owner, phase,m_engineer,m_status));
	}
	file.close();
}
void FileManager::saveSite(vector<Site*>& sites)
{
	ofstream file(SITE);
	for (auto site : sites)
	{
		file << site->getId() << '|'
			<< site->getSiteName() << '|'
			<< site->getOwner() << '|'
			<< site->getLocation() << '|'
			<< site->getEngineer() << '|'
			<< site->getArea() << '|'
			<< site->getPhase() << '|';
		if (site->isActiveSite())
		{
			file << "Active";
		}
		else
		{
			file << "InActive";
		}
			file <<"\n";
	}
	file.close();
}
void FileManager::loadSiteStatus(vector<Site*>& sites)
{
	ifstream file(SITESTATUS);
	if (!file)
	{
		return;
	}
	string line,m_message;
	while (getline(file, m_id, '|') && getline(file, m_message))
	{
		for (auto site : sites)
		{
			if (site->getId() == m_id)
			{
				site->updateSiteStatus(m_message);
				break;
			}
		}
	}
	file.close();
}
void FileManager::saveSiteStatus(vector<Site*>& sites)
{
	ofstream file(SITESTATUS);
	for (auto site : sites)
	{
		file << site->getId() << '|' << site->getSiteStatusMessage() << '\n';
	}
	file.close();
}
void FileManager::loadWorker(Engineer& engineer)
{
	ifstream file(WORKER);
	if (!file)
	{
		return;
	}
	string name, role, siteId, line, tempAge,isActive;
	int age;
	while (getline(file, line))
	{
		stringstream ss(line);
		getline(ss, name, '|');
		getline(ss, role, '|');
		getline(ss, tempAge, '|');
		getline(ss, siteId, '|');
		getline(ss, isActive);
		age = stoi(tempAge);
		engineer.addWorker(name, role, age, siteId, isActive);
	}
	file.close();
}
void FileManager::saveWorker(Engineer& engineer)
{
	ofstream file(WORKER);
	vector<Worker*>workers=engineer.displayWorker();
	for (auto worker : workers)
	{
		file << worker->getName() << '|'
			<< worker->getRole() << '|'
			<< worker->getAge() << '|'
			<< worker->getSiteID() << "|";
		string status = worker->isActive() ? "Active" : "InActive";
		file << status << "\n";
	}
	file.close();
}
void FileManager::loadTask(Engineer& engineer)
{
	ifstream file(TASK);
	if (!file)
	{
		return;
	}
	string taskId,description, deadline, status, siteID, line;
	while (getline(file, line))
	{
		stringstream ss(line);
		getline(ss, taskId, '|');
		getline(ss, description, '|');
		getline(ss, deadline, '|');
		getline(ss, status, '|');
		getline(ss, siteID, '|');
		engineer.addTask(description, deadline, status, siteID);
	}
	file.close();
}
void FileManager::saveTask(Engineer& engineer)
{
	ofstream file(TASK);
	vector<Task*> tasks = engineer.displayTask();
	for (auto task : tasks)
	{
		file<<task->getId()<<'|'
		    << task->getDescription() << '|'
			<< task->getDeadline() << '|'
			<< task->getStatus() << '|'
			<< task->getSiteID() << "\n";
	}
	file.close();
}
void FileManager::loadMaterial(Engineer& engineer)
{
	ifstream file(MATERIAL);
	if (!file)
	{
		return;
	}
	string name,siteID,tempQuantity,line,materialId;
	int quantity;
	while (getline(file, line))
	{
		stringstream ss(line);
		getline(ss, materialId,'|');
		getline(ss, name, '|');
		getline(ss, siteID, '|');
		getline(ss, tempQuantity, '|');
		quantity = stoi(tempQuantity);
		engineer.addMetrial(name, siteID, quantity);
	}
	file.close();
}
void FileManager::saveMaterial(Engineer& engineer)
{
	ofstream file(MATERIAL);
	vector<Material*> materials = engineer.displayMatrial();
	for (auto material : materials)
	{
		file << material->getId() << '|'
			<< material->getName() << '|'
			<< material->getSiteID() << '|'
			<< material->getQuantity() << "\n";
	}
}
