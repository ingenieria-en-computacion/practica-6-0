#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CIRCULAR_DEQUE_IMPLEMENTATION
#include "bicola_circular.h" // Cambia por el nombre real del archivo .h que contiene la macro

// Funciones para imprimir los tipos
void print_int(int x) {
    printf("%d", x);
}

void print_char(char c) {
    printf("'%c'", c);
}

int main() {
    printf("=== Bicola circular de enteros ===\n");
    CircularDeque_int* dq_int = deque_int_create(5);

    deque_int_push_back(dq_int, 10);
    deque_int_push_back(dq_int, 20);
    deque_int_push_front(dq_int, 5);
    deque_int_push_front(dq_int, 1);

    printf("Bicola actual: ");
    deque_int_print(dq_int, print_int);

    int front_val, back_val;
    deque_int_front(dq_int, &front_val);
    deque_int_back(dq_int, &back_val);
    printf("Frente: %d, Final: %d\n", front_val, back_val);

    deque_int_pop_back(dq_int);
    deque_int_pop_front(dq_int);

    printf("Después de eliminar frente y final: ");
    deque_int_print(dq_int, print_int);

    deque_int_destroy(dq_int);

    printf("\n=== Bicola circular de caracteres ===\n");
    CircularDeque_char* dq_char = deque_char_create(4);

    deque_char_push_back(dq_char, 'A');
    deque_char_push_front(dq_char, 'B');
    deque_char_push_back(dq_char, 'C');

    printf("Bicola de caracteres: ");
    deque_char_print(dq_char, print_char);

    deque_char_pop_front(dq_char);

    printf("Después de eliminar del frente: ");
    deque_char_print(dq_char, print_char);

    deque_char_destroy(dq_char);

    return 0;
}
