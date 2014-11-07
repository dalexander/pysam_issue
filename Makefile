

build:
	gcc -I ../htslib/htslib htslib_example.c ../htslib/libhts.a -lz -o htslib_example

clean:
	-rm -rf *~ htslib_example
