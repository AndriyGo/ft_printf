#include <stdio.h>
#include <locale.h>
#include <wchar.h>

int main(void)
{
    wchar_t a = 23532;

     setlocale(LC_ALL, "");
   //printf("1%i\n", 42);
   ft_printf("1%+i\n", 42);
   ft_printf("1%i\n", 42);
   return 0;
}