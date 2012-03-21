CFLAGS = -Wall -g

HEADERFILES = libblake/blake256.h libblake/blake512.h  libblake/blake.h
CFILES = libblake/blake256.c  libblake/blake512.c libblake/blake.c

OBJS = libblake/blake256.o  libblake/blake512.o libblake/blake.o

#Executavel capaz de hashar files a partir da command line
blake : $(OBJS)  blake.c 
	gcc $(CFLAGS) -o blake  blake.c $(OBJS)  

$(OBJS): libblake/blake256.h libblake/blake512.h  libblake/blake.h

test: $(OBJS) correctnesstests/test_file256 correctnesstests/test_file512 correctnesstests/test.c
	$(CC) -o test $(CFLAGS) correctnesstests/test.c $(OBJS)

clean: $(OBJS)
	rm -f $(OBJS) blake

clean-test: $(OBJS)
	     rm -f $(OBJS) test correctnesstests/test.o
remake: 
	clean all
remake-test: 
	clean-test test

compress: blake.tar.bz2

blake.tar.bz2: Makefile $(HEADERFILES) $(CFILES)
	tar jcf blake.tar.bz2 Makefile libblake/ correctnesstests/ benchmark/ 1MB.bmp 10MB.bmp		#$(HEADERFILES) $(CFILES)

