
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>

/*///////////////////////////////////////////////////////////
------------------ESPACIO----VACIO---------------------------
/*/
////////////////////////////////////////////////////////*/

/*Encuentra el primer espacio vacio
e imprime el texto nuevo contacto (el numero de espacio )*/

int obtenerEspacioLibre(int flag)
{
    for (int i = 0; i < MAX; i++)
    {
        if (listaAgenda[i].estado != Usado)
        { // usado es cte=1
            printf("Nuevo contacto (%d)", flag);
            return i; // cuando encuentra un espacio vacio devuelve la posicion
        }
    }
    return -1;
    // si no encuestra espacio libre devuelve -1 y en main se guarda dentro de LIBRE
}

/*///////////////////////////////////////////////////////////////////////////
-------------------AGREGAR  CONTACTO----------------------------------
///////////////////////////////////////////////////////////////////////////*/

void agregarNuevo(int lib, int flag)
{

    // Guarda cada propiedad del contacto en la estructura principal listaAgenda

    printf("\nNombre: ");
    gets(listaAgenda[lib].nombre);
    fflush(stdin);
    printf("Edad: ");
    scanf("%i", &listaAgenda[lib].edad);
    fflush(stdin);
    printf("DNI: ");
    scanf("%i", &listaAgenda[lib].dni);
    fflush(stdin);

    // declara el espacio como usado
    listaAgenda[lib].estado = 1;

    // y declara el puntero correspondiente
    listado[flag - 1] = &listaAgenda[lib];

    printf("\n\t\t\tAGREGADO: %s\n", listado[flag - 1]->nombre);

    // luego de 1 seg limpiamos pantalla
    Sleep(1000);
    system("cls");
}

/*////////////////////////////////////////////////////////
---------------- BORRAR   PERSONA-------------------
////////////////////////////////////////////////////////*/

int borrarpersona(int flag)
{
    char Nombre_del[20];
    int Find = 0; // encontrar
    int Pos = 0;
    char *borrado = 0;

    while (borrado == 0)
    {

        printf("Nombre de contacto a Eliminar?:\t");
        scanf("%s", &Nombre_del);
        // primero busca un contacto con el mismo nombre
        for (int i = 0; i < flag; i++)
        {
            if (strcmp(Nombre_del, listado[i]->nombre) == 0) // si en la comparacion son iguales da 0
            {
                Find = 1;
                Pos = i;
                break;
            }
        }

        // Si intercambian corren los datos a la posicion anterior desde la posicion a eliminar

        if (Find == 1)
        {
            // se anulan los datos del borrado
            strcpy(listado[Pos]->nombre, "borrado");
            listado[Pos]->edad = NULL;
            listado[Pos]->dni = NULL;
            listado[Pos]->estado = NULL;

            // reasignando la posicion de memoria
            for (int i = Pos; i < flag - 1; i++)
            {
                listado[i] = listado[i + 1];
            }

            listado[flag - 1] = -1;

            flag--;
            // para indicar que hay un contacto menos

            printf("\n\t->%s<-\tSE HA BORRADO CORRECTAMENTE\n", Nombre_del);

            borrado = 1;

            // luego de 1.5 seg limpiamos pantalla
            Sleep(1500);
            system("cls");

            return flag;
        }
        else
        {

            printf("\t\t: ->%s<- NO SE ENCUENTRA AGENDADO\n", Nombre_del);
            do
            {
                printf("ingresa:\n 1- para volver al menu principal \n 0- para volver a intentar \n");
                scanf("%d", &borrado);
            } while (borrado != 1 && borrado != 0);

            system("cls");
        }
    }
    system("cls");
    return flag;
}

/*//////////////////////////////////////////////////
-------IMPRIMIR CONTACTOS ORDENADOS----------------
//////////////////////////////////////////////////*/

void listaordenada(personaLista *listadob[], int flag)
{
    personaLista *temp;
    char salida = "s";

    for (int i = 0; i < flag; i++)
    {
        int traba = 0;

        for (int j = 0; j < flag - 1; j++)
        {
            if (strcmp(listadob[j]->nombre, listadob[j + 1]->nombre) > 0)
            {
                temp = listadob[j];
                listadob[j] = listadob[j + 1];
                listadob[j + 1] = temp;
                traba = 1;
            }
        }
        if (traba = 0)
        {
            i = flag - 1;
        }
    }
    printf("\n\t\t--NOMBRES AGENDADOS--\n");
    for (int Count = 0; Count < flag; Count++)
    {
        printf("\nNombre: %s\t", listadob[Count]->nombre);
        printf("Edad:%d  ", listadob[Count]->edad);
        printf("DNI:%d\n", listadob[Count]->dni);
    }

    system("pause");
    system("cls");
    // cls, limpia consola
}

/*/////////////////////////////////////////////////////////////
---------------IMPRIMIR GRAFICO-------------------------------
////////////////////////////////////////////////////////////*/

void imprimrGrafico(personaLista *listadob[], int arrayLenght)
{
    int grupos = 3;
    int filas = 0;
    int contadores[grupos];

    printf(" GRAFICO DE EDADES  \n");

    // Inicializo contadores en 0
    for (int i = 0; i < grupos; i++)
    {
        contadores[i] = 0;
    }

    // SEPARO POR GRUPOS DE EDADES Y DIFINO LAS FILAS SEGUN EL GRUPO MAYOR

    for (int i = 0; i < arrayLenght; i++)
    {
        if (listadob[i]->edad < 19)
        {
            contadores[0]++; // grupo de < 19
            if (contadores[0] > filas)
            { // compara los numeros mayores de filas
                filas = contadores[0];
            }
        }
        if (listadob[i]->edad > 18 && listadob[i]->edad < 36)
        {
            contadores[1]++;
            if (contadores[1] > filas)
            {
                filas = contadores[1];
            }
        }
        if (listadob[i]->edad > 35)
        {
            contadores[2]++;
            if (contadores[2] > filas)
            {
                filas = contadores[2];
            }
        }
    }
    // Imprimo el grafico

    for (int i = filas; i >= 0; i--)
    {
        if (i == 0)
        { // verifica si faltan personas por imprimir

            printf("    -----------------\n    <18 19-35  >35\n");

            break;
        }
        if (i > 9)
        {
            printf("%i |", i);
        }
        if (i <= 9)
        {
            printf(" %i |", i);
        }
        for (int j = 0; j < grupos; j++)
        { // define en que grupo imprime una barra
            if (contadores[j] < i)
            {
                printf("     ");
            }
            else
            {
                printf("  *  ");
            }
        }
        printf("\n");
    }

    system("pause");
    system("cls");
}
