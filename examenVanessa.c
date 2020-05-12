//examen 2 Vanessa Espitia Villamil
//Uso de Hamming para coficar y verificar  errores.
//materia TDA
//todo el programa es demasiado sencillo, segun yo se entiende por si solo, pero ahí va jaja 
//en el menu hay dos opciones codificacion y error
//recibe numero del 0-7 ya que son 4 bits jiji
//hasta medio validaciones tiene, please no me mates.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int codificacion();
int decodificacion(int n);
//funcion para imprimir el numero binario
void binario();
    int main()
{
    int n, opcion;

    do
    {
        printf("\n   1. Codificacion.");
        printf("\n   2. Error.");
        printf("\n   3. Salir.");
        printf("\n\n   Introduzca numero (1-3): ");

        scanf("%d", &opcion);

        /* Inicio del anidamiento */

        switch (opcion)
        {
        case 1:
        system("clear");
        //funcion de codificacion con hamming 
            n=codificacion();
            break;

        case 2:
        system("clear");
        //error
            decodificacion(n);
            break;
        
        }

        /* Fin del anidamiento */

    } while (opcion != 3);

    return 0;
}

int codificacion (){
    //miles de variables que sé que debia de ser mas facil por for y con switch, lo se, pero murio mi programa anterior
    //de hecho lo volvia hacer y moria casi mi computadora, entonces lo hice asi de rustico, no me mates. PLEASEEE 
    int numero, resp, num8, andraro, sumarara, numnuevo,sumaand, sumaand1, sumaand2;
    int and1,and2,and3;
    int and11, and22, and33;
    int and111, and222, and333;
    int mask=1;
    printf("Ingrese un entero: ");
    scanf("%i", &numero);
  if (numero  >7)
    {
        printf("no se puede\n");
        return 0;
    }
   num8 = numero << 3;
//printf("%d",num8);

//esta es como una "validacion" ya que yo corro el numero tres veces y aveces hay un 1 en la posicion 4 y deberia de estar en la 3
//entonces lo que hice fue que si un el and daba 8 pues era de que habia un numero en la posicion 4 y que luego cambiara al 3
// no me mates

//ADVERTENCIA vas a ver mil printf MILES, pero ten ecuneta que mi primer programa murio y quiero pasar la materia.
andraro=num8 & mask<<3;
if (andraro == 8)
{
sumarara= num8 + 4;
numnuevo=sumarara-8;
//printf("numero nuevo%d\n", numnuevo);
}
else
{
    numnuevo= num8;
}

//aqui se hace super rusitico la comparacion de pares de uno si y uno no, encontes fui "comparando" las posiciones 
//y ya dependiendo de la posicion se sumaba una cantidad
and1= numnuevo & mask<<6;
and2= numnuevo & mask<<4;
and3= numnuevo & mask<<2;
sumaand= and1 + and2 + and3;
//printf("la suma de los AND pares uno si uno no %d\n", sumaand);
if (sumaand == 4 ||sumaand == 16 ||sumaand == 64 || sumaand == 84)
{
   numnuevo= numnuevo +1;
   //printf("numero nuevo por si impar1 %d\n", numnuevo);
}

and11 = numnuevo & mask << 6;
and22 = numnuevo & mask << 5;
and33 = numnuevo & mask << 2;
sumaand1 = and11 + and22 + and33;
//printf("la suma de los AND pares dos si dos no %d\n", sumaand1);
if (sumaand1 == 4 || sumaand1 == 32 || sumaand1 == 64 || sumaand1 == 97)
{
    numnuevo = numnuevo + 2;
    //printf("numero nuevo por si impar2 %d\n", numnuevo);
}

and111 = numnuevo & mask << 6;
and222 = numnuevo & mask << 5;
and333 = numnuevo & mask << 4;
sumaand2 = and111 + and222 + and333;
//printf("la suma de los AND pares dos si dos no %d\n", sumaand2);
if (sumaand2 == 112 || sumaand2 == 32 || sumaand2 == 64 || sumaand2 == 16)
{
    numnuevo = numnuevo + 8;
    //printf("numero nuevo por si impar3 %d\n", numnuevo);
}


   // printf("hola %d", resp);

   //y boom el milagro, salió, el milagro de la vida.
printf("numero original\n");
binario(numero);
printf("\nel numero codificado\n");

//funcion para imprimir el binario.
  binario(numnuevo);
    return numnuevo;
}
//funcion de error
int decodificacion(int n){
//mas variables de la muerte, lo siento jajaaj 
    int numero, resp, num8, andraro, sumarara, sumaand, sumaand1, sumaand2;
    int and1, and2, and3, and4;
    int and11, and22, and33, and44;
    int and111, and222, and333, and444;
    int mask = 1, menor = 7, xor=0;
    //el lala que es un clasico, por lo menos en mi vida jaajjaa 
    int numerror, cambio,lala,lala1,lala2,lala3,lala4;
    printf("Prueba de error, dame una posicion\n");
    scanf("%d", &numero);
    cambio = mask << numero;
    if (numero >= menor)
    {
        printf("no se puede\n");
        return 0;
}
andraro = n & cambio;
//printf("cambio %d", cambio);
//printf("and raro %d", andraro);

//hice basicamente una "validacion" ya que si en la posicion que me daban habia un numero cambiar de 0-1 o de 1-0
if(andraro==0){

    numerror = n + cambio;
}
if (andraro == 1 || andraro == 2 || andraro == 4 || andraro == 8 || andraro == 16 || andraro == 32 || andraro == 64 )
{
    numerror =n - cambio;
}
//numero con el error
printf("numero binario con el error\t\t");
binario(numerror);
printf("\n");

//aqui empieza otra vez, de que mi for no funcionaba y lo hice todo rustico 
and1 = numerror & mask << 6;
if (and1==64){
     lala=1;
}
else
{
    lala=0;
}

and2 = numerror & mask << 4;
if (and2 == 16)
{
   lala1 = 1;
}
else
{
    lala1=0;
}

and3 = numerror & mask << 2;
if (and3 == 4)
{
    lala2 = 1;
}
else
{
    lala2=0;
}

and4 = numerror & mask << 0;
if (and4 == 1)
{
    lala3 = 1;
}
else
{
    lala3=0;
}

int raro1= lala3 ^ lala2;
//printf("xor1 %d\n", raro1);
int raro2= raro1 ^ lala1;
//printf("xor2 %d\n", raro2);
xor=raro2^lala;
printf("C0=%d", xor);
xor=xor*1;

and11 = numerror & mask << 6;
if (and11 == 64)
{
    lala = 1;
}
else
{
    lala = 0;
}

and22 = numerror & mask << 5;
if (and22 == 32)
{
    lala1 = 1;
}
else
{
    lala1 = 0;
}

and33 = numerror & mask << 2;
if (and33 == 4)
{
    lala2 = 1;
}
else
{
    lala2 = 0;
}

and44 = numerror & mask << 1;
if (and44 == 2)
{
    lala3 = 1;
}
else
{
    lala3 = 0;
}

int raro3 = lala3 ^ lala2;
//printf("xor1 %d\n", raro1);
int raro4 = raro3 ^ lala1;
//printf("lala1 %d\n", lala1);
//printf("xor2 %d\n", raro2);
int xor1 = raro4 ^ lala;
printf("\nC1=%d",xor1);
xor1=xor1*2;
and111 = numerror & mask << 6;
if (and111 == 64)
{
    lala = 1;
}
else
{
    lala = 0;
}

and222 = numerror & mask << 5;
if (and222 == 32)
{
    lala1 = 1;
}
else
{
    lala1 = 0;
}

and333 = numerror & mask << 4;
if (and333 == 16)
{
    lala2 = 1;
}
else
{
    lala2 = 0;
}

and444 = numerror & mask << 3;
if (and444 == 8)
{
    lala3 = 1;
}
else
{
    lala3 = 0;
}

int raro5 = lala3 ^ lala2;
//printf("xor1 %d\n", raro5);
int raro6 = raro5 ^ lala1;
//printf("lala1 %d\n", lala1);
//printf("xor2 %d\n", raro6);
int xor2 = raro6 ^ lala;
printf("\nC2=%d", xor2);
xor2=xor2*4;

resp= xor+xor1+xor2;

//y esto es el resultado
printf("\nError en la posicion %d", resp);
printf("\nNumero corregido\t\t");
binario(n);

return 0;
}

//funcion para imprimir el numero binario.
void binario(int n)
{
    if (n)
    {
        binario(n / 2);
        printf("%d", n % 2);
    }
    
}

//maybe no es nada optimo y el nombre de mis variables son fabulosas, pero me quedo, gracias, perdon por entregarlo tan tarde
//pero no sé que le pasó al anterior jaja