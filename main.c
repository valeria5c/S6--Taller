#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"


int main (int argc, char *argv[])
{
    int opc=0;// Variable para almacenar la opción del menú
    int cont=0; // Contador de productos registrados
    char nom_prod[10][30]; // Arreglo para almacenar hasta 10 nombres de productos
    float precio[10]; // Arreglo para almacenar hasta 10 precios de productos
    char continuar='S'; // Variable para controlar si se repite el menú

    printf("\nPrograma de gestion de inventario\n");
    // Bucle principal del programa
    do
    {
        opc=menu(); // Mostrar menú y obtener opción del usuario
        switch (opc)
        {
        case 1:
            // Registrar productos
            cont = registro_producto(nom_prod, precio, cont);
            break;

        case 2:
            // Calcular el precio total del inventario
            if (!ValidacionProdExist(cont)) break;
            printf("El precio total del inventario es: $%.2f\n", total_inventario( precio, cont));
            break;
        
        case 3:
            // Mostrar el producto más caro y el más barato
            if (!ValidacionProdExist(cont)) break;
            Prod_carobarato(precio, nom_prod, cont);
            break;
        
        case 4:
            // Calcular el precio promedio de los productos
            if (!ValidacionProdExist(cont)) break;
            printf("El promedio total del precio de los productos es: $%.2f\n", Promedio_producto(precio, cont));
            break;

        case 5:
            // Buscar un producto por nombre
            if (!ValidacionProdExist(cont)) break;
            buscar_producto(nom_prod, precio, cont);
            break;

        case 6:
            // Salir del programa
            printf("\nSaliendo del Programa...\n");
            return 0;
            break;
        
        default:
            printf("Opcion Invalida");
            break;
        }

        // Preguntar si desea volver al menú
        continuar = ValidacionLetras("\nDesea regresar al menu (S/N): ");
    } while (continuar=='S'); 
    return 0;

}
