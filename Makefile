include /var/www/c/makefile

OBJS = list.o


list : $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $@ $(LFLAGS) -pthread

.PHONY: clean
clean:
	\rm list
	\find . -name '*.o' -delete
