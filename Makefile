#compilateur et argument
CC=gcc
CFLAGS = -Wall -Werror -pedantic
CDEBUGF= -g

#fichier .c contenant le main et nom du programe
TARGET = LO21.c
MAIN = LO21

#liste des fichiers .c qui serons transformer en .o
OSRCS= ./bits/bits.c 
OBJS = $(OSRCS:.c=.o)

#liste des fichier .c qui serons transformer en .so
LSRCS= 
DLIBS = $(LSRC:.c=.so)

#liste des libs et des dossier ou trouver les lib en plus /usr/lib avec -L
LIBS = -L./
LFLAG=

#liste des dossiers ou trouver les headers en plus de /usr/include avec -I
INCLUDES= -I./

all: $(MAIN)
	@echo Programme compiler: $(MAIN)

$(MAIN): $(TARGET)  $(OBJS) $(DLIBS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(TARGET) $(OBJS) $(DLIBS) $(LFLAGS) $(LIBS) 

.c.o:
	@echo compilage de $< vers $@
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

.c.so:
	@echo Création de la Librairie $@
	$(CC) -shared -o $@ $<

clean:
	@echo Nettoyage des fichier temporaire de compilation
	rm -r -f *.o *~ ./*/*.o ./*/*~

cleanall:
	@echo Nettoyage de tout les fichiers créer lors de la compilation
	rm -f -r *.o *~ *.so ./*/*.o ./*/*~ ./*/*.so $(MAIN)

debug: dbg all
	gdb ./$(MAIN)

dbg:
CFLAGS+= $(CDEBUGF)

lib: $(DLIBS)
	@echo Lib compiler


