# test manager and diary
# without UI
CC = g++
SRCOBJS = Manager.o Diary.o
OBJS = backendtest.o $(SRCOBJS)

test: $(OBJS)
	$(CC) $(OBJS) -o $@

clean:
	rm -f $(OBJS) test