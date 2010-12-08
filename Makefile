PROJECT = pigeonhol
LIB = lib/
SRC = src/
BUILD = build/
OBJ = $(BUILD)main.o $(BUILD)observer.o $(BUILD)utils.o $(BUILD)file.o $(BUILD)condition.o $(BUILD)rules.o
LIBS = inotify-cxx -Itinyxml
CPP = g++
CXXFLAGS = -Wall -ansi -pedantic-errors

all: compilelib 
	@if [ ! -d "$(BUILD)" ]; then \
		mkdir $(BUILD); \
	fi
	$(CPP) -c $(SRC)observer.cpp -I$(LIB) -o $(BUILD)observer.o $(CXXFLAGS)
	$(CPP) -c $(SRC)utils.cpp -o $(BUILD)utils.o $(CXXFLAGS)
	$(CPP) -c $(SRC)file.cpp -o $(BUILD)file.o $(CXXFLAGS)
	$(CPP) -c $(SRC)condition.cpp -o $(BUILD)condition.o $(CXXFLAGS)
	$(CPP) -c $(SRC)rules.cpp -o $(BUILD)rules.o $(CXXFLAGS)
	$(CPP) -c $(SRC)main.cpp -o $(BUILD)main.o $(CXXFLAGS)
	$(CPP) $(OBJ) -L $(LIB) -l$(LIBS) -o $(BUILD)$(PROJECT) $(CXXFLAGS) 

compilelib:
	$(CPP) -c $(LIB)inotify-cxx.cpp -o $(LIB)inotify-cxx.o
	ar -q $(LIB)libinotify-cxx.a $(LIB)inotify-cxx.o

run: all
	@./$(BUILD)$(PROJECT)
