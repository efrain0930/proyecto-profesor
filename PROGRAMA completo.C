
/*----------------------------------------------------------------
|  Autor:       efrain nuñez            Matricula:                |
|  Fecha:15/12/2023                               Versi�n: 		  |
|-----------------------------------------------------------------|
|  Descripci�n del Programa:control de los datos de los vehiculos|
|                                                                 |
| ----------------------------------------------------------------*/
// Incluir E/S y Librer�as Standard
#include <>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Estructura para almacenar los datos del usuario
struct Usuario {
    char nombre[50];
    char contrasena[50];
};

// Prototipos de funciones.
void registrarUsuario();
void iniciarSesion();
void cambiarContrasena();
void guardarDatos(struct Usuario usuario);
void cargarDatos(struct Usuario *usuario);
void mostrarMenu();
void altas(); //Función para registrar  los vehiculos 
void chasis(); //Función para buscar los vehiculos  por numero de chasis 
void bus_nombre(); //Función para buscar vehiculo por palabra clave 
void ord_nombre(); //Función para consultar a todos los vehiculos ordenados alfabéticamente
char nombre[3][20],numero[3][6],precio[3][6],hor[3][6]; //Variables de cada vehiculo
int y=1; //Bandera indicadora de que no han ingresado vehiculo  (cuando está en 1)
// Programa Principal
int main() {
    int opcion;

    do {
        mostrarMenu();
        printf("Ingrese la opcion deseada: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                registrarUsuario();
                break;
            case 2:
                iniciarSesion();
                break;
            case 3:
                cambiarContrasena();
                break;
            case 4:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
        }
    } while (opcion != 4);

    return 0;
}

void mostrarMenu() {
    printf("\n--- MENU ---\n");
    printf("1. Registrar usuario\n");
    printf("2. Iniciar sesion\n");
    printf("3. Cambiar contrasena\n");
    printf("4. Salir\n");
}

void registrarUsuario() {
    struct Usuario nuevoUsuario;

    printf("Ingrese el nombre de usuario: ");
    scanf("%s", nuevoUsuario.nombre);

    printf("Ingrese la contrasena: ");
    scanf("%s", nuevoUsuario.contrasena);

    guardarDatos(nuevoUsuario);
    printf("Usuario registrado exitosamente.\n");
}

void iniciarSesion() {
    struct Usuario usuarioExistente;
    cargarDatos(&usuarioExistente);

    char nombreIngresado[50];
    char contrasenaIngresada[50];
    char opcion; //Variable que guardara la opción seleccionada

    printf("Ingrese el nombre de usuario: ");
    scanf("%s", nombreIngresado);

    printf("Ingrese la contrasena: ");
    scanf("%s", contrasenaIngresada);

    if (strcmp(usuarioExistente.nombre, nombreIngresado) == 0 &&
        strcmp(usuarioExistente.contrasena, contrasenaIngresada) == 0) {
       do{ //Hacer...
		system("cls"); //Limpiamos pantalla y desplegamos menú
		printf("\n----------------------------\nBienvenido usuario\n\n");
		printf("A - registros: agregar vehiculos  r\n");
		printf("B - Consultas generales\n");
		printf("C - Consultas por matriculas\n");
		printf("D - Consultas por nombres\n");
		printf("E - Salir\n\n");
		printf("Selecciona una opcion: ");
		scanf("%s",&opcion); //Guardamos la opción seleccionada por el usuario
	
		//Mandamos a llamar a la función que el usuario selecciono
		switch(opcion){ 
			case 'A':
			case 'a':
				altas();
			break;
		
			case 'b':
			case 'B':
				ord_nombre();
			break;
		
			case 'c':
			case 'C':
				chasis();
			break;
		
			case 'd':
			case 'D':
				bus_nombre();
			break;
		
			case 'e':
			case 'E': //Opción para salir del programa
				printf("Saliendo del programa \n");			
			break;
		
			default: //Opción que no está disponible en el menú
				printf("Opcion no valida");
			break;
		}	
	}while(opcion!='e' && opcion!='E'); 
	//Hacer mientras el usuario no selecciona la opción de salir...
	

  } else {
        printf("Nombre de usuario o contrasena incorrectos.\n");
    }
}

void cambiarContrasena() {
    struct Usuario usuarioExistente;
    cargarDatos(&usuarioExistente);

    char nuevaContrasena[50];

    printf("Ingrese la nueva contrasena: ");
    scanf("%s", nuevaContrasena);

    strcpy(usuarioExistente.contrasena, nuevaContrasena);

    guardarDatos(usuarioExistente);
    printf("Contrasena cambiada exitosamente.\n");
}

void guardarDatos(struct Usuario usuario) {
    FILE *archivo = fopen("/C:/Users/Steve/Desktop/proyecto final  carrosdatos.txt", "w");

    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    fprintf(archivo, "%s %s", usuario.nombre, usuario.contrasena);

    fclose(archivo);
}

void cargarDatos(struct Usuario *usuario) {
    FILE *archivo = fopen("C:/Users/Steve/Desktop/proyecto final  carros/datos.txt", "r");

    if (archivo == NULL) {
        // Si el archivo no existe, inicializamos los datos con cadenas vacías
        strcpy(usuario->nombre, "");
        strcpy(usuario->contrasena, "");
        return;
    }

    fscanf(archivo, "%s %s", usuario->nombre, usuario->contrasena);

    fclose(archivo);
}
void altas() {
    int x;
    system("cls");

    if (y == 1) {
        for (x = 0; x < 3; x++) {
            while (getchar() != '\n')
                ;

            printf("Ingrese el nombre clave de vehiculo: ");
            gets(nombre[x]);
            printf("Ingrese el numero de chasis del vehiculo: ");
            scanf("%s", &numero[x]);
            printf("Ingrese el costo del vehiculo: ");
            scanf("%s", &precio[x]);
            printf("Ingrese las horas de uso del vehiculo: ");
            scanf("%s", &hor[x]);
            system("cls");
        }
        y = 2;
    } else {
        printf("El local esta saturado de vehiculos\n");
        system("PAUSE");
    }
}

void chasis() {
    int p, pos = -1;
    char buscar[6];
    system("cls");

    if (y == 1)
        printf("Primero debes reguistrar algunos veiculos\n");
    else {
        printf("Cual es el numero de chasis del vehiculo que buscas: ");
        while (getchar() != '\n')
            ;
        gets(buscar);

        for (p = 0; p < 3; p++) {
            if (strcmpi(numero[p], buscar) == 0) {
                pos = p;
            }
        }

        if (pos == -1)
            printf("Numero de chasis no encontrado\n");
        else
            printf("Nombre clave: %s\nNumero de chasis: %s\nPrecio: %s\nHoras de uso: %s\n", nombre[pos], numero[pos], precio[pos], hor[pos]);
    }
    system("PAUSE");
}

void bus_nombre() {
    char buscar_nombre[20];
    int q, pe = -1;
    system("cls");

    if (y == 1)
        printf("Primero debes reguistrar algunos vehiculos\n");
    else {
        printf("Cual es el nombre clave: ");
        while (getchar() != '\n')
            ;
        gets(buscar_nombre);

        for (q = 0; q < 3; q++) {
            if (strcmpi(nombre[q], buscar_nombre) == 0)
                pe = q;
        }
        if (pe == -1)
            printf("Vehiculo no encontrado\n");
        else
            printf("Nombre clave: %s\nNumero de chasis: %s\nPrecio: %s\nHoras de uso: %s\n", nombre[pe], numero[pe], precio[pe], hor[pe]);
    }
    system("PAUSE");
}

void ord_nombre() {
    int k, j;
    char aux[20], auxb[20], auxc[20], auxd[20];
    system("cls");

    if (y == 1)
        printf("Primero tienes que reguistrar algunos vehiculos\n");
    else {
        for (k = 0; k < 3; k++)
            for (j = 0; j < 3 - k; j++) {
                if (strcmp(nombre[j], nombre[j - 1]) < 0) {
                    strcpy(aux, nombre[j]);
                    strcpy(nombre[j], nombre[j - 1]);
                    strcpy(nombre[j - 1], aux);
                    strcpy(auxb, numero[j]);
                    strcpy(numero[j], numero[j - 1]);
                    strcpy(numero[j - 1], auxb);
                    strcpy(auxc, precio[j]);
                    strcpy(precio[j], precio[j - 1]);
                    strcpy(precio[j - 1], auxc);
                    strcpy(auxd, hor[j]);
                    strcpy(hor[j], hor[j - 1]);
                    strcpy(hor[j - 1], auxd);
                }
            }

        system("cls");
        printf("CONSULTAS GENERALES\n-----------\n");
        for (k = 0; k < 3; k++) {
            printf("Nombre clave: %s\nNumero de chasis: %s\nPrecio: %s\nHoras de uso: %s\n-------\n", nombre[k], numero[k], precio[k], hor[k]);
        }
    }
    system("PAUSE");
}

void guardar_vehiculos() {
    FILE *archivo = fopen("C:/Users/Steve/Desktop/proyecto final  carrosvehiculos.txt", "w");

    if (archivo == NULL) {
        printf("Error al abrir el archivo para escritura.\n");
        return;
    }

    for (int i = 0; i < 3; i++) {
        fprintf(archivo, "%s %s %s %s\n", nombre[i], numero[i], precio[i], hor[i]);
    }

    fclose(archivo);
}

void cargar_vehiculos() {
    FILE *archivo=fopen("C:/Users/Steve/Desktop/proyecto final  carrosvehiculos.txt", "r");

    if (archivo == NULL) {
        printf("No se encontró el archivo de vehiculos. Iniciando con vehiculos vacios.\n");
        return;
    }

    for (int i = 0; i < 3; i++) {
        if (fscanf(archivo, "%s %s %s %s", nombre[i], numero[i], precio[i], hor[i]) != 4) {
            printf("Error al leer el archivo de vehiculos. Iniciando con vehiculos vacios.\n");
            break;
        }
    }

    fclose(archivo);
}


