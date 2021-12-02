#include <stdio.h>
#include <stdlib.h>

int menu(void);
void opc1(int * arreNums, int cont);

int main()
{
    int reg=0;
    int  *pnum = (int *)malloc(sizeof(int));
    char sel;
    int opc; 
    printf("\nBienvenido al programa que ordena los numeros que ingresas ");
    printf("de manera aleatoria.\n");
    if(pnum==NULL)
    {
        printf("\nOcurrio un error");
        printf("\nEspacio insuficiente en memoria");
    }
    else
    {
        do{
        system("pause");
        system("cls");
        opc=menu();
        switch(opc)
        {
            case 1:opc1(pnum,reg);break;
            case 2:break;
            case 3:break;
            case 4:break;
            default:break;
        }
        fflush(stdin);
        reg++;
        printf("\nDigite \"s\" para continuar, de lo contrario terminaremos de captar datos: ");
        sel=getchar();
        fflush(stdin);

    }while(sel == 's');
    }
    
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

void opc1(int * arreNums,int cont)
{
    printf("\nA continuacion ingresara un numero el cual guardaremos\n");
    printf("\nDigite un numero: ");
    scanf("%d",(arreNums+cont));
}