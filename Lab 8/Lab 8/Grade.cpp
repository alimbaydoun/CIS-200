#include<iostream>
#include"grade.h"
#include <vector>
#pragma warning(disable : 4996)

void Grader::setOutputFile(string file = "cis200finalgrades.txt", int mode = 0)
{
	output.open(file, mode);

	if (!input)
	{
		cout << "File does not exist" << endl;
	}
}

void Grader::closeOutputFile()
{
	if (output)
		output.close();
}

void Grader::searchID(string ID)
{
	string line, name, lname, id;
	
	input.open("cis200finalgrades.txt");
	
	if (!input)
		return;
	getline(input, line);
	getline(input, line);
	
	while (!input.eof())
	{
		input >> name >> lname >> id;
		getline(input, line);
		if (ID == id)
		{
			cout << name << " " << lname << " " << id << " " << line << endl;
			return;
		}
	}
	cout << "Error" << endl;
}

void Grader::readFile(string inFile)
{
	string line;
	
	vector<string> grades;
	
	setOutputFile("cis200finalgrades.txt");
	input.open(inFile);
	if (!input)
	{
		cout << "File does not exist" << endl;
		return;
	}
	
	getline(input, line);
	output << line << endl;
	
	getline(input, line);
	output << line << " " << "Grades" << endl;
	
	while (!input.eof())
	{
		getline(input, line);
		if (line.size() > 20)
			output << line << " " << calculateGrade(line) << endl;
	}
	
	closeOutputFile();
	input.close();
	
	cout << "File: " << inFile << " Successful" << endl;
}

double Grader::calculateMidTerms(double ex1, double ex2)
{
	return ((ex1 + ex2) / 2) * 0.2;
}
double Grader::calculateFinal(double ex3)
{
	return (ex3) * 0.25;
}
double Grader::calculateProgs(double p[])
{
	return ((p[1] + p[2] + p[3] + p[0]) / 4) * 0.3;
}
double Grader::calculateLabs(double p[])
{
	double sum = 0;
	for (int i = 0; i < 10; i++)
		sum += p[i];
	return ((sum / 10) * 1.5);
}
string Grader::calculateGrade(string line)
{
	string grade;
	char* temp;
	double mid[2], finalMarks, marks[17];
	int i = 0;

	temp = strtok((char*)(line.c_str()), " ");

	while (temp != NULL)
	{
		if (i > 2)
		{
			marks[i - 3] = atof(temp);
		}
		temp = strtok(NULL, " ");
		i++;
	}
	finalMarks = calculateMidTerms(marks[0], marks[1]) + calculateFinal(marks[2]) + calculateProgs(&marks[3]) + calculateLabs(&marks[7]);
	if (finalMarks >= 97)
		grade = "A+";
	else if (finalMarks < 97 && finalMarks >= 93)
		grade = "A";
	else if (finalMarks < 93 && finalMarks >= 92)
		grade = "A-";
	else if (finalMarks < 92 && finalMarks >= 87)
		grade = "B+";
	else if (finalMarks < 87 && finalMarks >= 83)
		grade = "B";
	else if (finalMarks < 83 && finalMarks >= 80)
		grade = "B-";
	else if (finalMarks < 80 && finalMarks >= 77)
		grade = "C+";
	else if (finalMarks < 77 && finalMarks >= 73)
		grade = "C";
	else if (finalMarks < 73 && finalMarks >= 70)
		grade = "C-";
	else if (finalMarks < 80 && finalMarks >= 67)
		grade = "D+";
	else if (finalMarks < 67 && finalMarks >= 63)
		grade = "D";
	else if (finalMarks < 63 && finalMarks >= 60)
		grade = "D-";
	else
		grade = "F";

	return grade;
}
void Grader::calcualteDistribution() {
	input.open("cis200finalgrades.txt");
	string grade, line;
	int grades[5] = { 0 };
	int num;

	if (!input)
		return;
	getline(input, line);
	getline(input, line);


	getline(input, line);
	getline(input, line);
	while (!input.eof())
	{
		input >> line >> line;
		for (int i = 0; i < 18; i++)
			cin >> num;
		cin >> grade;
		if (grade == "A+" || grade == "A" || grade == "A-")
			grades[0]++;
		else if (grade == "B" || grade == "B-" || grade == "B+")
			grades[1]++;
		else if (grade == "C-" || grade == "C" || grade == "C+")
			grades[2]++;
		else if (grade == "D+" || grade == "D" || grade == "D-")
			grades[3]++;
		else
			grades[4]++;

		getline(input, line);

	}
	input.close();
	setOutputFile("cis200finalgrades.txt", ios::app);
	output << "\nCIS 200 Grade Distribution	A: " << grades[0] << " B: " << grades[1];
	output << " C: " << grades[2] << " D: " << grades[3] << " F: " << grades[4] << endl;
}