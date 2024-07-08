#include <stdio.h>
#include <stdlib.h>
#include <windows.h> // Inclui a biblioteca necessária para Sleep e system("cls")

void getTimeInput(int *h, int *m, int *s) {
    printf("Set time (hh:mm:ss): \n");
    scanf("%d%d%d", h, m, s);
    
    // Validação da entrada
    if (*h >= 24 || *m >= 60 || *s >= 60 || *h < 0 || *m < 0 || *s < 0) {
        printf("Erro! Hora inválida. Insira valores válidos.\n");
        exit(1);
    }
}

void displayTime(int h, int m, int s) {
    printf("\t\t\t\t\t\t\t   TIMER\n");
    printf("\t\t\t\t\t\t\t  %.2d:%.2d:%.2d\n", h, m, s);
}

int main() {
    int h, m, s;
    int delay = 1000; // Delay de 1000 milissegundos (1 segundo)

    getTimeInput(&h, &m, &s);

    while (1) {
        s++; // Incrementa os segundos
        if (s > 59) {
            m++; // Incrementa os minutos
            s = 0;
        }
        if (m > 59) {
            h++; // Incrementa as horas
            m = 0;
        }
        if (h > 23) { // Corrige para 23, pois a hora deve ser de 0 a 23
            h = 0;
        }

        system("cls"); // Limpa a tela
        displayTime(h, m, s);

        Sleep(delay); // Atraso de 1 segundo
    }

    return 0;
}

