#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "persona.h"

void cargarPersonasArchivo(char nombre[])
{
FILE * archi = fopen(nombre,"wb");
persona aux;
int i =1;
char letra = 's';
    if(!archi)
        archi = fopen(nombre,"wb");
    while(i < 40)
    {
        printf("\n______%d______\n",i);
       /* printf("Ingrese id: ");
        fflush(stdin);
        scanf("%d",&aux.id);*/

        aux.id = i++;

        printf("Ingrese nombre: ");
        fflush(stdin);
        scanf("%s",&aux.nombres);

        printf("Ingrese apellido: ");
        fflush(stdin);
        scanf("%s",&aux.apellido);


        srand(time(NULL));  /// FUNCIONES QUE CREE PARA HACER LA CARGA MAS DINAMICA NO TOCAR!!!
        int pagoCliente = rand() % 3 -0+1;
        int CantArti = rand() % 30 - 0+1;
        int tipoCliente = rand() % 3 -0 +1;
        aux.medioPago = pagoCliente;
        aux.cantArticulos = CantArti;

        printf("Ingrese tipo de cliente: ");
        fflush(stdin);
        scanf("%d",&aux.tipoCliente);
/*
        printf("Ingrese medio de pago: ");
        fflush(stdin);
        scanf("%d",&aux.medioPago);

        printf("Ingrese la cantidad de articulos: ");
        fflush(stdin);
        scanf("%d",&aux.cantArticulos);
*/
        aux.eliminado = 0;
        aux.tiempoEspera = 0;
        aux.tiempoProcesado = 0;

        fwrite(&aux,1,sizeof(persona),archi);

/*
        printf("Seguis?");
        fflush(stdin);
        scanf("%c",&letra);
        printf("\n________________________________\n");*/
    }
    fclose(archi);

}
void mostrar1Persona(persona aux)
{

    printf("\n_________________________________\n");
    printf("Id: % d\n",aux.id);
    printf("Nombres: %s \n",aux.nombres);
    printf("Apellido: %s \n",aux.apellido);
    printf("Cantidad de articulos: %d\n",aux.cantArticulos);
    printf("Medio de pago: %d\n",aux.medioPago);
    printf("Tipo de cliente: %d\n",aux.tipoCliente);
}
void leerArchivoPersonas(char nombre[])
{
    persona aux;
    FILE * archi = fopen(nombre,"rb");
    if(archi)
    {
        while(fread(&aux,1,sizeof(persona),archi)>0)
        {
            mostrar1Persona(aux);
        }
    }
    fclose(archi);
}
void cambiarDatosArchivo(char nombre[])///aCambiar parametro que que sacar no dejar en la funcion /// FUNCION PARA CAMBIAR EL ID DEL PRIMER ELEMENTO QUE QUEDO EN 0 por 1024
{
    persona aux;
    int aCambiar =0;
    int r =0;                                                       /// utilizo para multiplicar por el tamaño del tipo de variable en este caso "persona" para ubicar la posicion
    FILE * archi = fopen(nombre,"r+b");

    if(archi)
    {
        while(fread(&aux,1,sizeof(persona),archi) > 0)                      /// RECORRE EL ARCHIVO
        {
                if(aux.id == 0)
                {

                                             ///LO CAMBIA
                fseek(archi,r*sizeof(persona),0);                                    /// se pone en la posicion a cambiar
                fwrite(&aux,1,sizeof(persona),archi);                                                /// lo escribe en el archivo
                r++;                                                                /// aumento para saber que parte del archivo estoy
                fseek(archi,r*sizeof(persona),0);
                break; /// se posiciona en la posicion siguiente con el r++;
            }
        }
    }
    fclose(archi);
}
void borrarPersonaArchivo(char nombre[], int id)
{
    persona aux;
    FILE * archi = fopen(nombre,"r+b");
    FILE * nuevoArchi = fopen("ArchiParaBorrar","wb");
    if(archi)
    {
        while(fread(&aux,1,sizeof(persona),archi))
        {
            if(aux.eliminado == 0)
            {
                fwrite(&aux,1,sizeof(persona),nuevoArchi);
            }
        }
    }
    fclose(archi);
    fclose(nuevoArchi);

    archi = fopen(nombre,"wb");
    nuevoArchi = fopen("ArchiParaBorrar","r+b");

     while(fread(&aux,1,sizeof(persona),nuevoArchi))
    {
        fwrite(&aux,1,sizeof(persona),archi);
    }

    fclose(archi);
    fclose(nuevoArchi);
}

persona agregar1Persona() /// AGREGAA
{
        persona aux;

        printf("Ingrese id: ");
        fflush(stdin);
        scanf("%d",&aux.id);

        printf("Ingrese nombre: ");
        fflush(stdin);
        scanf("%s",&aux.nombres);

        printf("Ingrese apellido: ");
        fflush(stdin);
        scanf("%s",&aux.apellido);

        printf("Ingrese tipo de cliente: ");
        fflush(stdin);
        scanf("%d",&aux.tipoCliente);

        printf("Ingrese medio de pago: ");
        fflush(stdin);
        scanf("%d",&aux.medioPago);

        printf("Ingrese la cantidad de articulos: ");
        fflush(stdin);
        scanf("%d",&aux.cantArticulos);

        aux.eliminado = 0;
        aux.tiempoEspera = 0;
        aux.tiempoProcesado = 0;

        return aux;
}

