{koder: A^2P}
{PSN 2006 #30 "Koze"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 251;
var
  fin,fout        : text;
  N,M,i,j,v,k     : longint;
  alive           : array[0..1] of word;
  c               : array[0..MaxN,0..MaxN] of char;

    procedure dfs(i,j: byte);
    begin
      if c[i,j] = 'v' then inc(v)
        else if c[i,j] = 'k' then inc(k);
      c[i,j] := '#';
      if c[i-1,j] <> '#' then dfs(i-1,j);
      if c[i+1,j] <> '#' then dfs(i+1,j);
      if c[i,j-1] <> '#' then dfs(i,j-1);
      if c[i,j+1] <> '#' then dfs(i,j+1);
    end;{dfs}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  fillchar(c,sizeof(c),'#');
  readln(fin,N,M);
  for i:=1 to N do
  begin
    for j:=1 to M do read(fin,c[i,j]);
    readln(fin);
  end;{for}

  {solve}
  for i:=1 to N do
    for j:=1 to M do
      if c[i,j] <> '#' then
      begin
        v := 0; k := 0;
        dfs(i,j);
        if v >= k then inc(alive[1],v)
          else inc(alive[0],k);
      end;{then}

  {dprint}
  writeln(fout,alive[0],' ',alive[1]);

  {fclose}
  close(fin); close(fout);
end.{main}

{
30� Koze.                                                  M�xico 2006
����������������������������������������������������������������������

Existe un n�mero de cabras en el patio tracero de Mickey's. Mientras
el esta firmemente durmiendo  hace entrada en el patio lobos
hambrientos y atacan a las cabras.

EL patio es de forma rectangular y consiste de campos formados por
filas y columnas, el  caracter �.� (punto) denota un campo vacio, el
caracter # denota una cerca, el caracter �k� denota una cabra y el
car�cter �v� denota un lobo.

Nosotros consideramos que dos campos estan en  la misma regi�n  si
nosotros podemos movernos desde uno de los campos por un camino
consistiendo de solamente movimientos horizontales y verticales que no
contengan cercas. El campo desde el cual nosotros podemos �escapar�
desde el patio no esta considerado como camino de cualquier regi�n.

Afortunadamente, nuestras cabras saben de karate � ellas pueden pelear
dentro de una regi�n y ganar (esto es eliminarlos) si el n�mero en que
la regi�n es grande que el n�mero de lobos en la misma regi�n. En otro
caso los lobos  se come todas las cabras que inciden en la regi�n.

En el comienzo, todas las cabras y lobos estan situados dentro de
regi�nes en el patio. Escriba un programa que p�rtmita  calcular el
n�mero de cabras y el n�mero de wolves que quedan vivos en la ma�ana

Entrada

La primera l�nea de la entrada consiste de dos enteros R y C, (3 = R,
C = 250), el n�mero de filas y columnas del patio de Mickey's Cada una
de las siguientes R l�neas contienen C caracteres. Todas ellas
conjuntamente representan  el  esquema del patio o posiciones de las
cercas, cabras y lobos en el patio.

Nota: 50% de los juegos de datos ser�  "simple" en el senido que
inside en el �rea de casda regi�n que tenga forma rectangular, y
dentro que el rectangulo no tenga cercas.

Salida

La primera y �nica l�nea del fichero de salida debe contener dos
enteros, n�mero de cabas y n�mero de lobos que quedean vivos en la
ma�ana


Ejemplo de Entrada y Salida:


Ejemplo # 1      Ejemplo # 2         Ejemplo # 3
����������Ŀ     ������������Ŀ      ����������������Ŀ
� KOSE.IN  �     �  KOSE.IN   �      � KOSE.IN        �
����������Ĵ     ������������Ĵ      ����������������Ĵ
� 6 6      �     �  8 8       �      �  9 12          �
� ...#..   �     �  .######.  �      �  .###.#####..  �
� .##v#.   �     �  #..k...#  �      �  #.kk#...#v#.  �
� #v.#.#   �     �  #.####.#  �      �  #..k#.#.#.#.  �
� #.k#.#   �     �  #.#v.#.#  �      �  #..##k#...#.  �
� .###.#   �     �  #.#.k#k#  �      �  #.#v#k###.#.  �
� ...###   �     �  #k.##..#  �      �  #..#v#....#.  �
������������     �  #.v..v.#  �      �  #...v#v####.  �
                 �  .######.  �      �  .####.#vv.k#  �
                 ��������������      �  .......####.  �
                                     ������������������
����������Ŀ     ������������Ŀ      �����������Ŀ
� KOSE.OUT �     �  KOSE.OUT  �      � KOSE.OUT  �
����������Ĵ     ������������Ĵ      �����������ĳ
� 0 2      �     � 3 1        �      � 3 5       �
������������     ��������������      �������������
}