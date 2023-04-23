#include <iostream>
#include "Header.h"
#include <string>
using namespace std;
void filling(struct student*& stu, int n)
{
	int random;
	for (int i = 0; i < n; i++)
	{
		stu[i].debt = 0;
		random = 10000 + rand() % (20000 - 10000);
		stu[i].id = random;
		random = 1 + rand() % (4 - 1 + 1);
		stu[i].course = random;
		random = rand() % 4;
		stu[i].napravlenie = napr(random);
		stu[i].past = 0;
		for (int j = 0; j < 8; j++)
		{
			stu[i].exams[j] = new marks[4];
		}
		for (int k = 0; k < 8; k++)
		{
			stu[i].zachet[k] = new marks[6];
		}
	}
}
void print(struct student*& stu, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << i + 1 << ')' << "ID: " << stu[i].id << " | Êóğñ: " << stu[i].course << ' ' << naprav_to_str(stu[i].napravlenie) << ' ' <<
			status_to_str(stu[i].status);
		std::cout << '\n';
		for (int j = 0; j < stu[i].course * 2; j++)
		{
			std::cout << '|';
			for (int j1 = 0; j1 < 4; j1++)
			{
				std::cout << stu[i].exams[j][j1].e << '|';
			}
			std::cout << '\n';
			std::cout << '|';
			for (int k = 0; k < 6; k++)
			{
				std::cout << stu[i].zachet[j][k].z << '|';
			}
			std::cout << '\n';
		}
		std::cout << "Õâîñòû: " << stu[i].debt << '\n';
		std::cout << '\n';
	}
}
void filling_exams(struct student*& stu, int n)
{
	int random;
	for (int i = 0; i < n / 2; i++)
	{
		for (int j = 0; j < stu[i].course * 2; j++)
		{
			for (int j1 = 0; j1 < 4; j1++)
			{
				random = 3 + rand() % 3;
				stu[i].exams[j][j1].e = random;
			}
		}
		for (int k = 0; k < stu[i].course * 2; k++)
		{
			for (int k1 = 0; k1 < 6; k1++)
			{
				stu[i].zachet[k][k1].z = 1;
			}
		}
	}
	for (int i = n / 2; i < n; i++)
	{
		if (stu[i].course == 1)
		{
			for (int j = 0; j < stu[i].course * 2; j++)
			{
				for (int j1 = 0; j1 < 4; j1++)
				{
					random = 2 + rand() % 4;
					stu[i].exams[j][j1].e = random;
					if (random < 3) stu[i].debt++;
				}
			}
			for (int k = 0; k < stu[i].course * 2; k++)
			{
				for (int k1 = 0; k1 < 6; k1++)
				{
					random = rand() % 2;
					stu[i].zachet[k][k1].z = random;
					if (random == 0) stu[i].debt++;
				}
			}
		}
		else
		{
			for (int j = 0; j < stu[i].course * 2 - 2; j++)
			{
				for (int j1 = 0; j1 < 4; j1++)
				{
					random = 3 + rand() % 3;
					stu[i].exams[j][j1].e = random;
				}
			}
			for (int k = 0; k < stu[i].course * 2 - 2; k++)
			{
				for (int k1 = 0; k1 < 6; k1++)
				{
					stu[i].zachet[k][k1].z = 1;
				}
			}

			for (int j = stu[i].course * 2 - 2; j < stu[i].course * 2; j++)
			{
				for (int j1 = 0; j1 < 4; j1++)
				{
					random = 2 + rand() % 4;
					stu[i].exams[j][j1].e = random;
					if (random < 3) stu[i].debt++;
				}
			}
			for (int k = stu[i].course * 2 - 2; k < stu[i].course * 2; k++)
			{
				for (int k1 = 0; k1 < 6; k1++)
				{
					random = rand() % 2;
					stu[i].zachet[k][k1].z = random;
					if (random == 0) stu[i].debt++;
				}
			}
		}
	}
}
void sort(struct student*& stu, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (stu[j].debt > stu[j + 1].debt)
			{
				swap(stu[j], stu[j + 1]);
			}
		}
	}
}
void sort_past(struct student*& stu, int& n)
{
	int a = 0;
	for (int i = 0; i < n; i++)
	{
		if (stu[i].status == failed || stu[i].status == ended) a++;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (stu[j].past > stu[j + 1].past)
			{
				swap(stu[j], stu[j + 1]);
			}
		}
	}
	n -= a;
}
void give_status(struct student*& stu, int n)
{
	if (n == 1 && stu[0].course == 4) stu[0].status = ended;
	else if (n == 1 && stu[0].course != 4) stu[0].status = passed;
	else {
		for (int i = 0; i < n * 0.8; i++)
		{
			if (stu[i].course == 4)
			{
				stu[i].status = ended;
				stu[i].past = 1;
			}
			else stu[i].status = passed;
		}
		for (int i = n * 0.8; i < n; i++)
		{
			stu[i].status = failed;
			stu[i].past = 1;
		}
	}
}
void new_exam(struct student*& stu, int n)
{
	int random;
	for (int i = 0; i < n; i++)
	{
		stu[i].debt = 0;
	}
	for (int i = 0; i < n / 2; i++)
	{
		for (int j = stu[i].course * 2 - 2; j < stu[i].course * 2; j++)
		{
			for (int j1 = 0; j1 < 4; j1++)
			{
				random = 3 + rand() % 3;
				stu[i].exams[j][j1].e = random;

			}
		}
		for (int k = stu[i].course * 2 - 2; k < stu[i].course * 2; k++)
		{
			for (int k1 = 0; k1 < 6; k1++)
			{
				stu[i].zachet[k][k1].z = 1;
			}
		}
	}
	for (int i = n / 2; i < n; i++)
	{
		for (int j = stu[i].course * 2 - 2; j < stu[i].course * 2; j++)
		{
			for (int j1 = 0; j1 < 4; j1++)
			{
				random = 2 + rand() % 4;
				stu[i].exams[j][j1].e = random;
				if (random == 2) stu[i].debt++;
			}
		}
		for (int k = stu[i].course * 2 - 2; k < stu[i].course * 2; k++)
		{
			for (int k1 = 0; k1 < 6; k1++)
			{
				random = rand() % 2;
				stu[i].zachet[k][k1].z = random;
				if (!random) stu[i].debt++;
			}
		}
	}
}
void next_course(struct student*& stu, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (stu[i].status == passed) {
			stu[i].course++;
		}
	}
}
void next_main(struct student*& stu, int n)
{
	sort_past(stu, n);
	next_course(stu, n);
	new_exam(stu, n);
	sort(stu, n);
	give_status(stu, n);
	print(stu, n);
}
string naprav_to_str(napr a)
{
	if (a == 0) return "ÔÈÈÒ";
	else if (a == 1) return "ÌÎÀÈÑ";
	else if (a == 2) return "ÏÌÈ";
	else if (a == 3) return "ÁÈ";
}
string status_to_str(statuses a)
{
	if (a == 0) return "Îò÷èñëåí";
	else if (a == 1) return "Îêîí÷èë";
	else if (a == 2) return "Çà÷èñëåí íà ñëåäóşùèé êóğñ";
}