#include "Site.h"
int Site::m_counter = 1;
Site::Site(string siteName, string location, float area, string owner, int phase)
{
	if (m_counter < 10)
	{
		m_id = "S0" + to_string(m_counter);
	}
	else
	{
		m_id = "S" + to_string(m_counter);
	}
	m_counter++;
	m_siteName = siteName;
	m_phase = phase;
	m_location = location;
	m_area = area;
	m_owner = owner;
	m_isActive = true;
}
Site::Site(string siteName, string location, float area, string owner, int phase, string engineerName,string status)
{
	if (m_counter < 10)
	{
		m_id = "S0" + to_string(m_counter);
	}
	else
	{
		m_id = "S" + to_string(m_counter);
	}
	m_counter++;
	m_siteName = siteName;
	m_phase = phase;
	m_location = location;
	m_engineer = engineerName; 
	m_area = area;
	m_owner = owner;
	if(status=="Active")
	{
		m_isActive = true;
	}
	else
	{
		m_isActive = false;
	}
}
void Site::setEngineer(string name)
{
	m_engineer = name;
}
string Site::getOwner()
{
	return m_owner;
}
string Site::getLocation()
{
	return m_location;
}
string Site::getEngineer()
{
	if (m_engineer.empty())
	{
		return "Not assigned Engineer yet";
	}
	return m_engineer;
}
string Site::getId()
{
	return m_id;
}
string Site::getSiteName()
{
	return m_siteName;
}
float Site::getArea()
{
	return m_area;
}
int Site::getPhase()
{
	return m_phase;
}
void Site::updateSiteStatus(string message)
{
	status.update(m_id, message);
}
string Site::getSiteStatusMessage()
{
	return status.getMessage();
}
void Site::setPhase(int phase)
{
	m_phase = phase;
}
void Site::deactiveSite()
{
	m_isActive = false;
}
bool Site::isActiveSite()
{
	return m_isActive;
}
