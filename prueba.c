/* Pasar de binario a decimal */

#include <stdio.h>
#include <math.h>
int main()
{
    int binario, aux, aux2, potencia, decimal = 0, resto, cuentadigitos = 0, i = 0;
    printf("Ingrese el numero en binario [Sin Decimales]: ");
    scanf("%d", &binario);
    aux = binario;
    aux2 = binario;
    while (aux)
    {
        cuentadigitos++;
        aux /= 10;
    }
    for (i = 0; i < cuentadigitos; i++)
    {
        resto = binario % 10;
        binario /= 10;
        decimal = decimal + resto * pow(2, i);
    }
    printf("\nEl numero %d(base 2) es %d(base10)", aux2, decimal);
}