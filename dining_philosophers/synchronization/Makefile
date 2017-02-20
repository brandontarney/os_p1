
OBJS = main.o diners.o simp_sem.o
OBJS2 = test_dining_philosophers.o diners.o simp_sem.o

diners: $(OBJS)
	cc $(OBJS) -lpthread -lrt -o $@

test_dining_philosophers: $(OBJS2)
	cc $(OBJS2) -lpthread -lrt -o $@

clean:
	rm -f $(OBJS)
clean2:
	rm -f $(OBJS2)
