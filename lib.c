#include "lib.h"


void cargarprogrmandore(Sprogramador vprogramador[])
{
    int idprogramador[10]={1,2,3,4,5,6,7,8,9,10};
   int idcategoria[10]={1,2,3,1,3,2,2,1,3,2};
    char nombre[10][30]={"nicolas","eugenia","daniel","cristian","adriana","yulian","jose","pedro","juan","maria"};
    char apellido[10][30]={"gonzalez","rodriguez","rojas","rodriguez","zapata","rodriguez","fonseca","herrera","rozo","andrade"};
    int estado[10]={1,1,1,1,1,1,1,1,1,1};

    int i;
     for(i=0; i<10;i++)
    {
        vprogramador[i].idprogramador = idprogramador[i];
        vprogramador[i].idcategoria = idcategoria[i];
        vprogramador[i].estado=estado[i];
        strcpy(vprogramador[i].nombre,nombre[i]);
       strcpy(vprogramador[i].apellido,apellido[i]);

    }

}

void cargarcategorias(Scategoria vcategoria[])
{
   int idcategoria[5]={1,2,3};
    char describcion[3][30]={"junior","semisinior","siñior"};
    float pago[3]={100,200,500};


    int i;
     for(i=0; i<3;i++)
    {
        vcategoria[i].idcategoria = idcategoria[i];
        strcpy(vcategoria[i].descripcion, describcion[i]);
        vcategoria[i].pagoxhora = pago[i];

    }

}

void cargarproyectos(Sproyecto vproyecto[])
{
   int i;
   int idproyecto[10]={1,2,3,4,5,6,7,8,9,10};
    char describcion[10][30]={"ibm\0","hsbc\0","windows\0","windows\0","olx\0","mercadolire\0","google\0","mac\0","linux\0","peoplesoft\0"};
    int estado[10]={1,1,1,1,1,1,1,1,1,1};



     for(i=0; i<10;i++)
    {
        vproyecto[i].idproyecto =idproyecto[i];
        strcpy(vproyecto[i].nombre,describcion[i]);
        vproyecto[i].estado =estado[i];

    }

}


int esNumerico(char *str)
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}



int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}



void limpiarfgets(char cadena[])
{
if(cadena[strlen(cadena)-1]=='\n')
{
cadena[strlen(cadena)-1]='\0';
}
}
int obtenerEspacioLibrePro(Sproyecto Vproyecto[],int tamanioproyecto)
{
   int i;
    int indice=-1;
    for(i=0;i<tamanioproyecto;i++)
    {
        if(Vproyecto[i].estado==0)
        {
            indice=i;
            break;
        }
    }
return indice;
}

int obtenerEspacioLibre(Sprogramador Vprogramadores[],int tamanioprogramadores)
{
    int i;
    int indice=-1;
    for(i=0;i<tamanioprogramadores;i++)
    {
        if(Vprogramadores[i].estado==0)
        {
            indice=i;
            break;
        }
    }
return indice;
}


void getString(char mensaje[],char input[],int tamanio)
{
    printf("%s",mensaje);
    fgets(input,tamanio,stdin);
     limpiarfgets(input);
}
int getStringLetras(char mensaje[],char input[],int tamanio)
{
    char aux[tamanio];
    getString(mensaje,aux,tamanio);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
int getStringNumeros(char mensaje[],char input[],int tamanio)
{
    char aux[256];
    getString(mensaje,aux,tamanio);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
void getValidString(char requestMessage[],char errorMessage[], char input[],int tamaniimput)
{

    while(1)
    {
        if (!getStringLetras(requestMessage,input,tamaniimput))
        {
            printf ("%s\n",errorMessage);
            continue;
        }

        break;
    }

}
int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit,int tamanio)
{
    char auxStr[256];
    int auxInt;
    while(1)
    {
        if (!getStringNumeros(requestMessage,auxStr,tamanio))
        {
            printf ("%s\n",errorMessage);
            continue;

        }
        auxInt = atoi(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("El numero del debe ser mayor a %d y menor a %d\n",lowLimit,hiLimit);
            continue;

        }
        return auxInt;

    }


}
 int modificar(Sprogramador Vprogramador[],int tamanioprogramadores,int idmodificar)
{
    int i,opcion,respuesta,idcategoria,flag;
    char aux[TAMNOMBRES];
    respuesta='y';
    flag=0;
    for(i=0;i<tamanioprogramadores&&flag==0;i++)
    {
        if(Vprogramador[i].idprogramador==idmodificar)
        {
            if(Vprogramador[i].estado==1)
            {
                flag=1;
               while(respuesta=='y')
                {
                    printf("1nombre:%s\n2apellido:%s\n3categoria:%d\n4salir \n",Vprogramador[i].nombre,Vprogramador[i].apellido,Vprogramador[i].idcategoria);
                opcion=getValidInt("que opcion desea modificar?\n1categoriajunior\t2categoria semisinior \t3categoria siñior","debe ser una opcion numerica\n",1,4,3);
                switch(opcion)
                {
                    case 1:
                        getValidString("ingrese el nuevo nombre","el nombre debe ser solo letras",aux,TAMNOMBRES);
                        strcpy(Vprogramador[i].nombre,aux);
                        printf("nombre cambiado con exito\n");
                        system("pause");
                        system("cls");
                        break;
                         case 2:
                             getValidString("ingrese el nuevo apellido","el apellido debe ser solo letras",aux,TAMNOMBRES);
                             strcpy(Vprogramador[i].apellido,aux);
                            printf("apellido cambiado con exito\n");
                            system("pause");
                            system("cls");

                        break;
                         case 3:
                             idcategoria=getValidInt("ingrese el numero de categotria de 1a3","la categoria debe tener solo nuemros",1,3,4);
                            Vprogramador[i].idcategoria=idcategoria;
                              printf("categoria cambiada con exito\n");
                            system("pause");
                            system("cls");
                        break;
                         case 4:
                             respuesta='n';
                        break;

                         default:
                            break;
                    }
                }

            }

        }

    }
   return flag;



}
int altausuario(Sprogramador Vprogramador[],int tamanioprogramadores,int tamaniostring ,int *contadoridprogramador )
{



    char nombreaux[TAMNOMBRES];
    char apellidoaux[TAMNOMBRES];
    int espacio,idcategoria;

    espacio=obtenerEspacioLibre(Vprogramador,tamanioprogramadores);

    if(espacio!=-1)
       {
        getValidString("ingrese nombre\n","el nombre debe ser solo letras\n",nombreaux,tamaniostring);

        getValidString("ingrese apellid\n","el apellido debe ser solo letras\n",apellidoaux,tamaniostring);

        idcategoria=getValidInt("ingrese el id de categoria","error al introducir   el id de categoria",1,3,4);
        strcpy(Vprogramador[espacio].nombre,nombreaux);
        strcpy(Vprogramador[espacio].apellido,apellidoaux);

         Vprogramador[espacio].estado=1;
         Vprogramador[espacio].idcategoria=idcategoria;
         Vprogramador[espacio].idprogramador=*contadoridprogramador;

        (*contadoridprogramador)++;
       }


return espacio;
}
int validarIDestructura(Sprogramador Vprogramador[],int tamanioprogramadores,int idbuscar)
{
    int i;
    int retorno=-1;
    for(i=0;i<tamanioprogramadores;i++)
    {
       if(Vprogramador[i].estado==1)
       {
           if(Vprogramador[i].idprogramador==idbuscar)
           {
               retorno=i;
               break;
           }


       }


    }


return retorno;
}

int bajausuario(Sprogramador Vprogramador[],Sproyeprogrmador Vproyectoprogramador[], int tamanioprogramador,int tamanioproyectoprogramador,int ideliminar)
{
    int i,posicieliminar,retorno;
    posicieliminar=validarIDestructura(Vprogramador,tamanioprogramador,ideliminar);
    if(posicieliminar>=0)
    {
        Vprogramador[posicieliminar].estado=0;
        retorno=1;
        for(i=0;i<tamanioproyectoprogramador;i++)
        {
           if(Vproyectoprogramador[i].idprogramador==Vprogramador[posicieliminar].idprogramador)
           {
               if(Vproyectoprogramador[i].estado==1)
               {
                   Vproyectoprogramador[i].estado=0;

               }
           }

        }

    }
    else
    {
        printf("id no encontrado");
        retorno =0;
    }
return retorno;
}
int obtenerEspacioLibreP(Sproyeprogrmador Vproyectoprogramador[],int tamanioprogramadores)
{
    {
    int i;
    int indice=-1;
    for(i=0;i<tamanioprogramadores;i++)
    {
        if(Vproyectoprogramador[i].estado==0)
        {
            indice=i;
            break;
        }
    }
return indice;
}

}
int eleguirproyecto(Sproyecto Vproyecto[],int tamanioproyecto,int *idproyecto)
{

  int proyectoelegido=0;
  int contador2=1;
  int espacio,i;
   char proyectonombre[TAMNOMBRES];
   int posicionretornada=-1;
  while(proyectoelegido==0)
    {
        contador2=1;
        for(i=0;i<tamanioproyecto;i++)
        {
            if(Vproyecto[i].estado==1)
            {

              printf("%d %s\n",Vproyecto[i].idproyecto,Vproyecto[i].nombre);
              contador2++;
            }

        }
         printf("%d crear nuevo proyecto \n",contador2);


            proyectoelegido=getValidInt("escoga la opcion numerica\n","la opcion debe ser numerica\n",1,TAMPROYECTOS,7);
        if(contador2==proyectoelegido)
        {
            getString("ingrese el nombre del proyecto\n",proyectonombre,TAMNOMBRES);
            espacio=obtenerEspacioLibrePro(Vproyecto,tamanioproyecto);
            if(espacio>=0)
            {
                Vproyecto[espacio].estado=1;
               strcpy(Vproyecto[espacio].nombre,proyectonombre);
               Vproyecto[espacio].idproyecto=*idproyecto;
                *idproyecto=(*idproyecto)+1;




            }
            else
                {
                    printf("no hay mas espacio para proyecotos debe eliminar 1 o eligir uno\n");

                }
                proyectoelegido=0;
        }
        else
        {
            for(i=0;i<TAMPROYECTOS;i++)
            {
                if(Vproyecto[i].idproyecto==proyectoelegido)
                {
                    posicionretornada=i;


                    break;
                }

            }
            if(posicionretornada==-1)
            {
                printf("opcion incorreta escoja un proyecto\n");
                proyectoelegido=0;
            }
        }

    }
  return posicionretornada;
}
int asignarprogrmadorproyecto(Sprogramador Vprogramador[],Sproyecto Vproyecto[],Sproyeprogrmador Vproyectoprogramador[],Scategoria Vcategoria[],int tamanioprogramador,int tamanioproyecto,int tamanioproyectopregramador,int tamaniocategoria,int *contadorid,int *idproyecto)
{
    int i=0;
    int contador=0;
    int proyectoelgido;
    int espacio;
    int programadorelegido,horastrabajar;
    int espacioProgramadorelegido=-1;

   proyectoelgido=eleguirproyecto(Vproyecto,tamanioproyecto,idproyecto);





    for(i=0;i<tamanioprogramador;i++)
    {
        if(Vprogramador[i].estado==1)
        {
            contador++;
          printf("%d %s\n",Vprogramador[i].idprogramador,Vprogramador[i].nombre);
        }

    }

    programadorelegido=getValidInt("elija programador \n","tiene que ser solo numeros\n",1,tamanioprogramador,7);
    horastrabajar=getValidInt("elijala cantidad de horas que desea que trabaje\n","la cantidad de horas tiene que ser un dato numerico\n",1,1000,8);


    espacio=obtenerEspacioLibreP(Vproyectoprogramador,tamanioproyectopregramador);

      if(espacio!=-1)
       {

         for(i=0;i<tamanioprogramador;i++)
         {
              if(Vprogramador[i].idprogramador==programadorelegido)
              {
                  if(Vprogramador[i].estado==1)
                  {
                    espacioProgramadorelegido=i;
                    break;
                  }

              }
         }
         if(espacioProgramadorelegido!=-1)
         {


           if(buscarProyectoExistente(Vproyectoprogramador,tamanioproyectopregramador,Vprogramador[espacioProgramadorelegido].idprogramador,Vproyecto[proyectoelgido].idproyecto))
            {


            Vproyectoprogramador[*contadorid].estado=1;
            Vproyectoprogramador[*contadorid].horas=horastrabajar;
            Vproyectoprogramador[*contadorid].idprogramador=Vprogramador[espacioProgramadorelegido].idprogramador;
            Vproyectoprogramador[*contadorid].idproyecto=Vproyecto[proyectoelgido].idproyecto;



                for(i=0;i<tamaniocategoria;i++)
                {


                    if(Vprogramador[espacioProgramadorelegido].idcategoria==Vcategoria[i].idcategoria)
                    {
                      Vproyectoprogramador[*contadorid].sueldo=((float)horastrabajar)*(Vcategoria[i].pagoxhora);
                    }

                }
           *contadorid=(*contadorid)+1;
            }

                 else
            {

                espacio=-2;
            }

         }
         else
         {
           espacio=-3;
         }

       }



return espacio;

}


int buscarProyectoExistente(Sproyeprogrmador Vproyectoprogramador[],int tamanioproyectopregramador,int programadorelegido,int proyectoelgido)
{

    int i;
    int existe=1;

    for(i=0;i<tamanioproyectopregramador;i++)
    {
        if(Vproyectoprogramador[i].estado==1)
        {
            if(Vproyectoprogramador[i].idprogramador==programadorelegido&&Vproyectoprogramador[i].idproyecto==proyectoelgido)
            {
                existe=0;
                break;
            }


        }



    }

return existe;


}

void ordenarid(Sprogramador Vprogramador[],int tamanioprogramador)
{
int i,j;
Sprogramador aux;

for(j=0;j<tamanioprogramador;j++)
{
    if(Vprogramador[j].estado==1)
    {


        for(i=1+j;i<tamanioprogramador;i++)
            {

               if(Vprogramador[j].idprogramador>Vprogramador[i].idprogramador)
                  {
                      if(Vprogramador[i].estado==1)
                      {
                         aux=Vprogramador[i];
                      Vprogramador[i]=Vprogramador[j];
                      Vprogramador[j]=aux;
                      }

                  }

            }
    }
}
}

void imprimirprogrmadores(Sprogramador Vprogramador[],Sproyecto Vproyecto[],Sproyeprogrmador Vproyectoprogramador[],Scategoria Vcategoria[],int tamanioprogramador,int tamanioproyecto,int tamanioproyectopregramador,int tamaniocategoria)
{

   int i,j,k,l;

   ordenarid(Vprogramador,tamanioprogramador);





for(i=0;i<tamanioprogramador;i++)
{
    if(Vprogramador[i].estado==1)
        {
            printf(" id %d programador:%s %s categoria:",Vprogramador[i].idprogramador,Vprogramador[i].nombre,Vprogramador[i].apellido);
            for(j=0;j<tamaniocategoria;j++)
            {
                if(Vprogramador[i].idcategoria==Vcategoria[j].idcategoria)
                {
                    printf("%s\n",Vcategoria[j].descripcion);
                    break;
                }
            }
                for(k=0;k<tamanioproyectopregramador;k++)
                {
                    if(Vproyectoprogramador[k].estado==1)
                    {
                        if(Vprogramador[i].idprogramador==Vproyectoprogramador[k].idprogramador)
                        {
                            for(l=0;l<tamanioproyecto;l++)
                            {
                              if(Vproyectoprogramador[k].idproyecto==Vproyecto[l].idproyecto)
                              {
                                  if(Vproyecto[l].estado==1)
                                  {
                                   printf("%s\t suma a cobrar %f\n",Vproyecto[l].nombre,Vproyectoprogramador[k].sueldo);
                                  }

                              }
                            }

                        }
                    }


                }



        }

}



}
void imprimirproyectos(Sprogramador Vprogramador[],Sproyecto Vproyecto[],Sproyeprogrmador Vproyectoprogramador[],Scategoria Vcategoria[],int tamanioprogramador,int tamanioproyecto,int tamanioproyectopregramador,int tamaaniocatecoria)
{
int i,j,k,l,m;
int contadorcategoria[3]={0,0,0};
for(i=0;i<tamanioproyecto;i++)
{


  if(Vproyecto[i].estado==1)
  {
    for(j=0;j<tamaaniocatecoria;j++)
    {
      contadorcategoria[j]=0;
    }
   printf("%d\t%s\n",Vproyecto[i].idproyecto,Vproyecto[i].nombre);

    for(k=0;k<tamanioproyectopregramador;k++)
    {
       if(Vproyectoprogramador[k].estado==1)
       {
           if(Vproyecto[i].idproyecto==Vproyectoprogramador[k].idproyecto)
           {
               for(l=0;l<tamanioprogramador;l++)
               {
                   if(Vprogramador[l].estado==1)
                   {
                      if(Vproyectoprogramador[k].idprogramador==Vprogramador[l].idprogramador)
                      {
                          for(m=0;m<tamaaniocatecoria;m++)
                          {
                            if(Vprogramador[l].idcategoria==Vcategoria[m].idcategoria)
                            {
                                switch(Vcategoria[m].idcategoria)
                                {
                                case 1:
                                    contadorcategoria[0]=contadorcategoria[0]+1;
                                    break;
                                case 2:
                                    contadorcategoria[1]=contadorcategoria[1]+1;
                                    break;
                                case 3:
                                   contadorcategoria[2]=contadorcategoria[2]+1;
                                    break;
                                }
                            }
                          }

                      }
                   }
               }

           }
       }

    }
    for(l=0;l<tamaaniocatecoria;l++)
        {
        printf("%s:\t%d\n",Vcategoria[l].descripcion,contadorcategoria[l]);

        }


  }



}



}

void  listarprogramadoresproyectos(Sprogramador Vprogramador[],Sproyecto Vproyecto[],Sproyeprogrmador Vproyectoprogramador[],Scategoria Vcategoria[],int tamanioprogramador,int tamanioproyecto,int tamanioproyectopregramador,int tamaaniocatecoria)
{
int i,j,espacioelegido;
int idprogramadorElegido=0;
int flag=0;
   ordenarid(Vprogramador,tamanioprogramador);

   while(flag==0)
   {


        for(i=0;i<tamanioprogramador;i++)
        {
            if(Vprogramador[i].estado==1)
                {
                    printf("id:%d programador:%s %s \n",Vprogramador[i].idprogramador,Vprogramador[i].nombre,Vprogramador[i].apellido);
                }


        }
        idprogramadorElegido=getValidInt("elija al prgogramador\n","el  valor debe ser numerico",1,tamanioproyectopregramador,7);
        espacioelegido=validarIDestructura(Vprogramador,tamanioprogramador,idprogramadorElegido);

        if(espacioelegido==-1)
            {
                printf("no existe ese id\n");
            }
        else
        {
            flag=1;
        }
   }
flag=0;
   for(i=0;i<tamanioproyectopregramador;i++)
   {
       if(Vproyectoprogramador[i].estado==1)
       {
           if(Vprogramador[espacioelegido].idprogramador==Vproyectoprogramador[i].idprogramador)
           {
               for(j=0;j<tamanioproyecto;j++)
               {
                   if(Vproyecto[j].estado==1)
                   {
                      if(Vproyectoprogramador[i].idproyecto==Vproyecto[j].idproyecto)
                      {
                          printf("%s\n",Vproyecto[j].nombre);
                          flag=1;
                      }

                   }


               }

           }


       }

   }
    if(flag==0)
    {
        printf("programador sin proyectos\n");
    }

}

void proyectomasdemandante(Sprogramador Vprogramador[],Sproyecto Vproyecto[],Sproyeprogrmador Vproyectoprogramador[],Scategoria Vcategoria[],Smasdemante Vmasdemandante[],int tamanioprogramador,int tamanioproyecto,int tamanioproyectopregramador,int tamaaniocatecoria,int tmaniomasdemantente){
int i,k;

int maximacantidad=0;
//memset((void*)contador,sizeof(int)*tamanioproyecto,0);

for(i=0;i<tamanioproyecto;i++)
{
    if(Vproyecto[i].estado==1)
    {
        Vmasdemandante[i].idproyecto=Vproyecto[i].idproyecto;
        for(k=0;k<tamanioproyectopregramador;k++)
        {
            if(Vproyectoprogramador[k].estado==1)
            {
                if(Vproyecto[i].idproyecto==Vproyectoprogramador[k].idproyecto)
                {

                    Vmasdemandante[i].cantidad=(Vmasdemandante[i].cantidad)+1;
                }
            }
        }


    }
}
maximacantidad=Vmasdemandante[0].cantidad;
for(i=0;i<tamanioproyecto;i++)
{

   if(Vmasdemandante[i].cantidad>maximacantidad)
   {
       maximacantidad=Vmasdemandante[i].cantidad;
   }


}
if(maximacantidad!=0)
{
            for(i=0;i<tamanioproyecto;i++)
            {
                if(Vmasdemandante[i].cantidad==maximacantidad)
                {
                   for(k=0;k<tamanioproyecto;k++)
                   {
                       if(Vproyecto[k].idproyecto==Vmasdemandante[i].idproyecto)
                       {
                           if(Vproyecto[k].estado==1)
                           {
                               printf(" proycto  con mas demanda %s  con %d programadores trabajando\n",Vproyecto[k].nombre,maximacantidad);
                           }
                       }
                   }


                }


            }


    }
    else
    {
        printf("todos los proyectos esta sin progrmador\n");
    }

}

