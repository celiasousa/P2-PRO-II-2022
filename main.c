/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Hugo Mato Cancela             LOGIN 1: hugo.matoc
 * AUTHOR 2: Celia Sousa Boo               LOGIN 2: celia.sousa
 * GROUP: 1.1
 * DATE: 31 / 03 / 22
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

#define MAX_BUFFER 255

#include "bid_stack.h"
#include "product_list.h"

tProductCategory strToCategory(char* str) {
    if (strcmp(str, "book") == 0){
        return book;
    }
    else return painting;
}
/*{ Objetivo: Cambiar de string a category
    Entradas: Un string
    Salidas: Category
    Precondiciones: Introducir una categoria existente
    Postcondiciones: -
}*/

const char* categoryToStr(tProductCategory category){
    if (category == book){
        return "book";
    }
    return "painting";
}
/*{ Objetivo: Cambiar de category a string
    Entradas: Category
    Salidas: Un string
    Precondiciones: Introducir una categoría existente
    Postcondiciones: -
}*/

void new(char *param1, char *param2, char *param3, char *param4,tList *L){
    if(findItem(param1, *L)!=LNULL)
        printf("+ Error: New not possible\n");
    else{
        tItemL I;
        float param4_f;
        tStack T;
        {
            //definimos el Item
            strcpy(I.productId, param1);
            strcpy(I.seller, param2);

            //pasamos de char a category
            I.productCategory= strToCategory(param3);

            //pasamos de  *char a float
            param4_f = atof(param4);
            I.productPrice = param4_f;

            I.bidCounter=0;

            //Creo una pila vacia
            createEmptyStack(&T);
            I.bidStack=T;
        }
        if(insertItem(I, L)!=false)
            printf("* New: product %s seller %s category %s price %.2f\n", param1, param2, param3, param4_f);
        else
            printf("+ Error: New not possible\n");
    }
}
/* Objetivo: Añadir un producto nuevo a la lista
   Entradas: Identificar de producto, identificador del vendedor, categoria y precio del producto.
   Salidas: Identificar de producto, identificador del vendedor, categoria y precio del producto.
   Precondiciones: Que no exista un producto con el mismo identificador y que la lista no esté completa.
   Postcondiciones: -
*/

void bid(tProductId PI,char UI,tProductPrice PP,tList *L, tStack *S){
//declaracion de variables
    tPosL p = findItem(PI, *L);

    //el item por el que quiere pujar no existe
    if (p == LNULL)
        printf("+ Error: Bid not possible");
        //el item existe
    else {
        tItemL I = getItem(p, *L);
        tItemS T;
        {
            //Definimos el Item en el Stack
            strcpy(T.bidder, UI);

            //Copiamos el precio del Item en el Stack
            T.productPrice = PP;
        }
        //el precio por el que puja es menor o igual al actual o quien puja es el vendedor
        if (strcmp(&UI, I.seller) == 0 || PP <= I.productPrice)
            printf("+ Error: Bid not possible\n");
        else {
            //la puja se realiza con exito
            I.bidCounter++;
            I.productPrice = PP;
            updateItem(I,p,L);
            push(T, S);
            printf("* Bid: product %s seller %s category %s price %.2f bids %d\n", I.productId, I.seller,
                   categoryToStr(I.productCategory),I.productPrice, I.bidCounter);
        }
    }
}
/*{ Objetivo: Puja por un determinado producto
    Entradas: Identificador del producto, identificador de usuario, precio del producto y una lista
    Salidas: Identificador de producto, identificcador del usuario que pide el producto, categoria del producto,
        precio actualizado y contador de pujas actualizado
    Precondiciones: Tiene que existir el producto por el que quiero pujar y que la puja realizada sea mayor que
        la anterior
    Postcondiciones: -
}*/


void delete(tProductId PI,tList* L){
    if (isEmptyList(*L))
        printf("+ Error: Delete not possible");
    else{
        //Declaracion de variables
        tPosL p = findItem(PI, *L);
        //Nombre de producto no encontrado
        if(p==LNULL)
            printf("+ Error: Delete not possible");
        //El producto está en la lista
        else{
            tItemL I = getItem(p, *L);
            tStack D = I.bidStack;
            printf("* Delete: product %s seller %s category %s price %.2f bids %d",
                   I.productId, I.seller, categoryToStr(I.productCategory), I.productPrice, I.bidCounter);
            do {
                pop(&D);
            } while (isEmptyStack(D));
            deleteAtPosition(p, L);
        }
    }//else
}//delete
/* Objetivo: Eliminar productos de la lista.
   Entradas: Identificador del producto y una lista.
   Salidas: La lista sin el producto eliminado.
   Precondiciones: Lista inicializada no vacia y que el producto este en la lista
   Postcondiciones: -
*/

void award(tProductId PI, tList* L){
    if(isEmptyList(*L))
        printf("+ Error: Award not possible");
    else{
        //Declaracion de variables
        tPosL p = findItem(PI, *L);
        //Nombre de producto no encontrado
        if(p==LNULL)
            printf("+ Error: Award not possible");
        else{
            tItemL I = getItem(p, *L);
            tStack D = I.bidStack;
            tItemS S = peek(D);
            printf("* Award: product %s bidder %s category %s price %.2f", I.productId, S.bidder,
                   categoryToStr(I.productCategory), S.productPrice);
            do {
                pop(&D);
            } while (isEmptyStack(D));
            deleteAtPosition(p, L);
        }//else
    }//else
}
/* Objetivo: Mostrar el ganador de la puja
   Entradas: Identificador de producto y una lista
   Salidas: Identificador de producto, ganador de la puja, precio final de la puja y categoria del producto
   Precondiciones:  Lista inicializada no vacia, que el producto este en la lista y que existan pujas para
        dicho producto
   Postcondiciones: El producto mostrado se eliminara de la lista
*/

void processCommand(char *commandNumber, char command, char *param1, char *param2, char *param3, char *param4, tList *L, tStack *S) {

    switch (command) {
        case 'N':
            printf("********************\n");
            printf("%s %c: product %s seller %s category %s price %s", commandNumber, command, param1, param2, param3, param4);
            new(param1, param2, param3, param4, L);
            break;
        case 'S':
            break;
        case 'B':
            printf("********************\n");
            printf("%s %c: product %s bidder %s price %s", commandNumber, command, param1, param2, param4);
            //pasamos de *char a float
            float param4_f;
            param4_f = atof(param4);
            bid(param1, *param2, param4_f, L, S);
            break;
        case 'D':
            printf("********************\n");
            printf("%s %c: product %s", commandNumber, command, param1);
            delete(param1, L);
            break;
        case 'A':
            printf("********************\n");
            printf("%s %S: producto %s", commandNumber, command, param1);
            break;
        case 'W':
            break;
        case 'R':
            break;
        default:
            break;
    }
}

void readTasks(char *filename) {
    FILE *f = NULL;
    char *commandNumber, *command, *param1, *param2, *param3, *param4;
    const char delimiters[] = " \n\r";
    char buffer[MAX_BUFFER];

    f = fopen(filename, "r");

    if (f != NULL) {

        while (fgets(buffer, MAX_BUFFER, f)) {
            commandNumber = strtok(buffer, delimiters);
            command = strtok(NULL, delimiters);
            param1 = strtok(NULL, delimiters);
            param2 = strtok(NULL, delimiters);
            param3 = strtok(NULL, delimiters);
            param4 = strtok(NULL, delimiters);

            processCommand(commandNumber, command[0], param1, param2, param3, param4);
        }

        fclose(f);

    } else {
        printf("Cannot open file %s.\n", filename);
    }
}


int main(int nargs, char **args) {

    char *file_name = "new.txt";

    if (nargs > 1) {
        file_name = args[1];
    } else {
        #ifdef INPUT_FILE
        file_name = INPUT_FILE;
        #endif
    }

    readTasks(file_name);

    return 0;
}






