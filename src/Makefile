CC = g++
CFLAGS = -Wall -std=c++17

# Lista fișierelor sursă și obiect
SRC = main.cpp Angajat.cpp Barista.cpp Manager.cpp Ospatar.cpp Comanda.cpp Cafenea.cpp Eveniment.cpp Rapoarte.cpp
OBJ = $(SRC:.cpp=.o)

# Numele executabilului
TARGET = cafenea

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)
	rm -f $(OBJ)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

