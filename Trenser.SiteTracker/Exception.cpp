#include "Exception.h"
int Exception::checker()
{
	int choice;
	bool valid = false;
	while (!valid)
	{
		try
		{
			cout << "\nEnter the choice: ";
			if (!(cin >> choice))	
			{
				throw runtime_error(" Invalid input !");
			}
			valid = true;
			return choice;
		}
		catch (const exception& e)
		{
			cout << "Exception: " << e.what()<<endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
}