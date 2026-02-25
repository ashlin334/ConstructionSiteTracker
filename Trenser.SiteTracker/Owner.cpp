#include "Owner.h"
int Owner::m_counter = 1;
Owner::Owner(string name, string phone, string username, string password) :User(username, password, "Owner", name, phone,true)
{
	if (m_counter < 10)
	{
		m_ownerId = "O0" + to_string(m_counter);
	}
	else
	{
		m_ownerId = "O" + to_string(m_counter);
	}
	m_counter++;
	m_name = name;
	m_phone = phone;
}
Owner::Owner(string name, string phone, string username, string password,bool status) :User(username, password, "Owner", name,phone,status)
{
	m_name = name;
	m_phone = phone;
	if (m_counter < 10)
	{
		m_ownerId = "O0" + to_string(m_counter);
	}
	else
	{
		m_ownerId = "O" + to_string(m_counter);
	}
	m_counter++;
}
string Owner::getOwnerID()
{
	return m_ownerId;
}
string Owner::getName()
{
	return m_name;
}
string Owner::getPhone()
{
	return m_phone;
}
string Owner::menu()
{
	return "Owner";
}
vector<string> Owner::getSiteIds()
{
	return m_siteIds;
}
void Owner::addSite(string id)
{
	m_siteIds.push_back(id);
}