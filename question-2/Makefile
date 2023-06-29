SOURCE = solution.c
EXEC = solution.bin

all:
	@ gcc $(SOURCE) -o $(EXEC)

run:
	@ ./$(EXEC)

valgrind:
	@ valgrind --leak-check=full ./$(EXEC)

clean:
	@ rm $(EXEC)
