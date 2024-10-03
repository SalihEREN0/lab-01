#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>


using namespace std;


int main()
{
	string filename;

	cout << "Enter the filename: ";
	getline(cin, filename);

	ifstream inFile;

	inFile.open(filename);

	if (inFile.fail())
	{
		cout << "Erorr while opening file!!!" << endl;
		return 1;

	}

	char c;

	while (inFile.get(c))
	{
		cout << c;
	}

	inFile.close();


	return 0;
}