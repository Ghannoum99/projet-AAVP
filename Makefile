main: main.o tas.o tas_fibonacci.o graphe.o etat.o dijkstra.o
	@gcc main.o tas.o tas_fibonacci.o graphe.o etat.o dijkstra.o -o main
	
main.o: main.c
	@gcc -c main.c
	
tas.o: tas.c tas.h
	@gcc tas.c

tas_fibonacci.o: tas_fibonacci.c tas_fibonacci.h
	@gcc tas_fibonacci.c

graphe.o: graphe.c graphe.h
	@gcc graphe.c graphe.h

etat.o: etat.c etat.h
	@gcc etat.c
	
dijkstra.o: dijkstra.c dijkstra.h
	@gcc dijkstra.c
	
clean:
	@rm *.o main
