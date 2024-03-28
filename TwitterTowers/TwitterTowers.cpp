#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

enum Shapes { RECTANGLE = 1, TRIANGLE = 2 };

void printTriangle(int  height, int width);
void rectangle(int  height, int width);
void triangle(int  height, int width);

int main()
{
	int choice, height, width;
	cout << "To select a rectangular tower press 1\nTo select a triangular tower press 2\nTo exit press 3\n";
	cin >> choice;
	while (choice != 3)
	{
		cout << "Enter height: ";
		cin >> height;
		cout << "Enter width: ";
		cin >> width;
		switch (choice)
		{
		case RECTANGLE:
			rectangle(height, width);
			break;
		case TRIANGLE:
			triangle(height, width);
			break;
		}
		cout << "To select a rectangular tower press 1\nTo select a triangular tower press 2\nTo exit press 3\n";
		cin >> choice;
	}
}

void rectangle(int  height, int width)
{
	if (height - width >= 5 || width - height >= 5)
		cout << "Area of the rectangle: " << height * width << "\n\n";
	else
		cout << "The scope of the rectangle: " << 2 * height + 2 * width << "\n\n";
}

void triangle(int  height, int width)
{
	int choice;
	cout << "To calculate the scope of the triangle press 1\nTo print the triangle press 2\n";
	cin >> choice;
	if (choice == 1)
	{
		float scope = pow(0.5 * width, 2) + pow(height, 2);
		scope = sqrt(scope);
		scope = 2 * scope + width;
		cout << "The scope of the triangle: " << scope << "\n\n";
	}
	else
	{
		if (width % 2 == 0 || pow(height, 2) < width)
			cout << "The triangle cannot be printed.\n\n";
		else
			printTriangle(height, width);
	}
}

void printTriangle(int  height, int width)
{
	int count = 0, space = width / 2, star = 1;
	int numRows = height - 2; //number of the row between the first and the last
	int numGroups = (width - 5) / 2 + 1; //wisth - 5 --> the second row from top has 2 stars less then the firs, minus the 3 stars in the second row from the top. /2 --> every row has to star more than the privies one.
	int remainder = numRows % numGroups; //remainder of rows's num
	int numLines = (numRows - remainder) / numGroups; //number of lines of star from the same group
	for (int i = 0; i < height; i++)
	{
		for (int j = space; j > 0; j--)
			cout << ' ';
		for (int j = 0; j < star; j++)
		{
			cout << '*';
		}
		cout << endl;
		if (i == 0 && remainder)
		{
			for (int j = 0; j < remainder; j++)
			{
				for (int j = space - 1; j > 0; j--)
					cout << ' ';
				cout << "***" << endl;
			}
			i += remainder;
		}
		if (star == width)
			break;
		count++;
		if (count == numLines || star == 1)
		{
			star += 2;
			count = 0;
			space--;
		}

	}
	cout << endl;
}