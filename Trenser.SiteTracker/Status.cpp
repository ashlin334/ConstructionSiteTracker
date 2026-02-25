#include "Status.h"
void Status::update(string id, string message)
{
	m_siteID=id;
	m_message = message;
}
string Status::getId()
{
	return m_siteID;
}
string Status::getMessage()
{
	return m_message;
}