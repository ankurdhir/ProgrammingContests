/*
Alfonso Alfonso Peterssen
12 - 7 - 2007
PSN 2007 #137 "Pruge"
*/
#include <fstream>
using namespace std;

#define problem "d"

long long sol;
int X1, X2, Y1, Y2, i, j;

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> X1 >> Y1 >> X2 >> Y2;

  for ( i = X1 | 1; i < X2; i += 2 ) {
    j = min( i, Y2 ) - Y1;
    if ( j > 0 ) sol += j;
  }

  for ( i = Y1 | 1; i < Y2; i += 2 ) {
    j = min( i + 1, X2 ) - X1;
    if ( j > 0 ) sol += j;
  }

  fout << sol << endl;

  return 0;
}

/*
137� Pruge.                                               Croacia 2007
����������������������������������������������������������������������

Un modelo compuesto por rayas oscuras (son descritas en la figura de
abajo). Intervalos enteros en el primer cuadrante del sistema de
coordenadas rectangulares.
Escriba un programa que encuentre el n�mero total de cuadrados oscuros
dentro de  un rect�ngulo dado.

                   
                   �����������������������Ŀ
                   �������������������������
                   �����������������������Ĵ
                   �  �  �  �  �  �  �  ����
                   ��������������������ͻ�Ĵ
                   �������������������  ����
                   �����������������������Ĵ
                   �  �  �  �  �  ����  ����
                   �����������������������Ĵ
                   �������������  ����  ����
                   ��������������������ͼ�Ĵ
                   �  �  �  ����  ����  ����
                   �����������������������Ĵ
                   �������  ����  ����  ����
                   �����������������������Ĵ
                   �  ����  ����  ����  ����
                ����������������������������������
                   �

Entrada

La primera  y �nica  l�nea del  fichero de  entrada PRUGE.IN  contiene
cuatro enteros X1, Y1, X2,  Y2 -las coordenadas del rect�ngulo con  la
esquina inferior izquierda (X1, Y1) y la esquina superior derecha (X2,
Y2). 0 <= X1 < X2 <= 1 000 000, 0 <= Y1 < Y2 <= 1 000 000.

Salida

La primera y �nica l�nea del fichero de salida PRUGE.OUT debe contener
un simple entero  -el  n�mero  total  de cuadrados oscuros  dentro del
rect�ngulo dado. Nota: use el tipo entero de 64-bit (int64 en  Pascal,
long long en C/C++).

Ejemplos de Entrada y Salida:

����������Ŀ        �����������Ŀ         ����������Ŀ
� PRUGE.IN �        � PRUGE.IN  �         � PRUGE.IN �
����������Ĵ        �����������Ĵ         ����������Ĵ
� 2 3 7 6  �        � 0 4 2 104 �         � 4 1 7 50 �
������������        �������������         ������������
�����������Ŀ       �����������Ŀ         �����������Ŀ
� PRUGE.OUT �       � PRUGE.OUT �         � PRUGE.OUT �
�����������Ĵ       �����������Ĵ         �����������Ĵ
� 8         �       � 100       �         � 72        �
�������������       �������������         �������������
*/
