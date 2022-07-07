# P02D13

![dayp02](misc/rus/images/dayp02.png)

## Contents

1. [Chapter I](#chapter-i) \
 1.1. [Level 2. Hall.](#level-2-hall)
2. [Chapter II](#chapter-ii)\
 2.1. [List 1.](#list-1)
 

# Chapter I

## Level 2. Hall.

***LOADING Level 2… \
LOADING Hall…***

Совсем недавно Вы были в подобном холе. Или это было уже очень давно? Сложно сказать. Все перепуталось. Опять слышны голоса в дальнем углу холла. Значит Вы снова тут не одни. \
Сегодня холл залит ярким светом и тут идеальный порядок. Разнообразие — это хорошо. 

Из колонок вдруг раздался четкий, кристально слышимый голос:

>Здравствуйте. \ 
>Позвольте представиться. Я созерцательно-анализирующий модуль M-53. По неустановленным причинам я оказался в этом довольно-таки скучном холле. Ответственность, конечно, большая, и все такое, но созерцать здесь совсем нечего. \
>Когда меня разрабатывали, в числе прочих материалов, я обучался на одной занимательной статье. Бумажная копия лежит в ящике А1Б18. Да, вот здесь. У меня к вам небольшая просьба — разработайте эту The Game of Life из статьи, надеюсь она меня хоть немного развлечет. И ступайте с миром. Графическое исполнение может быть самым простым — я публика непредвзятая. Вполне подойдет псевдографика в терминале. Вот можно было бы инициализировать состояние с помощью матрицы — и созерцать. Не лишним будет подготовить как минимум 5 начальных инициализаций с состояниями из классического набора (устойчивые фигуры, долгожители, периодические фигуры, двигающиеся фигуры, ружья, паровозы, пожиратели, отражатели, размножители и т.д.). \
>Жду результатов с нетерпением! \
>Спасибо.

***== Получен Quest. На языке программирования Си разработать программу src/game_of_life.c, представляющую из себя визуализацию "The Game of Life". Для отображения графики использовать только символьную (ASCII) графику (с выводом в терминал).***

* ***Управление:***

Каждый шаг "игры" выполнять по нажатию клавиши "пробел".

Обработка завершения игры.

* ***Графика*** 

Поле — прямоугольник 80 на 25 символов.
Подразумевается, что поле "замкнуто само на себя", к примеру у нижнего правого квадратика соседом справа является нижний левый квадратик, а соседом снизу - верхний правый.

Предусмотреть начальную инициализацию состояния "игры" через stdin. Подготовить несколько файлов с начальными состояними для быстрого запуска и инициализации через перенаправление ввода.

## Бонусная часть
***== Получен Quest. Необходимо реализовать в игре Game of life интерактивный режим, c настройкой скорости игры. ==*** 

## Важные замечания

* Игра должна быть разработана на языке Си, в структурном стиле и работать из терминала;
  
* Ваш исходный код будет тестироваться статическим анализатором ```cppcheck```, а также стилевым линтером 
```cpplint```.

* Инструкция о том, как запустить эти тесты у себя на компьютере, лежит в папке `materials`.

* Проверяйте вашу программу на утечки памяти!

> При разработке игры в полной мере руководствоваться принципами структрного программирования Э. Дейкстры. 

***LOADING...***

# Chapter II

## List 1.

>The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970. It is a zero-player game, meaning that its evolution is determined by its initial state, requiring no further input. One interacts with the Game of Life by creating an initial configuration and observing how it evolves. It is Turing complete and can simulate a universal constructor or any other Turing machine.
>
>The universe of the Game of Life is an infinite, two-dimensional orthogonal grid of square cells, each of which is in one of two possible states, live or dead, (or populated and unpopulated, respectively). Every cell interacts with its eight neighbours, which are the cells that are horizontally, vertically, or diagonally adjacent. At each step in time, the following transitions occur:
>
>Any live cell with fewer than two live neighbours dies, as if by underpopulation.
>Any live cell with two or three live neighbours lives on to the next generation.
>Any live cell with more than three live neighbours dies, as if by overpopulation.
>Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
>These rules, which compare the behavior of the automaton to real life, can be condensed into the following:
>
>Any live cell with two or three live neighbours survives.
>Any dead cell with three live neighbours becomes a live cell.
>All other live cells die in the next generation. Similarly, all other dead cells stay dead.
>The initial pattern constitutes the seed of the system. The first generation is created by applying the above rules simultaneously to every cell in the seed; births and deaths occur simultaneously, and the discrete moment at which this happens is sometimes called a tick. Each generation is a pure function of the preceding one. The rules continue to be applied repeatedly to create further generations.
>
>In late 1940, John von Neumann defined life as a creation (as a being or organism) which can reproduce itself and simulate a Turing machine. Von Neumann was thinking about an engineering solution which would use electromagnetic components floating randomly in liquid or gas. This turned out not to be realistic with the technology available at the time. Stanislaw Ulam invented cellular automata, which were intended to simulate von Neumann's theoretical electromagnetic constructions. Ulam discussed using computers to simulate his cellular automata in a two-dimensional lattice in several papers. In parallel, von Neumann attempted to construct Ulam's cellular automaton. Although successful, he was busy with other projects and left some details unfinished. His construction was complicated because it tried to simulate his own engineering design. Over time, simpler life constructions were provided by other researchers, and published in papers and books.
>
>Motivated by questions in mathematical logic and in part by work on simulation games by Ulam, among others, John Conway began doing experiments in 1968 with a variety of different two-dimensional cellular automaton rules.Conway's initial goal was to define an interesting and unpredictable cell automaton. For example, he wanted some configurations to last for a long time before dying and other configurations to go on forever without allowing cycles. It was a significant challenge and an open problem for years before experts on cellular automata managed to prove that, indeed, the Game of Life admitted of a configuration which was alive in the sense of satisfying Von Neumann's two general requirements. While the definitions before the Game of Life were proof-oriented, Conway's construction aimed at simplicity without a priori providing proof the automaton was alive.
>
>Conway chose his rules carefully, after considerable experimentation, to meet these criteria:
>
>There should be no explosive growth.
>There should exist small initial patterns with chaotic, unpredictable outcomes.
>There should be potential for von Neumann universal constructors.
>The rules should be as simple as possible, whilst adhering to the above constraints.
>The game made its first public appearance in the October 1970 issue of Scientific American, in Martin Gardner's "Mathematical Games" column. Theoretically, the Game of Life has the power of a universal Turing machine: anything that can be computed algorithmically can be computed within the Game of Life. Gardner wrote, "Because of Life's analogies with the rise, fall and alterations of a society of living organisms, it belongs to a growing class of what are called 'simulation games' (games that resemble real life processes)."
>
>Since its publication, the Game of Life has attracted much interest because of the surprising ways in which the patterns can evolve. It provides an example of emergence and self-organization. Scholars in various fields, such as computer science, physics, biology, biochemistry, economics, mathematics, philosophy, and generative sciences, have made use of the way that complex patterns can emerge from the implementation of the game's simple rules. The game can also serve as a didactic analogy, used to convey the somewhat counter-intuitive notion that design and organization can spontaneously emerge in the absence of a designer. For example, cognitive scientist Daniel Dennett has used the analogy of the Game of Life "universe" extensively to illustrate the possible evolution of complex philosophical constructs, such as consciousness and free will, from the relatively simple set of deterministic physical laws which might govern our universe.
>
>The popularity of the Game of Life was helped by its coming into being at the same time as increasingly inexpensive computer access. The game could be run for hours on these machines, which would otherwise have remained unused at night. In this respect, it foreshadowed the later popularity of computer-generated fractals. For many, the Game of Life was simply a programming challenge: a fun way to use otherwise wasted CPU cycles. For some, however, the Game of Life had more philosophical connotations. It developed a cult following through the 1970s and beyond; current developments have gone so far as to create theoretic emulations of computer systems within the confines of a Game of Life board.
>
![glider_emblem](materials/glider_emblem.gif)

***LOADING...***

