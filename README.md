TP2 - Avalia¸c˜ao do evento

Algoritmos 1

Data de entrega: 15/11/2022

1  Objetivos do trabalho

O objetivo deste trabalho ´e modelar o problema computacional descrito a seguir utilizando uma estrutura de dados que permita resolvˆe-lo de forma eficiente com os algoritmos estudados nesta disciplina.

Ser˜ao fornecidos alguns casos de teste bem como a resposta esperada para que o aluno possa verificar a corretude de seu algoritmo. N˜ao obstante, recomenda-se que o aluno crie casos de teste adicionais a fim de validar sua pr´opria implementa¸c˜ao.

A sua solu¸c˜ao deve obrigatoriamente ser desenvolvida utilizando algoritmos de divis˜ao e conquista.

O c´odigo-fonte da solu¸c˜ao e uma documenta¸c˜ao sucinta (relat´orio contendo n˜ao mais do que 5 p´aginas) dever˜ao ser submetidos via moodle at´e a data limite de 15/11/2022. A especifica¸c˜ao do conteudo´ do relat´orio e linguagens de programa¸c˜ao aceitas ser˜ao detalhadas nas se¸c˜oes subsequentes.

2  Defini¸c˜ao do problema

A cada 4 anos acontece o festival Rock In Rio, que ´e um evento que reune´ v´arias pessoas que gostam de musica´ em um unico´ lugar. A programa¸c˜ao do evento conta com um conjunto de shows que acontece de forma sequencial. Como o evento ainda ´e bem pequeno, eles n˜ao podem bancar mais de um palco ao mesmo tempo. Outro detalhe que torna esse evento interessante ´e que todo ano o festival convida as mesmas bandas, e garante que elas v˜ao tocar na mesma ordem do ano anterior.

Neste ano, um grupo de amigos decidiu ir ao festival e escutar todas as bandas dispon´ıveis. Esses amigos,

por acaso, fazem parte de uma turma de computa¸c˜ao e fizeram um aplicativo para cada um avaliar sua experiˆencia ao longo do festival. Com esse aplicativo cada membro do grupo de amigos pode dar uma nota

de -5 at´e +5 para cada show. Como requisito do aplicativo, todos os amigos do grupo devem avaliar todos os shows que aconteceram no evento. O objetivo deles com esse aplicativo ´e somar todas as avalia¸c˜oes de um mesmo show e descobrir qual ser´a o intervalo de shows consecutivos que mais agradou o grupo para que eles possam planejar o retorno no pr´oximo festival, uma vez que, se eles sa´ırem do festival, n˜ao podem voltar. Vale lembrar que na hora de montar o planejamento, sempre que existir um empate na decis˜ao de assistir

ou n˜ao um show, os amigos sempre optam por assistir ao show.

3  Exemplo do Problema

Em um caso hipot´etico, 3 amigos foram ao evento que teve 6 bandas diferentes tocando.

- A avalia¸c˜ao do primeiro amigo foi: 0, 3.5, -4, 2, 4 e 1.
- A avalia¸c˜ao do segundo amigo foi: 0, 2.7, -5, 0, 4 e 1.
- A avalia¸c˜ao do terceiro amigo foi: 1, 3, 5, 3 , 0 e -4.

De acordo com as avalia¸c˜oes desse grupo de amigos, no pr´oximo evento eles assistir˜ao apenas aos shows das bandas 1, 2, 3, 4 e 5. Note que, mesmo com o show 3 n˜ao sendo muito bem avaliado, vale a pena continuar no festival para assistir os shows 4 e 5.

Figure 1: Exemplo de notas para 3 amigos e 6 shows![](Aspose.Words.8e8f2ea9-a596-4ef4-8cbd-221fffd23001.001.png)

1. Modelagem do Problema

Este trabalho pr´atico aborda a parte de divis˜ao e conquista da ementa desta disciplina. Para a resolu¸c˜ao do problema a sua modelagem precisa usar algoritmos de divis˜ao e conquista. Caso contr´ario ele n˜ao vai rodar a tempo.

2. Formato da Entrada Esperada

O seu programa dever´a processar diversos casos de teste em umaun´ ica execu¸c˜ao. A primeira linha de um cen´ario de teste ´e composta de dois numero´ inteiros A e S, representando respectivamente o a quantidade

de amigos que assistiram os shows (1 ≤ A ≤ 50) e a quantidade de shows que aconteceram no festival (1 ≤ S ≤ 100000). Cada uma das pr´oximas A linhas descreve a avalia¸c˜ao de um integrante do grupo. A linha de avalia¸c˜oes ´e uma sequencia de S numeros´ reais separados por espa¸co. Uma linha com A = 0 e S = 0 indica o final do arquivo.

3. Formato da Sa´ıda Esperada

Para cada caso de teste seu programa deve imprimir uma linha contendo dois numeros´ inteiros ,Xi e Xf , separados por espa¸co, sendo que 1 ≤ Xi < Xf ≤ S. Xi ´e o ´ındice do primeiro show que eles devem assistir e Xf ´e o´ındice doultimo´ show que eles devem assistir. Repare que o intervalo [Xi,Xf ] ´e inclusivo nas duas pontas.

4. Caso de teste

Entrada

Sa´ıda

3 6

1 5 0 3.5 −4 2 4 1

1 4 0 2.7 −5 0 4 1

3 4 1 3 5 3 0 −4

1 3 5 5

5 −2 3 5 −2

3 −5 2 5 0

2 0 3 5 −2

4 1 1 5 1

3 2 3 5 3

2 7

−2 −4 3 1 −5 −1 3

−3 −5 2 4 −5 −2 3

10 4

4.1 −2 3 1 3 −5 2 3.7

4.4 0 2.8 0.88

3.8 1 1 −5 3 2 3 2

5 5 5 5

1.3 − 2.2 0 −4 4 3 0 0

−5 −5 −5 −5

−2 −1 0.5 1

. 0 0

4  Implementa¸c˜ao

O seu programa dever´a ser implementado na linguagem C++ e dever´a fazer uso apenas de fun¸c˜oes da biblioteca padr˜ao da linguagem. Trabalhos que utilizem qualquer outra linguagem de programa¸c˜ao e/ou que fa¸cam uso de bibliotecas que n˜ao a padr˜ao n˜ao ser˜ao aceitos.

O aluno pode implementar seu programa em qualquer ambiente (Windows, Linux, MacOS, etc...), no entanto, deve garantir que seu c´odigo compile e rode nas m´aquinas do DCC (tigre.dcc.ufmg.br ou jaguar.dcc.ufmg.br ou login.dcc.ufmg.br), pois ser´a neste ambiente que o TP ser´a corrigido. Note que essas m´aquinas s˜ao acess´ıveis a todos os alunos do DCC com seu login e senha, podendo inclusive ser realizado acesso remoto via ssh. O aluno pode buscar informa¸c˜oes no site do CRC (Centro de Recursos Computa- cionais) do DCC (https://www.crc.dcc.ufmg.br/).

Para facilitar o desenvolvimento vamos fornecer uma estrutura base de arquivos com Makefile j´a configu- rado. A pasta TP02-Template-CPP.zip, dispon´ıvel para download na tarefa do Moodle, contem 4 arquivos: main.cpp, rock.cpp, rock.hpp e Makefile. O ponto de entrada do seu programa est´a no arquivo main.cpp. Para compilar seu programa basta executar o comando “make” no mesmo diret´orio que o Makefile est´a. Ao final deste comando, se a compila¸c˜ao for bem sucedida, ser´a criado um arquivo execut´avel chamado “tp02”. Esse arquivo pode ser executado pela linha de comando usando “./tp02”.

O arquivo da entrada deve ser passado ao seu programa como entrada padr˜ao, atrav´es da linha de comando (e.g., $ ./tp02 < casoTeste02.txt ) e gerar o resultado tamb´em na sa´ıda padr˜ao (n˜ao gerar sa´ıda em arquivo).

Por favor n˜ao altere o nome da pasta nem o nome do arquivo execut´avel. Parte da corre¸c˜ao ´e autom´atica e ´e extremamente importante manter o padr˜ao de execu¸c˜ao.

5  O que deve ser entregue

Dever´a ser submetido um arquivo .zip contendo apenas uma pasta chamada tp2, esta pasta dever´a conter: (i) Documenta¸c˜ao em formato PDF e (ii) Implementa¸c˜ao.

1. Documenta¸c˜ao

A documenta¸c˜ao deve ser sucinta e n˜ao ultrapassar 5 p´aginas. Vocˆe deve descrever cada solu¸c˜ao do problema de maneira clara e precisa, detalhando e justificando os algoritmos e estruturas de dados utilizados. Para tal, artif´ıcios como pseudo-c´odigos, exemplos ou diagramas podem seruteis.´ Note que documentar uma solu¸c˜ao n˜ao ´e o mesmo que documentar seu c´odigo. N˜ao ´e necess´ario incluir trechos de c´odigo em sua documenta¸c˜ao nem mostrar detalhes de sua implementa¸c˜ao, exceto quando estes influenciem o seu algoritmo principal, o

que se torna interessante. E´ essencial que a documenta¸c˜ao contenha ao menos:

1. Identifica¸c˜ao : Nome e Matr´ıcula.
1. Introdu¸c˜ao : Breve resumo do problema com suas palavras.
1. Modelagem: Detalhamento e justificativa dos algoritmos e estruturas de dados escolhidos.
2. Implementa¸c˜ao

O c´odigo fonte submetido deve conter todos os arquivos fonte e o Makefile usado para compilar o pro- jeto. Lembre que seu c´odigo deve ser leg´ıvel, ent˜ao evite vari´aveis com nomes n˜ao descritivos (int a, aa, aaa;) e lembre-se de comentar seu c´odigo. J´a estamos fornecendo uma implementa¸c˜ao base com os arquivos necess´arios, ent˜ao indicamos que vocˆe s´o o altere se for necess´ario.

3. Atrasos

Trabalhos poder˜ao ser entregues ap´os o prazo estabelecido, por´em sujeitos a uma penaliza¸c˜ao regida pela seguinte f´ormula:

2d−1

∆ =~~ % (1) p 0.32

Nesta f´ormula d representa dias de atraso. Por exemplo, se a nota dada pelo corretor for 70 e vocˆe entregou o TP com 4 dias corridos de atraso, sua penaliza¸c˜ao ser´a de ∆p = 25% e, portanto, a sua nota final ser´a: Nf= 70 ∗(1 − ∆p) = 52.2. Note que a penaliza¸c˜ao ´e exponencial e 6 dias de atraso resultam em uma penaliza¸c˜ao de 100%.

6  Considera¸c˜oes Finais

Assim como em todos os trabalhos dessa disciplina ´e estritamente proibida a c´opia parcial ou integral de c´odigos, seja da internet ou de colegas. Utilizaremos o algoritmo MOSS para detec¸c˜ao de pl´agio em trabalhos, seja honesto. Vocˆe n˜ao aprende nada copiando c´odigo de terceiros nem pedindo a outra pessoa que fa¸ca o trabalho por vocˆe. Se a c´opia for detectada, sua nota ser´a zerada e os professores ser˜ao informados para que as devidas providˆencias sejam tomadas.
5
