CPP = g++
CPPFLAGS = -Wall

TRABALHO3OBJS = main.o catalogo.o filme.o

trabalho3: $(TRABALHO3OBJS)
	$(CPP) $(CPPFLAGS) -o $@ $(TRABALHO3OBJS)