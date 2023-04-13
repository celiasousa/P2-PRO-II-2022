/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Hugo Mato Cancela             LOGIN 1: hugo.matoc
 * AUTHOR 2: Celia Sousa Boo               LOGIN 2: celia.sousa
 * GROUP: 1.1
 * DATE: 31 / 03 / 22
 */

#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H

#include "types.h"
#include "bid_stack.h"
#include <stdbool.h>
#include <stddef.h>
#define LNULL NULL

typedef struct tItemL {
    tUserId seller;
    tProductId productId;
    tProductCategory productCategory;
    tProductPrice productPrice;
    tBidCounter bidCounter;
    tStack bidStack;
} tItemL;

typedef struct tNode* tPosL;

struct tNode{
    tItemL data;
    tPosL next;
};

typedef tPosL tList ;

bool createNode(tPosL *p);
/*{ Objetivo: Crear un nodo.
    Entradas: Un puntero.
    Salidas: Un nodo.
    Precondiciones: -
    Postcondiciones: -
}*/

tPosL findPosition(tList L,tItemL I);
/* Objetivo: Devuelve la posicion del Item en la lista (o LNULL si el Item no existe).
   Entradas: Una lista y un Item.
   Salidas: La posicion del Item en la lista.
   Precondiciones: La lista debe estar inicializada.
   Postcondiciones: -
*/

void createEmptyList (tList* L);
/*{ Objetivo: Crear una lista nueva sin ningún elemento.
    Entradas: Un puntero.
    Salidas: Una lista vacía.
    Precondiciones: -
    Postcondiciones: La lista queda inicializada y no contiene elementos.
}*/

bool isEmptyList (tList L);
/*{ Objetivo: Determinar si la lista está vacía.
    Entradas: Una lista.
    Salidas: Verdadero si la lista está vacía o Falso si no.
    Precondiciones: La lista debe estar inicializada.
    Postcondiciones:-
}*/

tPosL first(tList L);
/*{ Objetivo: Devolver la posición del primer elemento de la lista.
    Entradas: Una lista.
    Salidas: Posición del primer elemento.
    Precondiciones: La lista debe estar inicializada y no debe estar vacía.
    Postcondiciones:-
}*/
tPosL last(tList L);
/*{ Objetivo:Devolver la poscición del último elemento de la lista.
    Entradas: Una lista
    Salidas: La posición del último elemento.
    Precondiciones: La lista debe estar inicializada y no debe estar vacía.
    Postcondiciones:-
}*/

tPosL next(tPosL p, tList L);
/*{ Objetivo: Devolver la posición del elemento siguiente al de
        la posición indicada (o LNULL si la posición no tiene siguiente).
    Entradas: Una lista y una posición.
    Salidas: La posición del elemento siguiente al de la posición indicada (si es posible si no LNULL)
    Precondiciones: La lista debe estar inicializada y la posición debe ser válida.
    Postcondiciones:-
}*/

tPosL previous(tPosL p, tList L);
/*{ Objetivo: Devolver la posición en la lista del elemento anterior al de
        la posición indicada (o LNULL si la posición no tiene anterior).
    Entradas: Una posición y una lista.
    Salidas: La posición del elemento anterior al indicado en la lista (LNULL si no es posible)
    Precondiciones: La lista debe estar inicializada y la posición debe ser válida.
    Postcondiciones:-
}*/

bool insertItem(tItemL I, tList* L);
/*{ Objetivo: Insertar un elemento en la lista de forma ordenada por el campo productId.
    Entradas:Un item, una posición y una lista.
    Salidas: Un TRUE si el elemento fue insertado en la lista con éxito o un FALSE si no se pudo insertar.
    Precondiciones: La lista debe estar inicializada y la posición debe ser válida o bien nula (LNULL).
    Postcondiciones: Las posiciones de los elementos posteriores a la del elemento insertado pueden haber variado.
}*/

void deleteAtPosition(tPosL p, tList* L);
/*{ Objetivo: Elimina de la lista el elemento que ocupa la posición indicada.
    Entradas:Una posición y una lista.
    Salidas:La lista sin el elemento de la posición especificada.
    Precondiciones: La posición indicada es una posición válida en la lista y el producto en dicha posición tiene
        una pila de pujas vacía.
    Postcondiciones:Las posiciones de los elementos de la lista posteriores a la de la posición indicada pueden
        haber variado.
}*/
tItemL getItem(tPosL p, tList L);
/*{ Objetivo: Devuelve el contenido del elemenot de la lista que ocupa la posición indicada.
    Entradas:Un item, una posición y una lista.
    Salidas:EL item indicado.
    Precondiciones: La lista debe estar inicializada y la posición debe ser válida.
    Postcondiciones:-
}*/
void updateItem(tItemL I, tPosL p, tList* L);
/*{ Objetivo:Modifica el contenido del elemento situado en la posición indicada.
    Entradas:Un item, una posición y una lista.
    Salidas:La lista con el contenido del item modificado.
    Precondiciones: La lista debe estar inicializada y la posición indicada debe ser válida.
    Postcondiciones: El orden de los elementos de la lista no se ve modificado.
}*/
tPosL findItem(tProductId PI,tList L);
/*{ Objetivo: Devuelve la posición del primer elemento de la lista cuyo identificador de producto se corresponda
        con el indicado (o LNULL si no existe).
    Entradas: Un ID de producto y una lista.
    Salidas: La posición del primer elemento cuyo identificador de producto se corresponda con el indicado.
    Precondiciones: La lista debe estar inicializada.
    Postcondiciones:-
}*/

#endif
