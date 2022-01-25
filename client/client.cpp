#include "headerclient.h"
//-------------------------------------------------------------------
//ИКТИБ ЮФУ
//кафедра МОП ЭВМ(09.03.04)
//Алгоритмизация и основы программирования
// Исполнитель : Казаков Василий Тимофеевич (КТбо1-8)
// 11.01.22
//-------------------------------------------------------------------


int main()
{
	//!! РАБОТАЮ С ФАЙЛОМ HOME.TXT (библиотечная функция)
	//чистаю значение общей площади и кол-ва квартир
	Home* home = (Home*)malloc(1 * sizeof(Home));
	read_home_file_one(home);
	//читаю значения каждой квартиры в массив структур
	Flat* flat = (Flat*)malloc((home[0].count_flat + 1) * sizeof(Flat));
	read_home_file_two(flat,home[0].count_flat);
	

	//!! РАБОТАЮ С ФАЙЛОМ TAXES.TXT (библиотечная функция)
	//читаю кол-во ресурсов
	int count_tax = 0;
	int* count_taxes_all = &count_tax;
	count_taxes(count_taxes_all);
	//записываю ресурсики в массив структур
	Taxes* taxes = (Taxes*)malloc((*(count_taxes_all) + 1) * sizeof(Taxes));
	read_taxes_file_all(taxes, *(count_taxes_all));
	

	//!! РАБОТАЮ С ФАЙЛОМ DETAILS.TXT (!!находится в модуле detailsread.h\cpp)
	//читаю кол-во ОДПУ  и ИПУ записей
	int count_ODPY = 0,count_IPY = 0,* ptr_count_ODPY = &count_ODPY, * ptr_count_IPY = &count_IPY;
	count_ODPY_details(ptr_count_ODPY);
	//считываю записи ОДПУ в массив структур
	ODPY* odpy = (ODPY*)calloc((count_ODPY+1), sizeof(ODPY));
	read_details_file_ODPY(odpy, count_ODPY, count_tax, ptr_count_IPY);
	//считываю записи ИПУ в массив структур
	ODPY* odpy_t = (ODPY*)calloc((count_ODPY + 1), sizeof(ODPY));
	IPY* ipy = (IPY*)calloc((count_IPY + 1), sizeof(IPY));
	read_details_file_IPY(odpy_t,ipy, count_ODPY, count_tax, count_IPY);
	

	//!! РАБОТАЮ С ФАЙЛОМ INPUT.TXT 
	int inp_flat, inp_start_m, inp_start_y, inp_end_m, inp_end_y;
	char inp_name_tax[6];
	FILE* f = fopen("input.txt", "r");
	assert(f != NULL && "Файл input.txt не был открыт, проверьте его наличие");
	fscanf(f, "%d %s %02d.%04d-%02d.%04d", &inp_flat, inp_name_tax, &inp_start_m, &inp_start_y, &inp_end_m, &inp_end_y);


	//передаю все-все значения в функцию в другой модуль для поулчения ответа(ответ выводится там же ) (!! находится в модуле sumexpflat)
	sumflat(home, flat, taxes, count_tax, odpy, count_ODPY, ipy, count_IPY, inp_flat, inp_name_tax, inp_start_m, inp_start_y, inp_end_m, inp_end_y);
	


	//чищу карму 
	fclose(f);
	free(ipy);		ipy = NULL;
	free(odpy);		odpy = NULL;
	free(taxes);	taxes = NULL;
	free(home);		home = NULL;
	free(flat);		flat = NULL;
	return 0;
}