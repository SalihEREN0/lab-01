#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>


using namespace std;


struct Blob {
	int id;
	int pixels;
	double comRow;
	double comCol;
};

void printTable(vector<vector<char>> array, int row, int col); 
void dfs(vector<vector<char>>& array, int row, int col, int blobId, int& pixels, double& comRow, double& comCol);
void processBlobs(vector<vector<char>>& array, vector<Blob>& blobs);
void printBlob(vector<Blob>blobs);



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
	while (inFile >> a)  //Inputs the rows and columns
	{
		if (row != 0)
		{
			col = a;
			break;
		}
		row = a;
	}

	if (row == 0 || col == 0)
	{
		cerr << "Enter a valid file" <<endl;
		return 1;
	}

	vector<vector<char>> array(row, vector<char>(col)); //char vector 

	for (int i = 0; i < row; ++i) // Text file to char vector
	{
        inFile.ignore();  // :)

		for (int j = 0; j < col; ++j)
		{
			inFile.get(array[i][j]);  // After long researches i found the way to copy the text file thanks to .ignore
		}
		
	}

	inFile.close();   //closes the file

	printTable(array, row, col); //prints the blobs

	vector<Blob> blobs;
	processBlobs(array, blobs); // processes the array with depth first search algorithm 
	printBlob(blobs);  // prints the blobs

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


void dfs(vector<vector<char>>& array, int row, int col, int blobId, int& pixels, double& comRow, double& comCol)
{
	if (row < 0 || row >= array.size() || col < 0 || col >= array[0].size() || array[row][col] != 'x')
	{
		return;
	}
	array[row][col] = blobId + '0'; // marks as visited
	pixels++;
	comRow += row;
	comCol += col;

	dfs(array, row - 1, col, blobId, pixels, comRow, comCol); // Up
	dfs(array, row + 1, col, blobId, pixels, comRow, comCol); // Down
	dfs(array, row, col - 1, blobId, pixels, comRow, comCol); // Left
	dfs(array, row, col + 1, blobId, pixels, comRow, comCol); // Right

}


void processBlobs(vector<vector<char>>& array, vector<Blob>& blobs)
{
	int blobId = 1;

	for (int i = 0; i < array.size(); i++)
	{
		for (int j = 0; j < array[0].size(); j++)
		{
			if (array[i][j] == 'x')
			{
				int pixels = 0;
				double comRow = 0.0;
				double comCol = 0.0;

				dfs(array, i, j, blobId, pixels, comRow, comCol);

				Blob blob;
				blob.id = blobId;
				blob.pixels = pixels;
				blob.comRow = comRow / pixels;
				blob.comCol = comCol / pixels;

				blobs.push_back(blob);
				blobId++;
			}
		}
	}
}


void printBlob(vector<Blob>blobs)
{
	cout << fixed << setprecision(2);
	cout << "+--------+--------------+-----------+--------------+" << endl; //8  14  11  14
	cout << "|  Blob  |  NoOfPixels  |  CoM Row  |  CoM Column  |" << endl;
	cout << "+--------+--------------+-----------+--------------+" << endl;
	for (const auto& blob : blobs)
	{
		cout << "|" << setw(8) << blob.id << "|" << setw(14) << blob.pixels << "|" << setw(11) << blob.comRow << "|" << setw(14) << blob.comCol << "|" << endl;
	}
	cout << "+--------+--------------+-----------+--------------+" << endl;
}