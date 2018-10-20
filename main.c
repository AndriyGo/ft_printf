#include <stdio.h>
#include <locale.h>
#include <wchar.h>

int main(void)
{
    wchar_t a = 23532;

     //setlocale(LC_ALL, "");
   printf("1:%03S\n", L"aà");
   ft_printf("1:%03S\n", L"aà");
   //printf("!%d\n", ft_printf("2%03S\n", L"à"));
   return 0;
}