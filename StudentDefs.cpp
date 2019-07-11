//Moses Cuevas
//CS 840
//Due 5/21/2017
//Assignment 6
#include <iostream>
#include "Student.h"
using namespace std;

Student::Student()
{
	units=0;
	gpa=0;
	strcpy(name, "\0");
	strcpy(id,"\0");
}

Student::Student(const Student& s)
{
	units=s.units;
	gpa=s.gpa;
	strcpy(name, s.name);
	strcpy(id, s.id);
}

Student& Student::operator= (const Student& s)
{
	units=s.units;
	gpa=s.gpa;
	strcpy(name, s.name);
	strcpy(id, s.id);
	return *this;
}

void Student::read()
{
	char c;
	int i = 0;
	cin.ignore();
	cout<<"Enter name: ";
	cin.get(c);
	while (c != '\n')
	{
		name[i++] = c;
		cin.get(c);
	}
	name[i] = '\0';

	i = 0;
	cout<<"Enter ID: ";
	cin.get(c);
	while (c != '\n')
	{
		id[i++] = c;
		cin.get(c);
	}
	id[i] = '\0';

	cout<<"Enter completed units: ";
	cin>> units;

	cout<<"Enter GPA: ";
	cin>> gpa;
}

void Student::print()
{
	cout<<"Name: "<< name <<endl;
	cout<<"ID: "<< id <<endl;
	cout<<"Units completed: "<< units <<endl;
	cout<<"GPA: "<< gpa <<endl;
}

double Student::get_gpa()
{
	return gpa;
}

char* Student::get_name()
{
	return name;
}

Student::~Student(){}

//Student==Worker==Definitions==================
StuWorker::StuWorker() : Student()
{
	hours=0;
	hourlyRate=0;
}

StuWorker::StuWorker(const StuWorker& sw) : Student(sw)
{
	hours=sw.hours;
	hourlyRate=sw.hourlyRate;
}

StuWorker& StuWorker::operator=(const StuWorker& sw)
{
	Student::operator=(sw);
	hours=sw.hours;
	hourlyRate=sw.hourlyRate;
	return *this;
}

StuWorker::~StuWorker(){}

void StuWorker::read()
{
	Student::read();
	cout<<"Enter hours assigned per week: ";
	cin>> hours;
	cout<<"Enter hourly rate of pay: ";
	cin>> hourlyRate;
}
void StuWorker::print()
{
	Student::print();
	cout<<"Hours worked: "<< hours <<endl;
	cout<<"Rate of pay: $"<< hourlyRate << "/hr\n";
}