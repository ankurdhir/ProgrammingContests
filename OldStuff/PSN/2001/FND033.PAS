{koder: A^2P}{FPC}
{PSN 2001 #33 "Mercado"}
const
     filein = 'd.in';
     fileout = 'd.out';
var
   fin,fout      : text;
   N,S,i,j,v,sol : longint;
   c             : array[0..500000] of boolean;

begin
     {fload}
     assign(fin,filein); reset(fin);
     assign(fout,fileout); rewrite(fout);

     {solve}
     readln(fin,N);
     c[0] := true;
     for i:=1 to N do
     begin
     	  readln(fin,v);
          S := S + v;
          for j:=S downto v do
              if (c[j - v]) and (not c[j]) then
              begin
                   c[j] := true;
                   inc(sol);
              end;{then}
     end;{for}

     {dprint}
     write(fout,sol);

     {fclose}
     close(fin);
     close(fout);
end.{main}

{
33� Mercado.                                            Finlandia 2001
����������������������������������������������������������������������

El pescador Clement ha capturado N peces y los ha llevado a un mercado
de peces. Los personas de este mercado empacan el pescado en paquetes,
con pesos diferentes. Cada paquete puede tener uno o m�s peces.

Suponga que usted es el primer cliente y puede seleccionar el peso de
los paquetes. �Cu�ntos posibles pesos diferentes de paquetes existen
con esos N peces?

Restricciones:

N <= 500: es un entero positivo representando el n�mero de peces.
Ti <= 1000: es un entero positivo representando el peso del i-�simo
           pez.

Fichero de Entrada (MARKET.IN)

En la primera l�nea del fichero de entrada hay un n�mero entero N. En
cada una de las siguientes N l�neas hay un n�mero entero Ti.

Fichero de Salida (MARKET.OUT)

La salida consiste de un entero K representando el n�mero de pesos
diferentes posibles.

���������Ŀ����������Ŀ
�MARKET.IN��MARKET.OUT�
���������Ĵ����������Ĵ
� 5       �� 27       �
� 800     �������������
� 200     �
� 354     �
� 18      �
� 182     �
�����������
}