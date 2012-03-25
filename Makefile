CFLAGS = -Wall -lm  -march=core2 -pipe -O3

OBJS = libblake/blake256.o  libblake/blake512.o libblake/blake.o

#Executavel capaz de hashar files a partir da command line
blake : $(OBJS)  blake.c 
	gcc $(CFLAGS) -o blake  blake.c $(OBJS)  

$(OBJS): libblake/blake256.h libblake/blake512.h  libblake/blake.h

test: $(OBJS) correctnesstests/test_file256 correctnesstests/test_file512 correctnesstests/test.c
	$(CC) -o test $(CFLAGS) correctnesstests/test.c $(OBJS)

clean: 
	rm -f  libblake/*.o  blake *.o  test bench 

bench: $(OBJS) benchmark/bench.c
	$(CC) -o bench $(CFLAGS) benchmark/bench.c $(OBJS)

compress: blake.tar.bz2

blake.tar.bz2: Makefile $(HEADERFILES) $(CFILES)
	tar jcf blake.tar.bz2 Makefile libblake/ correctnesstests/ benchmark/ imgs/


# FLAGS-lib
# Not (or very) successful: 
#			-fmodulo-sched -fmodulo-sched-allow-regmoves -fno-branch-count-reg
#			-fgcse-sm -fgcse-las -fgcse-after-reload
#			-funsafe-loop-optimizations -fipa-pta  -floop-interchange -floop-strip-mine -floop-block -funroll-loops -funroll-all-loops -fgraphite-identity -floop-flatten -floop-parallelize-all 
#			-ftree-loop-if-convert -ftree-loop-if-convert-stores -ftree-loop-distribution -funswitch-loops -ftree-loop-im
#			-fivopts -fvect-cost-model -ftracer -freorder-blocks-and-partition
#			-funsafe-math-optimizations -fassociative-math -freciprocal-math -ffinite-math-only -fno-signed-zeros -fno-trapping-math
#			-fvpt -fprofile-use -fbranch-target-load-optimize -fbranch-target-load-optimize2 -fbtr-bb-exclusive -fno-stack-protector -fsection-anchors -fprefetch-loop-arrays

