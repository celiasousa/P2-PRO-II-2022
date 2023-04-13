/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Hugo Mato Cancela             LOGIN 1: hugo.matoc
 * AUTHOR 2: Celia Sousa Boo               LOGIN 2: celia.sousa
 * GROUP: 1.1
 * DATE: 31 / 03 / 22
 */

#include "bid_stack.h"

//Crear una pila vacía:
void createEmptyStack(tStack* stack){
    stack -> top=SNULL;
}//createEmptyStack

//Comprobar si la pila está vacía:
bool isEmptyStack(tStack stack){
    return (stack.top==SNULL);
}

//Insertar datos en una pila:
bool push (tItemS d, tStack* stack){
    if (stack->top==SMAX -1)//Comprobar si hay espacio para realizar la inserción
        return false;
    else{
        stack->top++;
        stack->data[stack->top]=d;
        return true;
    }//else
}//push

//Eliminar un dato de la pila:
void pop(tStack* stack){
    stack->top--;
}//pop

//Mostrar elemento superior de la pila:
tItemS peek(tStack stack){
    return stack.data[stack.top];
}//peek

