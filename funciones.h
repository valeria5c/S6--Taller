#ifndef FUNCIONES_H
#define FUNCIONES_H

int menu();
int registro_producto(char nom_prod[][30], float precio[10], int cont);
void borrarSaltoLinea(char cadena[]);
char Mayuscula(char caracter);
float ValidacionNumeros(const char mensaje[], char nom_prod[]);
char ValidacionLetras(const char mensaje[]);
int ValidacionProdExist(int cont);
float total_inventario(float precio[], int cont);
void Prod_carobarato(float precio[], char nom_prod[][30], int cont);
float Promedio_producto(float precio[], int cont);
void buscar_producto(char nom_prod[][30], float precio[], int cont);

#endif
