SRC=main.cpp
SRC+=ZoneBagage.cpp Boutique.cpp Personne.cpp Douanier.cpp Visiteur.cpp Position.cpp ZoneEmbarquement.cpp Map.cpp Random_MT.cpp Zone.cpp
EXE=SMAirport

CC=g++
CFLAGS:=-Wall -Wextra -g 
LDFLAGS:=-lm

OBJ=$(addprefix build/,$(SRC:.cpp=.o))
DEP=$(addprefix build/,$(SRC:.cpp=.d))

all: $(OBJ) 
	$(CC) -o $(EXE) $^ $(LDFLAGS)

build/%.o: %.cpp
	@mkdir -p build
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf build core *.o
	rm -rf $(EXE)

-include $(DEP)						