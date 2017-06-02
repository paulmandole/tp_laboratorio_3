#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char link[50];
    char linkImagen[50];
    int estado;
}EMovie;
/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
void agregarPelicula(EMovie *movie,int tam);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
void borrarPelicula(EMovie *movie,int tam);


void inicializarArray(EMovie *movie,int tam);

int cargarArchivo(EMovie *movie,int tam);

int guardarDatos(EMovie *movie,int tam);
void modificarMovie(EMovie *movie,int tam);
#endif // FUNCIONES_H_INCLUDED
