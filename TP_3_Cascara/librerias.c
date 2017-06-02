#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "librerias.h"

int validaChar(char palabra[50])
{
    int retorno=1,tam,i;
    tam=strlen(palabra);
    for(i=0; i<tam; i++)
    {
        if(isalpha(palabra[i])==0&&isspace(palabra[i])==0)
        {
            printf("ERROR EL DATO INGRESADO NO ES VALIDO REINGRESE!!\n");
            retorno=0;
            break;
        }
    }
    return retorno;
}


int validaLink(char link[50],EMovie *movie,int tam)
{
    int i,retorno=1;

    for(i=0;i<tam;i++)
    {
        if(movie[i].estado==1)
        {
            if(strcmp(link,movie[i].link)==0)
            {
                printf("ERROR el link d ela pelicula ya esta registrado.\n");
                retorno=0;
            }
        }
    }
    return retorno;
}


