#include "PhoneList.h"

//client code
//By: Brendon Kearney
//Assignment 3

ostream& operator << (ostream& out, const PhoneList& list)
{
	out << endl << list.title << "'s Number Of Directories: " << list.numberOfDirectories << endl << endl;
	return out;
}

int main()
{
	PhoneList* firstPtr = new PhoneList("brendonList");
	assert(firstPtr);

	firstPtr->addDirectory("alexander", 5486, 613382172);
	firstPtr->addDirectory("kearney", 4204, 61380172);
	firstPtr->addDirectory("drney", 42054, 613803517);
	firstPtr->addDirectory("bearney", 424, 613831172);
	firstPtr->addDirectory("drney", 42054, 613803517);
	firstPtr->addDirectory("cearney", 420, 618031172);
	firstPtr->addDirectory("aearney", 404, 613803112);

	cout << endl << firstPtr->getTitle();
	firstPtr->showPhoneList(cout);
	cout << *firstPtr;

	firstPtr->removeDirectory("kearney");
	firstPtr->removeDirectory("aearney");
	firstPtr->removeDirectory("drney");

	cout << endl << firstPtr->getTitle();
	firstPtr->showPhoneList(cout);
	cout << *firstPtr;

	system("pause");
}
