# The Diary Project

Federal University of Rio Grande do Norte (UFRN) programming project of the "Programming Language I" class (From portuguese "Linguagem de Programação I", also known as LP1). The purpose of the project is to develop a computer program written in the C++ programming language that creates, reads or write a diary in the .md file extension. The orientations and deadline requirements were given by Professor Waldson Patricio do Nascimento Leandro, teacher of the LP1 class (2020.5 semester).

## How to compile the program

If you are running Linux on your machine, open the terminal and follow the steps:

- Access the project directory.
- Type in the following command on the terminal: "make".
- Press return.

## How to run the program

If you are running Linux on your machine, open the terminal and follow the steps:

- Access the project directory.
- Type in the following command on the terminal: "make run".
- Press return.

## Commands and Parameters

The full list of the program commands, what they do, what parameters they take and a few examples are as follow:

- make: compiles the source code
- make run: compiles the source code and runs the program in interactive mode
- make clean: deletes the object files in the bin directory
- make rmproper: runs "make clean" and deletes "diary.exe"
- make test: compiles and runs the "Test.cpp" source code file for the purpose of testing functions
- ./diary.exe interactive: runs the program in interactive mode
- ./diary.exe add "string": adds message with content set as "string". The program asks the content if the "string" parameter is omitted.
- ./diary.exe list "format": list all messages following the pattern set by the "format" parameter. If the "format" parameter is omitted the messages follow the default pattern set by "diary.config".
- ./diary.exe search "string": list all messages with the "string" parameter in their contents. If the "string" parameter is omitted the program asks.

## Links to clone the repository

- HTTPS: <https://github.com/felipecosta332/grocerystore.git>
- SSH: <git@github.com:felipecosta332/grocerystore.git>
