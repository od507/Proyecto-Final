#include <stdio.h>
#include <stdlib.h>

int menu(void);
void opc1(int *arreNums, int cont);
void ordeArre(int *arreNums,int cont);

int main()
{
    int reg=0;
    int tam=1;
    int i;
    int *pnum = (int *)malloc(sizeof(int));
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
        //system("pause");
        //system("cls");
        opc=menu();
        switch(opc)
        {
            case 1:
            {
                opc1(pnum,reg);
                reg++;
                ordeArre(pnum,reg);
                tam++;
                pnum=(int *)realloc(pnum,tam*sizeof(int));
                if(pnum == NULL)
                {
                    printf("\nEspacio insuficiente en memoria");
                    break;
                }
            }
            break;
            case 2:
            {
                system("cls");
                printf("\n\t\t\tCONTENIDO DEL VECTOR");
                printf("\nVALOR ALMACENADO\tDIRECCION DE MEMORIA\tPOSICION EN VECTOR\n");
                if(reg==0)
                {
                    printf("No se ha ingresado un numero\t\tDireccion almacenada: %x\n",(pnum+i));
                }
                for(i=0;i<reg;i++)
                {
                    printf("\t%d\t\t\t%x\t\t%d\n",*(pnum+i),(pnum+i),i);
                }    
            }
            break;
            case 3:
            {
                system("cls");
                printf("\nEL vector tiene %d elementos",reg);
            }
            break;
            case 4:break;
            default:break;
        }
        fflush(stdin);
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
    fflush(stdin);
    return sele;
}

void opc1(int *arreNums,int cont)
{
    printf("\nA continuacion ingresara un numero el cual guardaremos\n");
    printf("\nDigite un numero: ");
    scanf("%d",(arreNums+cont));
    fflush(stdin);
}

void ordeArre(int *arreNums,int cont)
{
    int temp;
    int i=0;
    int k=0;
    for(i=0;i<cont;i++)
    {
        for(k=i+1;k<cont;k++)
        {
            if(*(arreNums+i)>*(arreNums+k))
            {
                temp=*(arreNums+i);
                *(arreNums+i)=*(arreNums+k);
                *(arreNums+k)=temp;
            }
        }
    }
}