#include "Admin.h"
Admin::Admin(string name, string phone, string username, string password,string status) : User(username, password, "Admin",name,phone,true)
{
	m_name = name;
	m_phone = phone;
	m_isActive = true;
}
string Admin::getName()
{
	return m_name;
}
string Admin::getPhone()
{
	return m_phone;
}
string Admin::menu()
{
	return "Admin";
}
void Admin::addNewSite(string siteName,string location, float area, string owner, int phase)
{
	m_site.push_back(new Site(siteName,location, area, owner, phase));
}
Engineer* Admin::createEngineer(string name, string phone, string username, string password)
{
	Engineer* engineer = new Engineer(name, phone, username, password);
	m_engineers.push_back(engineer);
	return engineer;
}
Engineer* Admin::createEngineer(string name, string phone, string username, string password,vector<string> ids,bool status)
{
	Engineer* engineer = new Engineer(name, phone, username, password,ids,status);
	m_engineers.push_back(engineer);
	return engineer;
}
string Admin::assignEngineerToSite(string siteId, string engineerId)
{
	Engineer* foundEngineer = nullptr;
	Site* foundSite = nullptr;
	for (auto engineer : m_engineers)
	{
		if (engineer->getId() == engineerId)
		{
			foundEngineer = engineer;
			break;
		}
	}
	for (auto site : m_site)
	{
		if (site->getId() == siteId)
		{
			foundSite = site;
			break;
		}
	}
	if (!foundEngineer || !foundSite)
	{
		return "ID is not in your Data Base, Try another one!";
	}
	foundEngineer->setSiteId(siteId);
	foundSite->setEngineer(foundEngineer->getName());
	return "Engineer assigned successfully";
}    
vector<Site*>& Admin::getSite()
{
	return m_site;
}
vector<Task*>& Admin::getTask()
{
	return m_task;
}
vector<Engineer*>& Admin::getEngineersList()
{
	return m_engineers;
}
string Admin::viewSiteStatus(string siteID)
{
	for (auto site : m_site)
	{
		if (site->getId() == siteID)
		{
			string message = site->getSiteStatusMessage();
			if (message.empty())
			{
				return "No Status Updates";
			}
			return message;
		}
	}
	return "Site Not Found";
}
bool Admin::deleteSite(string id,vector<Task*>& tasks)
{
	for (auto task = tasks.begin(); task != tasks.end();)
	{
		if ((*task)->getSiteID() == id)
		{
			delete* task;
			task = tasks.erase(task);
		}
		else { task++; }
	}
	for (auto iterator = m_site.begin(); iterator != m_site.end(); iterator++)
	{
		if ((*iterator)->getId() == id)
		{
			(*iterator)->deactiveSite();
			return true;
		}
	}
	return false;
}
bool Admin::deleteEngineer(string engineerId,vector<Engineer*>& engineers)
{
	for (auto iterator = engineers.begin(); iterator != engineers.end(); iterator++)
	{
		if ((*iterator)->getId() == engineerId)
		{
			(*iterator)->deactive();
			return true;
		}
	}
	return false;
}
bool Admin::isActiveAdmin()
{
	return m_isActive;
}
vector<Site*> Admin::findSitesByName(string name)
{
	vector<Site*> result;

	for (auto site : m_site)
	{
		if (site->getSiteName() == name)
		{
			result.push_back(site);
		}
	}
	return result;
}
vector<Engineer*> Admin::findEngineersByName(string name)
{
	vector<Engineer*> result;
	for (auto engineer : m_engineers)
	{
		if (engineer->getName() == name)
		{
			result.push_back(engineer);
		}
	}
	return result;
}
vector<Site*> Admin::getSitesByOwner(string ownerName)
{
	vector<Site*> result;
	for (auto site : m_site)
	{
		if (site->getOwner() == ownerName)
		{
			result.push_back(site);
		}
	}
	return result;
}
Admin::~Admin()
{
	for (auto site : m_site)
	{
		delete site;
	}
	for (auto engineer : m_engineers)
	{
		delete engineer;
	}
	for (auto task : m_task)
	{
		delete task;
	}
}