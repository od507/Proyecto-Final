#include <stdio.h>
#include <stdlib.h>

int menu(void);

int main()
{
    int num;
    int reg=0;
    char sel;
    int opc; 
    printf("\nBienvenido al programa que ordena los numeros que ingresas ");
    printf("de manera aleatoria.");
    do{
        system("pause");
        system("cls");
        opc=menu();
        switch(opc)
        {
            case 1:break;
            case 2:break;
            case 3:break;
            case 4:break;
            default:break;
        }
        printf("\nDigite un numero: ");
        scanf("%d",&num);
        fflush(stdin);
        reg++;
        printf("\nDigite \"s\" para continuar, de lo contrario terminaremos de captar datos: ");
        sel=getchar();
        fflush(stdin);

    }while(sel == 's');
    return 0;
}

int menu(void)
{
    int sele;

    printf("\nDigite el numero de su seleccion");
    printf("\n1. Ingresar un numero y almacenarlo en la memoria dinamica");
    printf("\n2. Imprimir cada elemento del vector, la posicion y su direccion.");
    printf("\n3. Total de elementos del vector.");
    printf("\n4. Salir\n");

    scanf("%d",&sele);
    return sele;
}