(*
Alfonso Alfonso Peterssen
21 - 9 - 2007
USACO 2006 OCT Open "Adivina Mi N�mero"
*)
var
  lo, hi, mid : longint;
  answer : string;

begin

  lo := 1;
  readln( hi );

  repeat

    mid := ( lo + hi ) div 2;

    writeln( mid );
    readln( answer );

    if answer = 'L' then
         lo := mid + 1
    else hi := mid - 1;

  until answer = 'OK';

end. { main }

(*
Problema 2: Adivina Mi N�mero [Tradicional, 2006]

Las vacas est�n jugando �Mayor-Menor�, el juego de adivinar mi n�mero.
La l�der piensa un n�mero en el rango 1..N (10 <= N <= 1,000,000); las
otras vacas tratan de adivinarlo. Cada vez que se da una conjetura, la
l�der dice a la adivinadora si el n�mero es mayor, menor, o correcto.
Escriba un programa que juegue este juego en contra de un l�der
rob�tico.

Lea toda su entrada de la entrada est�ndar (tambi�n conocida como la
consola). Escriba todas sus salidas en la salida est�ndar (simplemente
como imprimiendo en la pantalla). Vea a continuaci�n para instrucciones
especiales.

Primero, lea N, luego haga su conjetura imprimi�ndola.

Lea una respuesta que es . 'H', 'L', o 'OK' (Mayor, Menor o Correcto).
Su programa ser� terminado autom�ticamente por el sistema de calificaci�n
despu�s del 'OK'.

Su puntaje depende de cu�n r�pidamente usted adivine el n�mero. Las
soluciones �ptimas recibir�n todo el puntaje; otras recibir�n menos.

Un di�logo t�pico podr�a ser como este (el n�mero secreto es 7):
-> 10                 [adivine en el rango 1..10]
<- 4                  [Su conjetura es 4]
-> L                  [Su conjetura es menor]
<- 6                  [Su conjetura es 6]
-> L                  [Su conjetura es menor]
<- 8                  [Su conjetura es 8]
-> H                  [Su conjetura es mayor]
<- 7                  [Su conjetura es 7]
-> OK                 [�Su conjetura es correcta!]

�Aseg�rese de vaciar su salida! Si usted usa stdio.h, incluya la l�nea

setbuf(stdout, 0);

cerca al principio de su programa. Si usted usa el estilo C++ de entrada
salida, vac�e cada l�nea como esto:

cout << line << "\n" << flush;

Para Pascal, haga lo siguiente despu�s de cada sentencia writeln:

flush(stdout);

Para Java, haga lo siguiente despu�s de cada sentencia de salida:

System.out.flush();


NOMBRE DEL PROBLEMA: guess

FORMATO DE ENTRADA:

* L�nea 1: Un solo entero N

* L�neas 2..??: Cada l�nea contiene una respuesta como se ha explicado.

ENTRADA EJEMPLO (entrada est�ndar)

10
...[Vea antes los detalles]...

FORMATO DE SALIDA:

* L�neas 1..??: Cada l�nea de salida es una conjetura como se ha
       detallado.


EJEMPLO DE SALIDA (salida est�ndar):

...[vea antes]...
*)
