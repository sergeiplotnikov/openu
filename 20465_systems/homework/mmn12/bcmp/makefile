CFLAGS = -g -Wall -pedantic -ansi
EXECUTABLE = my_bcmp

$(EXECUTABLE): my_bcmp.o my_bytecompare.o
	gcc $(CFLAGS) -o $(EXECUTABLE) my_bcmp.o my_bytecompare.o

my_bcmp.o: my_bcmp.c my_bytecompare.h
	gcc $(CFLAGS) -c my_bcmp.c

my_bytecompare.o: my_bytecompare.c
	gcc $(CFLAGS) -c my_bytecompare.c

.PHONY: clean
clean:
	rm *.o $(EXECUTABLE)

.PHONY: run-examples
run-examples:
	if [ -e $(EXECUTABLE) ]; then \
		while read line; do \
			echo "$$line" | ./$(EXECUTABLE); \
			echo "################################################################################"; \
			echo ""; \
		done < input_examples > results; \
	else \
		echo "\033[0;31m!!! Missing '$(EXECUTABLE)' executable. Plese run 'make' first.\033[0m"; \
	fi; \
