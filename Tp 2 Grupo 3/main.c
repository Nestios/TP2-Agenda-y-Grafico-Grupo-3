#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int main()
{
    int flag = 0; // guarda la cantidad de contactos
    char seguir = 's';
    int opcion = 0;
    int libre = 0;

    /*limpiamos la memoria de los estados
      los inicializamos en NULL para que n tengan basura*/

    for (int i = 0; i < 20; i++)
    {
        listaAgenda[i].estado = NULL;
    }

    while (seguir == 's')
    {

        printf("\n1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d", &opcion);
        fflush(stdin);

        // Limpiamos la pantalla
        system("cls");

        switch (opcion)
        {
        case 1:
            // buscamos espacio vacio
            flag = flag + 1;
            libre = obtenerEspacioLibre(flag);

            // continuamos segun la devolucion de la funcion
            if (libre == -1)
            {
                printf("sin espacios libres");
                flag--; // vuelve el flag a su estado anterior
            }
            else
            {
                agregarNuevo(libre, flag);
            }
            break;

        case 2:
            flag = borrarpersona(flag);
            break;

        case 3:
            listaordenada(listado, flag);
            break;

        case 4:
            imprimrGrafico(listado, flag);
            break;

        case 5:
            seguir = 'n';
            break;
        }
    }

    return 0;
}
