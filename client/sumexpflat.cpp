
#include "sumexpflat.h"


//���������� ��� ���������� ������� ���
int cpc(const void* a, const void* b)
{
	IPY* ia = (IPY*)a;
	IPY* ib = (IPY*)b;
	int ia_date, ib_date;
	ia_date = ia->date_mounth + 12 * ia->date_year;
	ib_date = ib->date_mounth + 12 * ib->date_year;
	if (ia->flat_number < ib->flat_number)
	{
		return -1;
	}
	else if (ia->flat_number > ib->flat_number)
	{
		return 1;
	}
	else
	{
		if (ia_date < ib_date)
		{
			return -1;
		}
		else
		{
			return 1;
		}
	}

}

//���������� ��� ���������� ������� ����
int cpcp(const void* a, const void* b)
{
	ODPY* ia = (ODPY*)a;
	ODPY* ib = (ODPY*)b;
	int ia_date, ib_date;
	ia_date = ia->date_mounth + 12 * ia->date_year;
	ib_date = ib->date_mounth + 12 * ib->date_year;
	
	if (ia_date < ib_date)
	{
		return -1;
	}
	else
	{
		return 1;
	}
	
}

void sumflat(Home* home, Flat* flat, Taxes* taxes, int count_taxes, ODPY* odpy, int count_odpy, IPY* ipy, int count_ipy, int numb_flat, char* taxx, int start_m, int start_y, int end_m, int end_y)
{
	//������ ���� ��� �������� ����������
	FILE* out = fopen("answer.txt", "w");

	int znak_resyrsa = 0;
	//������ � ������� ������� ������� � ��� ����
	// ��� ����� ������� � ��� ����
	int numb_of_tax = 0, prise_of_tax = 0;
	for (int i = 0; i != count_taxes; i++)
	{
		if (!strcmp(taxes[i].name_taxes, taxx))
		{
			numb_of_tax = (i + 1);
			prise_of_tax = taxes[i].price;
			znak_resyrsa = taxes[i].rezervnoe_pole;
		}
	}


	//!!������ � ��� ����� ��������
	// ������� ������ ���
	qsort(ipy, count_ipy, sizeof(IPY), cpc);
	//�������� ������� ��� �� �� ��� �� ��������� ������������
	/*for (int i = 0; i != count_ipy; i++)
	{
		printf("%2d.%2d %2d %2d %2d\n", ipy[i].date_mounth, ipy[i].date_year, ipy[i].flat_number, ipy[i].res_one, ipy[i].res_two);
	}*/
	//������ ��� �������� �������  ��� ����� �������� �� ��� �����
	int* rez_arr_ipy = (int*)calloc(count_ipy, sizeof(int)); 
	//������� ������������ ������� �� ������ ������
	int count_rez_ipy = 0; //��� ����������� �� ������� , ������� ������ ���� ����)
	//������ ��� - ��� �������� ��������� ��� �� ���������
	int start_date = start_m + start_y * 12, end_date = end_m + end_y * 12, now_date;
	// ���� ������� ����� �������� ������ ��� � ��������� ���� ����� ����� 09.2021
	int flag = 0;
	// ���� �� ��� �������������� ���
	for (int i = 0; i != count_ipy; i++)
	{
		if (numb_flat == ipy[i].flat_number)
		{
			now_date = (ipy[i].date_mounth + 12 * ipy[i].date_year);
			if (start_m == 9 && start_y == 2021 && flag == 0)
			{
				flag = 1;
				rez_arr_ipy[count_rez_ipy] = 0;
				count_rez_ipy++;
			}
			//else if (start_m <= ipy[i].date_mounth && start_y <= ipy[i].date_year && end_m >= ipy[i].date_mounth && end_y >= ipy[i].date_year)
			else if(now_date <= end_date && now_date >= start_date)
			{
				if (numb_of_tax == 1)
				{
					rez_arr_ipy[count_rez_ipy] = ipy[i].res_one - ipy[i - 1].res_one;
					//���������� ��� �������� 
					//printf("flat %d %d.%d %d || %d %d.%d flat %d\n",ipy[i].flat_number,ipy[i].date_mounth, ipy[i].date_year, ipy[i].res_one, ipy[i - 1].res_one, ipy[i - 1].date_mounth, ipy[i - 1].date_year, ipy[i - 1].flat_number);
					count_rez_ipy++;
				}
				else if (numb_of_tax == 2)
				{
					rez_arr_ipy[count_rez_ipy] = ipy[i].res_two - ipy[i - 1].res_two;
					count_rez_ipy++;
				}
				else if (numb_of_tax == 3)
				{
					rez_arr_ipy[count_rez_ipy] = ipy[i].res_three - ipy[i - 1].res_three;
					count_rez_ipy++;
				}
				else if (numb_of_tax == 4)
				{
					rez_arr_ipy[count_rez_ipy] = ipy[i].res_four - ipy[i - 1].res_four;
					count_rez_ipy++;
				}
				else if (numb_of_tax == 5)
				{
					rez_arr_ipy[count_rez_ipy] = ipy[i].res_five - ipy[i - 1].res_five;
					count_rez_ipy++;
				}
				else if (numb_of_tax == 6)
				{
					rez_arr_ipy[count_rez_ipy] = ipy[i].res_six - ipy[i - 1].res_six;
					count_rez_ipy++;
				}
			}
		}
	}

	//����� ������� �� ����������� ����
	// ����� ���� � ��������� � ���������� �����, ��� ������� ����� �����������
	int sum_rez_ipy = 0;
	for (int i = 0; i != count_rez_ipy;i++)
	{
		sum_rez_ipy += rez_arr_ipy[i];
	}

	//���-�� ��� � ��������� ���
	//!!!������ ��� ������ � ����� ��� � ��������� ���
	fprintf(out,"%d %d ", sum_rez_ipy, sum_rez_ipy * prise_of_tax);



	//!!!������ �������� ��� ���� ������� �� ������ �����
	//������� ������ �������� ��������, � �� ������
	//���-�� ������� ��� �����
	int count_mounht = (end_y * 12 + end_m) - (start_y * 12 + start_m) + 1;
	//������ ��� ��� ���� ������� �� ���� ���� 
	int* count_all_ipy_m = (int*)calloc(count_mounht, sizeof(int));

	//!!!!!! ������ ����� ��� � ��������� �� ������������ ����
	count_rez_ipy = 0;
	for (int y = (start_y * 12 + start_m); y != (end_y * 12 + end_m) + 1; y++)
	{
		int flag = 0, sum_all_ipy = 0;
		int now_year = 0, now_maunth = 0;
		if (y % 12 == 0)
		{
			now_year = y / 12 - 1;
			now_maunth = 12;
		}
		else
		{
			now_year = y / 12;
			now_maunth = y % 12;
		}
			for (int i = 0; i != count_ipy;i++)
			{
				if (now_maunth == 9 && now_year == 2021)
				{
					count_all_ipy_m[count_rez_ipy] += 0;
				}
				else if (ipy[i].date_year == now_year && ipy[i].date_mounth == now_maunth)
				{
					if (numb_of_tax == 1)
					{
						count_all_ipy_m[count_rez_ipy] += ipy[i].res_one - ipy[i - 1].res_one;

					}
					else if (numb_of_tax == 2)
					{
						count_all_ipy_m[count_rez_ipy] += ipy[i].res_two - ipy[i - 1].res_two;

					}
					else if (numb_of_tax == 3)
					{
						count_all_ipy_m[count_rez_ipy] += ipy[i].res_three - ipy[i - 1].res_three;

					}
					else if (numb_of_tax == 4)
					{
						count_all_ipy_m[count_rez_ipy] += ipy[i].res_four - ipy[i - 1].res_four;

					}
					else if (numb_of_tax == 5)
					{
						count_all_ipy_m[count_rez_ipy] += ipy[i].res_five - ipy[i - 1].res_five;

					}
					else if (numb_of_tax == 6)
					{
						count_all_ipy_m[count_rez_ipy] += ipy[i].res_six - ipy[i - 1].res_six;
						
					}
				}
					
			}	
		count_rez_ipy++;
	}


	//!!!!������ ����� ��������� ���
	//�������� ����
	qsort(odpy, count_odpy, sizeof(ODPY), cpcp);
	int sum_rez_odpy = 0, count_rez_odpy = 0;
	//������ ��� �������� ���� �� ������ �����
	int* rez_arr_odpy = (int*)calloc(count_mounht, sizeof(int));
	flag = 0;
	//���� ��� ���������� ���� �� ������ ���� 
	for (int i = 0; i != count_odpy; i++)
	{
		now_date = (odpy[i].date_mounth + 12 * odpy[i].date_year);
		if (start_m == 9 && start_y == 2021 && flag == 0)
		{
			flag = 1;
			rez_arr_odpy[count_rez_odpy] += 0;
			count_rez_odpy++;
		}
		//else if (start_m <= odpy[i].date_mounth && start_y <= odpy[i].date_year && end_m >= odpy[i].date_mounth && end_y >= odpy[i].date_year)
		else if(now_date <= end_date && now_date >= start_date)
		{
			if (numb_of_tax == 1)
			{
				rez_arr_odpy[count_rez_odpy] = odpy[i].res_one - odpy[i - 1].res_one;
				count_rez_odpy++;
			}
			else if (numb_of_tax == 2)
			{
				rez_arr_odpy[count_rez_odpy] = odpy[i].res_two - odpy[i - 1].res_two;
				count_rez_odpy++;
			}
			else if (numb_of_tax == 3)
			{
				rez_arr_odpy[count_rez_odpy] = odpy[i].res_three - odpy[i - 1].res_three;
				count_rez_odpy++;
			}
			else if (numb_of_tax == 4)
			{
				rez_arr_odpy[count_rez_odpy] = odpy[i].res_four - odpy[i - 1].res_four;
				count_rez_odpy++;
			}
			else if (numb_of_tax == 5)
			{
				rez_arr_odpy[count_rez_odpy] = odpy[i].res_five - odpy[i - 1].res_five;
				count_rez_odpy++;
			}
			else if (numb_of_tax == 6)
			{
				rez_arr_odpy[count_rez_odpy] = odpy[i].res_six - odpy[i - 1].res_six;
				count_rez_odpy++;
			}
		}
	}
	//����� � ������������ , � ������ ������� ��� ������ ����� ���� ��� �������� ����� �������
	/*int sum_squard_all_flat = 0;
	for (int i = 0; i != home[0].count_flat; i++)
	{
		sum_squard_all_flat += flat[i].square_flat;
	}*/

	//������� 2 �� ���-�� �������
	// ������ ���-�� ������� � ����
	int count_all_people = 0;
	for (int i = 0; i != home[0].count_flat; i++)
	{
		count_all_people += flat[i].count_person;
	}
	double rez_koaf_people = double(flat[numb_flat - 1].count_person) / double(count_all_people);
	//printf("%d", count_all_people);



	//������� 1 �� ������� ����
	int rez_odn_sum = 0;
	//!!!���� ������� ��� �������� �������e!!!
	double rez_S_double = (double(flat[numb_flat - 1].square_flat) / double(home[0].square_home));




	//������ ��� ��� �� ������ �����
	int* rez_odn_m = (int*)calloc(count_mounht, sizeof(int));
	//���� ��� �������� ��� �� ������ ����� � ������ ���������� ����
	if (znak_resyrsa == 0)
	{
		for (int i = 0; i != count_rez_odpy; i++)
		{
			rez_odn_m[i] = int(double((rez_arr_odpy[i] - count_all_ipy_m[i])) * rez_S_double);
			rez_odn_sum += rez_odn_m[i];
		}
	}
	else
	{
		for (int i = 0; i != count_rez_odpy; i++)
		{
			rez_odn_m[i] = int(double((rez_arr_odpy[i] - count_all_ipy_m[i])) * rez_koaf_people);
			rez_odn_sum += rez_odn_m[i];
		}
	}

	//!!!������ ��� ������ (������ ������)
	fprintf(out,"%d %d\n", rez_odn_sum, rez_odn_sum * prise_of_tax);

	//!!!���-�� ������� �� ������ ����
	fprintf(out,"%d\n", count_mounht);
	//��� ������� ����� � ���������� �� ���� ���������� (��. �����)
	int prosto_count = 0;
	
	//!!!���� ������ ������ �� �����
	for (int y = (start_y * 12 + start_m); y != (end_y * 12 + end_m) + 1; y++, prosto_count++)
	{
		int flag = 0, sum_all_ipy = 0;
		int now_year = 0, now_maunth = 0;
		if (y % 12 == 0)
		{
			now_year = y / 12 - 1;
			now_maunth = 12;
		}
		else
		{
			now_year = y / 12;
			now_maunth = y % 12;
		}
		fprintf(out, "%02d.%04d %-d %-d %-d %-d\n", now_maunth, now_year, rez_arr_ipy[prosto_count], rez_arr_ipy[prosto_count] * prise_of_tax, rez_odn_m[prosto_count], rez_odn_m[prosto_count] * prise_of_tax);
	}




	//���� �����
	fclose(out);
	free(rez_odn_m);		rez_odn_m = NULL;
	free(rez_arr_odpy);		rez_arr_odpy = NULL;
	free(count_all_ipy_m);	count_all_ipy_m = NULL;
	free(rez_arr_ipy);		rez_arr_ipy = NULL;
}
