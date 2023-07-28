
GHC_TO_GIR = ./ghc_to_gir.pl
GIR_TO_CC = ./gir_to_cc.pl
BUILTIN_GHC = ./builtin.ghc

all:: sample/hello sample/test sample/tarai sample/primes

sample/hello: sample/hello.cc ghc.h
	g++ --std=c++11 -Wall -g -I. sample/hello.cc -o sample/hello
sample/hello.cc: $(GIR_TO_CC) sample/hello.gir
	$(GIR_TO_CC) sample/hello.gir -o sample/hello.cc
sample/hello.gir: $(GHC_TO_GIR) $(BUILTIN_GHC) sample/hello.ghc
	$(GHC_TO_GIR) $(BUILTIN_GHC) sample/hello.ghc -o sample/hello.gir

sample/hello_to_file: sample/hello_to_file.cc ghc.h
	g++ --std=c++11 -Wall -g sample/hello_to_file.cc -o sample/hello_to_file
sample/hello_to_file.cc: $(GIR_TO_CC) sample/hello_to_file.gir
	$(GIR_TO_CC) sample/hello_to_file.gir -o sample/hello_to_file.cc
sample/hello_to_file.gir: $(GHC_TO_GIR) $(BUILTIN_GHC) sample/hello_to_file.ghc
	$(GHC_TO_GIR) $(BUILTIN_GHC) sample/hello_to_file.ghc -o sample/hello_to_file.gir

sample/test: sample/test.cc ghc.h
	g++ --std=c++11 -Wall -g -I. sample/test.cc -o sample/test
sample/test.cc: $(GIR_TO_CC) sample/test.gir
	$(GIR_TO_CC) sample/test.gir -o sample/test.cc
sample/test.gir: $(GHC_TO_GIR) $(BUILTIN_GHC) sample/test.ghc
	$(GHC_TO_GIR) $(BUILTIN_GHC) sample/test.ghc -o sample/test.gir

sample/tarai: sample/tarai.cc ghc.h
	g++ --std=c++11 -Wall -g -O3 -I. sample/tarai.cc -o sample/tarai
sample/tarai.cc: $(GIR_TO_CC) sample/tarai.gir
	$(GIR_TO_CC) sample/tarai.gir -o sample/tarai.cc
sample/tarai.gir: $(GHC_TO_GIR) $(BUILTIN_GHC) sample/tarai.ghc
	$(GHC_TO_GIR) $(BUILTIN_GHC) sample/tarai.ghc -o sample/tarai.gir

sample/primes: sample/primes.cc ghc.h
	g++ --std=c++11 -Wall -g -O3 -I. sample/primes.cc -o sample/primes
sample/primes.cc: $(GIR_TO_CC) sample/primes.gir
	$(GIR_TO_CC) sample/primes.gir -o sample/primes.cc
sample/primes.gir: $(GHC_TO_GIR) $(BUILTIN_GHC) sample/primes.ghc
	$(GHC_TO_GIR) $(BUILTIN_GHC) sample/primes.ghc -o sample/primes.gir
