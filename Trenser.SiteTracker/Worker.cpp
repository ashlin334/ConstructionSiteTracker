#include "Worker.h"
int Worker::m_counter = 1;
Worker::Worker(string name, string role, int age, string siteId, bool isActive)
{
	if (m_counter < 10)
	{
		m_id = "W0" + to_string(m_counter);
	}
	else
	{
		m_id = "W" + to_string(m_counter);
	}
	m_counter++;
	m_workerName = name;
	m_role = role;
	m_age = age;
	m_siteId = siteId;
	if (isActive)
	{
		m_isActive = true;
	}
	else
	{
		m_isActive = false;
	}
}
bool Worker::isActive()
{
	return m_isActive;
}
void Worker::deactive()
{
	m_isActive = false;
}
string Worker::getName()
{
	return m_workerName;
}
string Worker::getRole()
{
	return m_role;
}
string Worker :: getId()
{
	return m_id;
}
string Worker::getSiteID()
{
	return m_siteId;
}
int Worker::getAge()
{
	return m_age;
}