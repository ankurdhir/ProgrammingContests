/*
Alfonso Alfonso Peterssen
18 - 6 - 2007
PSN 2007 #70 "Tablero de Ra�l"
*/
#include <fstream>
using namespace std;

#define problem "d"
#define MAXN 35

ifstream fin (problem ".in");
ofstream fout (problem ".out");

int N, i, j;
unsigned int C[MAXN], S[MAXN];

int main() {
  fin >> N;
  
  if ( N & 1 ) {
    fout << 0 << endl;
    return 0;
  }
  
  /* DP */
  N /= 2;
  C[0] = S[0] = 1;
  for ( i = 1; i <= N; i++ ) {
    C[i] = 2 * S[i - 1] + C[i - 1];
    S[i] = S[i - 1] + C[i];
  }
  
  fout << C[N] << endl;
  return 0;
}

/*
70� Tablero de Ra�l.                                      Croacia 2007
����������������������������������������������������������������������

 Se  tiene un  tablero  de Nx3,  donde se  quieren  contar la cantidad
 de formas en que  se  pueden  colocar  fichas de   dimensi�n de  1x2,
 considerando que todas las  fichas son iguales.

 Reglas

 - Una  ficha se puede  rotar 90 grados  cuantas veces se  requiera.
 - El tablero debe quedar  cubierto totalmente con estas fichas,  esto
   quiere decir  que no puede haber una casilla vac�a.

 Tarea

 Escriba  un programa  que cuente  la cantidad  de formas  de  colocar
 las fichas en el tablero dado.

 Entrada.

 El fichero  de entrada  TABLERO.IN contiene  en una  linea simple  un
 entero N, 0 < N <= 35.

 Salida

 El fichero  de salida  TABLERO.OUT contiene  en una  linea simple  la
 cantidad de formas  descritas en el problema.

 Ejemplo de Entrada y Salida

         Ejemplo 1                             Ejemplo 2
 �����������Ŀ  ������������Ŀ        �����������Ŀ  ������������Ŀ
 �TABLERO.IN �  �TABLERO.OUT �        �TABLERO.IN �  �TABLERO.OUT �
 �����������Ĵ  ������������Ĵ        �����������Ĵ  ������������Ĵ
 � 2         �  � 3 	       �        � 4         �  � 11 	      �
 �������������  ��������������        �������������  ��������������
*/
