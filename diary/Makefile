CC = g++
FLAGS = -I inc -std=c++11 -Wall -O2
OBJECTS = bin/App.o bin/Date.o bin/Diary.o bin/Main.o bin/Time.o
PROGRAM = diary.exe

$(PROGRAM): objects $(OBJECTS)
	$(CC) $(FLAGS) -o $(PROGRAM) $(OBJECTS)

objects:
	mv *.o bin

bin/Main.o: src/Main.cpp
	$(CC) $(FLAGS) -c src/Main.cpp

bin/App.o: src/App.cpp inc/App.h
	$(CC) $(FLAGS) -c src/App.cpp

bin/Date.o: src/Date.cpp inc/Date.h
	$(CC) $(FLAGS) -c src/Date.cpp

bin/Diary.o: src/Diary.cpp inc/Diary.h
	$(CC) $(FLAGS) -c src/Diary.cpp

bin/Time.o: src/Time.cpp inc/Time.h
	$(CC) $(FLAGS) -c src/Time.cpp