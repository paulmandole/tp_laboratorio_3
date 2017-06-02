#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include<string.h>
#include<ctype.h>
#include<conio.h>

#define E 3



int main()
{
    char seguir='s',guardar;
    int opcion=0;

    EMovie movie[E];

    inicializarArray(movie,E);

    if(cargarArchivo(movie,E)==1)
    {
        printf("NO SE PUEDE ABRIR EL ARCHIVO!!\n");
    }
    else
    {
        printf("se cargo el archivo con exito!!\n");

    }

    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Generar pagina web\n");
        printf("4- Modificar datos\n");
        printf("5- gardar y Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                agregarPelicula(movie,E);
                system("pause");
                system("cls");
                break;
            case 2:
                borrarPelicula(movie,E);
                system("pause");
                system("cls");
                break;
            case 3:

               break;
            case 4:
                modificarMovie(movie,E);
                system("pause");
                system("cls");
                break;
            case 5:
                printf("\nGuardar cambios S/N ?: ");
				guardar = tolower(getche());
				if(guardar == 's')
				{
					if(guardarDatos(movie,E)==1)
					{
						printf("\nNo se pudo abrir el fichero\n");
					}
					else
					{
						printf("\nSe guardo la informacion con exito\n");
					}
				}

                seguir = 'n';
                break;
            default:
                printf("no ingreso una opcion correcta.");
                system("pause");
                system("cls");
                break;
        }
    }

    return 0;
}
