
/*________[ Struct Alimentos y Bebidas ]____________*/

/* Cantidades    */
typedef struct {
    int cant_cassata;
    int cant_donPedro;
    int cant_mixFruta;
    int cant_cerveza;
    int cant_vino;
    int cant_agua;
    int cant_soda;
    int cant_fernet;
    int cant_pizza;
    int cant_papas;
    int cant_burger;
    int cant_cubiertos;
} CantConsumos;
/*    Alimentos   */
typedef struct {
    int cassata;
    int donPedro;
    int mixFruta;
} Postres;
typedef struct {
    int cerveza;
    int vino;
    int agua;
    int soda;
    int fernet;
} Bebidas;
typedef struct {
    int pizza;
    int papas;
    int burger;
} Comidas;
typedef struct {
    Bebidas bebidas;
    Postres postres;
    Comidas comidas;
} Carta;
/*_____________[ CONTANDO LOS DIAS ]____________*/
typedef struct {
    int dia;
    int meses;
} Dias;
/*_____________[ Struct Reservar Mesa ]____________*/
typedef struct {
    char nombre[60];
    char tel[30];
    int cantidadPersonas;
    int numeroReserva;

} Reserva;
/*-____________[ Struct MESA ]______________*/
typedef struct {
    Carta carta;

    int cubierto;  // Precio
    float precioTotal;
    int numeroMesa;
    int flag;
    CantConsumos consumos;

} Mesa;
/*________[   Struct Datos Empleado ]__________*/
typedef struct {
    char nombre[50];
    int edad;
    int dni;
    char calle[30];
    int legajo;

} dataEmpleado;
/*    Cajero    */
typedef struct {
    dataEmpleado datos;
    float sueldo;

} Cajero;
/*     Mozo      */
typedef struct {
    dataEmpleado datos;
    float sueldo;

} Mozo;
typedef struct {
    Cajero cajero;
    Mozo mozo;

} Empleados;
/*----------------------  FIN DE LAS ESTRUCTURAS   --------------------*/
