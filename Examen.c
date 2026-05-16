// PROYECTO FINAL 
// ALUMNO: REYES MORALES MIGUEL ALBERTO
// MATERIA: FUNDAMENTOS DE PROGRAMACION
# include <stdio.h>
int vect[10][100];
int i, j, n, op, con, cont;

void main (){
  for (j=0; j<100; j++) {
    for (i=0; i<10; i++)
      vect[i][j]=0; }
  j=0, i=0, n=0, con=0, cont=0;
  do {
  printf ("Hola, oyente numero %d, que canciones pones en tu top 3?\n", n+1);
  printf ("1. Cancion uno.\n");
  printf ("2. Cancion dos.\n");
  printf ("3. Cancion tres.\n");
  printf ("4. Cancion cuatro.\n");
  printf ("5. Cancion cinco.\n");
  printf ("6. Cancion seis.\n");
  printf ("7. Cancion siete.\n");
  printf ("8. Cancion siete.\n");
  printf ("9. Cancion siete.\n");
  printf ("10. Cancion siete.\n");
  printf ("Coloca el valor de menos uno para pasar a los resultados\n");
  cont=0;
  do {
  scanf ("%d", &op);
  if (op == ant1 && op== ant2)
    printf ("No puedes dar el mismo valor al anterior\n");
  if (op == -1)
        con=1;
    else {
        if (op>=1 && op<=10)
          cont=1;
        else 
          printf ("Dame un valor del 1 al 10\n"); }
  } while (cont != 1 && con!= 1);
switch (op) 
