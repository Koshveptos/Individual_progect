#pragma once
#ifndef _DETAILSREAD_H_
#define _DETAILSREAD_H_
//client
//-----------------------------------------------------
#include "library.h"

/**
*   \struct ODPY
*    \brief ��������� ������, ������� ������ � ���� ��������� ���� �� ���� �����.
*	\details ��������� �������� ������ � ����(������ � ����) � ���-�� ������������ �������� �� ������ �����.
*/
typedef struct
{
	int date_mounth;
	int date_year;
	int res_one;
	int res_two;
	int res_three;
	int res_four;
	int res_five;
	int res_six;
}ODPY;
/**
*   \struct IPY
*    \brief ��������� ������, ������� ������ � ���� ��������� ��� �� ���� �����.
*	\details ��������� �������� ������ � ����(������ � ����) ,������ ��������, � ��� �� ���-�� ������������ �������� �� ������ �����.
*/
typedef struct
{
	int date_mounth;
	int date_year;
	int flat_number;
	int res_one;
	int res_two;
	int res_three;
	int res_four;
	int res_five;
	int res_six;
}IPY;
//��������� ������ � ���-�� ����
void count_ODPY_details(int* n);
//������  ���� � ������ �������� � ��������� ����� � ���-�� ���
void read_details_file_ODPY(ODPY* n, int count_ODPY, int count_texes_last, int* count_IPY_notis);
//������ ��� � ������ ��������
void read_details_file_IPY(ODPY*nn,IPY* n, int count_ODPY, int count_texes_last, int count_IPY_notis);
//-----------------------------------------------------
#endif
