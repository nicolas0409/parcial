#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

#define TAMPROGRAMADORES 50
#define TAMPROYECTOS 1000
#define TAMNOMBRES  40
#define TAMANIOCATEGORIA 3


typedef struct
{
    int idcategoria;
    char descripcion[TAMNOMBRES];
    float pagoxhora;


}Scategoria;
typedef struct
{
    int estado;
    int idproyecto;
    char nombre[TAMNOMBRES];

}Sproyecto;

typedef struct
{
    int idprogramador;
    int idcategoria;
    char nombre[TAMNOMBRES];
    char apellido[TAMNOMBRES];
    int estado;



}Sprogramador;

typedef struct
{
    int idproyecto;
    int idprogramador;
    int horas;
    int estado;
    float sueldo;
}Sproyeprogrmador;




/*
int getInt();
float getFloat();
char getChar();
void limpiarfgets(char cadena[]);




int esNumerico(char *str) ;
int esTelefono(char *str);

int esSoloLetras(char *str);
int esNumericoFlotante(char str[]);

int buscaridstructura(Susuario Vusuarios[],int tamaniostructura ,int idusuario);
int obtenerEspacioLibre(Susuario lista[],int tamanio);
int obtenerEspacioLibreArticulos(Sarticulos articulos[],int tamanio);
int validarIDestructura(Susuario Vusuarios[],int tamaniostructura,int idbuscar);
void getString(char mensaje[],char input[],int tamanio);
int getStringLetras(char mensaje[],char input[],int tamanio);
int getStringNumeros(char mensaje[],char input[],int tamanioimput);
int getStringNumerosFlotantes(char mensaje[],char input[]);


*/



void cargarprogrmandore(Sprogramador vprogramador[]);///////////////////
/** \brief  carga harcodeada de categorias
 *
 * \param vcategoria[] Scategoria
 * \return void
 *
 */
void cargarcategorias(Scategoria vcategoria[]);
/** \brief  carga harcodeada de proyectos
 *
 * \param vproyecto[] Sproyecto
 * \return void
 *
 */
void cargarproyectos(Sproyecto vproyecto[]);
/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */

int esSoloLetras(char str[]);



/** \brief  verifica si un valor es numerico
 *
 * \param str char* string a analizar
 * \return int retorna 1 si si lo es 0 si no
 *
 */
int esNumerico(char *str);

/** \brief solicita un texto al usuario
 *
 * \param cadena[] char array donde guarda el texto
 * \return void
 *
 */
void limpiarfgets(char cadena[]);

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[],int tamanio);


/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumeros(char mensaje[],char input[],int tamanio);



/** \brief
 *
 * \param requestMessage[] char mensaje para  informar al  usuario que debe ingresar
 * \param errorMessage[] char  mensaje que muesta si ocurre un erro
 * \param lowLimit int      limites maximos  y minimos del valor entero
 * \param hiLimit int
 * \param tamanioimput int      tamaño maximo del string donde se cargara el numero
 * \return int         reotrna el entero  escrito por el usuario
 *
 */
int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit,int tamanioimput);


/** \brief  obtiene el primer espacio libre para asignar el  progtramador
 *
 * \param Vprogramadores[] Sprogramador estructura en la cual busca el espacio libre
 * \param tamanioprogramadores int  tamanio maximo de la estructura
 * \return int retorna -1 si no encuentra espasio o   retorna el espacio en el cual asignar
 *
 */
int obtenerEspacioLibre(Sprogramador Vprogramadores[],int tamanioprogramadores);

int obtenerEspacioLibreP(Sproyeprogrmador Vproyectoprogramador[],int tamanioprogramadores);

int obtenerEspacioLibrePro(Sproyecto Vproyecto[],int tamanioproyecto);

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[],int tamanio);


/**
 * \brief Solicita un string
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargará el texto ingresado
 * \return -
 *
 */


 void getValidString(char requestMessage[],char errorMessage[], char input[],int tamanio);



 /** \brief  modifica los datos de algun programador
  *
  * \param Vprogramador[] Sprogramador  es donde estan el vector de estructuras d eprogramadores
  * \param tamanioprogramadores int el tamanio maximo  de la estructura
  * \param idmodificar int es el id del programador a modificar
  * \return int retorna 0 si no puede modificar porque el id ingresado no existe o 1 si se logro modificar ocn exito
  *
  */
 int modificar(Sprogramador Vprogramador[],int tamanioprogramadores,int idmodificar);


/** \brief  da el alta a un programador en el vector de Vprogramadores
 *
 * \param Vprogramador[] Sprogramador vector de estructuras donde se guardaran los datos
 * \param tamanioprogramadores int  tamanio maximo de la estructura
 * \param tamaniostring int       tamanio del string
 * \param contadoridprogramador int*   id del programador nuevo
 * \return int
 *
 */
int altausuario(Sprogramador Vprogramador[],int tamanioprogramadores,int tamaniostring ,int *contadoridprogramador );



/** \brief  busca el id  para eliminar
 *
 * \param Vprogramador[] Sprogramador estructura en la cual busca el id
 * \param tamanioprogramadores int tamanio  de  la estructura de vectores
 * \param idbuscar int id el cual  va a buscar
 * \return int devuelve 0 si no encuentre nada o mayor que 0 si encuentra el id
 *
 */
int validarIDestructura(Sprogramador Vprogramador[],int tamanioprogramadores,int idbuscar);

/** \brief  da de baja a un usuario con el id del usuario
 *
 * \param Vprogramador[] Sprogramador estructura donde busca al usuario
 * \param Vproyectoprogramador  estructura donde elimina al programador asignado a un proyecto
 * \param tamanioprogramador int tmaanio maximo de la estructura programado
 * \param tamanioproyectoprogramador int  tamanio maximo de la estructura  proyectosprogramador
 * \param ideliminar int  id el cual va a eliminar
 * \return int
 *
 */
int bajausuario(Sprogramador Vprogramador[],Sproyeprogrmador Vproyectoprogramador[], int tamanioprogramador,int tamanioproyectoprogramador,int ideliminar);

int buscarProyectoExistente(Sproyeprogrmador Vproyectoprogramador[],int tamanioproyectopregramador,int programadorelegido,int proyectoelgido);
int asignarprogrmadorproyecto(Sprogramador Vprogramador[],Sproyecto Vproyecto[],Sproyeprogrmador Vproyectoprogramador[],Scategoria Vcategoria[],int tamanioprogramador,int tamanioproyecto,int tamanioproyectopregramador,int tamaniocategoria,int *contador,int *idproyecto);

int imprimirprogrmadores(Sprogramador Vprogramador[],Sproyecto Vproyecto[],Sproyeprogrmador Vproyectoprogramador[],Scategoria Vcategoria[],int tamanioprogramador,int tamanioproyecto,int tamanioproyectopregramador,int tamaaniocatecoria);

int eleguirproyecto(Sproyecto Vproyecto[],int tamanioproyecto,int *idproyecto);

void ordenarid(Sprogramador Vprogramador[],int tamanioprogramador);

void imprimirproyectos(Sprogramador Vprogramador[],Sproyecto Vproyecto[],Sproyeprogrmador Vproyectoprogramador[],Scategoria Vcategoria[],int tamanioprogramador,int tamanioproyecto,int tamanioproyectopregramador,int tamaaniocatecoria);

void  listarprogramadoresproyectos(Sprogramador Vprogramador[],Sproyecto Vproyecto[],Sproyeprogrmador Vproyectoprogramador[],Scategoria Vcategoria[],int tamanioprogramador,int tamanioproyecto,int tamanioproyectopregramador,int tamaaniocatecoria);


 void proyectomasdemandante(Sprogramador Vprogramador[],Sproyecto Vproyecto[],Sproyeprogrmador Vproyectoprogramador[],Scategoria Vcategoria[],int tamanioprogramador,int tamanioproyecto,int tamanioproyectopregramador,int tamaaniocatecoria);

#endif // LIB_H_INCLUDED
