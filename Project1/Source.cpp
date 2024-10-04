#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>


using namespace std;


int main()
{
	int i = 0;
	int j = 0;

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

	char** blobArray = new char* [row+1];
	for (int i = 0; i < row; i++) {
		blobArray[i] = new char[col];
	}


	vector<vector<char>> array(row, vector<char>(col));

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			inFile.get(array[i][j]);  // After long researches i found the way to copy the text file thanks to .ignore
		}
		inFile.ignore();  // :)
	}


	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cout << array[i][j] << " ";
		}
		cout << endl;
	}


	inFile.close();


	return 0;
}