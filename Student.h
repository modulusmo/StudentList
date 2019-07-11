//Moses Cuevas
//CS 840
//Due 5/21/2017
//Assignment 6
#ifndef STUDENTS_H
#define STUDENTS_H

class Student {
protected:
	char name[40];
	char id[40];
	int units;
	double gpa;
public:
	Student();
	Student(const Student&);
	virtual Student& operator= (const Student&);//might not need to be virtual
	virtual void read();//shouldn't this be write?
	virtual void print();
	double get_gpa();
	char* get_name();
	~Student();
};

class StuWorker : public Student
{
private:
	int hours;
	double hourlyRate;
public:
	StuWorker();
	StuWorker(const StuWorker&);
	StuWorker& operator=(const StuWorker&);
	~StuWorker();
	void read();
	void print();
};
#endif