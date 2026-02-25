#include "Material.h"
int Material::m_counter = 1;
Material::Material(string name, string siteID, int quantity)
{
	if (m_counter < 10)
	{
		m_id = "M0" + to_string(m_counter);
	}
	else
	{
		m_id = "M" + to_string(m_counter);
	}
	m_counter++;
	m_name = name;
	m_siteId = siteID;
	m_quantity = quantity;
}
string Material::getName()
{
	return m_name;
}
string Material::getId()
{
	return m_id;
}
string Material::getSiteID()
{
	return m_siteId;
}
int Material::getQuantity()
{
	return m_quantity;
}