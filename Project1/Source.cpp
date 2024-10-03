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

	char a;
	while (inFile.get(a))
	{
		cout << "Read char:" << a << endl;  //A way to read every char one by one and visualize it
	}

	inFile.close();


	return 0;
}