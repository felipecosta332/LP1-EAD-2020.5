CC = g++
FLAGS = -I inc -std=c++11 -O2
OBJECT = bin/App.o bin/Date.o bin/Diary.o bin/Main.o bin/Time.o 
PROGRAM = diary.exe

all: $(PROGRAM)

$(PROGRAM): $(OBJECT)
	$(CC) $(FLAGS) -o $@ $^

bin/%.o: src/%.cpp
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	rm -rf bin/*

rmproper: clean
	rm $(PROGRAM)