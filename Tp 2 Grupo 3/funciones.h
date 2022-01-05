#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define MAX 20
#define Usado 1
#include <windows.h>

typedef struct listas
{

    char nombre[50];
    int edad;
    int dni;
    int estado;

} personaLista;

personaLista listaAgenda[MAX]; // MAX es una constante =20
personaLista *listado[MAX];    // puntero vector 20

void agregarNuevo(int lib, int flag);

int obtenerEspacioLibre(int flag);

int borrarpersona(int flag);

void listaordenada(personaLista *listadob[], int flag);

void imprimrGrafico(personaLista *listadob[], int arrayLenght);
#endif // FUNCIONES_H_INCLUDED
