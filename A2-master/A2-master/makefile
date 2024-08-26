stringMe: shethTishaA2.o shethTishaA2Main.o
	gcc -Wall -std=c99 shethTishaA2.o shethTishaA2Main.o -o bin/stringMe
shethTishaA2.o: src/shethTishaA2.c include/shethTishaA2.h
	gcc -Wall -std=c99 -c src/shethTishaA2.c
shethTishaA2Main.o: src/shethTishaA2Main.c include/shethTishaA2.h
	gcc -Wall -std=c99 -c src/shethTishaA2Main.c
clean:
	rm *.o bin/stringMe
