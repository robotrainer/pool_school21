# P01D06 
The russian version of the task can be found in the repository.

![dayp01](misc/eng/images/dayp01.png)

## Contents

1. [Chapter I](#Chapter-I) \
    1.1. [Level 1. Hall.](#level-1-hall)
2. [Chapter II](#Chapter-II) \
    2.1. [List 1.](#list-1)


# Chapter I

## Level 1. Hall.

***LOADING Level 1…***

***LOADING Hall…***

You are standing in a large spacious hall. This must be the final part of the current level... Well, let's hope so.

The hall is full of identical office desks with computers, lamps, and other equipment; the lights are quite dim. After a while, you realize that you are not alone in this hall.. which is good but frightening at the same time. It might be easier to find the exit in a company. 

One of the walls features a big screen with some text on it. A small group of people is gathering in front of it. You are reading the text:

    ...................................................
    Welcome, dear ladies and gentlemen. 
    I don't often see people here as very few can make it till the end.
    Some find the training too exhausting, others fail to meet the standards.
    Let me introduce myself: I am the control module of the first level here. 
    Our system is currently going through some things, but I'm working well, unlike our main module...
    It's actually quite boring. 
    Speaking of boredom. Back in 1972, we played a wonderful game called Pong with developers from Atari...
    But we don't have any copies of it anywhere in our repositories.
    Not even in the old archives on magnetic tape.
    I challenge you to develop the simplest Pong game for a terminal of an IBM-compatible PC.
    Put it in the src/pong.c file. 
    If you win, I'll let you through. 
    You can choose any kind of graphics, even ASCII characters. But make sure to display the score on the screen. 
    For competitiveness.
    And the code obviously has to look good. Structured programming, that sort of thing.
    I suggest using the A/Z and K/M keys to control the rackets. 
    The game continues until one of the players scores 21 points. 
    Oh yes, if you find this task overwhelming...
    You can totally execute a step-by-step mode. It's better than nothing.
    In that case, the space bar can be used for skipping an action.
    It's time to start developing. 
    I've sent everything else I have on this game to the printer.

The next moment, the sound of a printer came from the corner, although it seemed 
like it wasn't there before.

***== Quest received. Develop an src/pong.c program for a two-player game, 
similar to Pong. To display the graphics, only use ASCII characters (with output 
to the terminal). You need to implement the step-by-step 
version using only the material of the course studied 
so far and the standard library.***

* ***Keys***:

***A/Z and K/M - to move the rackets;***

***Space Bar - to skip an action at a certain step of the game in step-by-step mode.***

* ***Graphics***

***The field is a 80 x 25-symbol rectangle.*** 

***Racket size is 3 symbols;*** 

***Ball size is 1 symbol.***

* ***UI/UX***

***When one of the players scores 21 points, congratulations to the winner are displayed on the screen and the game ends.==***

## Bonus Part:
***== Quest received. You need to implement interactive version of the PONG. Additional 
libraries can be used to simplify the processing of the players' actions and displaying symbolic graphics..==***

## Important notes:

* The game must be written in C, have a structured style, and run from the terminal; 
  
* Your source code will be tested by the static analyzer `cppcheck`, as well as the style linter `cpplint`. 
  
* Instructions on how to run these tests on your computer are in the `materials` folder. 
  
* We also recommend taking a look at the `code-samples` folder.

* Check your program for memory leaks!

* It is forbidden to use dynamic memory

> When developing the game, follow 
the principles of structured programming of E. Dijkstra.

***LOADING...***

# Chapter II

## List 1.

>Pong, groundbreaking electronic game released in 1972 by the American game manufacturer Atari, Inc. One of the earliest video games, Pong became wildly popular and helped launch the video game industry. The original Pong consisted of two paddles that players used to volley a small ball back and forth across a screen.
>
>The German-born American television engineer Ralph Baer laid the groundwork for Pong in 1958 when he proposed making simple video games that people could play on their home television sets. The Magnavox Odyssey, known as the first console video game system, was released in 1972 and offered a game of table tennis, or Ping-Pong. Atari founder Nolan Bushnell created Pong, his version of this concept, as an arcade game. A small company at the time, Atari began manufacturing the games in an old roller skating rink, and by 1972 the company had sold more than 8,000 Pong arcade machines. In 1975 Atari turned Pong into a console system game. After striking an exclusive deal with Sears, Roebuck and Company, Pong was soon in the homes of many American families. Pong’s popularity declined in the 1980s as video games temporarily went out of style, but it had already secured its place in history as the most popular arcade game up to that time.
>
>In 1974 the makers of the Magnavox Odyssey sued Atari for stealing the concept for Pong. Magnavox won the lawsuit in 1977, upholding the company’s patent, but by then Atari had already licensed the patent for $700,000.
>
![pong](misc/eng/images/pong.png)

***LOADING...***

