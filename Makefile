CC = g++
FLAGS = -I include -std=c++11 -O2 -o
OBJECT = bin/App.o bin/Date.o bin/Diary.o bin/Main.o bin/Time.o 
PROGRAM = ./diary.exe

all: $(PROGRAM)

run: $(PROGRAM)
	./$< interactive

$(PROGRAM): $(OBJECT)
	$(CC) $(FLAGS) $@ $^

bin/%.o: src/%.cpp
	$(CC) $(FLAGS) $@ -c $<

test: src/Test.cpp
	$(CC) -std=c++11 -O2 -o bin/Test.exe $<
	./bin/Test.exe

clean:
	rm -rf bin/*

rmproper: clean
	rm $(PROGRAM)