CPP = g++ 
FLAGS = -Wall -pedantic -std=c++11 -g
PROG = Biblioteca

OBJS = src/main.o src/livro.o src/usuario.o src/emprestimo.o


/bin/$(PROG) : $(OBJS)
	$(CPP) -o bin/$(PROG) $(OBJS)

src/emprestimo.o: src/emprestimo.h
	$(CPP) $(FLAGS) -c /src/emprestimo.cpp 

src/usuario.o: src/usuario.h
	$(CPP) $(FLAGS) -c /src/usuario.cpp 

src/livro.o : src/livro.h
	$(CPP) $(FLAGS) -c /src/livro.cpp 

src/main.o : src/listaEncadeada.h  
	$(CPP) $(FLAGS) -c /src/main.cpp


clean:
	rm -f core bin/$(PROG) src/$(OBJS)