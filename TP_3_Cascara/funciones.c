#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
#include "funciones.h"
#include "librerias.h"

void inicializarArray(EMovie *movie,int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        movie[i].estado=0;

    }
}

int cargarArchivo(EMovie *movie,int tam)
{
    FILE *f;
    int retorno=0,flag=0;

    f=fopen("bin.dat","rb");
    if(f==NULL)
    {
        f=fopen("bin.dat","wr");
        if(f==NULL)
        {
            retorno=1;
        }
        flag=1;
    }
    if(flag==0)
    {
        fread(movie,sizeof(EMovie),tam,f);
    }
    fclose(f);
    return retorno;
}

void agregarPelicula(EMovie *movie,int tam)
{
    int i,flag=0,retorno1,retorno;


    for(i=0;i<tam;i++)
    {
        if(movie[i].estado==0)
        {
            do
            {
                printf("ingrese el titulo de la pelicula: ");
                fflush(stdin);
                gets(movie[i].titulo);
                retorno=validaChar(movie[i].titulo);
            }while(retorno==0);
            do
            {
                printf("ingrese el genero: ");
                fflush(stdin);
                gets(movie[i].genero);
                retorno=validaChar(movie[i].genero);
            }while(retorno==0);
            do
            {
                printf("ingrese la descripcion de la pelicula: ");
                fflush(stdin);
                gets(movie[i].descripcion);
                retorno=validaChar(movie[i].descripcion);
            }while(retorno==0);
            do
            {
                printf("ingrese la duracion de la pelicula: ");
                scanf("%d",&movie[i].duracion);
            }while(movie[i].duracion<=0);
            do
            {
                printf("ingrese puntaje de la pelicula entre 1 y 10: ");
                scanf("%d",&movie[i].puntaje);
            }while(movie[i].puntaje<0||movie[i].puntaje>10);

            do
            {
                printf("ingrese el linck del al pelicula: ");
                fflush(stdin);
                gets(movie[i].link);
                retorno1=validaLink(movie[i].link,movie,tam);

            }while(retorno1==0);

            printf("ingrese el link de la imagen: ");
            fflush(stdin);
            gets(movie[i].linkImagen);
            movie[i].estado=1;
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("no se pudo guardar la pelicula no ahy espacio\n");
    }

}

void borrarPelicula(EMovie *movie,int tam)
{
    int i,flag=0;
    char link[50];
    printf("ingrese el linck de la pelicula a dar de baja: ");
    fflush(stdin);
    gets(link);

    for(i=0;i<tam;i++)
    {
        if(movie[i].estado==1)
        {
            if(strcmp(movie[i].link,link)==0)
            {
                movie[i].estado=0;
                flag=1;
                printf("la pelicula a sido borrada.\n");
                break;
            }
        }

    }
    if(flag==0)
    {
        printf("el link ingresado no esta registrado.\n");
    }
}
int guardarDatos(EMovie *movie,int tam)
{
   	FILE *f;
   	int retorno=0;

		f=fopen("bin.dat","wb");
		if(f == NULL)
		{
			retorno=1;
		}

	fwrite(movie,sizeof(EMovie),tam,f);

	fclose(f);
	return retorno;
}

void modificarMovie(EMovie *movie,int tam)
{
    int i,opcion,flag=0;
    char linck[50],salir='s';

    printf("ingrese el linck de la pelicula a modificar: ");
    fflush(stdin);
    gets(linck);

    for(i=0;i<tam;i++)
    {
        if(movie[i].estado==1)
        {
            if(strcmp(linck,movie[i].link)==0)
            {
                do
                {
                    printf("que desea modificar: ");
                    printf("1- Titulo\n");
                    printf("2- Descripcion\n");
                    printf("3- Puntaje\n");
                    printf("4- Duracion\n");
                    printf("5- Descripcion\n");
                    printf("6- Link imagen\n");
                    scanf("%d",&opcion);
                    switch(opcion)
                    {
                        case 1:
                        do
                        {
                            printf("ingrese el titulo de la pelicula: ");
                            fflush(stdin);
                            gets(movie[i].titulo);
                            retorno=validaChar(movie[i].titulo);
                        }while(retorno==0);
                            break;
                        case 2:
                        do
                        {
                            printf("ingrese la descripcion de la pelicula: ");
                            fflush(stdin);
                            gets(movie[i].descripcion);
                            retorno=validaChar(movie[i].descripcion);
                        }while(retorno==0);
                            break;
                        case 3:
                            do
                            {
                                printf("ingrese puntaje de la pelicula entre 1 y 10: ");
                                scanf("%d",&movie[i].puntaje);
                            }while(movie[i].puntaje<0||movie[i].puntaje>10);
                            break;
                        case 4:
                            do
                            {
                                printf("ingrese la duracion de la pelicula: ");
                                scanf("%d",&movie[i].duracion);
                            }while(movie[i].duracion<=0);
                            break;
                        case 5:
                            do
                            {
                                printf("ingrese la descripcion de la pelicula: ");
                                fflush(stdin);
                                gets(movie[i].descripcion);
                                retorno=validaChar(movie[i].descripcion);
                            }while(retorno==0);
                            break;
                        case 6:
                            printf("ingrese el link de la imagen: ");
                            fflush(stdin);
                            gets(movie[i].linkImagen);
                            break;
                        default:
                            printf("no ingreso una opcion correcta.\n");
                            break;
                    }
                }while(salir=='n');

            }
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("ERROR no se a encontrado el link ingresado.\n");
    }
}

