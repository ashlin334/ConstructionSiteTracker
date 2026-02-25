#include "Engineer.h"
int Engineer::m_counter = 1;
Engineer::Engineer(string name, string phone, string username, string password) : User(username,password,"Engineer",name,phone,true)
{
	if (m_counter < 10)
	{
		m_id = "E0" + to_string(m_counter);
	}
	else
	{
		m_id = "E" + to_string(m_counter);
	}
	m_counter++;
	m_name = name;
	m_phone = phone;
}
Engineer::Engineer(string name, string phone, string username, string password, vector<string> ids,bool status) : User(username, password, "Engineer", name,phone,status)
{
	if (m_counter < 10)
	{
		m_id = "E0" + to_string(m_counter);
	}
	else
	{
		m_id = "E" + to_string(m_counter);
	}
	m_counter++;
	m_name = name;
	m_phone = phone;
	m_siteId = ids;
}
string Engineer::getName()
{
	return m_name;
}
string Engineer::getPhone()
{
	return m_phone;
}
string Engineer::getId()
{
	return m_id;
}
string Engineer::menu()
{
	return "Engineer";
}
void Engineer::setSiteId(string id)
{
	m_siteId.push_back(id);
}
vector<string> Engineer::getSiteId()
{
	if (m_siteId.empty())
	{
		return {};
	}
	return m_siteId;
}
void Engineer::addWorker(string name, string role, int age, string siteID)
{
	worker.push_back(new Worker(name, role, age, siteID, true));
}

void Engineer::addWorker( string name, string role, int age, string siteID,string isActive)
{
	bool status = false;
	if (isActive == "Active")
	{
		status = true;
	}
	worker.push_back(new Worker(name, role, age, siteID,status));
}
vector<Worker*> Engineer::displayWorker()
{
	return worker;
}
void Engineer::addMetrial(string name, string siteID, int quantity)
{
	m_material.push_back(new Material(name, siteID, quantity));
}
vector<Material*> Engineer::displayMatrial()
{
	return m_material;
}
void Engineer::addTask( string description, string deadline, string status,string siteID)
{
	m_task.push_back(new Task(description,deadline, status,siteID));
}
vector<Task*> Engineer::displayTask()
{
	return m_task;
}
string Engineer::addSiteStatus(string id,string message,vector<Site*>& sites)
{
	for (auto site : sites)
	{
		if (site->getId() == id && site->isActiveSite())
		{
			site->updateSiteStatus(message);
			return "Status Added!";
		}
	}
	return "Not Found!";
}
string Engineer::viewSiteStatus(string id, vector<Site*>& sites)
{
	for (auto site : sites)
	{
		if (site->getId() == id)
		{
			return site->getSiteStatusMessage();
		}
	}
	return "No Status Found!";
}
string Engineer::updateSitePhase(string id, int phase, vector<Site*>& sites)
{
	for (auto site : sites)
	{
		if (site->getId() == id)
		{
			site->setPhase(phase);
			return "\nThe Site Phase has been updated!";
		}
	}
	return "\nThe site ID is not in the Data base try another one!";
}
bool Engineer::checkSiteID(string id, vector<Site*>& sites)
{
	for (auto site : sites)
	{
		if (site->getId() == id && site->isActiveSite())
		{
			return true;
		}
	}
	return false;
}
string Engineer::updateTaskStatus(string id, string status)
{
	for (auto task : m_task)
	{
		if (task->getId() == id)
		{
			task->updateStatus(status);
			return "\nTask Updated";
		}
	}
	return "\nTask Id not in your database, Try another one!";
}
vector<string> Engineer::getAssignedSites()
{
	return m_siteId;
}
void Engineer::addSite(string id)
{
	m_siteId.push_back(id);
}
bool Engineer::hasSite(string siteId)
{
	for (const string& id : m_siteId)
		if (id == siteId)
			return true;

	return false;
}
Engineer::~Engineer()
{
	for (auto worker : worker)
	{
		delete worker;
	}
	for (auto material : m_material)
	{
		delete material;
	}
	for (auto task : m_task)
	{
		delete task;
	}
}