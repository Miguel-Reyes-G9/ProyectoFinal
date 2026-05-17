// PROYECTO FINAL
// ALUMNO: REYES MORALES MIGUEL ALBERTO
// MATERIA: FUNDAMENTOS DE PROGRAMACION
#include <stdio.h>

int vect[10][100];
int ant[2];
int pcont[10];
int topoyent[100];
int puntper[100];

int i, j, n, op, cont, puntaje, k, top;

void inicializar ();
void leerVotos ();
void calcularCanciones ();
void calcularGanador ();

void main () {
    inicializar();
    leerVotos();
    calcularCanciones();
    calcularGanador();
}


void inicializar () {

    for (j=0; j<100; j++) {
        for (i=0; i<10; i++)
            vect[i][j]=0;
    }

    for (i=0; i<10; i++)
        pcont[i]=0;

    j=0;
    n=0;
    ant[0]=47667;
    ant[1]=32432;
    top=1;
}


void leerVotos () {
    do {
        printf ("Hola, oyente numero %d, que canciones pones en tu top?\n", j+1);
        printf ("0. Cancion cero.\n");
        printf ("1. Cancion uno.\n");
        printf ("2. Cancion dos.\n");
        printf ("3. Cancion tres.\n");
        printf ("4. Cancion cuatro.\n");
        printf ("5. Cancion cinco.\n");
        printf ("6. Cancion seis.\n");
        printf ("7. Cancion siete.\n");
        printf ("8. Cancion ocho.\n");
        printf ("9. Cancion nueve.\n");
        printf ("-1. Resultados.\n");

        for (puntaje=3; puntaje>0; puntaje--) {
            cont=0;
            printf ("Cual es la cancion que para ti esta en el top %d ?\n", top);
            do {
                scanf ("%d", &op);
                if (op == ant[0] || op == ant[1])
                    printf ("No puedes repetir canciones.\n");
                else {
                    if (op>=0 && op<=9)
                        cont=1;
                    else if (op != -1)
                        printf ("Dame un valor del 0 al 9\n");
                }

            } while (cont != 1 && op != -1);
            if (op == -1)
                break;
            
            ant[3-puntaje]=op;
            vect[op][j]=puntaje;
            ++top;
        }

        top=1; ant[0]=47667; ant[1]=32432;
        ++j;

    } while (j<100 && op!=-1);
    --j;
    for (i=0; i<10; i++)
        vect[i][j]=0;
}


void calcularCanciones () {
    for (cont=0; cont<j; cont++) {
        for (i=0; i<10; i++) {
            pcont[i]+=vect[i][cont];
        }
    }

    printf ("\n");

  k=0;
  for (i=0; i<10; i++) {
    if (pcont[i] > pcont[k])
      k=i;
  }
  printf ("La musica preferida es la cancion %d \n", k+1);
    
  n=0;
  for (i=0; i<10; i++) {
    if (i != k) {
      if (pcont[i] > pcont[n] || n == k)
        n=i;
    }
  }
  printf ("La segunda musica preferida es la cancion %d \n", n+1);
}


void calcularGanador () {
    for (cont=0; cont<j; cont++) {
        puntper[cont]=0;
        if (vect[k][cont]!=0)
            puntper[cont]+=30;
        if (vect[n][cont]!=0)
            puntper[cont]+=20;
        if ((vect[k][cont]!=0) && (vect[n][cont]!=0))
            puntper[cont]+=10;
    }

    k=0;
    for (i=0; i<j; i++) {
        if (puntper[i] > puntper[k])
            k=i;
    }

    n=0;
    for (i=0; i<j; i++) {

        if (puntper[i] == puntper[k]) {
            topoyent[n]=i;
            ++n;
        }
    }

  printf ("Oyentes con mayor cantidad de puntos: ");
  for (cont=0; cont<n; cont++)
    printf ("Oyente %d ,", topoyent[cont]);
  printf ("\n\n");
}
