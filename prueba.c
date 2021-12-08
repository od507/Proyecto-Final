#include <stdio.h>

int main()
{
    char nombre[50];
    printf("\nDigite su nombre: ");
    scanf("%[^\n]",nombre);
    return 0;
}