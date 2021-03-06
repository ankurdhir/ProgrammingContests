/*
Alfonso Alfonso Peterssen
30 - 8 - 2007
USACO 2005 OCT Silver "Encuentros Cercanos"
*/
#include <fstream>
#include <cmath>
using namespace std;

#define problem "d"
#define MAXD 32768
#define fraction( n, d ) ( double( n ) / d )

int N, D, i, j, k, solN, solD;
double diff = 1e6;

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> N >> D;

  for ( j = 1; j < MAXD; j++ ) {

    if ( j % D == 0 ) continue;

    i = round( j * fraction( N, D ) );

    if ( abs( fraction( i, j ) - fraction( N, D ) ) < diff ) {
      solN = i;
      solD = j;
      diff = abs( fraction( i, j ) - fraction( N, D ) );
    }
  }

  fout << solN << ' ' << solD << endl;

  return 0;
}

/*
Problema 6: Encuentros Cercanos [Hal Burch, 2005]

Careciendo a�n de quinto grado de educaci�n, las vacas han tenido
problemas con un problema de fracciones de su libro de texto. Por
favor, ay�delas. El problema es sencillo:

    Dada una fracci�n reducida apropiadamente (esto es, el m�ximo
    com�n divisor del numerador y del denominador es 1, de tal
    forma que la fracci�n no puede ser reducida m�s) encuentre la
    fracci�n reducida apropiadamente m�s peque�a con numerador y
    denominador en el rango 1..32,767 que sea m�s cercana (pero no
    igual) a la fracci�n dada.

NOMBRE DEL PROBLEMA: nearfr

FORMATO DE ENTRADA:

* L�nea 1: Dos enteros separados por espacio N y D (1 <= N < D <=
        32,767), que son respectivamente el numerador y el denominador
        de la fracci�n dada.

ENTRADA EJEMPLO (archivo nearfr.in):

2 3

DETALLES DE LA ENTRADA:

2/3

FORMATO DE LA SALIDA:

* L�nea 1: Dos enteros separados por espacio, que son respectivamete
        el numerador y el denominador de la fracci�n diferente m�s
        peque�a, m�s cercana a la fracci�n de la entrada.

SALIDA EJEMPLO (archivo nearfr.out):

21845 32767

DETALLES DE LA SALIDA:

21845/32767 = .666676839503.... ~ 0.666666.... = 2/3.
*/
