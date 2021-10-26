#include<stdio.h>
#define DAYS 31

void getYearMonth(int*, int*);
int getMonthDays(int, int);
int getWeekday(int, int, int);
void getHoliday(int*, int, int, int);
void sort(int*, int);
void holiday_Input(int*);
void holiday_Output(int*);
void Transfer(int*, int*, int*);
void holiday_Schedule(int*, int*);

int main()
{
	int year, month, days, youbi, holiday[DAYS], t_holiday[DAYS], holiday_c[DAYS], transfer_c[DAYS];

	getYearMonth(&year, &month);
	
	days = getMonthDays(year, month);
	
	youbi = getWeekday(year, month, 1);
	
	getHoliday(holiday, month, days, youbi);
	
	printf("‹Î–±•\‚Ì‹x“ú‚ğ“ü—Í\n");
	
	holiday_Input(holiday_c);
	
	holiday_Output(holiday_c);
	
	Transfer(holiday_c, holiday, t_holiday);
	
	printf("U‹x‚Í\n");
	holiday_Output(t_holiday);
	
	Transfer(holiday, holiday_c, transfer_c);
	
	printf("Uo‚Í\n");
	holiday_Output(transfer_c);
	
	printf("U‹x“ú@Uo“ú\n");
	holiday_Schedule(t_holiday, transfer_c);

	return 0;
}

void getYearMonth(int* py, int* pm)
{
	printf("ƒJƒŒƒ“ƒ_[‚ğ•\¦\n");
	printf("¼—ï‚ÆŒ‚ğ“ü—Í(—á:2003 5)\n");
	while (1)
	{
		scanf_s("%d %d", py, pm);
		if (*pm >= 1 && *pm <= 12)
			break;
		printf("“ü—Í‚µ’¼‚µ\n");
	}
	return;
}

int getMonthDays(int y, int m)
{
	int dm;

	switch(m)
	{
	case 1:case 3: case 5: case 7: case 8: case 10: case 12:
		dm = 31;
		break;
	case 4: case 6: case 9: case 11:
		dm = 30;
		break;
	case 2:
		if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
			dm = 29;
		else
			dm = 28;
		break;
	default:
		dm = 0;
	}
	return dm;
}

int getWeekday(int y, int m, int d)
{
	int w;

	if (m == 1 || m == 2)
	{
		y--;
		m += 12;
	}
	w = (y + y / 4 - y / 100 + y / 400 + (13 * m + 8) / 5 + d) % 7;
	return w;
}

void getHoliday(int* hd, int m, int dm, int dw)
{
	int j = 0;
	switch (m)
	{
	case 1:
		for (int i = 1; i <= dm; i++)
		{
			int d = 0;
			d = i + dw;
			if (d % 7 == 0 || d % 7 == 1 || (d / 7 == 2 && d % 7 == 2) || (i >= 1 && i <= 4))
			{
				*(hd + j)= i;
				j++;
			}
		}
		break;
	case 2:
		for (int i = 1; i <= dm; i++)
		{
			int d = 0;
			d = i + dw;
			if (d % 7 == 0 || d % 7 == 1 || i == 11 || i == 23)
			{
				*(hd + j) = i;
				j++;
				if ((i == 11 && d % 7 == 1) || (i == 23 && d % 7 == 1))
				{
					i++;
					*(hd + j) = i;
					j++;
				}
			}
		}
		break;
	case 3:
		printf("¡”N‚Ìt•ª‚Ì“ú‚ğ“ü—Í\n");
		int k;
		scanf_s("%d", &k);
		for (int i = 1; i <= dm; i++)
		{
			int d = 0;
			d = i + dw;
			if (d % 7 == 0 || d % 7 == 1 || i == k)
			{
				*(hd + j) = i;
				j++;
			}
		}
		break;
	case 4:
		for (int i = 1; i <= dm; i++)
		{
			int d = 0;
			d = i + dw;
			if (d % 7 == 0 || d % 7 == 1 || i == 29)
			{
				*(hd + j) = i;
				j++;
				if (i == 29 && d % 7 == 1) 
				{
					i++;
					*(hd + j) = i;
					j++;
				}
			}
		}
		break;
	case 5:
		for (int i = 1; i <= dm; i++)
		{
			int d = 0;
			d = i + dw;
			if (d % 7 == 0 || d % 7 == 1 || (i >= 3 && i <= 5))
			{
				*(hd + j) = i;
				j++;
				if (i == 5) 
				{
					for(int k = 3; k <=5; k++)
					{
						if ((k + dw) % 7 == 1)
						{
							*(hd + j) = 6;
							j++;
						}
					}
				}
			}
		}
		break;
	case 6:
		for (int i = 1; i <= dm; i++)
		{
			int d = 0;
			d = i + dw;
			if (d % 7 == 0 || d % 7 == 1 )
			{
				*(hd + j) = i;
				j++;
			}
		}
		break;
	case 7:
		for (int i = 1; i <= dm; i++)
		{
			int d = 0;
			d = i + dw;
			if (d % 7 == 0 || d % 7 == 1 || (d / 7 == 3 && d % 7 == 2))
			{
				*(hd + j) = i;
				j++;
			}
		}
		break;
	case 8:
		for (int i = 1; i <= dm; i++)
		{
			int d = 0;
			d = i + dw;
			if (d % 7 == 0 || d % 7 == 1 || i == 11)
			{
				*(hd + j) = i;
				j++;
			}
			if (i == 11 && d % 7 == 1)
			{
				i++;
				*(hd + j) = i;
				j++;
			}
		}
		break;
	case 9:
		printf("¡”N‚ÌH•ª‚Ì“ú‚ğ“ü—Í\n");
		scanf_s("%d", &k);
		for (int i = 1; i <= dm; i++)
		{
			int d = 0;
			d = i + dw;
			if (d % 7 == 0 || d % 7 == 1 ||(d / 7 == 3 && d % 7 == 2) || i == k)
			{
				*(hd + j) = i;
				j++;
			}
		}
		break;
	case 10:
		for (int i = 1; i <= dm; i++)
		{
			int d = 0;
			d = i + dw;
			if (d % 7 == 0 || d % 7 == 1 || i == 10 || (d / 7 == 2 && d % 7 ==2))
			{
				*(hd + j) = i;
				j++;
			}
		}
		break;
	case 11:
		for (int i = 1; i <= dm; i++)
		{
			int d = 0;
			d = i + dw;
			if (d % 7 == 0 || d % 7 == 1 || i == 3 || i == 23)
			{
				*(hd + j) = i;
				j++;
				if ((i == 3 && d % 7 == 1) || (i == 23 && d % 7 == 1))
				{
					i++;
					*(hd + j) = i;
					j++;
				}
			}
		}
		break;
	case 12:
		for (int i = 1; i <= dm; i++)
		{
			int d = 0;
			d = i + dw;
			if (d % 7 == 0 || d % 7 == 1 || (i >= 30 && i <= 31))
			{
				*(hd + j) = i;
				j++;
			}
		}
		break;
	}

	*(hd + j) = '\0';

	for (int i = 0; i < j;i++)
	{
		printf("%d@", *(hd + i));
	}
	
	printf("\n");

	return;
}

void sort(int* v, int n)
{
	int i, j;

	for (i = 0; i < n - 1; i++)
	{
		for (j = n - 1; j > i; j--)
		{
			if (*(v + (j - 1)) > *(v + j))
			{
				int temp = *(v + j);
				*(v + j) = *(v + (j - 1));
				*(v + (j - 1)) = temp;
			}
		}
	}
}

void holiday_Input(int* hd)
{
	int i = 1, j = 0;

	for(; ; )
	{
		scanf_s("%d", hd + j);
		if (*(hd + j) < 1 || *(hd + j) > 31)
		{
			printf("1`31‚Å“ü—Í‚µ‚Ä‚­‚¾‚³‚¢\n");
			continue;
		}		
		j++;
		printf("“ü—Í‚ğ‘±‚¯‚Ü‚·‚©HyYesc1, Noc0z\n");
		scanf_s("%d", &i);
		if (i == 0)
		{
			*(hd + j) = '\0';
			break;
		}
		else
			printf("“ü—Í‚µ‚Ä‚­‚¾‚³‚¢\n");
		
	}
	sort(hd, j);
	return;
}

void holiday_Output(int* hd)
{
	int i = 0;

	while (*(hd + i) != '\0')
	{
		printf("%d ", *(hd + i));
		i++;
	}
	printf("\n");
	return;
}

void Transfer(int* p1, int* p2, int* p3)	/* U‹xEUo‚ğ”»•Ê */
{
	int i = 0, j = 0, k = 0;

	while (*(p1 + i) != '\0')	/* *p1‚Ìƒ|ƒCƒ“ƒ^ŒJ‚è•Ô‚µ */
	{
		j = 0;

		while (*(p2 + j) != '\0')	/* *p2‚ÌŒJ‚è•Ô‚µ */
		{
			if (*(p1 + i) == *(p2 + j))	/* ‹x‚İ‚ªŒö‹x‚©–@’è‹x“ú */
				break;
			else
			{
				if (*(p2 + j + 1) == '\0')	/* U‹xEUo‚ğ*p3‚É‘ã“ü */
				{
					*(p3 + k) = *(p1 + i);
					k++;
				}
			}
			j++;
		}
		i++;
		*(p3 + k) = '\0';
	}
	return;
}

void holiday_Schedule(int* t_hd, int* t_c)
{

	int i = 0;
	while (*(t_hd + i) != '\0')
	{
		printf("%5d %5d\n", *(t_hd + i), *(t_c + i));
		i++;
	}
	return;
}