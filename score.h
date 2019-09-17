
typedef struct student
{
	char name[10];
	char number[10];
	float usual_grade;
	float test_grade;
	float final_exam_grade;
	float final_grade;
}Stu;

#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED

int load_data(Stu stu[]);

void sort(Stu stu[], int N);

void Print_unsorted(Stu stu[], int N);

void Print_sorted(Stu stu[], int N);

void Search(Stu stu[], int N, char search[]);

void To_show_variance(Stu stu[], int N);


#endif // SCORE_H_INCLUDED

