#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;


size_t ParseVar(string, string);
int ParseEOF(string);
void Extract(string, string, ifstream&);

int main()
{
	string textDat;
	string searchtxt = "contact_name";
	
	cout << "Enter term to search: ";
	getline(cin, searchtxt);

	ifstream inFile("/home/chasechimeric/Downloads/signalbackup-tools/yeet.xml");

	Extract(textDat, searchtxt, inFile);

	inFile.close();
	return 0;
}


size_t ParseVar(string textDat, string sentinel)
{
	size_t found = textDat.find(sentinel);
	return found;
}

int ParseEOF(string textDat)
{
	size_t location;
	int iter = 0;
	for (size_t i = 0; i < textDat.length(); i++)
	{
		if (textDat[i] == '"')
		{
			location = i;
			break;
		}
	}
	return location;
}

void Extract(string textDat, string searchtxt, ifstream& inFile)
{
	int iter = 0;
	size_t loc;
	while (getline(inFile, textDat))
	{
		iter++;
		if(textDat.length() != 0)
		{
			loc = ParseVar(textDat, searchtxt);
			textDat.erase(0, loc + searchtxt.length()+2);
			loc = ParseEOF(textDat);
			textDat.erase(loc, textDat.length() - (loc));
			cout  << iter << ' ' << textDat << endl;
		}
	}
}
