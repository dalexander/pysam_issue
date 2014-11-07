

build:
	gcc -I ../htslib/htslib htslib_example.c ../htslib/libhts.a -lz -o htslib_example

clean:
	-rm -rf *~ htslib_example

demo: htslib_example
	@echo "From pysam:"
	./pysam_example.py bam_mapping.bam
	@echo
	@echo "From htslib:"
	./htslib_example bam_mapping.bam
