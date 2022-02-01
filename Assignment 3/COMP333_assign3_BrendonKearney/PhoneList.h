#include <iostream>
#include <string>
#include <cassert>
#include <iomanip>
using namespace std;

//specification
//By: Brendon Kearney
//Assignment 3

struct Directory
{
	string name;
	int areaCode;
	int phoneNo;
	Directory* link;
};

class PhoneList
{
public:
	PhoneList(string /*title*/);
	~PhoneList();
	void showPhoneList(ostream& /*output*/)const;
	void addDirectory(string /*name*/, int /*areaCode*/, int/*phoneNo*/);
	void removeDirectory(string /*name*/);
	int getNoDirectories()const { return numberOfDirectories; }
	string getTitle()const { return title; }

private:
	Directory* firstPtr;
	string title;
	int numberOfDirectories;
	friend ostream& operator << (ostream&, const PhoneList&);
};