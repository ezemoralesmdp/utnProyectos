#include "motor.h"


nodoA* crearNodoArbol(char* palabra) {

    nodoA* nuevo = (nodoA*)malloc(sizeof(nodoA));
    strcpy(nuevo->palabra, palabra);
    nuevo->frecuencia = 0;
    nuevo->ocurrencias = NULL;
    nuevo->izq = NULL;
    nuevo->der = NULL;

    return nuevo;
}

nodoT* crearNodoOcurrencia(termino palabra) {

    nodoT* nuevo = (nodoT*)malloc(sizeof(nodoT));
    nuevo->idDOC = palabra.idDOC;
    nuevo->pos = palabra.pos;
    nuevo->sig = NULL;

    return nuevo;
}

void insertarNodoArbol(nodoA** motor, termino palabra) { //Ordenado por orden alfabetico

    if(*motor == NULL) {

        *motor = crearNodoArbol(palabra.palabra);
        insertarNodoOcurrencia(&(*motor)->ocurrencias, palabra);
        (*motor)->frecuencia += 1;

    } else {

        if(strcmpi(palabra.palabra, (*motor)->palabra)<0)
        {
            insertarNodoArbol(&(*motor)->izq, palabra);

        } else if(strcmpi(palabra.palabra, (*motor)->palabra) > 0) {

            insertarNodoArbol(&(*motor)->der, palabra);

        } else {

            insertarNodoOcurrencia(&(*motor)->ocurrencias, palabra);
            (*motor)->frecuencia += 1;
        }
    }
}

void insertarNodoOcurrencia(nodoT** ocurrencia,termino palabra) { //Ordenado por ID y por pos

    nodoT* nuevo = crearNodoOcurrencia(palabra);
    nodoT* ant;
    nodoT* act;

    if(*ocurrencia == NULL) {

        *ocurrencia = nuevo;

    } else {

        if(nuevo->idDOC <= (*ocurrencia)->idDOC) {

            nuevo->sig = *ocurrencia;
            *ocurrencia = nuevo;

        } else {

            ant = *ocurrencia;
            act = (*ocurrencia)->sig;

            while(act && nuevo->idDOC>act->idDOC) {

                ant=act;
                act=act->sig;
            }

            ant->sig = nuevo;
            nuevo->sig = act;
        }
    }
}

void cargarMotor(nodoA** motor) {

    FILE * archiDic = fopen(diccionario, "rb");
    termino palabra;

    if(archiDic) {

        while(fread(&palabra, sizeof(termino), 1, archiDic) > 0) {

            insertarNodoArbol(motor, palabra);
        }

        fclose(archiDic);
    }
}

void mostrarUnNodo(nodoA* dato) {

    printf("\n- PALABRA: %s\n", dato->palabra);
    printf("- FRECUENCIA: %i\n", dato->frecuencia);
    printf("\n- [OCURRENCIAS]:\n");

    mostrarListaDeOcurrencias(dato->ocurrencias);
}

void mostrarMotor(nodoA* motor) {

    if(motor) {

        mostrarMotor(motor->izq);
        mostrarUnNodo(motor);
        mostrarMotor(motor->der);
    }
}

void mostrarListaDeOcurrencias(nodoT* ocurrencias) {

    while(ocurrencias) {

        printf("-----------------\n");
        printf("ID DOC: %i\n", ocurrencias->idDOC);
        printf("POS: %i\n", ocurrencias->pos);
        printf("-----------------\n");
        ocurrencias = ocurrencias->sig;
    }
}

nodoA * busquedaUnica(nodoA* motor, char* palabra) {

    if(motor) {

        if(strcmpi(motor->palabra, palabra) == 0) {
            return motor;

        } else {

            if(strcmpi(motor->palabra, palabra) > 0) {

                return busquedaUnica(motor->izq, palabra);

            } else if(strcmpi(motor->palabra, palabra) < 0) {

                return busquedaUnica(motor->der, palabra);
            }
        }

    } else {

        return motor;
    }
}

int cantPalabrasFrase(char* frase) {

    int cantLetras = strlen(frase);
    int cantPalabras = 0;
    char letraAux;

    for(int i = 0; i <= cantLetras; i++) {

        letraAux = frase[i];

        if(letraAux != ' ' && letraAux != '.' && letraAux != ',' && letraAux != '\0') {

        } else {

            cantPalabras++;
        }
    }

    return cantPalabras;
}

void mostrarUnaOcurrencia(nodoT* nodoOcurrencia) {

    setColor(RED); printf("-----------------\n"); setColor(CYAN);
    printf("ID DOC:"); setColor(GREEN); printf(" %d\n", nodoOcurrencia->idDOC); setColor(CYAN);
    printf("POS: "); setColor(GREEN); printf("%d\n", nodoOcurrencia->pos);
    setColor(RED); printf("-----------------\n"); setColor(CYAN);
}

int buscarCoincidenciaID(nodoT* ocurrencias, int ID) {

    while(ocurrencias && ocurrencias->idDOC != ID) {

        ocurrencias = ocurrencias->sig;
    }

    if(ocurrencias) {

        return 1;

    } else {

        return 0;
    }
}

int verificarExistencias(nodoA* motor, char* frase) {

    int cantLetras = strlen(frase);
    //int cantPalabras=cantPalabrasFrase(frase);
    //printf("La frase cargada es: %s\n",frase);
    //printf("La cantidad de letras son: %i\n",cantLetras);
    char arregloAux[MAX_WORD];
    char letraAux;
    int i = 0;
    int k = 0;
    int todas;
    nodoA* aux;

    while(i <= cantLetras) {

        letraAux = frase[i];

        if(letraAux != ' ' && letraAux != '.' && letraAux != ',' && letraAux != '\0') {

            arregloAux[k] = letraAux;
            k++;

        } else {

            //printf("Palabra: %s\n",arregloAux);

                aux = busquedaUnica(motor, arregloAux);

                if(aux) {

                    todas = 1;

                } else {

                    setColor(RED); printf("[!]"); setColor(CYAN); printf(" La palabra"); setColor(GREEN); printf(" %s ", arregloAux); setColor(CYAN); printf("no se encuentra en el motor\n");
                    return 0;
                }

                k = 0;
                memset(arregloAux, 0, MAX_WORD);
        }

        i++;
    }

    return todas;
}


int Levenshtein(char *s1,char *s2) {

    int t1, t2, i, j, *m, costo, res, ancho;

// Calcula tamanios strings
    t1 = strlen(s1);
    t2 = strlen(s2);

// Verifica que exista algo que comparar
    if (t1 == 0) return(t2);
    if (t2 == 0) return(t1);
    ancho = t1 + 1;

// Reserva matriz con malloc                     m[i,j] = m[j*ancho+i] !!
    m = (int*)malloc(sizeof(int)*(t1+1)*(t2+1));
    if (m == NULL) return(-1); // ERROR!!

// Rellena primera fila y primera columna
    for (i = 0; i <= t1; i++) m[i] = i;
    for (j = 0; j <= t2; j++) m[j*ancho] = j;

// Recorremos resto de la matriz llenando pesos
    for (i = 1; i<=t1; i++) for (j=1; j<=t2; j++) {

            if (s1[i - 1] == s2[j - 1]) costo = 0;
            else costo = 1;
            m[j*ancho + i] = min(min(m[j * ancho + i -1 ] + 1,     // Eliminacion
                                 m[(j - 1) * ancho + i] + 1),              // Insercion
                                 m[(j - 1) * ancho + i - 1] + costo);
        }      // Sustitucion

// Devolvemos esquina final de la matriz
    res = m[t2 * ancho + t1];
    free(m);
    return(res);
}

nodoA* sugerirPalabra(nodoA* motor, char* palabra) {

    int distancia = Levenshtein(motor->palabra, palabra);

    if(distancia <= 3) {

        return motor;

    } else if(strcmpi(motor->palabra, palabra) > 0) {

        return sugerirPalabra(motor->izq, palabra);

    } else {

        return sugerirPalabra(motor->der, palabra);
    }
}
