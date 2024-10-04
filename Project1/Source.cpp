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
		cerr << "Erorr while opening file!!!" << endl; // I change the cout with cerr because cerr used specifically for error messages or alerts. Since it is unbuffered, it is immediately printed to the console or log, which is important when debugging or handling errors.
		return 1;

	}

	int row = 0;
	int col = 0;


	int a;
	while (inFile >> a)
	{
		if (row != 0)
		{
			col = a;
			break;
		}
		row = a;
	}

	cout << "Row=" << row << "   Col=" << col << endl;


	inFile.close();


	return 0;
}