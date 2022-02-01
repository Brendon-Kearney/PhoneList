#include "PhoneList.h"

//implementation
//By: Brendon Kearney
//Assignment 3

PhoneList::PhoneList(string newTitle)
{
	firstPtr = NULL;
	numberOfDirectories = 0;
	title = newTitle;
}

PhoneList::~PhoneList()
{
	delete firstPtr;
}

void PhoneList::showPhoneList(ostream& out) const
{
	out << endl << left << setw(20) << "name" << left << setw(20) << "areaCode" << "phoneNo" << endl << endl;
	Directory* walker = firstPtr;

	while (walker != NULL)
	{
		out << left << setw(20) << walker->name << left << setw(20) << walker->areaCode << walker->phoneNo << endl;
		walker = walker->link;
	}
}

void PhoneList::addDirectory(string newName, int newAreaCode, int newPhoneNo)
{
	//build 
	Directory* builder = new Directory;//add
	assert(builder != 0);
	//populate 
	builder->name = newName;
	builder->areaCode = newAreaCode;
	builder->phoneNo = newPhoneNo;
	numberOfDirectories++;
	builder->link = NULL;
	Directory* walker = firstPtr, * stalker = NULL;

	if (firstPtr == NULL)
	{
		builder->link = firstPtr;
		firstPtr = builder;
		cout << "node was added" << endl;
	}
	else
	{
		walker = firstPtr;
		stalker = firstPtr;
		while (walker && walker->name < newName) /* walk through list */
		{
			stalker = walker;
			walker = walker->link;
		}

		if (walker && walker->name == newName) /* duplicate name */
		{
			numberOfDirectories--;
			cout << "ERROR! duplicate name " << walker->name << endl;
		}

		else if (walker == firstPtr) /* Insert before first node */
		{
			builder->link = firstPtr;
			firstPtr = builder;
			cout << "node was added" << endl;
		}

		else /* Insert between or at end of list */
		{
			stalker->link = builder;
			builder->link = walker;
			cout << "node was added" << endl;
		}
	}
}


void PhoneList::removeDirectory(string newName)
{
	Directory* walker = firstPtr, * stalker = NULL;

	while (walker->link != NULL) /* walk through list */
	{
		if (walker->name == newName)
			break;

		stalker = walker;
		walker = walker->link;
	}

	if (firstPtr == walker) /* remove first node */
	{
		cout << "removed " << walker->name << endl;
		numberOfDirectories--;
		firstPtr = firstPtr->link;
		delete walker;
	}

	else if (walker->name == newName) /* remove node */
	{
		cout << "removed " << walker->name << endl;
		numberOfDirectories--;
		stalker->link = walker->link;
		delete walker;
	}

	else /* name not found */
	{
		cout << "ERROR! name not found " << newName << endl;
	}
}

