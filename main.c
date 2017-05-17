#include "lib.h"

int main()
{

    Scategoria Vcategoria[TAMANIOCATEGORIA];
    Sproyecto Vproyecto[TAMPROYECTOS];
    Sprogramador Vprogramador[TAMPROGRAMADORES];
    Sproyeprogrmador Vproyectoprogramador[TAMPROYXPROGRAMADOE];
    Smasdemante Vmasdemandante[TAMPROYECTOS];

    int contadorIdprogramador=11;//debido a los proyectos harcodeados
    int contadorIdproyecto=11;//debido a los proyectos harcodeados
    int espacioproyectoprogram=0;
    int respuesta='y';
    int i;
    int idusuario,estado,ideliminar,opcion;




inicializarestados(Vprogramador,Vproyecto,Vproyectoprogramador,Vmasdemandante,TAMPROGRAMADORES,TAMPROYECTOS,TAMPROYXPROGRAMADOE,TAMPROYECTOS);


    cargarcategorias(Vcategoria);//harcodeadas
    cargarproyectos(Vproyecto);
    cargarprogrmandore(Vprogramador);
   do
    {
        printf("1- alta  de programadores\n");
        printf("2- modificardatos del programador\n");
        printf("3- baja del programador\n");
        printf("4- asignar programador a proyecto\n");
        printf("5- listado de programadores\n");
        printf("6- listado de todos los proyectos\n");
        printf("7- listar proyectos de programador " "\n");
        printf("8 proyecto demandante " "\n");
        printf("9- Salir\n");
        fflush(stdin);
        opcion=getValidInt("escoga una opcion\n","error al obtener la opcion elija un numero de 1 a 19",1,9,4);
    switch(opcion)
    {
        case 1:
            if(altausuario(Vprogramador,TAMPROGRAMADORES,TAMNOMBRES,&contadorIdprogramador)==-1)
            {
                printf("no hay espacio para mas usuarios nuevos debe eliminar uno\n");
                system("pause");
                system("cls");
            }
            else
                {
                printf("alta de usuario agregado con exito\n");
                system("pause");
                system("cls");

                }

        break;
        case 2:

         idusuario=getValidInt("ingrese el id del programador","el id debe ser solo numeros sin letras",1,TAMPROGRAMADORES+1,4);
         if(modificar(Vprogramador,TAMPROGRAMADORES,idusuario))
         {
            printf("usuario modificadon con exito\n");
            system("pause");
            system("cls");
         }
         else
         {
            printf("el id ingresado no existe intentelo de nuevo\n");
            system("pause");
            system("cls");
         }


        break;
        case 3:
            ideliminar=getValidInt("ingrese el id del programador que desa eliminar","el id debe ser solo numeros sin letras",1,TAMPROGRAMADORES+1,4);
            estado=bajausuario(Vprogramador,Vproyectoprogramador,TAMPROGRAMADORES,TAMPROYXPROGRAMADOE,ideliminar);
            if(estado>0)
            {
                printf("programador %s eliminado correctamente\n",Vprogramador[estado].nombre);
                system("pause");
                system("cls");
            }
            else
            {
                printf("usuaario no encontrado en la base de datos\n");
                system("pause");
                system("cls");

            }


        break;
        case 4:
            estado=asignarprogrmadorproyecto(Vprogramador,Vproyecto,Vproyectoprogramador,Vcategoria,TAMPROGRAMADORES,TAMPROYECTOS,TAMPROYXPROGRAMADOE,TAMANIOCATEGORIA,&espacioproyectoprogram,&contadorIdproyecto);
            if(estado>=0)
            {
                printf("programador asignado correctamente al proyecto\n ");
                system("pause");
                system("cls");
            }
             else if(estado==-1)
            {
                printf(" no es posible asignarle mas proyectos a programadores\n");
                system("pause");
                system("cls");
            }
            else if(estado==-2)
            {
                printf(" este  programado ya fue asignado  ese proyecto\n");
                system("pause");
                system("cls");
            }
            else if(estado==-3)
            {
                printf(" error programador no  existe\n");
                system("pause");
                system("cls");

            }

        break;
        case 5:
           imprimirprogrmadores(Vprogramador,Vproyecto,Vproyectoprogramador,Vcategoria,TAMPROGRAMADORES,TAMPROYECTOS,TAMPROYXPROGRAMADOE,TAMANIOCATEGORIA);
        break;
        case 6:
            imprimirproyectos(Vprogramador,Vproyecto,Vproyectoprogramador,Vcategoria,TAMPROGRAMADORES,TAMPROYECTOS,TAMPROYXPROGRAMADOE,TAMANIOCATEGORIA);

        break;
        case 7:

            listarprogramadoresproyectos(Vprogramador,Vproyecto,Vproyectoprogramador,Vcategoria,TAMPROGRAMADORES,TAMPROYECTOS,TAMPROYXPROGRAMADOE,TAMANIOCATEGORIA);
        break;
        case 8:
            proyectomasdemandante(Vprogramador,Vproyecto,Vproyectoprogramador,Vcategoria,Vmasdemandante,TAMPROGRAMADORES,TAMPROYECTOS,(TAMPROGRAMADORES*TAMPROYECTOS),TAMANIOCATEGORIA,TAMPROYECTOS);
        break;
        case 9:
               respuesta='n';
        break;

        default:
        break;
    }

    }
    while(respuesta=='y');




}


