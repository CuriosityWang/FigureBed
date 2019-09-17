#include <iostream>
#include "score.h"
#include <stdio.h>
using namespace std;


int main()
{
	Stu stu[100];

	// 获取学生数
	int N;
	N = load_data(stu);
	Print_unsorted(stu, N);
	sort(stu, N);

    cout << "Grade_sorted:\n";
	Print_sorted(stu, N);
	To_show_variance(stu, N);

	char search[10];
	cout << "Please input the num of the students you are searching:";
	cin >> search;
	Search(stu, N, search);

	getchar();
	getchar();
	return 0;
}








