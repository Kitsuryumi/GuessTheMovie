#include <stdio.h>
#include <stdlib.h>

const int MAX = 80;
typedef char string1 [MAX];
typedef enum {FALSE, TRUE} boolean;

int main()
{
    string1 peli, guiones, equiv, arriesgo;
    int i = 0, j = 0, opcion, intentos;
    char aux;
    boolean esta = FALSE, iguales = TRUE, gano = FALSE;

    equiv[0] = '\0';

    printf("Jugador 1, ingrese el nombre de la pelicula, finalice con ENTER: ");
    scanf("%c", &aux);
    /*carga de pelicula*/
    while(aux != '\n' && i < MAX - 1)
    {
        peli[i] = aux;
        scanf("%c", &aux);
        i++;
    }
    peli[i] = '\0';

    /*conversion de peli a mayusculas*/
    i = 0;
    while(peli[i] != '\0')
    {
        if(peli[i] >='a' && peli[i] <= 'z')
        {
            peli[i] = peli[i] - 32;
        }
        i++;
    }

    /*carga de guiones*/
    i = 0;
    while(peli[i] != '\0')
    {
        if(peli[i] >= 'A' && peli[i] <= 'Z')
        {
            guiones[i] = '-';
        }
        else
            guiones[i] = ' ';
        i++;
    }
    guiones[i] = '\0';

    printf("\nIngrese la cantidad de intentos: ");
    fflush(stdin);
    scanf("%d", &intentos);


    do
    {

        system("cls");  //borra la pantalla
        printf("La pelicula a adivinar es: ");
        /*printf de guiones*/
        i = 0;
        while(guiones[i] != '\0')
       {
           printf("%c", guiones[i]);
           i++;
       }

        /*printf de equiv*/
            printf("\nLetras equivocadas: ");
            fflush(stdin);
            i = 0;
            while(equiv[i] != '\0')
           {
               printf("%c", equiv[i]);
               i++;

           }

       printf("\nJugador 2, elija una opcion:"); /*pregunta al jugador 2*/
       printf("\n1-Ingresar una letra");
       printf("\n2-Arriesgar\n");
       printf("\nOpcion: ");
       scanf("%d", &opcion);
       if(opcion == 1)
       {
            esta = FALSE; //vuelvo a FALSE para siguiente letra
            printf("\nIngrese la letra: ");
            fflush(stdin);
            scanf("%c", &aux);
            if(aux >= 'a' && aux <= 'z') /*conversion de aux a mayusculas*/
            {
                aux = aux - 32;
            }
            i = 0;
            while(peli[i] != '\0') /*sustitucion de guiones por letras*/
            {
                if(aux == peli[i])
                {
                    guiones[i] = aux;
                    esta = TRUE;
                }
                i++;
            }
            if(esta == FALSE)
            {
                equiv[j] = aux;
                equiv[j + 1] = '\0';
                j++;
                intentos--;
            }

            /*printf de guiones*/
            i = 0;
            while(guiones[i] != '\0')
           {
               printf("%c", guiones[i]);
               i++;
           }
            /*printf de equiv*/
            printf("\nLetras equivocadas: ");
            fflush(stdin);
            i = 0;
            while(equiv[i] != '\0')
           {
               printf("%c", equiv[i]);
               i++;

           }
            i = 0;
            while(guiones[i] != '\0' && guiones[i] != '-') /*revisión de guiones*/
            {
                if(guiones[i] != '-')
                {
                    i++;
                }
            }
            if(guiones[i] == '\0')
            {
                gano = TRUE;
            }
       }
       else
       {
           if(opcion == 2) /*cargo de arriesgo*/
           {
                printf("\nIngrese la pelicula: ");
                fflush(stdin);
                scanf("%c", &aux);
                i = 0;
                while(aux != '\n' && i < MAX - 1)
                {
                    arriesgo[i] = aux;
                    scanf("%c", &aux);
                    i++;
                }
                arriesgo[i] = '\0';
                i = 0;
                while(arriesgo[i] != '\0') /*conversion de arriesgo a mayusculas*/
                {
                    if(arriesgo[i] >='a' && arriesgo[i] <= 'z')
                    {
                       arriesgo[i] = arriesgo[i] - 32;
                    }
                    i++;
                }
                i = 0;
                while(peli[i] != '\0' && iguales == TRUE) /*comparacion de arriesgo con peli*/
                {
                    if(arriesgo[i] != peli[i])
                    {
                        iguales = FALSE;
                    }
                    i++;
                }
                if(iguales == TRUE && peli[i] == '\0' && arriesgo[i] == '\0')
                {
                    gano = TRUE;
                }
                intentos = 0;
           }
       }
        printf("\n");
        system("pause");
    }
    while(intentos != 0 && gano == FALSE);
    printf("\nPelicula: ");
        fflush(stdin);
        /*printf de peli*/
            i = 0;
            while(peli[i] != '\0')
           {
               printf("%c", peli[i]);
               i++;
           }

    if(gano == FALSE)
    {
        printf("\nPERDISTE!! A SEGUIR INTENTANDO :(");
    }
    else
    {
        printf("\nGANASTE!! FELICITACIONES :)");
    }

    return 0;
}
