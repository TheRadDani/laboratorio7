#makefile para programa de lista enlazada

#compilador
CC = gcc -Wall -Werror -static -g

#ruta base
DEPENDPATH = .

#ruta de includes
INCLUDEPATH = $(DEPENDPATH)/include

#ruta de archivos objeto
OBJDIR = $(DEPENDPATH)/obj

#ruta de archivos de codigo fuente
SRCDIR = $(DEPENDPATH)/src

#ruta de salida
OUTPUTDIR = $(DEPENDPATH)/build

#archivo de salida
OUTPUT = $(OUTPUTDIR)/ejecutable

all: programa

programa: main.o lista.o
	$(CC) -o $(OUTPUT) $(OBJDIR)/lista.o $(OBJDIR)/main.o

main.o: $(SRCDIR)/main.c
	$(CC) -o $(OBJDIR)/main.o -c $(SRCDIR)/main.c -I$(INCLUDEPATH)

lista.o: $(SRCDIR)/lista.c
	$(CC) -o $(OBJDIR)/lista.o -c $(SRCDIR)/lista.c -I$(INCLUDEPATH)

clean:
	rm -r obj/*.o
	rm -r build/*.bin
	rm -r build/ejecutable
