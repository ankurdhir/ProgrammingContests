/*
Alfonso Alfonso Peterssen
13 - 7 - 2007
USACO 2007 FEB Bronze "Estanque de Nen�fares Bronce"
*/
#include <fstream>
#include <queue>
using namespace std;

#define problem "bronlily"
#define MAXF 31

int mov[4][2] = { { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } };

int F, C, dx, dy, X, Y, i, j, sol;
int mark[MAXF][MAXF];
struct point {
  int X, Y, cost;
  point ( int a = 0, int b = 0, int c = 0 )
  : X( a ), Y( b ), cost( c ) {}
};
queue< point > Q;

  void push( point p ) {
    int x = p.X, y = p.Y;
    if ( ( x >= 0 && x < F ) && ( y >= 0 && y < C ) &&
         ( mark[x][y] == 1 || mark[x][y] == 4 ) ) {
      mark[x][y] = 2; // rockify
      Q.push( p );
    }
  }
  
ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> F >> C >> dx >> dy;
  for ( i = 0; i < F; i++ )
    for ( j = 0; j < C; j++ ) {
      fin >> mark[i][j];
      if ( mark[i][j] == 3 ) Q.push( point( i, j, 0 ) );
      if ( mark[i][j] == 4 ) X = i, Y = j;
    }

  /* BFS */
  do {
    point p = Q.front();
    sol = p.cost + 1;
    Q.pop();
    for ( i = 0; i < 4; i++ ) {
      push( point( p.X + dx * mov[i][0], p.Y + dy * mov[i][1], sol ) );
      push( point( p.X + dy * mov[i][0], p.Y + dx * mov[i][1], sol ) );
    }
  } while ( mark[X][Y] == 4 );

  fout << sol << endl;

  return 0;
}

/*
Problema 12: Estanque de Nen�fares Bronce [Ho/Kolstad, 2007]

GJ ha instalado un estanque hermoso para el disfrute est�tico y ejercicio
de sus vacas. El estanque rectangular ha sido particionado en celdas
cuadradas de M filas y N columnas (1 <= M <= 30; 1 <= N <= 30). Algunas
de las celdas tienen nen�fares asombrosamente robustos, otras tienen
rocas; las restantes tienen simplemente, agua azul, fresca, hermosa.

Bessie est� practicando sus movimientos de ballet saltando de un nen�far a
otro y est� actualmente ubicada en uno de los nen�fares. Ella quiere ir a
otro nen�far en el estanque saltando de un nen�far a otro.


Sorprendentemente, solo para los iniciados, los saltos de Bessie entre
nen�fares siempre se parecen a los movimientos de un caballo de ajedrez:
movers M1 (1 <= M1 <= 30) 'cuadrados' en una direcci�n y luego M2 ((1 <=
M2 <= 30; M1 !=M2) mas en una direcci�n ortogonal ( o tal vez M2 en una
direcci�n y luego M1 en una direcci�n ortogonal). Bessie algunas veces
podr�a tener hasta 8 posibilidades para su salto.

Dada la distribuci�n del estanque y el formato de los saltos de Bessie,
determine el menor n�mero de saltos que Bessie debe hacer para moverse de
su ubicaci�n inicial a su ubicaci�n final, un hecho que siempre es
posible para los conjuntos de entrada a usar.

NOMBRE DEL PROBLEMA: bronlily

FORMATO DE ENTRADA:

* L�nea 1: Cuatro enteros separados por espacio: M, N, M1 y M2.

* L�neas 2..M+1: La l�nea i+1 describe la fila i del estanque usando N
      enteros separados por espacio con estos valores: 0 indica agua
      vac�a; 1 indica un nen�far; 2 indica una roca; 3 indica el nen�far
      desde el cual Bessie comienza; 4 indica el nen�far que es el
      destino de Bessie.

ENTRADA EJEMPLO (archivo bronlily.in):

4 5 1 2
1 0 1 0 1
3 0 2 0 4
0 1 2 0 0
0 0 0 1 0

DETALLES DE LA ENTRADA:

Bessie comienza en la izquierda de la fila 2; su destino est� en la
derecha de la fila 2. Varios nen�fares y rocas ocupan el estaque.

FORMATO DE SALIDA:

* L�nea 1: Un solo entero que es el minimo numero de saltos entre
      nen�fares que Bessie debe hacer para ir de su lugar inicial a
      su destino.

SALIDA EJEMPLO (archivo bronlily.out):

2

DETALLES DE LA SALIDA:

De manera inteligente Bessie salta en el nen�far en la  fila 1, columna 3
en su camino al lado derecho.
*/
