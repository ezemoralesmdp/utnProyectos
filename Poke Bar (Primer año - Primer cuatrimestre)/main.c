//Librerias utilizadas
#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

//Headers (.h)
#include "pila.h"
#include "dibujo.h"
#include "struct.h"
#include "const.h"

/*____________[ Prototipado ]_____________*/
void presentacion();
void inicioSesion();
void contandoLosDias();

/*________[   MENUS   ]________*/
void menuTitulo();
void menuEncargado();
void menuMOZO(char matrizMesa[][CANT_MESA]);
void menuCajero();
void menuInicioSesion();

/*________[   LAS FUNCIONES DEL ENCARGADO   ]________*/
void trabajoEncargado(char matrizMesa[CANT_MESA][CANT_MESA], int bandera, Mesa unaMesa[], Pila *pilaReserva, Reserva reservas[]);
dataEmpleado scanDatosEmpleado();
void cargarDatosEmpleado();
void verDatosEmpleado(int puesto);
void verCajero(Empleados elEmpleado);
void verMozo(Empleados elEmpleado);
int cantLegajos();
void resetearArchivos();
void mostrarDeterminadoEmpleado(int puesto, int pos);
void modificarEmpleado(int puesto, int pos, int x, int y);
void buscarEmpleado(int puesto, int pos);
void elegirOpcion(int *opcion, int *var);
int validarArchivo(int legajoIngresado, int puesto);
void elegirOpcionDOS(int *opcion, int *var) ;

/*________[   LAS FUNCIONES DEL MOZO   ]________*/
void trabajoMozo(char matrizMesa[CANT_MESA][CANT_MESA], int bandera, Mesa unaMesa[]);
void mostrarCarta();
void hacerPedido(int abrir, Mesa laMesa[]);

/*________[   DIBUJOS DEL SALON   ]________*/
void dibujoMesa(char arrMesa[][CANT_MESA], int cant);
void cargarMatrizLETRAS(int cant, char arrAUX[][CANT_MESA]);
void ocuparMESA(char arrMesa[][CANT_MESA], int cant, int mesaElegida);
void cargarDibujoMesa(char arrMesa[][CANT_MESA], int cant);
void mesaParaABRIR(char matrizMesa[][CANT_MESA], int abrir, Mesa unaMesa[]);
void desocuparMesa(char arrMesa[][CANT_MESA], int cant, int mesaElegida);
void lineaHorizontalArriba(int tam);
void lineaHorizontalAbajo(int tam);

/*________[   FUNCIONES DE LAS MESAS   ]________*/
Mesa limpiarVariables();
void mostrarPedidosActuales(Mesa unaMesa[], int tam);
void cerrarUnaMesa(int pos, Mesa cerrarMesa[]);
void mostrarHistorialMesasCerradas();
void pedidosMesa(Mesa laMesa);
void agregarNuevosPedidos(Mesa laMesa[], int agregar);

/*________[   FUNCIONES DEL CAJERO   ]________*/
void trabajoCajero(Pila *pilaReserva, Reserva reservas[]);
void guardarDinero(int total);
void cobrarMesa(int numMesa, Mesa cerrada);
int verGananciasActuales();

/*________[   FUNCIONES DE LAS RESERVAS   ]________*/
Reserva pedirDatosCliente(Pila pilaReserva, int x, int y);
void verLaReserva(Reserva persona[], int numReserva, int totalReser);
void mostraUNAreserva(Reserva unaReserva);
void apilarReservas(Reserva persona[], Pila *reserva, int j);
int verificarEntrada(Pila a, int numReserva);
void ordenarReservas(Pila *ordenar);

//Presentacion al arrancar programa
void presentacion() {

    system("mode 150, 40"); //Tamaño consola
    dibujoCopa(); //Dibujo de copas
    int x = 33;
    int y = 10;
    gengar(x, y); //Dibujo pokemon: Gengar
    system("pause > nul");
}

int main() {

    presentacion();
    inicioSesion();

    return 0;
}

/*________[   ACUMULADOR DE DIAS DE TRABAJO   ]________*/
void contandoLosDias() {

    system("cls");
    FILE *tempDias;
    tempDias = fopen(FILE_DIAS, "ab");

    Dias el;
    el.dia = 1;

    int acumulador = 0;

    if(tempDias != NULL)
    {
        fwrite(&el, sizeof(Mesa), 1, tempDias);
        el.dia++;

        fseek(tempDias, 0, SEEK_END);
        acumulador = ftell(tempDias) / sizeof(Mesa);

        fclose(tempDias);
    }

    gotoxy(5, 1);
    printf("  DIA %d DE TRABAJO \n", acumulador);

}

/*________[   INICIO DE SESION PARA INGRESAR A UN PUESTO DE TRABAJO DETERMINADO   ]________*/
void inicioSesion() {

    system("cls");
    contandoLosDias();
    system("color 0E"); //COLOR AMARILLO
    char matrizMesa[CANT_MESA][CANT_MESA] = {" "};

    Pila *pilaReserva;
    inicpila(pilaReserva);
    const int RESER = 15;
    Reserva reservas[RESER];

    //Definimos una mesa, la cual empieza con sus variables limpias y definidas
    Mesa unaMesa[TAM_MESA];
    for (int i = 0; i < TAM_MESA; i++) {
        unaMesa[i] = limpiarVariables();
    }

    //Variables auxiliares
    int contrasenia = 0;
    int noPasanlosDias = 0;
    int flag = 0;
    int move = 0;

    do {

        menuTitulo();
        menuInicioSesion();

        gotoxy(2, 16);
        printf("____________________");
        gotoxy(2, 15);
        scanf("%d", &contrasenia);

        switch (contrasenia) {

            //Salimos del programa
            case 0:
                system("cls");
                system("color 0D "); //COLOR CELESTE
                JIGGlypuff(); //Dibujo pokemon: Jigglypuff
                Sleep(800);
                exit(0);

            //ACCESO: TRABAJADOR MOZO - PASSWORD: 54321
            case KEY_MOZO:
                //system("color 0A"); - COLOR VERDE
                trabajoMozo(matrizMesa, flag, unaMesa);
                flag = 1;
                charizard(20, 0); //Dibujo pokemon: Charizard
                break;

            //ACCESO: TRABAJADOR CAJERO - PASSWORD: 12345
            case KEY_CAJERO:
                trabajoCajero(pilaReserva, reservas);
                squirtle(); //Dibujo pokemon: Squirtle
                break;

            //ACCESO: TRABAJADOR ENCARGADO - PASSWORD: 98765
            case KEY_ENCARGADO:
                trabajoEncargado(matrizMesa, flag, unaMesa, pilaReserva, reservas);
                charmander(); //Dibujo pokemon: Charmander
                break;

            //SI LA CONTRASEÑA ES INCORRECTA
            default:
                gotoxy(3, 20);
                printf("\n\n [!] Contrase%ca incorrecta\n - Vuelva a ingresarla\n", 164);
                Sleep(900);
                break;
        }

        system("pause > nul");
        system("color 0E"); //COLOR AMARILLO
        system("cls");

    } while (contrasenia != 0);
}

/*________[   MENU DE INICIO DE SESION   ]________*/
void menuInicioSesion() {

    printf(" \n  INTEGRANTES DEL GRUPO  \n\n");
    simpleLineHori(0, 30, 0, 7);
    printf("\n   %c Kevin Reyna          \n", 5);              //                    ( ͡❛ ͜ʖ ͡❛)
    printf("   %c Daniel Diaz            \n", 2);
    printf("   %c Ezequiel Morales       \n\n", 14);
    simpleLineHori(0, 30, 0, 11);
    printf("\n");

    gotoxy(2, 13);
    printf("%c Iniciar sesion (Ingrese contrase%ca):", FLECHA_DER, 164);
    gotoxy(1, 19);
    printf(" Finalizar programa ( 0 )\n");
    int x = 57;
    int y = 10;
    pikachuChico(x, y); //Dibujo pokemon: Pikachu
}

/*________[   TITULO ESTATICO - POKEBAR   ]________*/
void menuTitulo() {

    gotoxy(52, 2);
    printf("___  ____ _  _ ____    ___  ____ ____ \n");
    gotoxy(52, 3);
    printf("|__] |  | |_/  |___    |__] |__| |__/ \n");

    gotoxy(52, 4);
    printf("|    |__| | \\_ |___    |__] |  | |  \\ \n");
    gotoxy(55, 1);
    printf("Sistema de Gestion de Restaurant\n");
}

/*________[   SELECCION DE MODIFICACION DE INFORMACION: MOZO O CAJERO   ]________*/
void elegirOpcion(int *opcion, int *var) {

    printf("\n 1. Modificar MOZO\n");
    printf(" 2. Modificar CAJERO\n");
    printf("%c Opcion : ", FLECHA_DER);

    fflush(stdin);
    scanf("%d", opcion);
    printf("\n Legajo del Empleado : ");
    fflush(stdin);
    scanf("%d", var);
}

/*________[   SELECCION DE BUSQUEDA DE INFORMACION: MOZO O CAJERO   ]________*/
void elegirOpcionDOS(int *opcion, int *var) {

        printf("\n 1. Buscar MOZO\n");
        printf(" 2. Buscar CAJERO\n");
        printf("%c Opcion : ", FLECHA_DER);
        fflush(stdin);
        scanf("%d", opcion);
        printf("\n Posicion del REGISTRO : ");
        fflush(stdin);
        scanf("%d", var);
}

/*________[   TRABAJO DEL ENCARGADO   ]________*/
void trabajoEncargado(char matrizMesa[CANT_MESA][CANT_MESA], int bandera, Mesa unaMesa[], Pila *pilaReserva, Reserva reservas[]) {

    system("cls");
    //system("color 0A"); //COLOR VERDE
    system("color 0D"); //COLOR VIOLETA

    //Variables auxiliares
    int x = 95;
    int y = 1;
    int op = 0;
    int opcion = 0;
    int var = 0;
    int legajo = 0;

    do {

        legajo = cantLegajos();
        machamp(x, y); //Dibujo pokemon: Machamp
        menuEncargado() ; //Menu del Encargado

        fflush(stdin);
        scanf("%d", &op);

        //OPCIONES
        switch (op) {

            //Cargamos datos de un empleado: MOZO o CAJERO
            case 1:
                    cargarDatosEmpleado();
                    Sleep(1000);
                    break;

            //Vemos el total de empleados MOZOS o CAJEROS
            case 2:
                    printf("\n 1. Ver MOZOS\n");
                    printf(" 2. Ver CAJEROS\n\n");
                    printf(" %c \n", GUION);
                    scanf("%d", &opcion);
                    verDatosEmpleado(opcion);
                    break;

            //Modificamos un empleado (MOZO o CAJERO) por NUMERO DE LEGAJO
            case 3:
                    elegirOpcion(&opcion, &var);
                    modificarEmpleado(opcion, var, x, y);
                    break;

            //Buscamos un empleado en particular (MOZO o CAJERO) por POSICION DE REGISTRO
            case 4:
                    elegirOpcionDOS(&opcion, &var);
                    buscarEmpleado(opcion, var);
                    Sleep(1000);
                    break;

            //Reseteamos los archivos de: MESAS, DINERO TOTAL, DIAS
            case 5:
                    resetearArchivos();
                    break;

            //EL ENCARGADO PUEDE TOMAR TODAS LAS FUNCIONES DE UN MOZO
            case 6:
                    trabajoMozo(matrizMesa, bandera, unaMesa);
                    break;

            //EL ENCARGADO PUEDE TOMAR TODAS LAS FUNCIONES DE UN CAJERO
            case 7:
                    trabajoCajero(pilaReserva, reservas);
                    break;

            //Si se equivoca al ingresar una opcion
            default:
                    if(op != 0){
                        printf(" [!] INGRESE LA OPCION CORRECTA\n");
                    }
                    break;
        }
        system("color 0D"); //COLOR VIOLETA
        system("cls");

    } while (op != 0);
}

/*________[   PRINTS DEL MENU DEL ENCARGADO   ]________*/
void menuEncargado() {

        menuTitulo();
        gotoxy(5, 3);
        printf(" E N C A R G A D O  \n");
        simpleLineHori(1, 25, 2, 4);

        gotoxy(3, 9);
        printf(" 1. Ingresar un NUEVO EMPLEADO \n");
        gotoxy(3, 10);
        printf(" 2. Ver los empleados \n");
        gotoxy(3, 11);
        printf(" 3. Modificar un empleado \n");
        gotoxy(3, 12);
        printf(" 4. Buscar un empleado \n");
        gotoxy(3, 13);
        printf(" 5. Borrar historiales (Mesas - Dinero - Dias) \n");
        gotoxy(3, 14);
        printf(" 6. Acceder como MOZO \n");
        gotoxy(3, 15);
        printf(" 7. Acceder como CAJERO \n\n");
        gotoxy(3, 17);
        printf(" 0. Volver \n\n");

        simpleLineHori(1, 20, 1, 20);
        gotoxy(3, 19);
        printf("%c Opcion : ", FLECHA_DER);
}

/*________[   RESETEAMOS LA INFORMACION DE LOS ARCHIVOS REMOVIENDOLOS   ]________*/
void resetearArchivos() {

    remove(FILE_HISTORIAL_MESAS);
    remove(FILE_DIAS);
    remove(F_HISTORIAL_DINERO);
}

/*________[   BUSCAMOS UN EMPLEADO EN PARTICULAR - 1: MOZO - 2: CAJERO   ]________*/
void buscarEmpleado(int puesto, int posicion) {

    FILE *archivoCajero;
    FILE *archivoMozo;

    Empleados unEmpleado;

    int i = 0;
    if(puesto == 1){

        if( (archivoMozo = fopen(FILE_MOZO, "rb") ) != NULL){

           while(fread(&unEmpleado, sizeof(Empleados), 1, archivoMozo) > 0) {
                i++;

                if(posicion == i){
                    printf("\n  ( Registro N.%d ) ", posicion);  // VALIDACION de registros mediante un contador EN EL CICLO
                    verMozo(unEmpleado); //Mostramos informacion de un MOZO

                }else{
                   printf(" \n  ( Registro invalido ) \n");
               }
           }

            fclose(archivoMozo);
        }

    }else if(puesto == 2){

        if( (archivoCajero = fopen(FILE_CAJERO,"rb") ) != NULL){

            while(fread(&unEmpleado, sizeof(Empleados), 1, archivoCajero) > 0){
                i++;

                if(posicion == i) {
                    printf("\n  ( Registro N.%d ) ", posicion);
                    verCajero(unEmpleado); //Mostramos informacion de un CAJERO

                }else{
                    printf("  ( Registro Invalido ) \n");

                }
            }

            fclose(archivoCajero);
        }
    }
}

/*________[   VALIDAMOS LA EXISTENCIA DEL REGISTRO DEL MOZO O CAJERO   ]________*/
int validarArchivo(int legajoIngresado, int puesto) {

    FILE *archivoCajero;
    FILE *archivoMozo;

    Empleados unEmpleado;
    int flag = 0;

    //Validar existencia MOZO
    if(puesto == 1){

        if( (archivoMozo = fopen(FILE_MOZO,"rb") ) != NULL){

            while(fread(&unEmpleado, sizeof(Empleados), 1, archivoMozo) > 0){

                if(unEmpleado.mozo.datos.legajo == legajoIngresado){

                    flag = 1;
                }
            }

            fclose(archivoMozo);
        }

    //Validar existencia CAJERO
    }else if(puesto == 2){

       if( (archivoCajero = fopen(FILE_CAJERO,"rb") ) != NULL){

            while(fread(&unEmpleado, sizeof(Empleados), 1, archivoCajero) > 0){

                if(unEmpleado.cajero.datos.legajo == legajoIngresado){

                    flag = 1;
                }
            }

            fclose(archivoCajero);
        }
    }

    return flag;
}

/*________[   MODIFICAMOS UN EMPLEADO EN PARTICULAR - 1: MOZO - 2: CAJERO   ]________*/
void modificarEmpleado(int puesto, int legajo, int x, int y) {

    system("cls");
    machamp(x, y); //Dibujo pokemon: Machamp
    menuTitulo();
    gotoxy(5, 3);
    printf(" E N C A R G A D O  \n");
    simpleLineHori(1, 25, 2, 4);

    FILE *archivoCajero;
    FILE *archivoMozo;

    Empleados unEmpleado;
    Empleados nuevo;

    int flag = 0;
    int i = 0;
    char valid = 's';

    //Modificar MOZO
    if(puesto == 1){

        if( (archivoMozo = fopen(FILE_MOZO, "r+b") ) != NULL){

            flag = validarArchivo(legajo, puesto);

            while(fread(&unEmpleado, sizeof(Empleados), 1, archivoMozo) > 0){

                i++;
                if(flag == 1 && legajo == unEmpleado.mozo.datos.legajo){

                    printf("\n  Registro N.%d ", legajo);
                    verMozo(unEmpleado); //Mostramos el MOZO a modificar

                    printf("\n %cSeguro que desea Modificarlo? ( s / n ) \n   . ", PREGUNTA); //Corroboramos modificacion
                    fflush(stdin);
                    scanf("%c", &valid);
                    valid = tolower(valid);

                    if(valid == 's') {

                        //Modificamos
                        printf(" ( Ingresar NUEVO EMPLEADO ) \n\n");
                        nuevo.mozo.datos= scanDatosEmpleado();
                        nuevo.mozo.datos.legajo = unEmpleado.mozo.datos.legajo;

                        fseek(archivoMozo, sizeof(Empleados)*(i-1), SEEK_SET);
                        fwrite(&nuevo, sizeof(Empleados), 1, archivoMozo);

                        break;

                    }else{
                        break;
                    }
                }
            }
            fclose(archivoMozo);
        }

    //Modificar CAJERO
    }else if(puesto == 2){

        if( (archivoCajero = fopen(FILE_CAJERO, "r+b") ) != NULL){

           flag = validarArchivo(legajo, puesto);

            while(fread(&unEmpleado, sizeof(Empleados), 1, archivoCajero) > 0){

                i++;
                if(flag == 1 && legajo == unEmpleado.cajero.datos.legajo){

                    printf("\n  Registro N.%d ", legajo);
                    verCajero(unEmpleado); //Mostramos el CAJERO a modificar

                    printf("\n %cSeguro que desea Modificarlo? ( s / n ) \n   .  ", PREGUNTA); //Corroboramos modificacion
                    fflush(stdin);
                    scanf("%c",&valid);
                    valid = tolower(valid);

                    //Modificamos
                    if( valid == 's') {
                        printf(" Ingresar NUEVO EMPLEADO \n");

                        nuevo.cajero.datos = scanDatosEmpleado();
                        nuevo.cajero.datos.legajo = unEmpleado.cajero.datos.legajo;

                        fseek(archivoCajero, sizeof(Empleados)*(i-1), SEEK_SET);
                        fwrite(&nuevo, sizeof(Empleados), 1, archivoCajero);

                        break;

                    }else{
                        break;
                    }
                }
            }
            fclose(archivoCajero);

        }
    }
}

/*________[   MODIFICAMOS UN EMPLEADO   ]________*/
dataEmpleado scanDatosEmpleado() {

    dataEmpleado datos;

    printf(" NOMBRE del empleado : ");
    fflush(stdin);
    gets(datos.nombre);
    printf(" DNI : ");
    scanf("%d", &datos.dni);
    printf(" EDAD : ");
    scanf("%d", &datos.edad);
    printf(" DIRECCION (calle y numero) : ");
    fflush(stdin);
    gets(datos.calle);

    return datos;
}

/*________[   CARGAR LOS DATOS DE LOS EMPLEADOS   ]________*/
void cargarDatosEmpleado() {

    FILE *archivoCajero;
    FILE *archivoMozo;
    Empleados unEmpleado;

    int legajo = cantLegajos();
    int op = 0;

    printf("\n    1. MOZO\n");
    printf("    2. CAJERO\n\n");
    printf(" %c Elegir el puesto de trabajo : ", GUION);
    scanf("%d", &op);
    printf("\n");

    //Si elige MOZO
    if (op == 1) {
        archivoMozo = fopen(FILE_MOZO, "ab");

        if (archivoMozo != NULL) {

            unEmpleado.mozo.datos = scanDatosEmpleado();
            legajo++;
            unEmpleado.mozo.datos.legajo = legajo;

            printf("\n El LEGAJO del empleado %s es: ( %d )\n", unEmpleado.mozo.datos.nombre, legajo);
            fwrite(&unEmpleado, sizeof(Empleados), 1, archivoMozo);
            Sleep(800);
        }
        fclose(archivoMozo);

    //Si elige CAJERO
    } else if (op == 2) {

        archivoCajero = fopen(FILE_CAJERO, "ab");

        if (archivoCajero != NULL) {

            unEmpleado.cajero.datos = scanDatosEmpleado();
            legajo++;
            unEmpleado.cajero.datos.legajo = legajo;

            printf("\n El Legajo del Empleado %s es ( %d )\n", unEmpleado.cajero.datos.nombre, legajo);
            fwrite(&unEmpleado, sizeof(Empleados), 1, archivoCajero);
            Sleep(800);
        }
        fclose(archivoCajero);

    }
}

/*________[   CANTIDAD DE LEGAJOS CARGADOS   ]________*/
int cantLegajos() {

    FILE *fileCajero;
    FILE *fileMozo;

    Empleados unEmpleado;

    //Variables auxiliares
    int legajoCajero = 0;
    int legajoMozo = 0;
    fileCajero = fopen(FILE_CAJERO, "rb");
    fileMozo = fopen(FILE_MOZO, "rb");

    if (fileCajero != NULL) {

        fseek(fileCajero, 0, SEEK_END);  // Colocar el Cursor al Final del Archivo
        legajoCajero = ftell(fileCajero) / sizeof(Empleados);
        fclose(fileCajero);
    }

    if (fileMozo != NULL) {

        fseek(fileMozo, 0, SEEK_END);
        legajoMozo = ftell(fileMozo) / sizeof(Empleados);
        fclose(fileMozo);
    }

    return legajoCajero + legajoMozo; //Retornamos la SUMA de AMBOS legajos
}

/*________[   DATOS PERSONALES DE LOS EMPLEADOS   ]________*/
void verDatosEmpleado(int puesto) {

    FILE *archivoCajero;
    FILE *archivoMozo;
    Empleados nuevoEmpleado;

    //Si elige MOZO
    if (puesto == 1) {

        archivoMozo = fopen(FILE_MOZO, "rb");

        if (archivoMozo != NULL) {

            while (fread(&nuevoEmpleado, sizeof(Empleados), 1, archivoMozo) > 0) {

                printf("\n\t\t[MOZOS] ");
                verMozo(nuevoEmpleado);
                Sleep(300);
            }
            fclose(archivoMozo);

        } else {
            printf(" [!] El archivo NO existe\n");
        }

    //Si elige CAJERO
    } else if (puesto == 2) {

        archivoCajero = fopen(FILE_CAJERO, "rb");

        if (archivoCajero != NULL) {

            while (fread(&nuevoEmpleado, sizeof(Empleados), 1, archivoCajero) > 0) {

                printf("\n\t\t[CAJEROS] ");
                verCajero(nuevoEmpleado);
                Sleep(300);
            }
            fclose(archivoCajero);

        } else {
            printf(" [!] El archivo NO existe\n");
        }
    }

    printf(" ( FIN DE LA LISTA ) \n ... ");
    system(" pause > nul");

}

/*________[   PRINTS DE LOS DATOS DE LOS EMPLEADOS   ]________*/

/*________[   ( MOZO )   ]________*/
void verMozo(Empleados elEmpleado) {

    printf("\n\n");
    printf(" EMPLEADO : %s \n", elEmpleado.mozo.datos.nombre);
    printf(" DNI: %d\n", elEmpleado.mozo.datos.dni);
    printf(" EDAD: %d \n", elEmpleado.mozo.datos.edad);
    printf(" DIRECCION: %s \n", elEmpleado.mozo.datos.calle);
    printf(" NUMERO DE LEGAJO: %d \n", elEmpleado.mozo.datos.legajo);
    printf("________________________\n");
}

/*________[   ( CAJERO )   ]________*/
void verCajero(Empleados elEmpleado) {

    printf("\n\n");
    printf(" EMPLEADO - %s \n", elEmpleado.cajero.datos.nombre);
    printf(" DNI: %d\n", elEmpleado.cajero.datos.dni);
    printf(" EDAD: %d \n", elEmpleado.cajero.datos.edad);
    printf(" DIRECCION: %s \n", elEmpleado.cajero.datos.calle);
    printf(" NUMERO DE LEGAJO: %d\n", elEmpleado.cajero.datos.legajo);
    printf("________________________\n");
}

/*______________________________[ EL TRABAJO DEL MOZO ]____________________________*/
void trabajoMozo(char matrizMesa[CANT_MESA][CANT_MESA], int bandera, Mesa unaMesa[]) {

    system("cls");
    //system("color 0A"); //COLOR VERDE
    system("color 0B");//COLOR CELESTE

    //Variables auxiliares
    int x = 60;
    int y = 7;
    int mesaAccion = 0;
    int op = 0;

    //Mostramos el dibujo del salon
    if (bandera == 0) {
        cargarDibujoMesa(matrizMesa, CANT_MESA);
    }

    do {

        meowth(x, y); //Dibujo pokemon: Meowth
        menuMOZO(matrizMesa);

        scanf("%d", &op);
        fflush(stdin);

        switch (op) {

            //Abrimos una MESA NUEVA
            case 1:
                printf("\n Numero de MESA A ABRIR : ");
                fflush(stdin);
                scanf("%d", &mesaAccion);
                mesaParaABRIR(matrizMesa, mesaAccion, unaMesa);
                break;

            //Agregamos pedidos a una mesa
            case 2:
                printf("\n Ingrese el NUMERO DE MESA :");
                scanf("%d", &mesaAccion);
                agregarNuevosPedidos(unaMesa, mesaAccion);
                break;

            //Vemos los pedidos realizados hasta el momento en las mesas
            case 3:
                system("cls");
                mostrarPedidosActuales(unaMesa, TAM_MESA);
                break;

            //Cerramos una mesa en particular
            case 4:
                printf("\n 0. Atras \n");
                printf("\n Numero de MESA A CERRAR : ");
                scanf("%d", &mesaAccion);

                if (1 == unaMesa[mesaAccion - 1].flag) {
                    desocuparMesa(matrizMesa, CANT_MESA, mesaAccion);
                    cerrarUnaMesa(mesaAccion, unaMesa);

                } else if (mesaAccion != 0) {
                    printf("\n ( Esta mesa NO esta ocupada. Debe abrirla antes de cerrarla )\n");
                    Sleep(1500);
                }
                break;

            //Mostramos el historial de mesas cerradas
            case 5:
                mostrarHistorialMesasCerradas();
                break;
        }

        system("cls");
        system("color 0B"); //COLOR CELESTE

    } while (op != 0);
}

/*__________[ PRINTS MENU DEL MOZO ]________*/
void menuMOZO(char matrizMesa[][CANT_MESA]) {

    menuTitulo();
    gotoxy(7, 1);
    printf(" M O Z O    \n");
    simpleLineHori(1, 20, 2, 2);
    dibujoMesa(matrizMesa, CANT_MESA); //Dibujo de la mesa

    printf("\n\n 1. Abrir mesa \n");
    printf(" 2. Agregar PEDIDOS a una mesa\n");
    printf(" 3. Pedidos actuales\n");
    printf(" 4. Cerrar una mesa\n");
    printf(" 5. Ver historial de mesas cerradas\n");
    printf("\n 0. Volver \n");

    /*****   LINEAS DE LAS MESAS   *****/
    simpleLineHori(1, 24, 0, 7);
    simpleLineVert(1, 11, 24, 8);
    simpleLineHori(1, 24, 0, 19);
    simpleLineHori(1, 20, 1, 31);

    gotoxy(2, 30);
    printf("%c ", GUION);
}

/*_____________________________[ ABRIR UNA MESA ]___________________________*/
void mesaParaABRIR(char matrizMesa[][CANT_MESA], int abrir, Mesa unaMesa[]) {

    //Corroboramos el ingreso de una mesa existente entre el 1 y el 9
    if (abrir <= 0 ^ abrir > 9) {

        printf("[!] Esta mesa NO existe\n");

    } else {

        if (unaMesa[abrir - 1].flag == 0) {

            unaMesa[abrir - 1] = limpiarVariables();
            hacerPedido(abrir, unaMesa);
            menuTitulo();
            ocuparMESA(matrizMesa, CANT_MESA, abrir);

        } else if (unaMesa[abrir - 1].flag == 1) {

            printf("\n\n[!] La mesa ya esta ocupada\n\n");
            Sleep(1500);
        }
    }
}

/*_________________[ DIBUJO DEL SALON ]_______________*/
void dibujoMesa(char arrMesa[][CANT_MESA], int cant) {

    printf("\n\n\n      ( S A L O N ) \n");

    for (int i = 0; i < cant; i++) {

        printf("\n\n");
        for (int j = 0; j < cant; j++) {
            printf(" | %c |\t", arrMesa[i][j]);
        }

        printf("\n\n\n");
    }
}

/*______[ PARA CARGAR EL DIBUJO DEL SALON AL PRINCIPIO ]____*/
void cargarDibujoMesa(char arrMesa[][CANT_MESA], int cant) {

    int cantidad = 49;
    for (int i = 0; i < cant; i++) {

        for (int j = 0; j < cant; j++) {
            arrMesa[i][j] = (char)cantidad++; //Se cargan con numeros del 1 al 9
        }
    }
}

/*____________[ PARA REMPLAZAR LOS NUMEROS CON LAS LETRAS ]__________*/
void ocuparMESA(char arrMesa[][CANT_MESA], int cant, int mesaElegida) {

    char arrBiAux[CANT_MESA][CANT_MESA];
    cargarMatrizLETRAS(CANT_MESA, arrBiAux);

    char eleccion = (char)mesaElegida + 48;

    for (int i = 0; i < cant; i++) {

        for (int j = 0; j < cant; j++) {

            if (eleccion == arrMesa[i][j]) {

                arrMesa[i][j] = arrBiAux[i][j];  //Se remplaza el numero por la letra
            }
        }
    }
}

/*____________[ Cargar una matriz de LETRAS ( SE USO PARA HACER COMPARACIONES ) ]__________*/
void cargarMatrizLETRAS(int cant, char arrAUX[][CANT_MESA]) {

    int letras = 65;

    for (int e = 0; e < cant; e++) {

        for (int f = 0; f < cant; f++) {

            arrAUX[e][f] = letras++;  //Carga la Matriz de la "A HASTA I"
        }
    }
}

/*____________[ REEMPLAZAR LAS LETRAS POR EL NUMERO DE LA MESA - CUANDO SE DESOCUPA LA MESA ]__________*/
void desocuparMesa(char arrMesa[][CANT_MESA], int cant, int mesaElegida) {

    char arrAUX[CANT_MESA][CANT_MESA];
    cargarMatrizLETRAS(CANT_MESA, arrAUX); //Se carga la matriz para hacer comparaciones

    char eleccion = (char)mesaElegida + 64;

    for (int i = 0; i < cant; i++) {

        for (int j = 0; j < cant; j++) {

            if (eleccion == arrAUX[i][j]) {

                arrMesa[i][j] = (char)mesaElegida + 48; //Se remplaza la LETRA con el NUMERO
            }
        }
    }
}

/*______________[ PARA CERRAR UNA MESA ]____________*/
void cerrarUnaMesa(int cerrada, Mesa cerrarMesa[]) {

    FILE *historialMesas;
    historialMesas = fopen(FILE_HISTORIAL_MESAS, "ab");

    //Variables auxiliares
    int i = 0;
    Mesa auxMesa;
    auxMesa = cerrarMesa[cerrada - 1];

    if (historialMesas != NULL) {

        fwrite(&auxMesa, sizeof(Mesa), 1, historialMesas);
    }

    cobrarMesa(cerrada, cerrarMesa[cerrada - 1]); //Cobramos la mesa

    fclose(historialMesas);

    cerrarMesa[cerrada - 1] = limpiarVariables(); //Limpiamos las variables de la estructura
}

/*______________[ MOSTRAMOS EL HISTORIAL DE MESAS CERRADAS ]____________*/
void mostrarHistorialMesasCerradas() {

    FILE *historialMesa;
    historialMesa = fopen(FILE_HISTORIAL_MESAS, "rb");
    Mesa unaMesa;

    if (historialMesa != NULL) {

        while (fread(&unaMesa, sizeof(Mesa), 1, historialMesa) > 0) {

            pedidosMesa(unaMesa);
            Sleep(450);
        }

        fclose(historialMesa);
    } else {

        printf("\n [!] Todavia no hay mesas cerradas\n\n");
    }
    printf(" ... ");
    system("pause > nul");
    system("cls");
}

/*______________[ AGREGAMOS NUEVOS PEDIDOS A UNA MESA ABIERTA ]____________*/
void agregarNuevosPedidos(Mesa laMesa[], int agregar) {

    if (laMesa[agregar - 1].flag == 1) {

        hacerPedido(agregar, laMesa);
    } else {

        printf(" [!] Esta mesa no esta abierta\n");
        Sleep(900);
    }
}

/*__________________[ MOSTRAR LOS PEDIDOS CARGADOS EN LAS MESAS ]___________*/
void mostrarPedidosActuales(Mesa unaMesa[], int tam) {

    int x = 70;
    int y = 2;
    diglett(x ,y);
    gotoxy(5, 3);
    int flag = 0;
    printf("\n\n");

    for (int i = 0; i < tam; i++) {

        if (unaMesa[i].flag == 1) {

            pedidosMesa(unaMesa[i]);
            flag = 1;
            Sleep(450);
        }
    }
    if (flag == 1) {
        printf(" [!] Estas son todas las mesas ocupadas hasta el momento\n");
        system("pause > nul");
    }
}

/*_________________[ Se muestra el HISTORIAL DE MESAS CERRADAS ]_______________*/
/*_________________[ MOSTRAMOS TODOS LOS PEDIDOS CARGADOS POR EL MOZO ]_______________*/
void pedidosMesa(Mesa laMesa) {

    printf(" NUMERO DE MESA : %d\n\n", laMesa.numeroMesa);
    if (laMesa.consumos.cant_cubiertos > 0) {
        printf(" CANT CUBIERTOS : %d \n", laMesa.consumos.cant_cubiertos);
    }
    if (laMesa.consumos.cant_burger > 0) {
        printf(" CANT HAMBURGESAS : %d\n", laMesa.consumos.cant_burger);
    }
    if (laMesa.consumos.cant_pizza > 0) {
        printf(" CANT PIZZA : %d\n", laMesa.consumos.cant_pizza);
    }
    if (laMesa.consumos.cant_papas > 0) {
        printf(" CANT PAPAS : %d\n", laMesa.consumos.cant_papas);
    }
    if (laMesa.consumos.cant_agua > 0) {
        printf(" CANT AGUA : %d\n\n", laMesa.consumos.cant_agua);
    }
    if (laMesa.consumos.cant_soda > 0) {
        printf(" CANT AGUA CON GAS : %d\n", laMesa.consumos.cant_soda);
    }
    if (laMesa.consumos.cant_cerveza > 0) {
        printf(" CANT CERVEZA : %d\n", laMesa.consumos.cant_cerveza);
    }
    if (laMesa.consumos.cant_fernet > 0) {
        printf(" CANT FERNET : %d\n", laMesa.consumos.cant_fernet);
    }
    if (laMesa.consumos.cant_vino > 0) {
        printf(" CANT VINO : %d\n", laMesa.consumos.cant_vino);
    }
    if (laMesa.consumos.cant_cassata > 0) {
        printf(" CANT POSTRE CASSATA : %d\n", laMesa.consumos.cant_cassata);
    }
    if (laMesa.consumos.cant_mixFruta > 0) {
        printf(" CANT ENSALADA DE FRUTAS : %d\n", laMesa.consumos.cant_mixFruta);
    }
    if (laMesa.consumos.cant_donPedro > 0) {
        printf(" CANT POSTRE DON PEDRO : %d\n", laMesa.consumos.cant_donPedro);
    }
    printf("\n PRECIO TOTAL : $%.2f \n", laMesa.precioTotal);
    printf("______________________________________\n\n");
}

/*_____[ LIMPIEZA DE LAS VARIABLES ]___*/
Mesa limpiarVariables() {

    Mesa vaciarMesa;

    vaciarMesa.consumos.cant_cassata = 0;
    vaciarMesa.consumos.cant_donPedro = 0;
    vaciarMesa.consumos.cant_mixFruta = 0;
    vaciarMesa.consumos.cant_cerveza = 0;
    vaciarMesa.consumos.cant_vino = 0;
    vaciarMesa.consumos.cant_agua = 0;
    vaciarMesa.consumos.cant_soda = 0;
    vaciarMesa.consumos.cant_fernet = 0;
    vaciarMesa.consumos.cant_pizza = 0;
    vaciarMesa.consumos.cant_papas = 0;
    vaciarMesa.consumos.cant_burger = 0;
    vaciarMesa.consumos.cant_cubiertos = 0;
    vaciarMesa.precioTotal = 0;
    vaciarMesa.flag = 0;

    /*_____[ SE INICIALIZA EL PRECIO DE LOS PRODUCTOS  ]___*/

    //Cubierto
    vaciarMesa.cubierto = 50;

    //Comidas
    vaciarMesa.carta.comidas.burger = 380;
    vaciarMesa.carta.comidas.pizza = 210;
    vaciarMesa.carta.comidas.papas = 180;

    //Bebidas
    vaciarMesa.carta.bebidas.agua = 80;
    vaciarMesa.carta.bebidas.cerveza = 130;
    vaciarMesa.carta.bebidas.fernet = 130;
    vaciarMesa.carta.bebidas.vino = 150;
    vaciarMesa.carta.bebidas.soda = 80;

    //Postres
    vaciarMesa.carta.postres.cassata = 190;
    vaciarMesa.carta.postres.mixFruta = 140;
    vaciarMesa.carta.postres.donPedro = 190;

    return vaciarMesa;
}

/* _______________[ FUNCIONALIDAD DE LOS PEDIDOS ]_______________*/
void hacerPedido(int abrir, Mesa laMesa[]) {

    system("cls");
    laMesa[abrir - 1].numeroMesa = abrir;
    laMesa[abrir - 1].flag = 1;

    int op = 0;
    int cantidad = 0;
    int guardaPrecio;

    do {

        printf("\n");
        mostrarCarta();
        pedidosMesa(laMesa[abrir - 1]);

        printf(" %c  Opcion : ", FLECHA_DER);
        scanf("%d", &op);

        switch (op) {

            case 0:
                break;

            //Cubiertos
            case 1:
                printf(" Cantidad de CUBIERTOS : ");
                scanf("%d", &cantidad);

                if (laMesa[abrir - 1].consumos.cant_cubiertos >= 8) {

                    printf(" [!] En la mesa no entran mas personas ");
                    Sleep(3000);

                } else if (cantidad <= 8 && cantidad > 0) {

                    laMesa[abrir - 1].precioTotal += laMesa[abrir - 1].cubierto * cantidad;
                    laMesa[abrir - 1].consumos.cant_cubiertos += cantidad;

                } else if (cantidad > 8) {

                    printf(" [!] Numero maximo permitido de cubiertos: 8");
                    Sleep(2300);

                } else if (cantidad < 1) {
                    printf(" [!] El minimo permitido es de un cubierto");
                    Sleep(5000);
                }
                break;

            //Pizzas
            case 2:
                printf(" %c Ingrese la cantidad de PIZZAS: ", GUION);
                scanf("%d", &cantidad);

                if(cantidad >0 ){
                    laMesa[abrir - 1].precioTotal += laMesa[abrir - 1].carta.comidas.pizza * cantidad;
                    laMesa[abrir - 1].consumos.cant_pizza += cantidad;

                }else{
                    printf(" [!] Cantidad invalida ");
                    Sleep(300);
                }
                break;

            //Hamburguesas
            case 3:
                printf(" %c Ingrese la cantidad de HAMBURGUESAS: ", GUION);
                scanf("%d", &cantidad);

                if(cantidad >0 ){
                    laMesa[abrir - 1].precioTotal += laMesa[abrir - 1].carta.comidas.burger * cantidad;
                    laMesa[abrir - 1].consumos.cant_burger += cantidad;

                }else{
                    printf(" [!] Cantidad invalida ");
                    Sleep(300);
                }
                break;

            //Platos de papas
            case 4:
                printf(" %c Ingrese la cantidad de PLATOS DE PAPAS: ", GUION);
                scanf("%d", &cantidad);

                if(cantidad >0 ){
                    laMesa[abrir - 1].precioTotal += laMesa[abrir - 1].carta.comidas.papas * cantidad;
                    laMesa[abrir - 1].consumos.cant_papas += cantidad;

                }else{
                    printf(" [!] Cantidad invalida ");
                    Sleep(300);
                }
                break;

            //Botellas de agua
            case 5:
                printf(" %c Ingrese la cantidad de BOTELLAS DE AGUA: ", GUION);
                scanf("%d", &cantidad);

                if(cantidad >0 ){
                    laMesa[abrir - 1].precioTotal += laMesa[abrir - 1].carta.bebidas.agua * cantidad;
                    laMesa[abrir - 1].consumos.cant_agua += cantidad;

                }else{
                    printf(" [!] Cantidad invalida ");
                    Sleep(300);
                }
                break;

            //Botellas de soda
            case 6:
                printf(" %c Ingrese la cantidad de BOTELLAS DE AGUA CON GAS: ", GUION);
                scanf("%d", &cantidad);

                if(cantidad >0 ){
                    laMesa[abrir - 1].precioTotal += laMesa[abrir - 1].carta.bebidas.soda * cantidad;
                    laMesa[abrir - 1].consumos.cant_soda += cantidad;

                }else{
                    printf(" [!] Cantidad invalida ");
                    Sleep(300);
                }
                break;

            //Botellas de vino
            case 7:
                printf(" %c Ingrese la cantidad de BOTELLAS DE VINO: ", GUION);
                scanf("%d", &cantidad);

                if(cantidad >0 ){
                    laMesa[abrir - 1].precioTotal += laMesa[abrir - 1].carta.bebidas.vino * cantidad;
                    laMesa[abrir - 1].consumos.cant_vino += cantidad;

                }else{
                    printf(" [!] Cantidad invalida ");
                    Sleep(300);
                }
                break;

            //Vasos de fernet
            case 8:
                printf(" %c Ingrese la cantidad de VASOS DE FERNET: ", GUION);
                scanf("%d", &cantidad);

                if(cantidad >0 ){
                    laMesa[abrir - 1].precioTotal += laMesa[abrir - 1].carta.bebidas.fernet * cantidad;
                    laMesa[abrir - 1].consumos.cant_fernet += cantidad;

                }else{
                    printf(" [!] Cantidad invalida ");
                    Sleep(300);
                }
                break;

            //Vasos de cerveza
            case 9:
                printf(" %c Ingrese la cantidad de VASOS DE CERVEZA: ", GUION);
                scanf("%d", &cantidad);

                if(cantidad >0 ){
                    laMesa[abrir - 1].precioTotal += laMesa[abrir - 1].carta.bebidas.cerveza * cantidad;
                    laMesa[abrir - 1].consumos.cant_cerveza += cantidad;

                }else{
                    printf(" [!] Cantidad invalida ");
                    Sleep(300);
                }
                break;

            //Postre Cassata
            case 10:
                printf(" %c Ingrese la cantidad de Postres CASSATA: ", GUION);
                scanf("%d", &cantidad);

                if(cantidad >0 ){
                    laMesa[abrir - 1].precioTotal += laMesa[abrir - 1].carta.postres.cassata * cantidad;
                    laMesa[abrir - 1].consumos.cant_cassata += cantidad;

                }else{
                    printf(" [!] Cantidad invalida ");
                    Sleep(300);
                }
                break;

            //Don pedro
            case 11:
                printf(" %c Ingrese la cantidad de postres DON PEDRO: ", GUION);
                scanf("%d", &cantidad);

                if(cantidad >0 ){
                    laMesa[abrir - 1].precioTotal += laMesa[abrir - 1].carta.postres.donPedro * cantidad;
                    laMesa[abrir - 1].consumos.cant_donPedro += cantidad;

                }else{
                    printf(" [!] Cantidad invalida ");
                    Sleep(300);
                }
                break;

            //Ensalada de fruta
            case 12:
                printf(" %c Ingrese la cantidad de ENSALADAS DE FRUTA: ", GUION);
                scanf("%d", &cantidad);

                if(cantidad >0 ){

                    laMesa[abrir - 1].precioTotal +=laMesa[abrir - 1].carta.postres.mixFruta * cantidad;
                    laMesa[abrir - 1].consumos.cant_mixFruta += cantidad;

                }else{
                    printf(" [!] Cantidad invalida ");
                    Sleep(300);
                }
                break;
        }

        system("cls");

    } while (op > 0);
}

/* _______________[ LINEA HORIZONTAL ARRIBA - ESTETICA ]_______________*/
void lineaHorizontalArriba(int tam) {

    for (int i = 0; i < tam; i++) {
        if (i == 0) {
            printf("\t\t\t\t\t\t\t%c", 218);
        }
        if (i == tam -1) {
            printf("%c\n", 191);
        } else {
            printf("%c", HORI);
        }
    }
}

/* _______________[ LINEA HORIZONTAL ABAJO - ESTETICA ]_______________*/
void lineaHorizontalAbajo(int tam) {

    for (int i = 0; i < tam; i++) {
        if (i == 0) {
            printf("\t\t\t\t\t\t\t%c", 192);
        }
        if (i == tam -1) {
            printf("%c", 217);
        } else {
            printf("%c", HORI);
        }
    }
}

/*_______________________[  PRINT DE LA CARTA (Una obra de arte ♥) ]_________________________*/
void mostrarCarta() {

    system("color 0A"); //COLOR VERDE

    /*   Precios   */
    Mesa laMesa;
    laMesa = limpiarVariables();
    int tam = 35;
    int x = 1;
    int y = 3;

    bulbasaur(x, y); //Dibujo pokemon: Bulbasaur
    gotoxy(61, 1);

    printf("[        POKE BAR        ]       \n");

    lineaHorizontalArriba(tam);
    printf("\t\t\t\t\t\t\t%c                                  %c\n", VERT, VERT);
    printf("\t\t\t\t\t\t\t%c 0. Salir de la Carta             %c\n", VERT, VERT);
    printf("\t\t\t\t\t\t\t%c 1. Cantidad de Cubiertos %d c/u  %c\n", VERT, laMesa.cubierto, VERT);
    printf("\t\t\t\t\t\t\t%c                                  %c\n", VERT, VERT);
    printf("\t\t\t\t\t\t\t%c ----------- Comidas ----------   %c\n", VERT, VERT);
    printf("\t\t\t\t\t\t\t%c 2. Pizza  $%d c/u               %c\n", VERT, laMesa.carta.comidas.pizza,
           VERT);
    printf("\t\t\t\t\t\t\t%c 3. Burger  $%d c/u              %c\n", VERT, laMesa.carta.comidas.burger,
           VERT);
    printf("\t\t\t\t\t\t\t%c 4. Papas   $%d c/u              %c\n", VERT, laMesa.carta.comidas.papas,
           VERT);

    printf("\t\t\t\t\t\t\t%c                                  %c\n", VERT, VERT);
    printf("\t\t\t\t\t\t\t%c ----------- Bebidas ----------   %c\n", VERT, VERT);
    printf("\t\t\t\t\t\t\t%c 5. Agua    $%d c/u               %c\n", VERT, laMesa.carta.bebidas.agua,
           VERT);
    printf("\t\t\t\t\t\t\t%c 6. Agua con Gas $%d c/u          %c\n", VERT, laMesa.carta.bebidas.soda,
           VERT);
    printf("\t\t\t\t\t\t\t%c 7. Vino $%d c/u                 %c\n", VERT, laMesa.carta.bebidas.vino,
           VERT);
    printf("\t\t\t\t\t\t\t%c 8. Fernet $%d c/u               %c\n", VERT, laMesa.carta.bebidas.fernet,
           VERT);
    printf("\t\t\t\t\t\t\t%c 9. Cervezas $%d c/u             %c\n", VERT, laMesa.carta.bebidas.cerveza,
           VERT);
    printf("\t\t\t\t\t\t\t%c                                  %c\n", VERT, VERT);
    printf("\t\t\t\t\t\t\t%c ----------- Postres ------------ %c\n", VERT, VERT);
    printf("\t\t\t\t\t\t\t%c 10. Cassata $%d c/u             %c\n", VERT, laMesa.carta.postres.cassata,
           VERT);
    printf("\t\t\t\t\t\t\t%c 11. Don Pedro $%d c/u           %c\n", VERT, laMesa.carta.postres.donPedro,
           VERT);
    printf("\t\t\t\t\t\t\t%c 12. Ensalada de Fruta $%d c/u   %c\n", VERT, laMesa.carta.postres.mixFruta,
           VERT);
    lineaHorizontalAbajo(tam);

    printf("\n");
}

/*_______________________[  TRABAJO DEL CAJERO ]_________________________*/
void trabajoCajero(Pila *pilaReserva,Reserva reservas[]) {

    system("cls");
    system("color 0A"); //VERDE

    //Variables auxiliares
    int x = 80;
    int y = 3;
    int posicionReserva = 0;
    int op = 0;
    int numRes = 0;
    int i = 0;
    int j = 0;
    int flag = 0;
    int dineroActual = 0;

    do {

        psyduck(x,y); //Dibujo pokemon: Psyduck
        menuCajero();
        fflush(stdin);
        scanf("%d", &op);

        switch (op) {

            //Atender el telefono (Registrar una reserva)
            case 1:
                reservas[i] = pedirDatosCliente(*pilaReserva,x,y);  //Pedir Datos de la Reserva
                apilarReservas(reservas, pilaReserva, i);
                i++;
                break;

            //Ver una reserva en particular
            case 2:
                ordenarReservas(pilaReserva);
                mostrar(pilaReserva);

                if (!pilavacia(pilaReserva)) {
                    printf("\n Numero de RESERVA : ");  //Ver una reserva determinada
                    scanf("%d", &numRes);
                }

                flag = verificarEntrada(*pilaReserva, numRes);

                if (flag == 1) {
                    verLaReserva(reservas, numRes, i);
                    system("pause > nul");

                } else if (flag == 0) {
                    printf("\n [!] No existe ese numero de reserva \n");
                    Sleep(1000);
                }
                break;

            // Ver las ganancias actuales
            case 3:
                dineroActual = verGananciasActuales();
                printf("\n El dinero guardado hasta el momento es de : $%d ", dineroActual);
                Sleep(1000);
                break;
        }

        system("cls");

    } while (op != 0);
}

/*_______________________[  PRINT DEL MENU DEL CAJERO ]_________________________*/
void menuCajero() {

    menuTitulo();
    gotoxy(5, 3);

    printf(" C A J E R O      \n\n\n");
    simpleLineHori(1, 20, 2, 4);

    printf("\n\n\n\n 1. Atender el telefono (Reservar una Mesa)\n");
    printf(" 2. Ver una reserva\n");
    printf(" 3. Ver ganancias actuales \n\n");
    printf(" 0. Volver \n\n");

    simpleLineHori(1, 20, 1, 16);
    gotoxy(2, 15);
    printf(" > Opcion : ");
}

/*_______________________[  COBRAR UNA MESA ]_________________________*/
void cobrarMesa(int numMesa, Mesa cerrada) {

    system("cls");

    //Variables auxiliares
    float total = cerrada.precioTotal;
    char aplicar = 's';
    float descuento = 0;
    int dineroRecibido = 0;
    int x = 70;
    int y = 2;

    diglett(x, y); //Dibujo pokemon: Diglett
    gotoxy(5, 3);

    printf(" C A J E R O      \n\n\n");
    simpleLineHori(1, 20, 2, 4);
    printf("\n\n\n");
    pedidosMesa(cerrada);  // Mostrar el ticket
    printf("%c Desea aplicar un descuento ? (s / n) \n", PREGUNTA); //Preguntar si desea realizar un descuento
    printf("       . ");
    fflush(stdin);
    scanf("%c", &aplicar);
    aplicar = tolower(aplicar);

    //Si confirma la realización del descuento
    if(aplicar == 's'){
        do {
            printf("\n Ingrese %% de descuento : ");
            fflush(stdin);
            scanf("%f",&descuento);

        }while(descuento < 0 || descuento > 100); //Pongo limites de descuento entre 0% y 100%

        //Calculo de descuento
        descuento = total * (descuento / 100);
        total -= descuento;
    }

    printf("\n EL PRECIO TOTAL ES : $%.2f\n\n",total);

    //Ingreso el dinero con lo que pago el cliente
    do{
       printf(" Ingrese el dinero recibido por el cliente : $");
       fflush(stdin);
       scanf("%d", &dineroRecibido);

       if(dineroRecibido < total){
           printf("\n [!] El dinero recibido es INFERIOR al precio total\n");
       }

   } while (dineroRecibido<total);

    //El vuelto del cliente
    int vuelto = dineroRecibido - total;
    printf("\n El VUELTO al cliente es de : $%d \n", vuelto);

    guardarDinero(total);

    printf(" ... ");
    system("pause > nul");
}

/*_______________________[  GUARDO EL DINERO QUE INGRESA AL POKEBAR ]_________________________*/
void guardarDinero(int total) {

    FILE *fileDinero;

    if ( (fileDinero = fopen(F_HISTORIAL_DINERO,"ab") ) != NULL) {
        fwrite(&total,sizeof(int),1,fileDinero);
        fclose(fileDinero);

    }else{
        printf(" [!] El dinero no se guardo, NOS ROBARON !!!!!!! >:( \n");
    }
}

/*_______________________[  VER GANANCIAS ACTUALES ]_________________________*/
int verGananciasActuales() {

    FILE *dineroActual;

    //Variables auxiliares
    int aux = 0;
    int dinero = 0;

    if ((dineroActual = fopen(F_HISTORIAL_DINERO,"rb"))!= NULL){

        while(fread(&aux, sizeof(int), 1, dineroActual) > 0 ) {

            dinero += aux;
        }
        fclose(dineroActual);

    }

    return dinero;
}

/*_______________________[  PEDIR DATOS AL CLIENTE PARA REALIZAR UNA RESERVA ]_________________________*/
Reserva pedirDatosCliente(Pila a,int x,int y) {

    system("cls");
    psyduck(x, y); //Dibujo pokemon: Psyduck

    menuTitulo();

    gotoxy(5, 3);
    printf(" C A J E R O      \n\n\n");
    simpleLineHori(1,20,2,4);

    printf("\n\n  (  Ingrese los DATOS  )\n\n");

    Reserva persona;
    int flag = 0;
    persona.cantidadPersonas = 0;
    printf(" 1. NOMBRE : ");
    fflush(stdin);
    gets(persona.nombre);
    printf(" 2. TELEFONO : ");
    gets(persona.tel);

    for (int i = 0; i < strlen(persona.tel); i++) {
        if (persona.tel[i] == ' ') {
            persona.tel[i] = '-';
        }
    }

    do {
        printf(" 3. CANTIDAD DE PERSONAS : ");
        scanf("%d", &persona.cantidadPersonas);

        if (persona.cantidadPersonas < 1 || persona.cantidadPersonas > 8) {
            printf(" [!] Ingresaste una cantidad de personas NO APTAS para el tama%co de nuestras mesas \n", 164);
        }

    } while (persona.cantidadPersonas < 1 || persona.cantidadPersonas > 8);

    do {
        printf(" 4. Numero de Reserva :");
        scanf("%d", &persona.numeroReserva);
        if(persona.numeroReserva > 0){

            flag = verificarEntrada(a, persona.numeroReserva); //Verificar el numero de mesa esta ocupado o no

            if (flag == 1) {
                flag = 1;
                printf(" [!] Ese numero de reserva ya esta ocupado.\n Ingrese otro.\n");
            }

        }else{
            printf(" [!] Ingrese un numero positivo\n");
        }
    } while (flag != 0 || persona.numeroReserva <= 0);

    return persona;
}

/*________________[  MOSTRAR UNA RESERVA - PRINT ]_________________*/
void mostraUNAreserva(Reserva unaReserva) {

    printf("_________________________________\n\n");
    printf(" NOMBRE : %s \n", unaReserva.nombre);
    printf(" TELEFONO : %s \n", unaReserva.tel);
    printf(" CANTIDAD DE PERSONAS : %d \n", unaReserva.cantidadPersonas);
    printf(" NUMERO DE RESERVA : %d \n", unaReserva.numeroReserva);
    printf("_________________________________\n\n");

}

/*________________[  APILAR EN LA PILA LOS NUMEROS DE LAS RESERVAS ]_________________*/
void apilarReservas(Reserva persona[], Pila *reserva, int j) {

    int personaReserva = persona[j].numeroReserva;
    apilar(reserva, personaReserva);
}

/*________________[  MOSTRAR UNA RESERVA DETERMINADA ]_________________*/
void verLaReserva(Reserva persona[], int numReserva, int totalReser) {

    int i = 0;

    while (i < totalReser) {
        if (numReserva == persona[i].numeroReserva) {
            mostraUNAreserva(persona[i]);
        }
        i++;
    }
}

/*________________[  VERIFICAR SI EL NUMERO DE MESA ESTA OCUPADO O NO ]_________________*/
int verificarEntrada(Pila a, int numReserva) {

    int flag = 0;

    while (!pilavacia(&a)) {
        if (tope(&a) == numReserva) {  // Verificar si esta el numero de reserva
            desapilar(&a);
            flag = 1;

        } else {
            desapilar(&a);
        }
    }

    return flag;
}

/*________________[  ORDENAR LOS NUMEROS DE LAS RESERVAS ]_________________*/
void ordenarReservas(Pila *ordenar) {

    //Declaracion e inicializacion de pilas
    Pila aux, mayor, local;
    inicpila(&aux);
    inicpila(&mayor);
    inicpila(&local);

    while(!pilavacia(ordenar)){

        apilar(&mayor, desapilar(ordenar));

        while(!pilavacia(ordenar)){

            if(tope(&mayor) > tope(ordenar)){
                apilar(&aux, desapilar(ordenar));

            }else{
                apilar(&aux, desapilar(&mayor));
                apilar(&mayor, desapilar(ordenar));

            }
        }
        apilar(&local,desapilar(&mayor));

        while(!pilavacia(&aux)) {
            apilar(ordenar, desapilar(&aux));
        }
    }

    while(!pilavacia(&local)){
        apilar(ordenar, desapilar(&local));
    }
}
