/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Hugo Mato Cancela             LOGIN 1: hugo.matoc
 * AUTHOR 2: Celia Sousa Boo               LOGIN 2: celia.sousa
 * GROUP: 1.1
 * DATE: 31 / 03 / 22
 */

/*
 Nombre de las variables:
 p = posicion       tPosL
 L = lista          tList
 I = Item           tItemL
 PI = ProductId     tProductId
*/

#include "product_list.h"
#include <string.h>
#include <malloc.h>

// crea un nodo
bool createNode(tPosL *p){
    *p=malloc(sizeof(struct tNode));
    return *p!=LNULL;
}
//Devuelve la posicion del item en la lista
tPosL findPosition(tList L,tItemL I){
    tPosL p;
    p=L;
    while((p->next!=LNULL)&&(strcmp(p->next->data.productId,I.productId)<0))
        p=p->next;
    return p;
}

// crea una lista vacía
void createEmptyList (tList* L){
    *L=LNULL;
}

//comprueba si una lista está vacía
bool isEmptyList (tList L){
    return L==LNULL;
}

//devuelve la posición del primer elemento de la lista
tPosL first(tList L){
    return L;
}

//devuelve la posición del último elemento de la lista
tPosL last(tList L){
    tPosL q;
    for(q=L; q->next != LNULL; q=q->next);
    return q;
}

//devuelve la posición del siguiente elemento de la lista
tPosL next(tPosL p, tList L){
    return(p->next);
}

//devuelve la posición del anterior elemento de la lista
tPosL previous(tPosL p, tList L){
    tPosL q;
    //el primer elemento no tiene anterior
    if(L==p)
        return LNULL;
    else {
        for(q=L; q->next != p; q=q->next);
        return q;
    }
}

//permite insertar un item en la lista
bool insertItem(tItemL I, tList* L){
    tPosL p, q;
    p=LNULL;
    if (!createNode(&q))
        return false;
    else{
        q->data=I;
        q->next=LNULL;
        if (*L==LNULL)
            *L=q;
        else if (strcmp(I.productId,(*L)->data.productId)<0){
            q->next=*L;
            *L=q;
        } else {
            p=findPosition(*L, I);
            q->next=p->next;
            p->next=q;
        }
        return true;
    }//else
}//insertItem

//elimina un elemento
void deleteAtPosition(tPosL p, tList* L){
    tPosL q;
    //primera posicion
    if (*L==p) {
        *L = p->next;
    }
    //ultima posicion
    else if (p->next==LNULL) {
        for(q = *L; q->next != p; q = q->next);
        q->next=LNULL;
    }
    //eliminar una posicion intermedia cualquiera
    else {
        q=p->next;
        p->data=q->data;
        p->next=q->next;
        p = q;
    }
    free(p);
}

//devuelve el contenido del elemenot de la lista que ocupa la posición indicada.
tItemL getItem(tPosL p, tList L){
    return (p->data);
}

//actualiza la información de un item
void updateItem(tItemL I, tPosL p, tList* L){
    p->data=I;
}

//busca un item en base a su productId
tPosL findItem(tProductId PI,tList L){
    tPosL p;
    for (p=L; (p != LNULL) && (strcmp(p->data.productId,PI)<0); p=p->next);
    if ((p != LNULL) && (strcmp(p->data.productId,PI)==0))
        return p;
    else
        return LNULL;

}

