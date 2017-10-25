#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char apellido[30];
    char nombres [40];
    int tipoCliente;             /// Prioridad 1:embarazada, 2:jubilado y 3:cliente com�n
    int medioPago;            /// 1:efectivo, 2:cr�dito y 3:todos
    int cantArticulos;            /// es el tiempo de ejecuci�n
    int tiempoEspera;     ///***    /// es el tiempo de respuesta
    int tiempoProcesado;  ///  ***     /// es el tiempo que ya fue procesado en la l�nea de caja
    int eliminado;        /// 1: eliminado, 0: activo

} persona;


void cambiarDatosArchivo(char nombre[]);
void cargarPersonasArchivo(char nombre[]);
void leerArchivoPersonas(char nombre[]);
void borrarPersonaArchivo(char nombre[], int id);


#endif // PERSONA_H_INCLUDED
