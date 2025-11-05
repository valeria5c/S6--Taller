#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

// Muestra el menú principal y devuelve la opción seleccionada
int menu()
{
    int opc;
    int valido;
    do{
        printf(" MENU\n");
        printf("1. Registrar los nombres y precios de los productos\n");
        printf("2. Calcular el precio total del inventario\n");
        printf("3. Encontrar el producto mas caro y el mas barato\n");
        printf("4. Calcular el precio promedio de todos los productos\n");
        printf("5. Buscar un producto por su nombre y mostrar su precio\n");
        printf("6. Salir del programa\n");
        printf("Seleccione una opcion >> ");
        valido = scanf("%d", &opc);
        //Validación (debe ser un número entre 1 y 6)
        if (valido!=1 || opc<1 || opc>6){
            printf("Opcion invalida. Intente nuevamente.\n");
            while (getchar() != '\n'); // Limpia el espacio de almacenamiento temporal
        }
    } while (valido != 1 || opc < 1 || opc > 6);

    return opc;
}

// Registra productos y precios, retorna el nuevo contador
int registro_producto(char nom_prod[][30], float precio[10], int cont){
    char continuar='S';
    do
    {
        printf("\nIngrese el nombre del producto %d\n", cont);
        fflush(stdin);
        fgets(nom_prod[cont],30,stdin);
        borrarSaltoLinea(nom_prod[cont]);
        precio[cont] = ValidacionNumeros("Ingrese el precio del producto %s\n", nom_prod[cont]);
        continuar = ValidacionLetras("Desea ingresar otro producto");
        cont++;
    } while (continuar=='S'&& cont<10);
    return cont;
}

// Elimina el salto de línea al final de una cadena
void borrarSaltoLinea(char cadena[]){
    int len=strlen(cadena) -1;
    cadena[len]='\0';
}

// Convierte un carácter a mayúscula
char Mayuscula(char caracter){
    return toupper(caracter);
}

// Valida que el número ingresado sea un float positivo
float ValidacionNumeros(const char mensaje[], char nom_prod[]){
    float numero;
    int valido;
    do {
        printf(mensaje, nom_prod);
        valido = scanf("%f", &numero);
        if (valido != 1 || numero < 0) {
            printf("Entrada invalida. Intente nuevamente.\n");
            while (getchar() != '\n');
        }
    } while (valido != 1 || numero < 0);
    return numero;
}

// Valida que la letra ingresada sea 'S' o 'N'
char ValidacionLetras(const char mensaje[]){
    char letra;
    int valido;
    do {
        printf("%s (S/N): ", mensaje);
        valido = scanf(" %c", &letra);
        letra = Mayuscula(letra);
        if (valido != 1 || (letra != 'S' && letra != 'N')) {
            printf("Entrada invalida. Ingrese S o N.\n");
            while (getchar() != '\n');
        }
    } while (letra != 'S' && letra != 'N');
    return letra;
}

// Verifica si hay productos registrados
int ValidacionProdExist(int cont){
    if (cont == 0) {
    printf("\nDebe registrar al menos un producto antes de usar esta opcion.\n");
    return 0;
    }
    return 1;
}

// Calcula el precio total del inventario
float total_inventario(float precio[], int cont){
    float total=0;
    for (int i = 0; i < cont; i++)
    {
        total+=precio[i];
    }
    return total;
}

// Muestra el producto más caro y el más barato
void Prod_carobarato(float precio[], char nom_prod[][30], int cont){
    float mas_caro=precio[0];
    float mas_barato=precio[0];
    int indiceaux_caro=0;
    int indiceaux_barato=0;

    for (int i = 1; i < cont; i++)
    {
        if (precio[i]>mas_caro)
        {
            mas_caro=precio[i];
            indiceaux_caro=i;
        }else if (precio[i]<mas_barato)
        {
            mas_barato=precio[i];
            indiceaux_barato=i;
        }
    }

    printf("Producto mas caro: %s $%.2f\n", nom_prod[indiceaux_caro], mas_caro);
    printf("Producto mas barato: %s $%.2f\n", nom_prod[indiceaux_barato], mas_barato);
    
}

// Calcula el precio promedio de los productos
float Promedio_producto(float precio[], int cont){
    if (cont == 0) {
        printf("No hay productos registrados.\n");
        return 0;
    }
    float promedio = total_inventario(precio, cont) / cont;
    return promedio;
}

// Busca un producto por nombre y muestra su precio
void buscar_producto(char nom_prod[][30], float precio[], int cont){
    char continuar;
    char prod_buscado[30];
    do
    {
        printf("\nIngrese el nombre del producto que desea buscar\n");
        fflush(stdin);
        fgets(prod_buscado,30,stdin);
        borrarSaltoLinea(prod_buscado);
        int encontrado = 0;
        for (int i = 0; i < cont; i++)
        {
            if (strcasecmp(prod_buscado, nom_prod[i]) == 0)
            {
                printf("El precio de %s es: $%.2f\n", nom_prod[i], precio[i]);
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            printf("Producto no encontrado.\n");
        }
        continuar = ValidacionLetras("Desea buscar otro producto");
        fflush(stdin);
    } while (continuar=='S');

}



