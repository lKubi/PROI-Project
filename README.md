Enunciado

Actualmente, a xestión hospitalaria é un tema de gran importancia, no que
priman non soamente factores asistenciais, senón tamén económicos e de
recursos de persoal.

Por iso, practicamente a totalidade de centros sanitarios e hospitalarios ten
implantado un sistema informático que permite, entre outros aspectos, controlar
os servizos prestados aos doentes, obter estatísticas, recoller información acerca
de datas de ingreso ou consulta, ou detallar o custo da atención prestada en cada
caso.

Obxectivo

No presente proxecto de programación débese implementar na linguaxe C++, e
empregando CodeBlocks, unha aplicación que permita xestionar doentes dun
hospital, tanto de consulta externa coma de hospitalización. Os datos dos
pacientes atópanse almacenados no arquivo binario doentes.dat. Estes datos deben
cargarse directamente no sistema cando se executa a aplicación (funcionalidade
proporcionada), e deben ser gardados cos cambios efectuados ao remate da
mesma. Ademais, os usuarios interaccionan coa aplicación a través dun menú, e
poden acceder ás seguintes funcionalidades:

    1) Visualizar listado de doentes (funcionalidade proporcionada).
    
    2) Dar de alta doentes (sempre e cando haxa menos dun determinado número
    de doentes almacenados no sistema).
    
    3) Dar de baixa calquera doente. Non deben quedar ocos ao eliminar doentes de
    posicións intermedias da listaxe.
    
    4) Buscar doentes por código.
    
    5) Buscar doentes por DNI.
    
    6) Modificar dende o teclado os datos dun doente, cuxo código se introduce por
    teclado.
    
    7) Visualizar os doentes separados por tipo de consulta, ben hospitalización, ben
    externa.
    
    8) Actualizar a información do arquivo (só do arquivo), modificando a
    información dun doente contido nel, cuxo código é introducido por teclado.

Consideracións

Para cada doente (un único rexistro por cada un deles) debe almacenarse a
seguinte información:

    ◦ Nome completo.
    
    ◦ DNI.
    
    ◦ Domicilio.
    
    ◦ Código da historia médica, formado por un conxunto alfanumérico dun
    máximo de 10 caracteres.
    
    ◦ Tipo de consulta: hospitalización, externa.
    
    ◦ Data de nacemento: formada por:
    
    ◦ Día: entre 1 - 30, 1 - 28 (29), e 1 - 31, dependendo do mes, e de se é
    ano bisesto.
    
    ◦ Mes : entre 1 - 12.
    
    ◦ Ano: non superior ao ano actual de 2021.
    
    ◦ A partir dos ficheiros proporcionados en EsqueletoProxecto.zip, deberá
    crearse un proxecto asociado, formado por un arquivo que contén a
    función main( ), e por unha serie de módulos adicionais de código e de
    ficheiros de cabeceira que conteñan declaracións de funcións
    (prototipos), definicións de estruturas, directivas de compilación,...
    
    ◦ A aplicación dispón ademais dunha interface que permite elixir a opción
    que se quere realizar entre as funcionalidades dispoñibles ou, de ser o
    caso, indicar que non desexa realizar máis operacións, e rematar a
    aplicación (neste caso, gardarase automaticamente a información
    actualizada dos doentes no arquivo doentes.dat).
    
    ◦ Poderanse almacenar, como moito, 200 doentes.