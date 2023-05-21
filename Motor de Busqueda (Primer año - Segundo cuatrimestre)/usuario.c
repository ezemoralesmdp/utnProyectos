#include "usuario.h"

nodoP* crearNodoPalabras(char* palabra,nodoT* ocurrencias) {

    nodoP* nuevo = (nodoP*)malloc(sizeof(nodoP));
    strcpy(nuevo->palabra, palabra);
    nuevo->ocurrencias = ocurrencias;
    nuevo->sig = NULL;

    return nuevo;
}

void insertarPalabraAlFinal(nodoP** listaDePalabras, char* palabra, nodoT* ocurrencias) {

    nodoP* nuevo = crearNodoPalabras(palabra, ocurrencias);
    nodoP* aux;

    if(*listaDePalabras == NULL)
    {

        *listaDePalabras = nuevo;

    }
    else
    {

        aux = *listaDePalabras;

        while(aux->sig != NULL)
        {

            aux = aux->sig;

        }

        aux->sig = nuevo;
    }
}

void mostrarListaDePalabras(nodoP* listaDePalabras) {

    nodoT* aux;

    while(listaDePalabras) {

        aux = listaDePalabras->ocurrencias;
        printf("%s\n", listaDePalabras->palabra);
        mostrarListaDeOcurrencias(aux);
        listaDePalabras = listaDePalabras->sig;
    }
}

void mostrarNodosCoincidentesDosID(nodoT* ocurrencias, int ID1, int ID2) {

    while(ocurrencias)
    {
        if(ocurrencias->idDOC == ID1 || ocurrencias->idDOC == ID2)
        {
            mostrarUnaOcurrencia(ocurrencias);
        }

        ocurrencias = ocurrencias->sig;
    }
}

nodoT * BuscarNodosCoincidentesUnID(nodoT* ocurrencias,int ID) {

    while(ocurrencias) {

        if(ocurrencias->idDOC == ID)
        {
            return ocurrencias;
        }

        ocurrencias = ocurrencias->sig;
    }

    return ocurrencias;
}

void mostrarNodosCoincidentesUnID(nodoT* ocurrencias, int ID1) {

    while(ocurrencias) {

        if(ocurrencias->idDOC == ID1) {

            mostrarUnaOcurrencia(ocurrencias);
        }

        ocurrencias = ocurrencias->sig;
    }
}

void buscarEnDosDoc(nodoA* motor, char* palabra, int ID1, int ID2) {

    //Variables locales
    int enc1, enc2;

    if(motor) {

        if(strcmpi(motor->palabra, palabra) == 0)
        {
            enc1 = buscarCoincidenciaID(motor->ocurrencias, ID1); //motor.c
            enc2 = buscarCoincidenciaID(motor->ocurrencias, ID2);

            if(enc1 && enc2)
            {
                mostrarNodosCoincidentesDosID(motor->ocurrencias, ID1, ID2);

            } else if(enc1 == 1 && enc2 == 0) {

                setColor(RED); printf("\n[!]"); setColor(CYAN); printf(" Se encontro la palabra en documento"); setColor(GREEN); printf(" %d ", ID1); setColor(CYAN); printf("pero no en el"); setColor(GREEN); printf(" %i \n", ID2);

            } else if(enc1 == 0 && enc2 == 1) {

                setColor(RED); printf("\n[!]"); setColor(CYAN); printf(" Se encontro la palabra en documento"); setColor(GREEN); printf(" %d ", ID2); setColor(CYAN); printf("pero no en el"); setColor(GREEN); printf(" %i \n", ID1);

            } else {

                setColor(RED); printf("\n[!]"); setColor(CYAN); printf(" No se encontro la palabra en ninguno de los documentos que indico\n");
            }

        } else {

            if(strcmpi(motor->palabra, palabra) > 0) {

                buscarEnDosDoc(motor->izq, palabra, ID1, ID2);

            } else if(strcmpi(motor->palabra, palabra) < 0) {

                buscarEnDosDoc(motor->der, palabra, ID1, ID2);
            }
        }
    }
}

void buscarVariosTerminosEnUnDoc(nodoA* motor, char* palabra, int ID) {

    nodoT* aux;

    if(motor) {

        if(strcmpi(motor->palabra, palabra) == 0) {

            aux = BuscarNodosCoincidentesUnID(motor->ocurrencias, ID);

            if(aux) {

                setColor(CYAN); printf("----------------------------------------------------------------------------------------------------\n");
                setColor(RED); printf("\n- ["); setColor(CYAN); printf("PALABRA"); setColor(RED); printf("]: ");
                setColor(GREEN);
                printf("%s\n\n", palabra);
                setColor(CYAN);
                mostrarNodosCoincidentesUnID(motor->ocurrencias, ID);

            } else {

                printf("[!] No se encuentra la palabra: \"%s\" en el documento %i\n", palabra, ID);
            }

        } else {

            if(strcmpi(motor->palabra, palabra) > 0) {

                buscarVariosTerminosEnUnDoc(motor->izq, palabra, ID);

            } else if(strcmpi(motor->palabra, palabra) < 0) {

                buscarVariosTerminosEnUnDoc(motor->der, palabra, ID);
            }
        }

    } else {

        printf("[!] No se encuentra la palabra: \"%s\" en el motor", palabra);
    }
}

void cargarPalabrasDeLaFrase(nodoA* motor, nodoP** listaPalabras, char* frase) {

    int cantLetras = strlen(frase);
    char arregloAux[MAX_WORD];
    char letraAux;
    int i = 0;
    int k = 0;
    nodoA* aux;

    while(i <= cantLetras) {

        letraAux = frase[i];

        if(letraAux != ' ' && letraAux != '.' && letraAux != ',' && letraAux != '\0') {

            arregloAux[k] = letraAux;
            k++;

        } else {

            aux = busquedaUnica(motor, arregloAux);

            insertarPalabraAlFinal(listaPalabras, arregloAux, aux->ocurrencias);

            k = 0;

            memset(arregloAux, 0, MAX_WORD);
        }

        i++;
    }
}

int AllWordsSameDoc(nodoP* listaPalabras, int cantPalabras) {

    int doc[CANT_DOCS];
    nodoT* aux;
    int j = 0;

                printf("id: %d | pos: %d\n", listaPalabras->ocurrencias->idDOC, listaPalabras->ocurrencias->pos);
    //PRUEBA
    nodoT * arregloOcurrencias[50];
    nodoT * listaOcurrenciasCoincidentes;
    int e = 0;

    for(int i = 0; i < CANT_DOCS; i++) {

        doc[i] = i + 1;
    }

    /*for(int i=0; i<CANT_DOCS ; i++)
    {
        printf("%i",doc[i]);
    }*/

    while(listaPalabras) {



        while(j < CANT_DOCS) {

            //arreglo de ocurrencias coincidentes
            //las
            if(buscarCoincidenciaID(listaPalabras->ocurrencias, doc[j])) {

                arregloOcurrencias[e] = listaPalabras->ocurrencias; //ID, POS, SIG
                e++;
                printf("id: %d | pos: %d\n", arregloOcurrencias[e]->idDOC, arregloOcurrencias[e]->pos);
            }

            j++;
        }

        listaPalabras = listaPalabras->sig;

        j=0;
    }

    esteEsElDocumento(arregloOcurrencias, e, cantPalabras);

    //printf("%i\n",coinciden);
    //printf("%i\n",j);
//    if(coinciden) {
//        //printf("%i",j);
//        return doc[j];
//
//    } else {
//
//        return coinciden;
//    }
}

void esteEsElDocumento(nodoT * arregloOcurrencias[50], int dimension, int cantPalabras) { //Tenemos 3 palabras

    nodoT * aux;

    int encontroTodasLasPalabras = 0;

    for(int i = 0; i < dimension; i++) {

        printf("nivel 1\n");

        for(int j = 0; j < dimension; j++) {

                printf("nivel 2\n");

            if(arregloOcurrencias[i]->idDOC == arregloOcurrencias[j]->idDOC) {

                printf("nivel 3\n");

                if(arregloOcurrencias[i]->pos == arregloOcurrencias[j]->pos-1) {

                    printf("nivel 4\n");

                    encontroTodasLasPalabras++;
                    insertarCoincidencias(&aux, arregloOcurrencias[i]);
                }
            }
        }
    }

    printf("cantPalabras: %d\n", cantPalabras);
    printf("encontro todas las palabrsa: %d\n", encontroTodasLasPalabras);

    if(encontroTodasLasPalabras == cantPalabras) {

        mostrarListaDeOcurrencias(aux);

    } else {

        printf("NO COINCIDEN VIEJA\n");
    }
}

void insertarCoincidencias(nodoT** aux, nodoT* arregloOcurrencias) {

    nodoT* aux2;

    if(*aux == NULL) {

        *aux = arregloOcurrencias;

    } else {

        aux2 = *aux;

        while(aux2->sig != NULL) {

            aux2 = aux2->sig;
        }

        aux2->sig = arregloOcurrencias;
    }
}

void palabraMasFrecuentePorDoc(nodoA* motor, int ID, int comparar) {

    int frec;
    //printf("%i\n",comparar);

    if(motor) {

        frec = retornarMaximaFrecuencia(motor->ocurrencias, ID);
        //printf("%i\n ",frec);

        if(frec > comparar) {
            comparar = frec;
            //printf("Test %i\n\n",comparar);
            system("cls");
            printf("\n----------------------------------------------------------------------------------------------------\n");
            setColor(RED); printf("[!]"); setColor(CYAN); printf(" La palabra mas repetida es:"); setColor(GREEN); printf(" %s ", motor->palabra);
        }

        palabraMasFrecuentePorDoc(motor->izq, ID, comparar);
        palabraMasFrecuentePorDoc(motor->der, ID, comparar);
    }
    //printf("%i",comparar);
}


int retornarMaximaFrecuencia(nodoT* ocurrencias, int ID) {

    int frec = 0;

    while(ocurrencias && ocurrencias->idDOC == ID) {
        //printf("%i == %i\n",ID,ocurrencias->idDOC);
        frec++;
        ocurrencias = ocurrencias->sig;
    }

    return frec;
}
