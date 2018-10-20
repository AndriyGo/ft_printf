#include <stdio.h>
#include <locale.h>
#include <wchar.h>

int main(void)
{
    wchar_t a = 23532;

     setlocale(LC_ALL, "");
   printf("1!%d\n", printf("1%.4S\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B"));
   printf("2!%d\n", ft_printf("2%.4S\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B"));
   return 0;
}