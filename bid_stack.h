/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Hugo Mato Cancela             LOGIN 1: hugo.matoc
 * AUTHOR 2: Celia Sousa Boo               LOGIN 2: celia.sousa
 * GROUP: 1.1
 * DATE: 31 / 03 / 22
 */

#ifndef BID_STACK_H
#define BID_STACK_H

#include "types.h"
#include <stdbool.h>

#define SMAX 25
#define SNULL -1

typedef struct{
    tUserId bidder;
    tProductPrice productPrice;
}tItemS;
typedef int tPosS;
typedef struct{
    tItemS data[SMAX];
    tPosS top;
} tStack;

void createEmptyStack(tStack* stack);
/*{ Objetivo: Crear una pila vacia.
    Entradas: Un puntero.
    Salidas: Una pila vacia.
    Precondiciones: -
    Postcondiciones: La pila no tiene elementos.
}*/

bool isEmptyStack(tStack stack);
/*{ Objetivo: Determinar si una pila esta vacia o no.
    Entradas: Una pila.
    Salidas: True si esta vacia, False si no esta vacia.
    Precondiciones: Una pila inicializada.
    Postcondiciones: -
}*/

bool push (tItemS d, tStack* stack);
/*{ Objetivo: Insertar un elemento en la cima de la pila.
    Entradas: Un item y una pila.
    Salidas: True si el elemento fue apilado y false en caso contrario.
    Precondiciones: Una pila inicializada.
    Postcondiciones: -
}*/

void pop(tStack* stack);
/*{ Objetivo: Elimina de la pila el elemento situado en la cima.
    Entradas: Una pila.
    Salidas: La pila sin el elemento que estaba situado en la cima.
    Precondiciones: La pila esta inicializada y no esta vacia.
    Postcondiciones: -
}*/

tItemS peek(tStack stack);
/*{ Objetivo: Recuperar el elemento situado en la cima de la pila sin eliminarlo.
    Entradas: Una pila.
    Salidas: Elemento situado en la cima de la pila
    Precondiciones: La pila esta inicializada y no esta vacia.
    Postcondiciones: -
}*/

#endif
