#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include datos char[5];

int[8], Edata[7] El síndrome codificados[3];
hmatrix int[3][7] = {1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1};
gmatrix char[4][8] = {"0111000", "1010100", "1100010", "1110001"};
int main()
{
    int i, j;
    Del sistema("clear");
    printf("Código \ nHamming ----- codificación \ n");
    printf("Introduzca los datos de 4 bits:");
    scanf("% s", de datos);
    printf("\ nGenerator matriz \ n");
    for (i = 0; i < 4; i++)
        printf("% s \ n", gmatrix[i]);
    printf("data \ nEncoded");
    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 4; j++)
            codificadas[i] + = ((datos[j] - '0') * (gmatrix[j][i] - '0'));
        codificada[i] = codificada[i] 2 % ;
        printf("% d", codificada[i]);
    }
    printf("Código \ nHamming ----- Decodificación \ n");
    printf("Introduzca bits codificados como se recibió:");
    for (i = 0; i < 7; i++)
        scanf("% d", y Edata[i]);
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 7; j++)
            Síndrome[i] + = (Edata[j] * hmatrix[i][j]);
        síndrome[i] = síndrome[i] 2 % ;
    }
    for (j = 0; j < 7; j++)
        if ((síndrome de[0] == hmatrix[0][j]) && (síndrome[1] == hmatrix[1][j]) && (síndrome[2] == hmatrix[2][j]))
            break;
    si(j == 7) printf("\ nError libre \ n");
    otro
    {
        printf("\ nError recibido con el número de bits de datos% d \ n", j + 1);
        !Edata[j] = Edata[j];
        printf("data \ nCorrect deben ser:");
        for (i = 0; i < 7; i++)
            printf("% d", Edata[i]);
    }
    return 0;
}