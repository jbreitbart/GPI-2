BIN = fetch_add.bin compare_swap.bin fetch_add_test.bin compare_swap_test.bin  \
	fetch_add_loop.bin fetch_add_unalignd.bin

CFLAGS+=-I../

build: $(BIN)

%.bin: %.o ../test_utils.o  
	$(CC) $(CFLAGS) $(LIB_PATH) -o $(TOPROOT)/bin/$@ $^ $(LIBS)
clean:
	rm -rf *~ \#_* *.o *.bin
