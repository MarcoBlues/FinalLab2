#ifndef ARREGLO_FILAS_H_INCLUDED
#define ARREGLO_FILAS_H_INCLUDED
#include "Fila.h"
#include "arbol_persona.h"
typedef struct
{
        int nro_de_caja;
        char nombreCajero[40];
        int tipo_pago; //  1 efectivo, 2 crédito o débito, 3 todos
        int abiertaOcerrada;
        char algoritmoPlanificacion[30];  // debe informar que tipo de alg. de planificación utiliza la caja
        Fila filita ;
} caja;

int agregarCaja(caja cajita[],int a); // crea una nueva caja en el arreglo
void abrirOcerrarCaja(caja aux[],int indice); // abre o cierra una caja a requerimiento (si hay clientes no puede cerrarse)
caja buscarCaja(int tipo_pago,caja cajita[],int indice); /// busca una caja de acuerdo a su tipo de pago y la retorna (si es que está abierta)
void mostrarCajasYFilas(caja cajita[]); // muestra la caja (sus datos) y toda la fila de clientes que esperan
void agregarClienteACaja(caja cajita[],int indice,persona aux); /// agrega un cliente a la caja de acuerdo al orden que plantea
void agregarClienteACajaEnTiempoDeterminado(caja cajita,nodo2 * cliente); ///el algoritmo de planificación que aplica la caja, siempre y cuando la caja está abierta
void atenderClientes(caja cajita); // atiende a los clientes de acuerdo al algoritmo de planificación que aplica la caja, calculando el tiempo de espera de cada cliente
int cajaConMenosCliente(int tipo_pago,caja cajita[8]);
#endif // ARREGLO_FILAS_H_INCLUDED
