# T09D15
The russian version of the task can be found in the repository.

You can find some useful video materials [here](https://edu.21-school.ru/video/selection/d30cc6ce-bd90-4352-a584-cdb5ab865112).

![This day will help you get acquainted with multifile projects.](misc/eng/images/day9_door.png)


## Contents

1. [Chapter I](#chapter-i) \
 1.1. [Level 3. Room 1.](#level-3-room-1) 
2. [Chapter II](#chapter-ii) \
 2.1. [List 1.](#list-1)
3. [Chapter III](#chapter-iii) \
 3.1. [Quest 1. Modules.](#quest-1-modules) \
 3.2. [Quest 2. Modules II.](#quest-2-modules-ii) \
 3.3. [Quest 3. Makefile.](#quest-3-makefile) \
 3.4. [Quest 4. Macro.](#quest-4-macro) \
 3.5. [Quest 5. Static Lib.](#quest-5-static-lib) \
 3.6. [Quest 6. Dynamic Lib.](#quest-6-dynamic-lib) 
4. [Chapter IV](#chapter-iv) 


# Chapter I

## Level 3. Room 1.

***LOADING Level 3… \
LOADING Room 1…***

You catch yourself contemplating the structures from The Game of Life pulsating in the black ocean and realize that you must have fallen asleep and your eyes are closed. You open your eyes and find yourself sitting in a rather comfortable chair in front of a large, heavy desk. There are long printed pieces of code that look like ancient scrolls hanging on the walls of this new room. They have a lot of marks, arrows, underlines, and other traces of intellectual activity. 

![day9_chair](misc/eng/images/day9_chair.png)

\> *Look around*

Aside from a shabby and not very trustworthy brochure titled "The C Preprocessor. Macro definitions. A guide for Professionals", the desk has a monitor with a lot of stickers on it. They mainly have dates that mean nothing to you, names, and events from someone's work and personal life. A bright red sticker catches your attention:

>Got to put things in order in the modules. Working with this endless code is unbearable. Looks like no one else is going to do it but me.

And a postscript:

>I've prepared all the necessary materials on the computer. A couple of things still need to be finalized. The work is going slowly. I'm getting constantly distracted by routine tasks and new features. But refactoring is important. Otherwise, we will just collapse at some point. Everything will fall apart.

This sticker holds another piece of paper, half the size of an A4

\> *Read*

***LOADING...***


# Chapter II

## List 1.

>Header file — a file with content that is automatically added to the source text where the include directive is located (#include <file.h>), by the preprocessor.
>In С/C++ programming languages, header files are the key method for connecting data types, structures, function prototypes, enumerated types, and macros used in a different module, to the program. .h extension is used by default. 
>The following directives are used to avoid including the same code again: #ifndef, #define, #endif.

You notice that the sheet of paper seems to be folded in half.

\> *Carefully unfold the sheet*

***LOADING...***

## List 2.

>In software development, Make is a build automation tool that automatically builds executable programs and libraries from source code by reading files called Makefiles which specify how to derive the target program. 
>Though integrated development environments and language-specific compiler features can also be used to manage a build process, Make remains widely used, especially in Unix and Unix-like operating systems.

\> *I see. Turn on the computer*

The text you already know flashed on the download screen:

> Don't forget to check your programs for style norms and memory leaks! \
> Don't forget to check your programs for style norms and memory leaks! \
> Don't forget to check your programs for style norms and memory leaks! \
> Check out ' materials` more often.....

***LOADING...***

# Chapter III

## Quest 1. Modules.

Strangely enough, the computer took a long time to start up. You finally see the terminal loading and the following text:

    Welcome message from workstation #771.
    The message is displayed automatically.
    The gateway of the 1st room of level 3 is under maintenance.
    Maintenance status:
     1. Refactoring of modules from the src directory has begun.
     2. The modules are not working properly.
    Check:
     1. Load data_module ... FAIL.
    Complete the refactoring of the specified modules.
    Do not change the division into files: it has been approved by the lead architect.

    Restart the system when it's ready.
    
***== Quest 1 received. Finalize the src/data_module module so src/data_module_entry.c is able to start and work correctly. Pay attention to the data_libs directory. Reuse the existing files and functions to the maximum, using the corresponding directives of the preprocessor. ==***

***LOADING…***


## Quest 2. Modules II.

\> *Ready. Restart the computer*

It's working much faster after the restart:

    Welcome message from workstation #771.
    The message is displayed automatically.
    The gateway of the 1st room of level 3 is under maintenance.
    Maintenance status:
     1. Refactoring of modules from the src directory has begun.
     2. The modules are not working properly.
    Checking modules:
     1. Load data_module ... SUCCESS.
     2. Load yet_another_decision_module ... FAIL.
    Complete the refactoring of the specified modules.
    Do not change the division into files: it has been approved by the lead architect.
    
    Restart the system when it's ready.

***== Quest 2 received. Finalize the src/yet_another_decision_module module so src/yet_another_decision_module_entry.c is able to start and work correctly. Pay attention to the data_libs directory. Reuse the existing files and functions to the maximum, using the corresponding directives of the preprocessor. ==***

***LOADING…***


## Quest 3. Makefile.

\> *Ready. Restart the computer#2*

The hard drive is rustling joyfully: 

    Welcome message from workstation #771.
    The message is displayed automatically.
    The gateway of the 1st room of level 3 is under maintenance.
    Maintenance status:
     1. Refactoring of modules from the src directory has begun.
     2. The modules are not working properly.
    Checking modules:
     1. Load data_module ... SUCCESS.
     2. Load yet_another_decision_module ... SUCCESS.
     3. Make main_executable_module ... FAIL
    The Makefile part of the build process must be finalized.
    I haven't had the time to finish it. I was planning to add standard targets (clean, all, rebuild)

    Restart the system when it's ready.

> **Attention!** All paths in the Makefile must be specified relative to the directory in which it is located, since it will be launched from there

***== Quest 3 received. Finalize the src/main_executable_module module so src/main_executable_module/main_executable_module.c is able to start and work correctly. Develop a Makefile for building the solution and place it in the source code directory. Add standard targets to the Makefile: clean, all, rebuild. When creating the Makefile, follow standard solutions used for developing programs in C. The compiled file should be located in the build folder at the root of the repository. It should be named Quest_3. ==***

***LOADING…***

## Quest 4. Macro.

\> *Ready. Restart the computer#3*

The computer is flying:

    Welcome message from workstation #771.
    The message is displayed automatically.
    The gateway of the 1st room of level 3 is under maintenance.
    Maintenance status:
     1. Refactoring of modules from the src directory has begun.
     2. The modules are not working properly.
    Checking modules:
     1. Load data_module ... SUCCESS.
     2. Load yet_another_decision_module ... SUCCESS.
     3. Make main_executable_module ... SUCCESS.
     4. Load check_list ...
     4.1. Add the data_io_macro.h implementation to the src/data_libs folder with parametric macros that take the array,
     the size, and the format for working with different types of arrays. Add the build_with_macro target to the Makefile. 
     Finalize main_executable_module.c.
     ...
     
    Press Enter when it's ready.

***== Quest 4 received. Add the data_io_macro.h implementation to the src/data_libs folder using parametrized multiline macro definitions. The implementation has to work with any types of arrays. Modify main_executable_module.c to make it possible to configure the connection of the io module's header file using a macro (standard data_io.h or data_io_macro.h implementation). Add the build_with_macro target to the Makefile for building main_executable_module with data_io_macro.h, and edit the all target if necessary (for working with data_io.h). The compiled file should be located in the build folder at the root of the repository. It should be named Quest_4. ==***

***LOADING...***


## Quest 5. Static Lib.

\> *Enter*

     4. Load check_list ...
     4.1. Add the data_io_macro.h implementation with parametric macros that take the array,
     the size, and the format for working with different types of arrays. Add the build_with_macro target to the Makefile... 
     DONE.
     4.2. Build data_stat as a static library (.a). Add the build_with_static target to the Makefile.
     
    Press Enter when it's ready.

***== Quest 5 received. Add the data_stat.a target that builds the data_stat module as the data_stat.a static library, to the Makefile. Add the build_with_static target that builds the main_executable_module, connecting the data_stat module as a static library, to the Makefile. It is not allowed to upload the data_stat.a to the repository, just like any other result of building or compilation (object file, static or dynamic library, executable file). The compiled file should be located in the build folder at the root of the repository. It should be named Quest_5. ==***

***LOADING...***


## Quest 6. Dynamic Lib.

\> *Enter*

     4. Load check_list ...
     4.1. Add the data_io_macro.h implementation with parametric macros that take the array,
     the size, and the format for working with different types of arrays. Add the build_with_macro target to the Makefile... 
     DONE.
     4.2. Build data_stat as a static library (.a). Add the build_with_static target to the Makefile... 
     DONE.
     4.3. Build data_process as a dynamic library (.so). Add the build_with_dynamic target to the Makefile.
     
    Press Enter when it's ready.

***== Quest 6 received. Add the data_process.so target that builds the data_process.so module as the data_process.so dynamic library, to the Makefile. Add the build_with_dynamic target that builds the main_executable_module, connecting the data_process module as a dynamic library, to the Makefile. Make the necessary changes to the code of the main_executable_module, configuring the use of the dynamic library using macros. It is not allowed to upload the data_process.so to the repository, just like any other building result. The compiled file should be located in the build folder at the root of the repository. It should be named Quest_6. ==***

***LOADING...***


# Chapter IV

\> *Enter*

     4. Load check_list ...
     4.1. Add the data_io_macro.h implementation with parametric macros that take the array, 
     the size, and the format for working with different types of arrays. Add the build_with_macro target to the Makefile... 
     DONE.
     4.2. Build data_stat as a static library (.a). Add the build_with_static target to the Makefile... 
     DONE.
     4.2. Build data_process as a dynamic library (.so). Add the build_with_dynamic target to the Makefile...
     DONE
     .....
     Initializing....
     .....
     The maintenance of the gateway of the 1st room of level 3 is complete.
     .....
     Checking door mechanisms...the doors are open...
     Please rate how open the doors are on the scale from 1 to 10:
     >>_

\> *I can just leave, right?*

Try it!

\> *Exit through the door* 

You successfully exit the room through the door. It seems too easy, and the AI has disappeared for some reason.. It's all very suspicious. But it's better to move forward than not to move at all. Clichéd, but true.

***LOADING...***

