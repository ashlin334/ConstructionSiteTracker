//<------ Author : Ashlin Babu--------->
//<------ Date   : 23-02-2026---------->
#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Material
{
private:
	static int m_counter;
	string m_name,m_id,m_siteId;
	int m_quantity;
public:
	Material(string name, string siteID, int quantity);
	string getName();
	string getId();
	string getSiteID();
	int getQuantity();
};