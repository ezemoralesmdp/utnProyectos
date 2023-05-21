#include "diccionario.h"

termino cargarUnTermino(char* palabra, int idDoc, int pos) {

    termino nuevo;

    strcpy(nuevo.palabra,palabra);
    nuevo.idDOC = idDoc;
    nuevo.pos = pos;

    return nuevo;
}

void mostrarUnaPalabra(termino palabra) {

    printf("Palabra: %s\n", palabra.palabra);
    printf("ID Documento: %i\n", palabra.idDOC);
    printf("Pos: %i\n", palabra.pos);
}

void mostrarTodasLasPalabrasCargadas(termino* arregloDePalabras, int cantPalabras) {

    for(int i = 0; i < cantPalabras; i++) {

        mostrarUnaPalabra(arregloDePalabras[i]);
        printf("\n");
    }
}

int contarPalabrasDocs() {

    int idDoc = 0;
    int cant = 0;

    while(idDoc < CANT_DOCS) {

        char nombreDoc[10] = "doc";
        char nroDoc[4];
        idDoc++;
        *nroDoc = idDoc + '0';
        strcat(nombreDoc, nroDoc);
        strcat(nombreDoc, ".txt");

        FILE * archiDoc = fopen(nombreDoc, "rb");
        char letra;

        if(archiDoc) {

            while(fread(&letra, sizeof(char), 1, archiDoc) > 0) {

                if(letra != ' ' && letra != '.' && letra != ',') {

                } else {

                    cant++;
                }
            }

            fclose(archiDoc);
        }
    }

    //printf("%i\n",cant);
    return cant;
}

void guardarPalabrasDelDocumento(termino* arregloDePalabras, int* validos) {

    //Variables locales
    int idDoc = 0;
    int j = 0;

    while(idDoc < CANT_DOCS) {

        char nombreDoc[10] = "doc";
        char nroDoc[4];
        idDoc++;
        *nroDoc = idDoc + '0';
        strcat(nombreDoc, nroDoc);
        strcat(nombreDoc, ".txt");

        FILE* archiDoc = fopen(nombreDoc, "rb");
        char letra;
        int i = 0;
        int pos = 0;
        char palabra[MAX_WORD];

        if(archiDoc) {

            while(fread(&letra, sizeof(char), 1, archiDoc) > 0) {

                if(letra != ',' && letra != ' ' && letra != '.' && (int)letra != 10) {

                    palabra[i] = letra;
                    i++;

                } else {

                    if(palabra[0] != 0) { //¿Corroboramos por las dudas que la palabra no tenga nada cargado?
                        //¿Funciona que un arreglo de char sea distinto de 0? ¿Lo toma como distinto de NULL?

                        arregloDePalabras[j] = cargarUnTermino(palabra, idDoc, pos);
                        j++;
                        i = 0;
                        pos++;
                        (*validos)++;
                        memset(palabra, 0, MAX_WORD);
                    }
                }
            }

            fclose(archiDoc);
        }
    }
}

void cargarPalabrasAlDiccionario(termino* arregloDeTerminos, int validos) {

    FILE * archiDiccionario = fopen(diccionario, "wb");

    if(archiDiccionario) {

        for(int i = 0; i < validos; i++) {

            fwrite(&arregloDeTerminos[i], sizeof(termino), 1, archiDiccionario);
        }

        fclose(archiDiccionario);
    }
}

void recorrerDiccionario() {

    FILE * archiDiccionario = fopen(diccionario, "rb");
    termino palabra;

    if(archiDiccionario) {

        while(fread(&palabra, sizeof(termino), 1, archiDiccionario) > 0) {

            mostrarUnaPalabra(palabra);
        }

        fclose(archiDiccionario);
    }
}
