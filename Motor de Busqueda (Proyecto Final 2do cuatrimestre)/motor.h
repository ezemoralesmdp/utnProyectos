#ifndef MOTOR_H_INCLUDED
#define MOTOR_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "diccionario.h"
#include <alg.h>
#include "colors.h"

typedef struct nodoT {

    int idDOC;
    int pos;
    struct nodoT* sig;

} nodoT;

typedef struct nodoA{

    char palabra[20];
    int frecuencia; //Representa la cantidad de nodos de la lista
    nodoT* ocurrencias; //Ordenada por idDOC, luego por pos
    struct nodoA* der;
    struct nodoA* izq;

} nodoA;

//PROTOTIPADO
nodoA * crearNodoArbol(char* palabra);
nodoT * crearNodoOcurrencia(termino palabra);
void insertarNodoArbol(nodoA** motor, termino palabra);
void insertarNodoOcurrencia(nodoT** ocurrencia, termino palabra);
void cargarMotor(nodoA** motor);
void mostrarUnNodo(nodoA* dato);
void mostrarMotor(nodoA* motor);
void mostrarListaDeOcurrencias(nodoT* ocurrencias);
void mostrarUnaOcurrencia(nodoT* nodoOcurrencia);
nodoA * busquedaUnica(nodoA* motor, char* palabra);
int buscarCoincidenciaID(nodoT* ocurrencias, int ID);
int verificarExistencias(nodoA* motor, char* frase);
int Levenshtein(char *s1, char *s2);
nodoA * sugerirPalabra(nodoA* motor, char* palabra);

#endif // MOTOR_H_INCLUDED
