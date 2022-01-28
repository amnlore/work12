all: dirinfo.o
	gcc -o dirinfo dirinfo.c
dirinfo.o: dirinfo.c
	gcc -c dirinfo.c
run:
	./dirinfo
clean:
	rm *.o
	rm dirinfo
