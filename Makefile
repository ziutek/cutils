ALL = common.o array.o
TESTS = array_test

all : $(ALL)

test : $(TESTS)

array_test : array_test.o array.o common.o


%.o : %.c
	$(CC) -c $(CFLAGS) $<

clean:
	rm -f $(ALL) $(TESTS) *.o

.PHONY : clean
