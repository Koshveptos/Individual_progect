#pragma once
#ifndef _DETAILSREAD_H_
#define _DETAILSREAD_H_
//client
//-----------------------------------------------------
#include "library.h"

/**
*   \struct ODPY
*    \brief —труктура данных, котора€ хранит в себе показани€ ќƒѕ” за один мес€ц.
*	\details —труктура содержит данные о дате(мес€це и года) и кол-ве потребленных ресурсов на данный мес€ц.
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
*    \brief —труктура данных, котора€ хранит в себе показани€ »ѕ” за один мес€ц.
*	\details —труктура содержит данные о дате(мес€це и года) ,номере квартиры, а так же кол-ве потребленных ресурсов на данный мес€ц.
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
//получени€ данных о кол-ве одпу
void count_ODPY_details(int* n);
//запись  одпу в массив структур и получение даные о кол-ве ипу
void read_details_file_ODPY(ODPY* n, int count_ODPY, int count_texes_last, int* count_IPY_notis);
//запись ипу в массив структур
void read_details_file_IPY(ODPY*nn,IPY* n, int count_ODPY, int count_texes_last, int count_IPY_notis);
//-----------------------------------------------------
#endif
