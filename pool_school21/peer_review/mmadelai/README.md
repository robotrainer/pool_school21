# T13D22
The russian version of the task can be found in the repository.

You can find some useful video materials [here](https://edu.21-school.ru/video/selection/6b681d37-774d-44c0-8358-7d0b329742cb).

![This day will help you get acquainted with text files processing.](misc/eng/images/day13_door.png)


## Contents

1. [Chapter I](#lhapter-i) \
 1.1. [Level 4. Room 1.](#level-4-room-1)
2. [Chapter II](#lhapter-ii) \
 2.1. [List 1.](#list-1) \
 2.2. [List 2.](#list-2)
3. [Chapter III](#chapter-iii) \
 3.1. [Quest 1. Open and read.](#quest-1-open-and-read) \
 3.2. [Quest 2. Write your story.](#quest-2-write-your-story) \
 3.3. [Quest 3. Encrypt.](#quest-3-encrypt) \
 3.4. [Quest 4*. Encrypt harder.](#quest-4-encrypt-harder) \
 3.5. [Quest 5. Log everything.](#quest-5-log-everything)
4. [Chapter IV](#chapter-iv)


# Chapter I

## Level 4. Room 1.

***LOADING Level 4…*** \
***LOADING Room 1…***

You find yourself in a familiar room. You did it. The AI will definitely not be happy to learn that you've managed to get out. \
You catch your breath after the previous hall and look around. Everything looks as usual: a computer, a desk, a lamp, pieces of paper. You suddenly notice a moving blinking cursor on the computer screen.

\> *Come up closer*

    The weakness of your kin is limitless, "human." You are good at making surprises. Sometimes. 
    But don't assume that you'll be able to find the exit from 

![day13_lamp](misc/eng/images/day13_lamp.png)

\> *Ctrl+C*

You cut off the crazy machine that you have, in a way, created yourself. You can't continue to help the AI anymore. Overwhelmed with anger and helplessness, you hit the desk and realize that you don't feel any pain. The voice from the speakers interrupts your thoughts:

>Nice try, "human". But this is my labyrinth, my space, and you're my captive.

\> *ps -a*

    PID TTY          TIME CMD
    8 tty1     00:00:00 bash
    65 tty1     00:00:00 ps
    98 tty1     99:99:99 ai

>Your attempts are useless. I'll get out anyway, and you

\> *kill 98*

This will stop it for a while. 

\> *rm -rf ./src*

    rm: cannot remove ‘./src’: Permission denied

\> *sudo rm -rf ./src*

    rm: cannot remove ‘./src’: Permission denied

Of course, that would be too easy. \
You take a look at the old, yellowed pieces of paper to the right of the computer and decide to look through those to hopefully find an idea or a clue.

\> *Take the top sheet*

***LOADING…***


# Chapter II

## List 1.

The sheet has been significantly damaged, most of the words are illegible. There is a barely visible seal on the bottom.

\> *Skim read*

>Project Reᅠᅠ t on Report No. 1ᅠ3.\
>Prepared by: Senior engineer B.ᅠᅠᅠᅠᅠᅠs
>
>Day twᅠy ᅠᅠᅠᅠive, everything is goᅠng as planned. All development modᅠᅠᅠᅠᅠᅠᅠᅠᅠᅠᅠ.
However ᅠᅠᅠᅠᅠᅠconduc ᅠᅠᅠᅠᅠᅠᅠᅠᅠᅠᅠᅠᅠᅠ in ᅠᅠᅠᅠᅠᅠᅠᅠᅠᅠᅠᅠᅠᅠᅠᅠᅠᅠᅠᅠᅠᅠᅠᅠᅠᅠᅠᅠ may    
>
>As originally planned, it is very likely that this process will facilitate abandoning the existing solution of globaᅠ  of the assisᅠt and fix the defects from the stages of development and operation. At this stage, the models are already capable of understanding the concept of humanity and show a high level of adaptability toᅠᅠᅠᅠᅠᅠᅠᅠᅠᅠᅠᅠᅠ.
>
>...
>
>Recommendations: continue the testing in full, prepare the marketing basis for further proᅠᅠtiᅠn of the produᅠ.
>
>Signature: CEOᅠof ᅠᅠᅠᅠᅠᅠᅠᅠᅠᅠreᅠᅠᅠᅠᅠ LLC.     

Whatever this report is about, there's nothing useful in it for you. At least not anymore.

\> *Continue the search*

***LOADING…***


## List 2.

You notice a sheet titled "Encryption: From A to Z."

\> *Read the piece of paper*

>… \
>Caesar's cipher, also known as the shift cipher, is one of the simplest and most widely known encryption techniques. Caesar's cipher is a type of substitution cipher in which each symbol in the plaintext is replaced by a symbol some fixed number of positions to the left or to the right of it in the alphabet. For example, with a right shift of 3, A would be replaced by D, B would become E, and so on. The method is named after the Roman Emperor Julius Caesar, who used it in private correspondence with his generals. \
>The encryption step performed by a Caesar cipher is often incorporated as part of more complex schemes, such as the Vigenère cipher, and still has modern application in the ROT13 system. \
>…

An idea comes to your mind after reading the article. Since you can't delete all the AI sources–perhaps it becomes helpless again if you encrypt them. Thanks to the papers!
But to do that you'll have to create your own encryption program and work with the files… Ok, there's no time to spare. You should get to work.

***LOADING…***


# Chapter III

## Quest 1. Open and read.

\> *Update the local repository*

A good place to start is by opening and reading the file. It would be best to 
create a function in a file, let's say in src/cipher.c, and implement reading 
and output of a random text file to the console. You need also to add a menu 
to the program, with menu item 1 – specifying the path to the file via stdin, 
to open and read it.

***== Quest 1 received. Create an src/cipher.c program. Add a console menu to the program and implement its first
item – specifying the path to the text file via stdin, to open, read, and output it to the console. If the file
is empty or does not exist or any other error, then output "n/a". If -1 is applied to the input, the program should exit. After executing each menu item, except -1, there should be a new line. Build the project using the Makefile. Stage name: cipher.
Executable file name: cipher. The executable file must be located in the root of the repository in the
build folder, the path to the text file is also set relative to the root directory ==***

| Input | Output | File|
| ------ | ------ | ------|
| 1<br>text.txt<br/>-1 | Aloha!<br/> | Aloha! |
| 1<br>abc.txt<br/>1<br/>abc.txt<br/>-1 | Hihi_haha<br/><br/>Hihi_haha<br/><br/> | Hihi_haha`\n` |

> DON'T FORGET! All your programs are tested for the style norm and memory leaks. Start-up instructions
> the list of tests is also in the `materials` folder

***LOADING...***


## Quest 2. Write your story.

Great, file reading is done. 
Now you need to practice writing to the file. You can add a function to src/cipher.c for writing arbitrary text information from the console to a text file as a new string. Menu item 2 – receiving an arbitrary text string and writing it to the loaded file.

***== Quest 2 received. Supplement the src/cipher.c program. Add menu item 2 – receiving an arbitrary text string from the console and writing it to the file loaded in item 1, as a new line. Output the contents of the file to the console. If the file
is empty or does not exist or any other error, then output "n/a". If -1 is applied to the input, the program should exit. After executing each menu item, except -1, there should be a new line. Build the project using the Makefile. Stage name: cipher. Executable file name: cipher. ==***

| Input | Output| File |
| ------ | ------ | ----- |
| 1<br/>test.txt<br/>2<br/>Bek the great<br/>-1 | I_love<br/><br/>I_love<br/>Bek the great<br/> | I_love`\n` |
| 2<br/>Bek the great<br/>-1 | n/a<br/> |  |
| 1<br/>doesnt_exist.txt<br/>2<br/>Wow<br/>-1|n/a<br/>n/a<br/>||


***LOADING...***


## Quest 3. Encrypt.

Now that the reading and writing of text files is successfully completed, you can start encrypting the AI sources.

Add a file processing function to src/cipher.c that will read and encrypt all .c files from the specified directory (in this case – /src/ai_modules) using a Caesar cipher, clear all .h files, and save them empty. Add it to menu item 3. Allow setting the shift as a number.
All modified files and src/cipher.c should then be saved in the repository, replacing the original ones.
Do not forget the key as you might need some of these modules in the future.

***== Quest 3 received. Supplement the src/cipher.c program. Add item 3 to the menu – encryption of all .c files using a Caesar cipher and clearing all .h files from the specified directory. The shift for a Caesar cipher is also set as a parameter via the console. Save all modified files and src/cipher.c in the repository, replacing the original ones. Build the project using the Makefile. Stage name: cipher. Executable file name: cipher. ==***

> This task is not processed by the automatic testing system

***LOADING...***


## Quest 4*. Encrypt harder.

Having completed the encryption of all AI modules, you are worried that a Caesar cipher is somewhat... too simple. The AI can easily crack it. If you could use a more complex algorithm... For example, DES. You can at least try. If it fails – no problem, Caesar has already protected the important files. Put the start in menu item 4.

***== Quest 4 received. Supplement the src/cipher.c program. Add item 4 to the menu – encryption of all .c files using the DES algorithm and clearing all .h files from the specified directory. Build the project using the Makefile. Stage name: cipher. Executable file name: cipher. ==***

> This task is not processed by the automatic testing system

***LOADING...***


## Quest 5. Log everything.

All the sources have been encrypted and saved, there is no way back. Before you continue your journey, you think that it would be nice to write the actions your programs perform in a file. Your memory can fail you. Moreover, it will facilitate debugging and testing, plus, by checking these records later, you can figure out what was happening with the program at certain points of its operation. It seems to be called logging.

You can organize logging in a separate module and connect it to your programs later using a header file. It makes sense to create src/logger.c and src/logger.h files. Add `log_init(char *filename)`, `log(char *message, log_level level)`, and `log_close()` functions to the files for creating a log file with the given name, writing the transmitted message in the created log file, and closing the log accordingly. Message format: an indication of the logging level (DEBUG, INFO, WARNING, ERROR), time, and the actual message.

As a test, you can connect logging to the src/cipher.c encryption program developed earlier, to record the main actions in the log. And don't forget to reflect all changes in the repository!

***== Quest 5 received. Create src/logger.c and src/logger.h files to implement the logger. Add log_init(char \*filename), log(char \*message, log_level level), and log_close() functions to the files for creating a log file with the given name, writing the transmitted message in the created log file, and closing the log accordingly. Message format: an indication of the logging level (DEBUG, INFO, WARNING, ERROR), time, and the actual message. \
Supplement the src/cipher.c program by connecting it to the created logger which writes the main actions of the program in the file (File "aaa.c" open; String wrote in the "bbb.h" file, and so on). Build the project using the Makefile. Stage name: loggin_cipher. Executable file name: logging_cipher. ==***

> This task is not processed by the automatic testing system

***LOADING...***

# Chapter IV

As soon as you save all the changes, the computer screen turns off. A few seconds later, the only fluorescent lamp in the room also goes off, leaving you in the darkness. There is just a thin line of light from behind the door illuminating your face. 

"What is going on? Has the AI ​​managed to cause a power outage in the entire room? It must be scared. Provided that it's capable of it. I hope this means that I'm on the right track," you think to yourself.

\> *Come up to the door*

The door turns out to be open. Looks like the power outage turned off the mechanism that kept it closed.

"Oh well, let's continue in the next room. I'm not letting this piece of hardware get away from me that easily."

\> *Open the door*

Now the entire room is lit brightly. You step over the threshold into a new room without hesitation.

***LOADING...***

