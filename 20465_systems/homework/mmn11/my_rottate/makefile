CFLAGS = -Wall -pedantic -ansi
EXECUTABLE = my_rottate

$(EXECUTABLE): my_rottate.o rottate.o
	gcc $(CFLAGS) -o $(EXECUTABLE) my_rottate.o rottate.o

my_rottate.o: rottate.h
	gcc $(CFLAGS) -c my_rottate.c

rottate.o:
	gcc $(CFLAGS) -c rottate.c

.PHONY: clean
clean:
	rm *.o $(EXECUTABLE)

.PHONY: run-examples
run-examples:
	if [ -e $(EXECUTABLE) ]; then \
		while read line; do \
			./$(EXECUTABLE) $$line; \
			echo ""; \
		done < input_examples > results; \
	else \
		echo "\033[0;31m!!! Missing '$(EXECUTABLE)' executable. Plese run 'make' first.\033[0m"; \
	fi; \
