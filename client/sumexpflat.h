#pragma once
#ifndef _SUMEXPFLAT_H_
#define _SUMEXPFLAT_H_
//-----------------------------------------------------
#include "libheader.h"
#include "detailsread.h"
//�������, ������� ��������� ��������� � ���������� ��� � ����, �� ���� ���� ��� ������, ������� ����
void sumflat(Home* home, Flat* flat, Taxes* taxes, int count_taxes, ODPY* odpy, int count_odpy, IPY* ipy, int count_ipy, int numb_flat, char* taxx, int strart_m, int start_y, int end_m, int end_y);
//-----------------------------------------------------
#endif