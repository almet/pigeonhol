PROJECT = pigeonhol
LIB = lib/
SRC = src/
BUILD = build/
OBJ = $(BUILD)main.o $(BUILD)observer.o
LIBS = inotify-cxx
CPP = g++
CXXFLAGS = -Wall -ansi -pedantic-errors

all: 
	if [ ! -d "$(BUILD)" ]; then \
		mkdir $(BUILD); \
	fi
	$(CPP) -c $(SRC)main.cpp -o $(BUILD)main.o $(CXXFLAGS)
	$(CPP) -c $(SRC)observer.cpp -o $(BUILD)observer.o $(CXXFLAGS)
	$(CPP) $(OBJ) -L $(LIB) -l$(LIBS) -o $(BUILD)$(PROJECT) $(CXXFLAGS) 

compilelib:
	$(CPP) -c $(LIB)inotify-cxx.cpp -o $(LIB)inotify-cxx.o
	ar -q $(LIB)libinotify-cxx.a $(LIB)inotify-cxx.o
