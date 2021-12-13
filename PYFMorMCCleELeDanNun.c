#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototipos de Funciones
int menu(void);
void opc1(int *arreNums, int cont, int *dig);
void ordeArre(int *arreNums,int cont);
void present();
void posi(int *arre, int size, int *numPos);
int main()
{
    //Declaracion de variables
    int reg=0; // Mantiene la cantidad de posiciones que lleva el arreglo
    int tam=1; // Guarda el tamaño del arreglo
    int numGua;    
    int *pnumGua=&numGua; 
    int i;
    int *pnum = (int *)malloc(sizeof(int)); //Inicializacion de puntero con espacio para 1 entero
    char sel='s';
    int opc;
    
    present();
    printf("\nBienvenido al programa que ordena los numeros que ingresas ");
    printf("de manera aleatoria.\n");
    if(pnum==NULL) // Controla caso de que no haya espacio en memoria
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
            case 1:
            {
                opc1(pnum,reg,pnumGua);
                reg++;
                ordeArre(pnum,reg);
                posi(pnum,tam,pnumGua);
                printf("\nVector Actualizado");
                for(i=0;i<reg;i++)
                {
                    printf("\n%d",*(pnum+i));
                }
                printf("\n");
                tam++;
                pnum=(int *)realloc(pnum,tam*sizeof(int)); //Incrementa el tamaño del arreglo en 1 unidad más para entero
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
                printf("\nVALOR ALMACENADO\tDIRECCION DE MEMORIA\t\tPOSICION EN VECTOR\n");
                if(reg==0)
                {
                    printf("No se ha ingresado un numero\t\tDireccion almacenada: %x\n",(pnum+i));
                }
                for(i=0;i<reg;i++)
                {
                    printf("\t%d\t\t\t%x\t\t\t%d\n",*(pnum+i),(pnum+i),i);
                }    
            }
            break;
            case 3:
            {
                system("cls");
                printf("\nEL vector tiene %d elementos\n",reg);
            }
            break;
            case 4:sel='n';break; //Cambia el valor para salir del bucle
            default:
            {
                printf("\nEleccion Incorrecta");
                printf("\nRetornara al menu principal");
                system("pause");
            }
            break;
        }
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
    char num[4];
    printf("\nA continuacion ingresara un numero el cual guardaremos\n");
    printf("\nDigite un numero: ");
    fgets(num,4,stdin); //Capturamos los datos como caracteres para validarlos
    *(arreNums+cont)=atoi(num);
    if(atoi(num)==0) // Maneja casos en los que el usuario introdujo letras o el "0"
    {
        printf("\nNuestro programa solamente acepta numeros, usted digito una letra");
        printf(" o selecciono el numero \"0\"\n");
        printf("\nProcederemos a ingresar un \"0\" al arreglo\n");
    }
    *dig=*(arreNums+cont);
    fflush(stdin);
}
void ordeArre(int *arreNums,int cont)
{
    /*Toma como parametro el puntero hacia la primera posicion del arreglo
    compara la posicón anterior con la que sigue y en caso de que sea mayor la corre
    usando una variable auxiliar para no borrar ningún elemento
    Se vale de dos bucles, el interno recorriendo más rápido el arreglo y partiendo de la 
    posicion adyacente a la primera*/
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
    /*Toma como parametro el arreglo, el tamaño del mismo (lo corremos
    antes de incrementar el tamaño del mismo) y el numero que acabamos de agregar al
    arreglo. Recorre el arreglo con un bucle que va desde la posición inicial hasta
    la ultima posición en ese momento comparando el contenido de cada posición con el
    numero que acabamos de agregar y una vez lo encuentra usa el iterador para saber
    si está al incio, final o la posición precisa en la que se encuentra.
    */
    int i;
    for(i=0;i<size;i++)
    {
        if(*(numPos)==*(arre+i))
        {
            if(i==0)
            {
                printf("%d se ingresa al inicio del vector\n",*(numPos));
            }
            else if(i==(size-1))
            {
                printf("%d se ingresa al final del vector\n",*(numPos));
            }
            else
            {
                printf("%d se ingresa en la posicion %d\n",*(numPos),i);
            }
        }
    }
}