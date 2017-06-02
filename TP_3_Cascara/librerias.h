#ifndef LIBRERIAS_H_INCLUDED
#define LIBRERIAS_H_INCLUDED
#include "funciones.h"

//valida q sea char
int validaChar(char palabra[50]);
//calida q no se repita el link
int validaLink(char link[50],EMovie *movie,int tam);

#endif

