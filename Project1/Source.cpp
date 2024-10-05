#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>


using namespace std;


void printTable(vector<vector<char>> array, int row, int col);



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

	cout << "Row=" << row << "   Col=" << col << endl;
	char** blobArray = new char* [row + 1];
	for (int i = 0; i < row; i++) {
		blobArray[i] = new char[col];
	}


	vector<vector<char>> array(row, vector<char>(col));

	for (int i = 0; i < row; ++i)
	{
        inFile.ignore();  // :)

		for (int j = 0; j < col; ++j)
		{
			inFile.get(array[i][j]);  // After long researches i found the way to copy the text file thanks to .ignore
		}
		
	}

	printTable(array, row, col); //prints the blobs



	return 0;

}



void printTable(vector<vector<char>> array, int row, int col)
{
	int count = 0;

	cout << "  ";
	for (int i = 0; i < col; i++)
	{
		cout << count;
		count++;
		if (count % 10 == 0)
		{
			count = 0;
		}
	}

	cout << endl << " +";
	for (int i = 0; i < col; i++)
	{
		cout << "-";
	}
	cout << "+" << endl;



	count = 0;

	for (int i = 0; i < row; i++)
	{

		if (count % 10 == 0)
		{
			count = 0;
		}

		cout << count  << "|";

		for (int j = 0; j < col; j++)
		{
			cout << array[i][j];
		}

		cout << "|" << count ;

		count++;

		cout << endl;
	}

	cout << " +";
	for (int i = 0; i < col; i++)
	{
		cout << "-";
	}
	cout << "+" << endl;

	count = 0;

	cout << "  ";
	for (int i = 0; i < col; i++)
	{
		cout << count;
		count++;
		if (count % 10 == 0)
		{
			count = 0;
		}
	}
	cout << "\n\n";
}