#include "Task.h"
int Task::m_counter = 1;
Task::Task(string description, string deadline, string status, string siteID)
{
	if (m_counter < 10)
	{
		m_id = "T0" + to_string(m_counter);
	}
	else
	{
		m_id = "T" + to_string(m_counter);
	}
	m_counter++;
	m_description = description;
	m_deadline = deadline;
	m_status = status;
	m_siteID = siteID;
}
string Task::getId()
{
	return m_id;
}
string Task::getDescription()
{
	return m_description;
}
string Task::getDeadline()
{
	return m_deadline;
}
string Task::getStatus()
{
	return m_status;
}
void Task::updateStatus(string newStatus)
{
	m_status = newStatus;
}
string Task::getSiteID()
{
	return m_siteID;
}