PAKAGES = packages
STIVA = $(PAKAGES)\stiva_q
DB = $(PAKAGES)\db_q
BIN = bin
EXTERNBIN = $(BIN)\extern
MAIN = index.c
MAIN_EXE = index.exe
EXTERNCONECTS = $(EXTERNBIN)\stiva_q.o $(EXTERNBIN)\db_q.o
COMPILEINDEX = $(BIN)\$(MAIN_EXE)

all: delIndex $(COMPILEINDEX)

$(BIN):
	mkdir $(BIN)

$(EXTERNBIN):
	mkdir $(EXTERNBIN)

$(EXTERNBIN)\stiva_q.o:
	gcc -c $(STIVA)\stiva_q.c -o $(EXTERNBIN)\stiva_q.o

$(EXTERNBIN)\db_q.o:
	gcc -c $(DB)\db_q.c -o $(EXTERNBIN)\db_q.o

$(COMPILEINDEX): $(BIN) $(EXTERNBIN) $(EXTERNCONECTS)
	gcc $(MAIN) $(EXTERNCONECTS) -o $(BIN)\index.exe

clear:
	rmdir /S /Q bin

delIndex:
	del /f $(BIN)\$(MAIN_EXE)