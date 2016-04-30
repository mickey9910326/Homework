# Project: 專案2
# Makefile created by Dev-C++ 5.11

CPP      = g++.exe -D__DEBUG__
CC       = gcc.exe -D__DEBUG__
WINDRES  = windres.exe
OBJ      = project01.o project01_header.o
LINKOBJ  = project01.o project01_header.o
BIN      = project.exe
CXXFLAGS = $(CXXINCS) -g3
CFLAGS   = $(INCS) -g3
RM       = rm.exe -f

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after

clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o $(BIN) $(LIBS)

project01.o: project01.cpp
	$(CPP) -c project01.cpp -o project01.o $(CXXFLAGS)

project01_header.o: project01_header.cpp
	$(CPP) -c project01_header.cpp -o project01_header.o $(CXXFLAGS)
