#include <stdio.h>
#include <locale.h>
#include <wchar.h>

int main(void)
{
    wchar_t a = 23532;
     //setlocale(LC_ALL, "");
   int i1 = printf("1:%03S\n", L"aà");
   int i2 = ft_printf("2:%03S\n", L"aà");
   printf("!1%d\n", i1);
   printf("!2%d\n", i2);
   //printf("!%d\n", ft_printf("2%03S\n", L"à"));
   return 0;
}