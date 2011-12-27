ALL = common.o array.o list.o
TESTS = array_test list_test

all : $(ALL)

test : $(TESTS)

array_test : array_test.o array.o common.o
list_test : list_test.o list.o common.o

%.o : %.c
	$(CC) -c $(CFLAGS) $<

clean:
	rm -f $(ALL) $(TESTS) *.o

.PHONY : clean
