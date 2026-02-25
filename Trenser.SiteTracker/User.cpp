#include "User.h"
string User::getPassword()
{
	return m_password;
}
string User::getUsername()
{
	return m_username;
}
string User::getUserType()
{
	return m_userType;
}
string User::getName()
{
	return m_name;
}
string User::getPhone()
{
	return m_phone;
}
bool User::isActive()
{
	return m_isActive;
}
void User::deactive()
{
	m_isActive = false;
}