CC=gcc
CROSS_COMPILE=aarch64-none-linux-gnu


writer: writer.c
	$(CC) writer.c -o writer

CROSS_COMPILE: writer.c
	$(CROSS_COMPILE)-$(CC) writer.c -o writer-cc

clean:
	rm  -f writer writer-cc *.o