PROJECT = pigeonhol
LIB = lib/
SRC = src/
BUILD = build/
OBJ = $(BUILD)main.o $(BUILD)observer.o
CPP = g++
FLAGS = -Wall -ansi -pedantic-errors
LIBS =  

compile:
	if [ ! -d "$(BUILD)" ]; then \
		mkdir $(BUILD); \
	fi
	$(CPP) -c $(SRC)main.cpp -o $(BUILD)main.o $(FLAGS)
	$(CPP) -c $(SRC)observer.cpp -o $(BUILD)observer.o $(FLAGS)
	$(CPP) $(OBJ) -o $(BUILD)$(PROJECT) $(FLAGS) -L $(LIB) $(LIBS)

compilelib:
	g++ lib/inotify-cxx.cpp -shared -o lib/libinotify.lib
