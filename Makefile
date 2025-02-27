.PHONY: test
test:
	cc -Wall -Werror -o arena_test arena_test.c
	./arena_test
