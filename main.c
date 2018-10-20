#include <stdio.h>
#include <locale.h>
#include <wchar.h>

int main(void)
{
    wchar_t a = 23532;

     //setlocale(LC_ALL, "");
   int i1 = printf("1%S\n", L"Lalalala, 100% des gens qui parlent ?à Ly adorent Ly. Ou Presque. 2, 10, 2710, ");
   int i2 = ft_printf("2%S\n", L"Lalalala, 100% des gens qui parlent ?à Ly adorent Ly. Ou Presque. 2, 10, 2710, ");
   printf("%d == %d\n", i1, i2);
   return 0;
}