//Brain Corporation Coding Challenge
//Candidate: Jeffrey Liv
//Date: 02/25/2019

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iomanip>

using namespace std;

//Filter object containing range and temporal median filter functions
class filters {
private:
	float min = 0.03;
	float max = 50.0;

public:
	filters() {}
	vector<float> update(vector<float> &scan);
	vector<float> median(vector<float> &data);
	~filters() {}
};

//Update function
//Takes in an array of float values and returns a filtered output with values within the range of [0.03, 50.0]
vector<float> filters::update(vector<float> &scan)
{
	vector<float> updated_scan(scan.size(), 0);
	for (int i = 0; i < scan.size(); i++)
	{
		if (scan[i] < min)
			updated_scan[i] = min;
		else if (scan[i] > max)
			updated_scan[i] = max;
		else
			updated_scan[i] = scan[i];
	}

	return updated_scan;
}

//Median function
//Takes in an array of float values and returns the median of the array
vector<float> filters::median(vector<float> &data)
{
	vector<float> updated_scan(data.size(), 0);
	sort(data.begin(), data.end());
	int n = data.size();
	float median;

	for (int i = 0; i < n; i++)
	{
		if (n % 2 == 0)
		{
			median = 0.5 * (data[n / 2] + data[n / 2 - 1]);
			updated_scan[i] = median;
		}
		else
			updated_scan[i] = data[n / 2];
	}

	return updated_scan;
}

//Println function
//Prints a line
void println()
{
	for (int i = 0; i < 50; i++)
	{
		cout << "-";
	}
	cout << endl;
}

int main()
{
	//Init variables
	filters test;
	vector<float> scan;
	vector<float> range_output;
	vector<float> med_data;
	vector<float> temp;
	vector<vector<float> > med_output;
	vector<vector<float> > twod_vector;
	twod_vector.resize(5, vector<float>(5, 0));
	med_output.resize(5, vector<float>(5, 0));
	
	fstream f;
	int row = 0;
	int col = 0;
	float num = 0;
	int count = 0; //generic counter
	int n = 5; //temporal median n variable
	int D = 5; //temporal median D variable


	//RANGE UPDATE DEMO
	//Read in file for testing range update function
	f.open("range_test.txt", ios::in);
	while (!f.eof())
	{
		f >> num;
		scan.push_back(num);
	}
	f.close();

	//Update function is called and returns a filtered output
	range_output = test.update(scan);

	cout << "Brain Corporation Coding Challenge" << endl;
	cout << "Candidate: Jeffrey Liv" << endl << endl;
	cout << "Range Filter Demo" << endl;
	println();
	cout << left << setw(10) << "Scan" << left << setw(10) << "Updated Scan" << endl;
	println();

	//Print filtered output
	for (int i = 0; i < range_output.size(); i++)
	{
		cout << left << setw(10) << scan[i] << left << setw(10) << range_output[i] << endl;
	}
	cout << endl;
	cout << "Numbers read: " << scan.size() << endl;
	println();

	
	//TEMPORAL MEDIAN DEMO
	cout << endl << endl;
	cout << "Temporal Median Filter Demo" << endl;
	println();
	
	scan.clear(); //Clean up scan vector

	//Read in file for testing temporal median function
	f.open("med_test.txt", ios::in);
	while (!f.eof())
	{
		f >> num;
		scan.push_back(num);
	}
	f.close();
	
	count = 0; //Reset counter

	//Place scanned float input values into a 2-D vector
	for(int i = 0; i < 25; i++)
	{

		if (count == 0)
		{
			twod_vector[row][col] = scan[i];
		}
		else if ((count % 5) == 0)
		{
			col = 0;
			row++;
			twod_vector[row][col] = scan[i];
		}
		else
		{
			twod_vector[row][col] = scan[i];
		}
		col++;
		count++;
	}

	//Print 2-D vector
	cout << left << setw(10) << "Time | " << left << setw(10) << "Input Scan" << endl;
	println();
	for (int i = 0; i < 5; i++)
	{
		cout << left << setw(5) << i << "|";
		for (int j = 0; j < 5; j++)
		{
			cout << right << setw(5) << twod_vector[i][j] << "|";
		}
		cout << endl;
	}
	

	count = 0; //Reset counter
	
	//Median function is called to find the temporal median of the data set
	for (int i = 0; i < D; i++)
	{
		for (int j = 0; j < D; j++)
		{
			med_data.push_back(twod_vector[j][i]);
			temp = test.median(med_data);
			med_output[j][i] = temp[j];
			count++;
		}
		med_data.clear();
		temp.clear();
	}

	//Print an updated vector containing the temporal median of the data set
	cout << endl << endl;
	cout << left << setw(10) << "Time | " << left << setw(10) << "Return of the Update" << endl;
	println();
	for (int i = 0; i < D; i++)
	{
		cout << left << setw(5) << i << "|";
		for(int j = 0; j < D; j++)
			{
			cout << right << setw(5) << med_output[i][j] << "|";
			}
		cout << endl;
	}

	test.~filters(); //Deconstructor
	system("PAUSE");

	return 0;
}