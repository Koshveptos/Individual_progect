#include "detailsread.h"
//client
//--------------------------------------------------------------------------------------------------------

//todo ������� ���������� � �������� ������ � fseek, ����� �� ������ ���� � ���� � ������ �������, � ������ �������� ��������� � �����..
//brief cpp ����, ���������� �� ������ ���� "details.txt".
//details ����, ������� �������� � ���� �������, ���������� �� ��������� ������ �� �����.


//!!������� �������� ������ � fseek ���� ������ �����,�� ����� �������� � ���, ��� ��������� �����
void count_ODPY_details(int* n)
{
    FILE* f = fopen("details.txt", "r");
    assert((f != NULL) && "���� details.txt �� ������, ��������� ����...");
    fscanf(f, "%d", n);
    fclose(f);
}
/**
* \brief ������� ������ ���� � ������������ ������ ��������
* \details ������� ���������� ������ �� ����� � ������������ ������ ��������. � ����� ������ ��� �������� ���������� �
* ���-�� ������� ���.
* \todo ������� ���������� � ������� ������ � fseek.
*/
void read_details_file_ODPY(ODPY* n, int count_ODPY, int count_texes_last, int* count_IPY_notis)
{
    FILE* f = fopen("details.txt", "r");
    assert((f != NULL) && "���� details.txt �� ������, ��������� ����...");
    //����� ������ ��� �� ������� ������ ������� , ������� ����� �����(����� �� ������� ������ � �������� �����, ��� �� �� ������ ���)
    int nm;
    fscanf(f, "%d", &nm);
    if (count_texes_last == 1)
    {
        for (int i = 0; i != count_ODPY; i++)
        {
            fscanf(f, "%d.%d %d", &n[i].date_mounth, &n[i].date_year, &n[i].res_one);
        }
    }
    else if (count_texes_last == 2)
    {
        for (int i = 0; i != (count_ODPY); i++)
        {
            fscanf(f, "%d.%d %d %d", &n[i].date_mounth, &n[i].date_year, &n[i].res_one, &n[i].res_two);
        }
    }
    else if (count_texes_last == 3)
    {
        for (int i = 0; i != (count_ODPY); i++)
        {
            fscanf(f, "%d.%d %d %d %d", &n[i].date_mounth, &n[i].date_year, &n[i].res_one, &n[i].res_two, &n[i].res_three);
        }
    }
    else if (count_texes_last == 4)
    {
        for (int i = 0; i != count_ODPY; i++)
        {
            fscanf(f, "%d.%d %d %d %d %d", &n[i].date_mounth, &n[i].date_year, &n[i].res_one, &n[i].res_two, &n[i].res_three, &n[i].res_four);
        }
    }
    else if (count_texes_last == 5)
    {
        for (int i = 0; i != (count_ODPY); i++)
        {
            fscanf(f, "%d.%d %d %d %d %d %d", &n[i].date_mounth, &n[i].date_year, &n[i].res_one, &n[i].res_two, &n[i].res_three, &n[i].res_four, &n[i].res_five);
        }
    }
    else if (count_texes_last == 6)
    {
        for (int i = 0; i != (0 + count_ODPY); i++)
        {
            fscanf(f, "%d.%d %d %d %d %d %d %d", &n[i].date_mounth, &n[i].date_year, &n[i].res_one, &n[i].res_two, &n[i].res_three, &n[i].res_four, &n[i].res_five, &n[i].res_six);
        }
    }
    fscanf(f, "%d", count_IPY_notis);
    fclose(f);
}
/**
* \brief ������� ������ ��� � ������������ ������ ��������
* \details ������� ���������� ������ �� ����� � ������������ ������ ��������.
* \todo ������� ���������� � ������� ������ � fseek.
*/
void read_details_file_IPY(ODPY*nn,IPY* n, int count_ODPY, int count_texes_last, int count_IPY_notis)
{
    FILE* f = fopen("details.txt", "r");
    assert((f != NULL) && "���� details.txt �� ������, ��������� ����...");
    //����� ������ ��� �� ������� ������ ������� , ������� ����� �����(����� �� ������� ������ � �������� �����, ��� �� �� ������ ���)
    int nm;
    fscanf(f, "%d", &nm);
    if (count_texes_last == 1)
    {
        for (int i = 0; i != count_ODPY; i++)
        {
            fscanf(f, "%d.%d %d", &nn[i].date_mounth, &nn[i].date_year, &nn[i].res_one);
        }
    }
    else if (count_texes_last == 2)
    {
        for (int i = 0; i != (count_ODPY); i++)
        {
            fscanf(f, "%d.%d %d %d", &nn[i].date_mounth, &nn[i].date_year, &nn[i].res_one, &nn[i].res_two);
        }
    }
    else if (count_texes_last == 3)
    {
        for (int i = 0; i != (count_ODPY); i++)
        {
            fscanf(f, "%d.%d %d %d %d", &nn[i].date_mounth, &nn[i].date_year, &nn[i].res_one, &nn[i].res_two, &nn[i].res_three);
        }
    }
    else if (count_texes_last == 4)
    {
        for (int i = 0; i != (count_ODPY); i++)
        {
            fscanf(f, "%d.%d %d %d %d %d", &nn[i].date_mounth, &nn[i].date_year, &nn[i].res_one, &nn[i].res_two, &nn[i].res_three, &nn[i].res_four);
        }
    }
    else if (count_texes_last == 5)
    {
        for (int i = 0; i != (count_ODPY); i++)
        {
            fscanf(f, "%d.%d %d %d %d %d %d", &nn[i].date_mounth, &nn[i].date_year, &nn[i].res_one, &nn[i].res_two, &nn[i].res_three, &nn[i].res_four, &nn[i].res_five);
        }
    }
    else if (count_texes_last == 6)
    {
        for (int i = 0; i != (count_ODPY); i++)
        {
            fscanf(f, "%d.%d %d %d %d %d %d %d", &nn[i].date_mounth, &nn[i].date_year, &nn[i].res_one, &nn[i].res_two, &nn[i].res_three, &nn[i].res_four, &nn[i].res_five, &nn[i].res_six);
        }
    }
    int tw;
    fscanf(f, "%d", &tw);
    if (count_texes_last == 1)
    {
        for (int i = 0; i != (count_IPY_notis); i++)
        {
            fscanf(f, "%d.%d %d %d", &n[i].date_mounth, &n[i].date_year, &n[i].flat_number, &n[i].res_one);
        }
    }
    else if (count_texes_last == 2)
    {
        for (int i = 0; i != (count_IPY_notis); i++)
        {
            fscanf(f, "%d.%d %d %d %d", &n[i].date_mounth, &n[i].date_year, &n[i].flat_number, &n[i].res_one, &n[i].res_two);
        }
    }
    else if (count_texes_last == 3)
    {
        for (int i = 0; i != (count_IPY_notis); i++)
        {
            fscanf(f, "%d.%d %d %d %d %d", &n[i].date_mounth, &n[i].date_year, &n[i].flat_number, &n[i].res_one, &n[i].res_two, &n[i].res_three);
        }
    }
    else if (count_texes_last == 4)
    {
        for (int i = 0; i != (count_IPY_notis); i++)
        {
            fscanf(f, "%d.%d %d %d %d %d %d", &n[i].date_mounth, &n[i].date_year, &n[i].flat_number, &n[i].res_one, &n[i].res_two, &n[i].res_three, &n[i].res_four);
        }
    }
    else if (count_texes_last == 5)
    {
        for (int i = 0; i != (count_IPY_notis); i++)
        {
            fscanf(f, "%d.%d %d %d %d %d %d %d", &n[i].date_mounth, &n[i].date_year, &n[i].flat_number, &n[i].res_one, &n[i].res_two, &n[i].res_three, &n[i].res_four, &n[i].res_five);
        }
    }
    else if (count_texes_last == 6)
    {
        for (int i = 0; i != (count_IPY_notis); i++)
        {
            fscanf(f, "%d.%d %d %d %d %d %d %d %d", &n[i].date_mounth, &n[i].date_year, &n[i].flat_number, &n[i].res_one, &n[i].res_two, &n[i].res_three, &n[i].res_four, &n[i].res_five, &n[i].res_six);
        }
    }
    fclose(f);
}
//--------------------------------------------------------------------------------------------------------