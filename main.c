#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"


int main (int argc, char *argv[])
{
    int opc=0;
    int cont=0;
    char nom_prod[10][30];
    float precio[10];
    char continuar='S';

    printf("\nPrograma de gestion de inventario\n");
    do
    {
        opc=menu();
        switch (opc)
        {
        case 1:
            cont = registro_producto(nom_prod, precio, cont);
            break;

        case 2:
            if (!ValidacionProdExist(cont)) break;
            printf("El precio total del inventario es: $%.2f\n", total_inventario( precio, cont));
            break;
        
        case 3:
            if (!ValidacionProdExist(cont)) break;
            Prod_carobarato(precio, nom_prod, cont);
            break;
        
        case 4:
            if (!ValidacionProdExist(cont)) break;
            printf("El promedio total del precio de los productos es: $%.2f\n", Promedio_producto(precio, cont));
            break;

        case 5:
            if (!ValidacionProdExist(cont)) break;
            buscar_producto(nom_prod, precio, cont);
            break;

        case 6:
            printf("\nSaliendo del Programa...\n");
            return 0;
            break;
        
        default:
            break;
        }

        continuar = ValidacionLetras("\nDesea regresar al menu (S/N): ");
    } while (continuar=='S'); 
    return 0;
}