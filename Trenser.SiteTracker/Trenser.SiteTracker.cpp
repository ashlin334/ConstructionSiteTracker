//<------ Author : Ashlin Babu--------->
//<------ Date   : 23-02-2026---------->
#include<iostream>
using namespace std;
#include "FileManager.h"
#include "SiteTrackerController.h"
int main()
{
	try
	{
		FileManager fileManager;
		SiteTrackerController siteControl(&fileManager);
		siteControl.loadFromFiles();
		siteControl.controllerMenu();
		siteControl.saveToFile();
	}
	catch (const exception& e)
	{
		cout << "Exception: " << e.what();
	}
	return 0;
}