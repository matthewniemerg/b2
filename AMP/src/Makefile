INCLUDE=-I../include
LIBS=-lgmp -lmpfr
DEFS= #
OPT= #

CC=/usr/local/gcc-4.7.3/bin/g++

# Describe how to create the object file
%.o:  %.cpp
	$(CC) $(INCLUDE) $(DEFS) $(OPT) -c $< -o $@



all: test_amp test_complex_amp test_mpfr rounding_issues
#	make test_amp; make test_complex_amp;

test_mpfr: test_mpfr.o
	$(CC) -o test_mpfr test_mpfr.o $(LIBS)

test_amp: test_amp.o amp.o bvalue.o
	$(CC) -o test_amp test_amp.o amp.o bvalue.o $(LIBS)


test_complex_amp: test_complex_amp.o complex_amp.o amp.o bvalue.o
	$(CC) -o test_complex_amp test_complex_amp.o complex_amp.o amp.o bvalue.o $(LIBS)

rounding_issues: rounding_issues.o complex_amp.o amp.o bvalue.o
	$(CC) -o rounding_issues rounding_issues.o complex_amp.o amp.o bvalue.o $(LIBS)

test_amp_rounding: test_amp_rounding.o amp.o bvalue.o
	$(CC) -o test_amp_rounding test_amp_rounding.o amp.o bvalue.o $(LIBS)
test_memory: test_memory.o complex_amp.o amp.o bvalue.o 
	$(CC) -o test_memory test_memory.o complex_amp.o amp.o bvalue.o $(LIBS)
test_base_ptr: test_base_ptr.o complex_amp.o amp.o bvalue.o
	$(CC) -o test_base_ptr test_base_ptr.o complex_amp.o amp.o bvalue.o $(LIBS)
clean:
	rm -rf *~ *.o test_amp test_complex_amp test_mpfr rounding_issues test_amp_rounding test_memory test_base_ptr
