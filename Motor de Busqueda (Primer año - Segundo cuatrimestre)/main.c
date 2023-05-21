#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "diccionario.h"
#include "motor.h"
#include "usuario.h"
#include "presentacion.h"
#include "colors.h"
#define MAX_ARROW 7
#define MIN_ARROW 1

//Prototipado
void operacionesUsuario();
void funcionesDiccionario();

int main() {

    SetConsoleTitle("MOTOR DE BUSQUEDA by Daniel Diaz, Ezequiel Morales & Nazareno Rodriguez");
    //Tamaño de la consola
    system("MODE 100");

    operacionesUsuario();
    return 0;
}

void funcionesDiccionario() {

    //Variables locales
    termino * arregloDePalabras;
    int validos = 0;

    //Contamos las palabras que hay dentro de los documentos
    int cantPalabras = contarPalabrasDocs();

    //Le otorgamos la dimension justa a nuestro arreglo de palabras
    arregloDePalabras = malloc(sizeof(termino)*cantPalabras);

    guardarPalabrasDelDocumento(arregloDePalabras, &validos);
    //mostrarTodasLasPalabrasCargadas(arregloDePalabras,validos);

    cargarPalabrasAlDiccionario(arregloDePalabras, validos);
    //recorrerDiccionario();
}



void operacionesUsuario() {

    funcionesDiccionario();

    //Funciones del motor
    nodoA * motor = NULL;
    cargarMotor(&motor); //Cargamos el motor con todas las palabras que hay dentro del diccionario
    //mostrarMotor(motor);

    int opcion = 0;

    //Variables locales
    nodoA* aux;
    char palabra[MAX_WORD];
    int ID1, ID2, idCoincidente;
    char frase[50], continuar, seguir;
    nodoP * listaPalabras = NULL;
    int comparador = 1;
    char mensajito[200] = "                            Gracias por utilizar nuestro MOTOR DE BUSQUEDA.";
    int cantPalabras;

    //Flechas
    int position = 1;
    int keyPressed = 0;

    do {

        while(keyPressed != 13) {

            system("cls");

            computadoraPresentacion();

            printf("----------------------------------------------------------------------------------------------------\n\n");
            setColor(RED);
            printf("\t\t\t\t\t--[");
            setColor(CYAN);
            printf("BIENVENIDO/A");
            setColor(RED);
            printf("]--\n\n");

            arrowHere(1, position);
            setColor(RED);
            printf("[1]");
            setColor(CYAN);
            printf(" Buscar todas las apariciones de un termino en algun documento.\n");
            arrowHere(2, position);
            setColor(RED);
            printf("[2]");
            setColor(CYAN);
            printf(" Buscar todas las apariciones de un termino en 2 documentos especificos.\n");
            arrowHere(3, position);
            setColor(RED);
            printf("[3]");
            setColor(CYAN);
            printf(" Buscar la aparicion de mas de un termino en el mismo documento.\n");
            arrowHere(4, position);
            setColor(RED);
            printf("[4]");
            setColor(CYAN);
            printf(" Buscar una frase completa.\n");
            arrowHere(5, position);
            setColor(RED);
            printf("[5]");
            setColor(CYAN);
            printf(" Buscar la palabra de mas frecuencia que aparece en alguno de los docs.\n");
            arrowHere(6, position);
            setColor(RED);
            printf("[6]");
            setColor(CYAN);
            printf(" Sugerir similares (Levenshtein).\n");
            arrowHere(7, position);
            setColor(RED);
            printf("[7]");
            setColor(CYAN);
            printf(" Salir\n");

            keyPressed = getch();

            if(keyPressed == 80 && position != MAX_ARROW) {

                position++;

            } else if(keyPressed == 72 && position != MIN_ARROW) {

                position--;

            } else {
                position = position;
            }

        }


//        setColor(RED); printf("\n- ["); setColor(CYAN); printf("OPCION"); setColor(RED); printf("]: ");
//        fflush(stdin);
//        setColor(GREEN);
//        scanf("%i", &opcion);
//        setColor(CYAN);

        switch(position) {

        //1) Buscar todas las apariciones de un término en algún documento (operación or).
        case 1:

            setColor(CYAN);
            printf("\n----------------------------------------------------------------------------------------------------\n\n");
            setColor(RED);
            printf("[1]");
            setColor(CYAN);
            printf(" Ingrese la palabra que desea buscar: ");
            fflush(stdin);
            setColor(GREEN);
            gets(palabra);
            setColor(CYAN);
            aux = busquedaUnica(motor, palabra);

            if(aux) {

                mostrarUnNodo(aux);

            } else {

                setColor(RED);
                printf("[!]");
                setColor(CYAN);
                printf(" La palabra que desea buscar no se encuentra en el motor\n");
            }

            break;

        //2) Buscar todas las apariciones de un término en un documento y otro (operacion and).
        case 2:

            setColor(CYAN);
            printf("\n----------------------------------------------------------------------------------------------------\n\n");
            setColor(RED);
            printf("[2]");
            setColor(CYAN);
            printf(" Ingrese la palabra que desea buscar: ");
            fflush(stdin);
            setColor(GREEN);
            gets(palabra);
            setColor(CYAN);

            setColor(RED);
            printf("\n[?]");
            setColor(CYAN);
            printf(" En que documentos desea realizar la busqueda? (Ingrese ID)\n");
            setColor(RED);
            printf("\t[1]");
            setColor(CYAN);
            printf(" INGRESE ID DOC: ");
            setColor(GREEN);
            scanf("%i", &ID1);
            setColor(RED);
            printf("\t[2]");
            setColor(CYAN);
            printf(" INGRESE ID DOC: ");
            setColor(GREEN);
            scanf("%i", &ID2);
            setColor(CYAN);

            buscarEnDosDoc(motor, palabra, ID1, ID2); //usuario.c

            break;

        //3) Buscar la aparición de más de un término en el mismo documento.
        case 3:

            do {
                setColor(CYAN);
                printf("\n----------------------------------------------------------------------------------------------------\n\n");
                setColor(RED);
                printf("[3]");
                setColor(CYAN);
                printf(" Ingrese la palabra que desea buscar: ");
                fflush(stdin);
                setColor(GREEN);
                scanf("%s",palabra);
                setColor(CYAN);
                insertarPalabraAlFinal(&listaPalabras, palabra, NULL); //usuario.c

                setColor(RED);
                printf("\n[?]");
                setColor(CYAN);
                printf(" Desea buscar otra palabra? (s/n)\n");
                setColor(RED);
                printf("\n- [");
                setColor(CYAN);
                printf("RESPUESTA");
                setColor(RED);
                printf("]: ");
                setColor(GREEN);
                fflush(stdin);
                scanf("%c", &continuar);

            } while(continuar == 's');

            setColor(RED);
            printf("\n[?]");
            setColor(CYAN);
            printf(" En que documentos desea realizar la busqueda? (Ingrese ID)\n");
            fflush(stdin);
            setColor(RED);
            printf("\n- [");
            setColor(CYAN);
            printf("RESPUESTA");
            setColor(RED);
            printf("]: ");
            setColor(GREEN);
            scanf("%i", &ID1);
            setColor(CYAN);
            printf("\n");

            while(listaPalabras) {

                buscarVariosTerminosEnUnDoc(motor, listaPalabras->palabra, ID1); //usuario.c
                listaPalabras = listaPalabras->sig;
            }

            //Inicializar la lista en NULL

            break;

        //4) Buscar una frase completa (las palabras deben estar contiguas en alguno de lo documentos).
        case 4:

            setColor(CYAN);
            printf("\n----------------------------------------------------------------------------------------------------\n\n");
            setColor(RED);
            printf("[4]");
            setColor(CYAN);
            printf(" Ingrese la frase que desea buscar: ");
            fflush(stdin);
            setColor(GREEN);
            gets(frase);
            setColor(CYAN);

            cantPalabras=cantPalabrasFrase(frase);
//            printf("Cant Palabras: %i",cantPalabras);

            if(cantPalabras==1) {
                aux=busquedaUnica(motor,frase);
                if(aux) {

                    mostrarUnNodo(aux);

                } else {

                    setColor(RED);
                    printf("[!]");
                    setColor(CYAN);
                    printf(" La palabra que desea buscar no se encuentra en el motor\n");
                }

            } else {

                if(verificarExistencias(motor, frase)) { //motor.c

                    cargarPalabrasDeLaFrase(motor, &listaPalabras, frase); //usuario.c
                    //mostrarListaDePalabras(listaPalabras);
                    //idCoincidente = AllWordsSameDoc(listaPalabras, cantPalabras);

                    AllWordsSameDoc(listaPalabras, cantPalabras);

//                    if(idCoincidente != 0) {
//
//                        setColor(RED);
//                        printf("[!]");
//                        setColor(CYAN);
//                        printf(" El documento donde se encuentra la frase es:");
//                        setColor(GREEN);
//                        printf(" %d ", idCoincidente);
//
//                    } else {
//
//
//
//                    }

                } else {

                    setColor(RED);
                    printf("[!]");
                    setColor(CYAN);
                    printf(" La frase que busca no existe en ningun documento\n");
                }

            }



            break;

        //5) Buscar la palabra de más frecuencia que aparece en alguno de los docs.
        case 5:
            setColor(CYAN);
            printf("\n----------------------------------------------------------------------------------------------------\n\n");
            setColor(RED);
            printf("[?]");
            setColor(CYAN);
            printf(" En que documento desea realizar la busqueda? (Ingrese ID)\n");
            setColor(RED);
            printf("\n- [");
            setColor(CYAN);
            printf("RESPUESTA");
            setColor(RED);
            printf("]: ");
            setColor(GREEN);
            scanf("%i", &ID1);
            setColor(CYAN);
            printf("\n");
            palabraMasFrecuentePorDoc(motor,ID1,comparador);
            //printf("%i\n",palabraMasFrecuentePorDoc(motor,ID1,0));
            /*aux=palabraMasFrecuentePorDoc(motor,ID1,0);
            if(aux)
            {
                printf("La palabra mas frecuente en el documento %i es %s",ID1,aux->palabra);
            }*/

            break;

        case 6:
            setColor(CYAN);
            printf("\n----------------------------------------------------------------------------------------------------\n\n");
            setColor(RED);
            printf("[!]");
            setColor(CYAN);
            printf(" Ingrese la palabra que desea buscar: ");
            setColor(GREEN);
            fflush(stdin);
            gets(palabra);
            setColor(CYAN);
            aux = busquedaUnica(motor, palabra);

            if(aux) {
                mostrarUnNodo(aux);

            } else {

                aux = sugerirPalabra(motor, palabra);

                if(aux) {
                    setColor(RED);
                    printf("\n[?]");
                    setColor(CYAN);
                    printf(" Quisiste decir");
                    setColor(GREEN);
                    printf(" %s", aux->palabra);
                    setColor(CYAN);
                    printf("?\n");
                }
            }

            break;

        case 7:


            setColor(RED);
            printf("\n----------------------------------------------------------------------------------------------------\n");
            setColor(GREEN);
            for(int i = 0; i < 100; i++) {
                printf("%c", mensajito[i]);
                Sleep(10);
            }
            setColor(RED);
            printf("\n----------------------------------------------------------------------------------------------------\n");
            seguir = 'n';

            break;

        default:

            printf("\n[!] Numero de operacion incorrecto, vuelva a intentarlo\n");

            break;
        }

        if(position != 7) {

            setColor(CYAN);
            printf("\n----------------------------------------------------------------------------------------------------\n");
            setColor(RED);
            printf("\n[?]");
            setColor(CYAN);
            printf(" Desea realizar otra operacion? (s/n)\n");
            fflush(stdin);
            setColor(RED);
            printf("\n- [");
            setColor(CYAN);
            printf("RESPUESTA");
            setColor(RED);
            printf("]: ");
            setColor(GREEN);
            scanf("%c", &seguir);
            system("cls");
        }

        keyPressed = 0;

    } while (seguir == 's');
}

void arrowHere(int realPosition, int arrowPosition) {

    if(realPosition == arrowPosition) {
        setColor(GREEN);
        printf(" ---->> ");

    } else {

        printf("       ");
    }
}
