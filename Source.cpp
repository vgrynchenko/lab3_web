#include "Header.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#pragma warning(disable : 4996)
using namespace std;

void main()
{
	
	char * StringParam = getenv("QUERY_STRING");
	int i = 0;
	if (StringParam == NULL)
	{
		cout << "Content-type:text/html\r\n\r\n";
		cout << "<html>\n";
		cout << "<head>\n";
		cout << "</head>\n";
		cout << "<body>\n";
		cout << "</body>\n";
		cout << "</html>\n";
		cout << "Parameters are not entered";

	}
	else if (strcmp(StringParam, "")==0)
	{
		cout << "Content-type:text/html\r\n\r\n";
		cout << "<html>\n";
		cout << "<head>\n";
		cout << "</head>\n";
		cout << "<body>\n";
		cout << "</body>\n";
		cout << "</html>\n";
		cout << "Check params!";
	}
	else
	{
		string tmp = "";
		string NewStr = StringParam;
		vector<int> OurParam;

		for (i = 0; i < NewStr.length(); i++)
		{
			if (StringParam[i] == ',')
			{
				int ForParam = stoi(tmp);
				OurParam.push_back(ForParam);
				tmp = "";
			}
			else if (i == NewStr.length() - 1)
			{
				tmp += NewStr[i];
				int ForParam = stoi(tmp);
				OurParam.push_back(ForParam);

			}
			else
			{
				tmp += NewStr[i];

			}
		}
		cout << "Content-type:text/html\r\n\r\n";
		cout << "<html>\n";
		cout << "<head>\n";
		cout << "</head>\n";
		cout << "<body>\n";
		cout << "</body>\n";
		cout << "</html>\n";
		int size;
		double percent, cat1, cat2;
		int increase, cat_index, index;
		//cout << "Enter the number of triangles in the array:";
		//cin >> size;
		cout << "Parameters: 1 - Array size of triangles; 2 - The index of the triangle for work; 3 - Choice the operation; 4 - Catet for resizing (1 or 2); 5 - Increase/Decrease; 6  - Percent" << "<br>";
		size = OurParam[0];
		cout << "Array size of triangles: " << size << "<br>";
		re_triangle *triangles = new re_triangle[size];
		for (i = 0; i < size; i++)
		{
			cat1 = 1 + rand() % 15;
			cat2 = 1 + rand() % 15;
			cout << " Cathetus of the triangle: " << i << ":" << cat1 << " " << cat2 << "<br>";
			triangles[i].Setcatet1(cat1);
			triangles[i].Setcatet2(cat2);
		}
		index = OurParam[1];
		cout << "Index of the triangle for work: " << OurParam[1] << "<br>";

		cout << "Select an operation (1 - Decrease/Increase, 2 - Radius of the circumscribed circle, 3 - Semiperimeter, 4 - Finding angles): " << OurParam[2] << "<br>";
		//cin >> ind;
		int ind  = 2;
		while(ind < OurParam.size())
		{
			switch (OurParam[ind])
			{
			case 1:
				//cout << "Select the cathetus for resizing(1 or 2):" << endl;
				//cin >> cat_index;
				cat_index = OurParam[3];
				cout << "The cathetus for resizing(1 or 2):" << cat_index << "<br>";
				//cout << "Find the operation (1- increase, 0 - decrease):" << endl;
				//cin >> increase;
				increase = OurParam[4];
				cout << "The operation (1- increase, 0 - decrease):" << increase << "<br>";
				//cout << "Enter the percentage increase/decrease:" << endl;
				//cin >> percent
				percent = OurParam[5];
				cout << "The percentage increase / decrease:" << percent << "<br>";
				cout << "Size of the modified side :" << triangles[index].scale(cat_index, percent, increase) << "<br>";
				ind += 2;
				break;
			case 2:
				cout << "Radius of the circumscribed circle :" << triangles[index].Radius_of_the_circumscribed_circle() << "<br>";
				break;
			case 3:
				cout << "Semiperimeter:" << triangles[index].half_per() << "<br>";
				break;
			case 4:
				cout << "Angles:" << "<br>";
				cout << "90" << "<br>";
				cout << triangles[index].one_of_the_corners() << "<br>";
				cout << triangles[index].second_corner() << "<br>";
				break;
			}
			ind++;
		}
	}
	//system("pause");
}