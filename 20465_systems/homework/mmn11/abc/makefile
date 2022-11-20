CFLAGS = -Wall -pedantic -ansi
EXECUTABLE = abc

$(EXECUTABLE): abc.o shorten.o
	gcc $(CFLAGS) -o $(EXECUTABLE) abc.o shorten.o

abc.o: abc.c shorten.h
	gcc $(CFLAGS) -c abc.c

shorten.o: shorten.c
	gcc $(CFLAGS) -c shorten.c

.PHONY: clean
clean:
	rm *.o $(EXECUTABLE)

.PHONY: run-examples
run-examples:
	if [ -e $(EXECUTABLE) ]; then \
		while read line; do \
			./$(EXECUTABLE) "$$line"; \
			echo ""; \
		done < input_examples > results; \
	else \
		echo "\033[0;31m!!! Missing '$(EXECUTABLE)' executable. Plese run 'make' first.\033[0m"; \
	fi; \
