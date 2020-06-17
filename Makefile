
# code details

EXE_DIR = .
EXE = $(EXE_DIR)/MapProject

SRC= main.c fileReader.c adjacency.c Astar.c output.c

# generic build details

CC=      cc
COPT=    -g
CFLAGS= -lm

# compile to  object code

OBJ= $(SRC:.c=.o)

.c.o:
	$(CC) $(COPT) -c -o $@ $<

# build executable

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(EXE)

# clean up compilation

clean:
	rm -f $(OBJ) $(EXE)

# dependencies

MapProject.o:  MapProject.c  fileReader.h Astar.h nodeList.h adjacency.h
fileReader.o: fileReader.c fileReader.h nodeList.h
adjacency.o: adjacency.c adjacency.h nodeList.h
Astar.o: Astar.c Astar.h nodeList.h
output.o: output.c output.h nodeList.h
