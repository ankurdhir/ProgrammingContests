/*
Alfonso Alfonso Peterssen
21 - 9 - 2007
USACO 2006 NOV Bronze "Nuevas Marcas de Vacas"
*/
#include <cstdio>
#include <cstdlib>

#define problem "d"
#define MAXN 15
#define MAXLEN 30

int N, i, start, end, cnt;
char valid[MAXN][MAXLEN];
bool mark[256];
char st[MAXLEN];

  void comb( int pos ) {

    if ( pos == N ) {
      cnt++;
      if ( cnt > end ) exit( 0 );
      if ( cnt >= start )
        printf( "%s\n", st );
    }

    for ( char *ch = valid[pos]; *ch; ch++ )
      if ( !mark[*ch] ) {
        st[pos] = *ch;
        mark[*ch] = true;
        comb( pos + 1 );
        mark[*ch] = false;
      }
  }

int main() {

  freopen( problem ".in", "r", stdin );
  freopen( problem ".out", "w", stdout );

  scanf( "%d %d %d", &N, &start, &end );
  for ( i = 0; i < N; i++ )
    scanf( "%s", valid[i] );

  comb( 0 );

  return 0;
}

/*

Problema 11: Nuevas Marcas de Vacas [Rob Kolstad, 2006]

Las vacas est�n felices: El Granjero Juan (GJ) ha decidido usar etiquetas
RFID en lugar de marcar las vacas con hierros al rojo vivo que causan
dolor intenso.

Las tarjetas RFID contienen un c�digo de N (3 <= N <= 15) caracteres
(cada uno en el rango 'A'..'Z') de longitud. Ning�n car�cter aparece dos
veces en el c�digo. Los caracteres elegidos para cualquier posici�n en el
c�digo son elegidos de un conjunto dado para esa posici�n. Se da siempre
el conjunto en orden alfab�tico.

Una m�quina genera los c�digos en orden alfab�tico. Cada tanda nueva de
vacas usa el siguiente conjunto no usado de c�digos. GJ mantiene registro
del n�mero de c�digos que �l ya ha usado.

Ayude a GJ a confirmar los c�digos RFID a ser usados para el nuevo
conjunto de vacas. Dados los c�digos inicial y final (1 <= inicial <=
final <= 22,000,000), imprima (en orden alfab�tico) los c�digos que ser�n
usados. Mire un ejemplo en las especificaciones de Entrada/Salida.

NOMBRE DEL PROBLEMA: brand3

FORMATO DE ENTRADA:

* L�nea 1: Tres enteros separados por espacio, respectivamente, N,
     inicial, y final.

* L�neas 2..N+1: La l�nea i+1 contiene un n�mero (1..26) de caracteres
     que son los caracteres v�lidos para la posici�n i en el c�digo RFID

ENTRADA EJEMPLO (archivo brand3.in):

4 6 13
ABC
CDELQ
CFH
ABC

DETALLES DE LA ENTRADA:

Cuatro posiciones en el c�digo RFID; imprima los c�digos desde el sexto
hasta el decimotercero.

FORMATO DE SALIDA:

* L�neas 1..final-inicio+1: La l�nea i contiene el c�digo RFID
     # inicio+i-1

SALIDA EJEMPLO (archivo brand3.out):

ADHB
ADHC
AECB
AEFB
AEFC
AEHB
AEHC
ALCB

DETALLES DE LA SALIDA:

Aqu� est�n los primeros 20 c�digos:
 1 ACFB    5 ADFC    9 AEFB   13 ALCB   17 ALHC
 2 ACHB    6 ADHB   10 AEFC   14 ALFB   18 AQCB
 3 ADCB    7 ADHC   11 AEHB   15 ALFC   19 AQFB
 4 ADFB    8 AECB   12 AEHC   16 ALHB   20 AQFC
*/
