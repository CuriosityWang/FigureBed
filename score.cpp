#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

typedef struct student
{
	char name[10];
	char number[10];
	float usual_grade;
	float test_grade;
	float final_exam_grade;
	float final_grade;
}Stu;


int load_data(Stu stu[])
{
	// load data
	int N;
	FILE *fp = NULL;

	fp = fopen("data.txt", "r");

	// to be safe
	if (fp == NULL)
	{
		cout << "fail";
		return 0;
	}
	if (fp != NULL)
	{
		fscanf(fp, "%d\n", &N);
	}

	int index = 0;
	while (index < N)
	{
		fscanf(fp, "%s%s%f%f%f\n", (stu[index].number), (stu[index].name), &stu[index].usual_grade, &stu[index].test_grade, &stu[index].final_exam_grade);
		index++;
	}


	fclose(fp);
	return N;
}

void sort(Stu stu[], int N)
{
	Stu temp;

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = N - 1; j > i; j--)
		{
			if (stu[j - 1].final_grade < stu[j].final_grade)
			{
				temp = stu[j - 1];
				stu[j - 1] = stu[j];
				stu[j] = temp;
			}
		}
	}
}

void Print_unsorted(Stu stu[], int N)
{
	int index = 0;
	cout << "Stu_Num\t\tname\tUsual_Grade\tTest_Grade\tFinal_Exam_Grade\tFinal_Grade\n";
	while (index < N)
	{
		cout << stu[index].number << "\t\t" << stu[index].name << '\t' << stu[index].usual_grade;
		cout << "\t\t" << stu[index].test_grade << "\t\t" << stu[index].final_exam_grade << "\t\t\t";
		stu[index].final_grade = (stu[index].usual_grade + stu[index].test_grade) * 0.2 + stu[index].final_exam_grade *0.6;
		cout << stu[index].final_grade << '\n';
		index++;
	}

}

void Print_sorted(Stu stu[], int N)
{
	int index = 0;
	cout << "Stu_Num\t\tname\tUsual_Grade\tTest_Grade\tFinal_Exam_Grade\tFinal_Grade\n";
	while (index < N)
	{
		cout << stu[index].number << "\t\t" << stu[index].name << '\t' << stu[index].usual_grade;
		cout << "\t\t" << stu[index].test_grade << "\t\t" << stu[index].final_exam_grade << "\t\t\t";
		cout << stu[index].final_grade << '\n';
		index++;
	}


}

void Search(Stu stu[], int N, char search[])
{
	int index = 0;
	while (index < N)
	{
		if (strcmp(stu[index].number, search) == 0)
		{
			cout << "Stu_Num\t\tname\tUsual_Grade\tTest_Grade\tFinal_Exam_Grade\tFinal_Grade\n";
			cout << stu[index].number << "\t\t" << stu[index].name << '\t' << stu[index].usual_grade;
			cout << "\t\t" << stu[index].test_grade << "\t\t" << stu[index].final_exam_grade << "\t\t\t";
			cout << stu[index].final_grade << '\n';
			return;
		}
		index++;
	}
	cout << "Can not find\n";
}

void To_show_variance(Stu stu[], int N)
{
	float sum = 0.0;
	int index = 0;
	while (index < N)
	{
		sum += stu[index].final_grade;
		index++;
	}

	float mean = sum / N;
	cout << "The mean is :" << mean << '\n';

	index = 0;
	sum = 0.0;
	while (index < N)
	{
		sum += (stu[index].final_grade - mean) * (stu[index].final_grade - mean);
		index++;
	}
	float variance = sum / N;
	cout << "The variance is:" << variance << '\n';
}
