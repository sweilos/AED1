#include "fila.h"
#include <stdio.h>

int main(){
    No_Fila* vetor_fila[7];

    for (int i = 0; i < 7; i++) {
        vetor_fila[i] = criarNo_Fila();
    }

    for (int i = 0; i < 7; i++) {
        printf("Dia %d: \n\n", i+1);
        int looping = 1;
        while (looping) {

            char texto[100];
            fgets(texto, sizeof(texto), stdin);

            if (strlen(texto) > 1) {
                texto[strlen(texto) - 1] = '\0'; // Remover o caractere '\n'
                enfileirar(vetor_fila[i], texto);
            } else {
                looping = 0;
            }
        }
    }

    for (int i = 0; i < 7; i++) {
        printf("\n\ndia %d\n\n", i+1);
        mostrar(vetor_fila[i]);
    }
    return 0;
}