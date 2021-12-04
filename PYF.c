#include <stdio.h>
#include <stdlib.h>
// Prototipos de Funciones
int menu(void);
void opc1(int *arreNums, int cont, int *dig);
void ordeArre(int *arreNums,int cont);
void present();
void posi(int *arre, int size, int *numPos);
int main()
{
    //Declaracion de variables
    int reg=0;
    int tam=1;
    int numGua;
    int *pnumGua=&numGua;
    int i;
    int *pnum = (int *)malloc(sizeof(int)); //Inicializacion de puntero con espacio para 1 entero
    char sel;
    int opc;
    
    present();
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
                opc1(pnum,reg,pnumGua);
                reg++;
                ordeArre(pnum,reg);
                posi(pnum,tam,pnumGua);
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
void opc1(int *arreNums,int cont,int *dig)
{
    printf("\nA continuacion ingresara un numero el cual guardaremos\n");
    printf("\nDigite un numero: ");
    scanf("%d",(arreNums+cont));
    *dig=*(arreNums+cont);
    fflush(stdin);
}
void ordeArre(int *arreNums,int cont)
{
    int temp;
    int tempPos;
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
                tempPos=i;
            }
        }
    }
}

void present()
{
    printf("\t\t\tUniversidad Tecnologica de Panama\n");
    printf("\t      Facultad de Ingieneria de Sistemas Computacionales\n");
    printf("\t\t Departamento de programacion de computadoras\n");
    printf("\n\t\t\t\tPROYECTO FINAL\n\n\n");
    printf("Facilitadora: Msc. Mitzi de Velasquez \t\t Asignatura: Herramientas de Programacion Aplicada 1");
    printf("\n\nIntegrantes:                   CEDULA: \n\n");
    printf("Eric Moreno               - Cedula:8-951-1011\n");
    printf("Jean Eleta                - Cedula:8-980-472\n");
    printf("Daniel Nunez              - Cedula:8-992-364\n");
    printf("Jackeline McClean         - Cedula:3-751-1480 \n");
    printf("Antonio Daniels           - Cedula:3-722-58 \n\n");
    printf("Fecha de entrega: Lunes, 20 de diciembe de 2021 - Hora 10:00\n\n\n");
    system("pause");
    system("cls"); 
}

void posi(int *arre, int size, int *numPos)
{
    int i;
    for(i=0;i<size;i++)
    {
        if(*(numPos)==*(arre+i))
        {
            if(i==0)
            {
                printf("%d se ingresa al inicio del vector",*(numPos));
            }
            else if(i==(size-1))
            {
                printf("%d se ingresa al final del vector",*(numPos));
            }
            else
            {
                printf("%d se ingresa en la posicion %d",*(numPos),i);
            }
        }
    }
}