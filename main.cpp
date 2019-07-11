//Moses Cuevas
//CS 840
//Due 5/21/2017
//Assignment 6

#include <iostream>
#include <conio.h>
#include <vector>
#include <iomanip>
#include "Student.h"
using namespace std;

void sort(vector<Student>& );
int bin_search(char[], vector<Student>&);

int main()
{
	vector<Student> stuVector;//instructions say vector of student objects
	Student* ptr;
	Student* stuArray[20];//instructions say array of student pointers
	int arrlength=0, result;
	char choice, search[40];
	double totalgpa=0;

	cout << showpoint << fixed << setprecision(2);

	do{
		cout << "Would you like to add a student? [y/n] : ";
		cin >> choice;
		if (choice=='y' || choice=='Y')
		{
			cout << "Does the student work? [y/n] : ";
			cin >> choice;
			if (choice=='y' || choice=='Y')
			{
				ptr = new StuWorker;
				ptr->read();
				stuArray[arrlength++] = ptr;
				stuVector.push_back(*ptr);
				cout<<endl;
			}
			else if (choice=='n' || choice=='N')
			{
				ptr = new Student;
				ptr->read();
				stuArray[arrlength++] = ptr;
				stuVector.push_back(*ptr);
				choice='y';//to stay in do while loop and use the same choice variable
				cout<<endl;
			}
			else
				cout<<"Invalid Entry\n";
		}
		else if (choice!='n' && choice!='N')
			cout<<"Invalid Entry\n";

	}while (choice!='n' && choice!='N');

	cout<<endl;
	for(int i=0; i<arrlength; i++)
	{
		stuArray[i]->print();
		cout<<endl;
	}

	sort(stuVector);//doesn't change the order in the array
	cout<<"\nSorted_Students_List______\n";
	for (vector<Student>::iterator it = stuVector.begin(); it != stuVector.end(); ++it)
	{
		it->print();
		cout << endl;
		totalgpa += it->get_gpa();
	}

	cout<<"Average GPA: "<< totalgpa / arrlength <<endl;

	cout<<"\nEnter the name of the student to search for: ";
	cin.ignore();
	cin.getline(search,40);

	result = bin_search(search, stuVector);

	if( result >= 0 )
		cout<<"Student was found at index "<< result <<endl;
	else
		cout<<"Student not found.\n";

	delete ptr;// maybe not needed (recheck main.cpp of assign.3)
	//delete [] stuArray;
	cout << "\nPress any key to continue.";
	_getch();
	return 0;
}

void sort(vector<Student>& list)
{
	bool swap;
	Student temp;
	do
	{
		swap = false;
		for (vector<Student>::iterator iter = list.begin(); ((1+iter) != list.end() && iter != list.end()); ++iter)//problem is list.end()
		{
			if (strcmp(iter->get_name(), (1+iter)->get_name()) > 0)//compare letters
			{
				temp = *iter;
				*iter = *(1+iter);
				*(1+iter) = temp;
				swap = true;
			}
		}
	} while (swap);
}

int bin_search(char query[], vector<Student>& list)
{
	//sort(list);//commented because redundant in this particular program
	int first = 0;
	int last = list.size() - 1;
	int middle;
	int position = -1;
	bool found = false;

	while (first <= last && !found)
	{
		middle = (first + last) / 2;
		if (strcmp(list.at(middle).get_name(), query) == 0)
		{
			found = true;
			position = middle;
		}
		else if (strcmp(list.at(middle).get_name(), query) > 0)
			last = middle - 1;
		else
			first = middle + 1;
	}
	return position;
}


/*void sort(vector<Student>& list)//sort without iterator
{
	bool swap;
	Student tmp;
	do
	{
		swap = false;
		for (int i = 0; i < list.size() - 1; i++)
			if (strcmp(list.at(i).get_name(),list.at(i + 1).get_name()) > 0)//compare letters
			{
				tmp = list.at(i);
				list.at(i) = list.at(i + 1);
				list.at(i + 1) = tmp;
				swap = true;
			}

	} while (swap);
}*/