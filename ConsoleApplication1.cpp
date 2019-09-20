#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS 
#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

void solve_equation()
{
	float a, b, c, mid;
	cout << "please input a b c:";
	cin >> a >> b >> c;
	mid = b * b - 4 * a*c;
	if (mid < 0)
	{
		float real, fake1;
		real = b * (-1) / 2 * a;
		fake1 = sqrt(mid*(-1)) / 2 * a;
		cout << "the roots is plural:\n";
		cout << "root1 = " << real << "+" << fake1 << "i\n";
		cout << "root2 = " << real << "-" << fake1 << 'i';
	}
	else if (mid == 0)
	{
		float root = (b*(-1)) / 2 * a;
		cout << "root = " << root;
	}
	else
	{
		float root1 = (b*(-1) + sqrt(mid)) / 2 * a;
		float root2 = (b*(-1) - sqrt(mid)) / 2 * a;
		cout << "root1 = " << root1 << '\n' << "root2 = " << root2;
	}
}

void cal_area()
{
	float a, b, c;
	cout << "please input the length of each brim\n(defalt:the longest is the firsrt one):";
	cin >> a >> b >> c;
	float E = (a + b + c) / 2;
	float S;
	S = sqrt(E*(E - a)*(E - b)*(E - c));
	cout << "The area is:" << S;
}

void judge()
{
	int day, month, year, sum, leap;
	cout << "\nPlease input like this Year-Month-Day\n";
	scanf("%d-%d-%d", &year, &month, &day);
	switch (month)
	{
	case 1:sum = 0; break;
	case 2:sum = 31; break;
	case 3:sum = 59; break;
	case 4:sum = 90; break;
	case 5:sum = 120; break;
	case 6:sum = 151; break;
	case 7:sum = 181; break;
	case 8:sum = 212; break;
	case 9:sum = 243; break;
	case 10:sum = 273; break;
	case 11:sum = 304; break;
	case 12:sum = 334; break;
	default:printf("data error"); break;
	}
	sum = sum + day;
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
	{
		leap = 1;
	}
	else
	{
		leap = 0;
	}
	if (leap == 1 && month > 2)
	{
		sum++;
	}
	int result, day_inweek;
	result = sum / 7;
	day_inweek = sum % 7;
	cout << "This is the " << result << "th week and the " << day_inweek << "th day of the year\n";
}

int main()
{
	// to begin the first function
	cout << "1 Find the roots of the ax^2 + bx + c = 0\n";
	cout << "2 Calculate the area of a triangle\n";
	cout << "3 Judge year month day\n";
	cout << "please input the number of the function you want to apply:";
	int flag;
	cin >> flag;
	switch (flag)
	{
	case 1:
		solve_equation();
		break;
	case 2:
		cal_area();
		break;
	case 3:
		judge();
		break;
	default:
		break;
	}
	getchar();

}
