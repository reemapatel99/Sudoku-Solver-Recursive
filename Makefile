all: third

third: third.c
	gcc -Wall -Werror -fsanitize=address third.c -o third

clean: all
	rm -rf third
