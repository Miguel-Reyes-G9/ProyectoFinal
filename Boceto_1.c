// PROYECTO FINAL 
// ALUMNO: REYES MORALES MIGUEL ALBERTO
// MATERIA: FUNDAMENTOS DE PROGRAMACION

#include <stdio.h>

int vect[10][100];
int ant[2];
int pcont[10];
int topoyent[100];
int puntper[100];
int i, j, n, op, cont, puntaje, k, top, con, con1, con2;

void main (){

  for (j=0; j<100; j++) {
    for (i=0; i<10; i++)
      vect[i][j]=0;
  }

  j=0;
  i=0;
  n=0;
  ant[0]=47667;
  ant[1]=32432;
  k=0;
  top=1;

  do {

    printf ("Hola, oyente numero %d, que canciones pones en tu top?\n", n+1);
    printf ("1. Cancion uno.\n");
    printf ("2. Cancion dos.\n");
    printf ("3. Cancion tres.\n");
    printf ("4. Cancion cuatro.\n");
    printf ("5. Cancion cinco.\n");
    printf ("6. Cancion seis.\n");
    printf ("7. Cancion siete.\n");
    printf ("8. Cancion ocho.\n");
    printf ("9. Cancion nueve.\n");
    printf ("10. Cancion diez.\n");
    printf ("-1. Resultados.\n");

    for (puntaje=3; puntaje>0; puntaje--) {

      cont=0;

      printf ("Cual es la cancion que para ti esta en el top %d ?\n", top );

      do {
    
        scanf ("%d", &op);
    
        if (op == ant[0] || op == ant[1])
            printf ("No puedes dar el mismo valor al anterior, dame otro diferete.\n");
    
        else {
    
            if (op>=1 && op<=10)
                cont=1;
    
            else if (op != -1)
                printf ("Dame un valor del 1 al 10\n");
        }
    
      } while (cont != 1 && op != -1);
    
      if (op == -1)
        break;
    
      ant[k]=op;
      ++k;

      switch (op) {

        case 1:
          vect[0][j]=puntaje;
          break;

        case 2:
          vect[1][j]=puntaje;
          break;

        case 3:
          vect[2][j]=puntaje;
          break;

        case 4:
          vect[3][j]=puntaje;
          break;

        case 5:
          vect[4][j]=puntaje;
          break;

        case 6:
          vect[5][j]=puntaje;
          break;

        case 7:
          vect[6][j]=puntaje;
          break;

        case 8:
          vect[7][j]=puntaje;
          break;

        case 9:
          vect[8][j]=puntaje;
          break;

        case 10:
          vect[9][j]=puntaje;
          break;
      }
      ++top;
    }

    k=0;
    ++j;
    ++n;
    top=1;
    ant[0]=47667;
    ant[1]=32432;

  } while (j<100 && op!=-1);
  
  --j;

  for (i=0; i<10; i++)
      vect[i][j]=0;

  for (cont=0; cont<=j; cont++) {
    for (i=0; i<10; i++) {
      if (vect[i][cont]==3 || vect[i][cont]==2 || vect[i][cont]==1) 
        ++pcont[i];
    }
  }
  
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

  for (i=0; i<10; i++)
      vect[i][j]=0;

  con=0;
  con1=0;
  con2=0;

  for (cont=0; cont<=j; cont++) {

    for (i=0; i<10; i++) {

      if (vect[i][cont]==k)
        con1=1;

      if (vect[i][cont]==n)
        con2=1;

      if (con2+con1==2) {
        puntper[cont]=60;
      }

      else {

        if (con1==1)
          puntper[cont]=30;

        if (con2==1)
          puntper[cont]=30;
      }
    }

    con1=0;
    con2=0;
  }
        
  //
  printf ("\n \n");

  for (i=0; i<j; i++)
    printf ("%d ,", puntper[i]);

  printf ("\n \n");
  //
    
  k=0;

  for (i=0; i<=j; i++) {
    if (puntper[i]>puntper[k])
      k=i;
  }
    
  n=0;

  for (i=0; i<=j; i++) {
    if (puntper[i]==k) {
      topoyent[n]=i;
      ++n;
    }
  }
  
  printf ("Oyentes con mayor cantidad de puntos:");

  for (cont=0; cont<n; cont++)
    printf ("Oyente %d ,", pcont[cont]+1);

  printf ("\n\n");
}
