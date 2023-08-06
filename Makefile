
GHC_TO_GIR = ./ghc_to_gir.pl
GIR_TO_CC = ./gir_to_cc.pl
BUILTIN_GHC = ./builtin.ghc

CXX=g++
CXXFLAGS=--std=c++11 -Wall -g -I.

TARGETS=sample/hello sample/test sample/tarai sample/tarai_reordered sample/primes sample/hanoi sample/queen

all:: $(TARGETS)

clean::
	rm -f $(TARGETS)

sample/hello: sample/hello.cc ghc.h
	$(CXX) $(CXXFLAGS) sample/hello.cc -o sample/hello
sample/hello.cc: $(GIR_TO_CC) sample/hello.gir
	$(GIR_TO_CC) sample/hello.gir -o sample/hello.cc
sample/hello.gir: $(GHC_TO_GIR) $(BUILTIN_GHC) sample/hello.ghc
	$(GHC_TO_GIR) $(BUILTIN_GHC) sample/hello.ghc -o sample/hello.gir

sample/test: sample/test.cc ghc.h
	$(CXX) $(CXXFLAGS) sample/test.cc -o sample/test
sample/test.cc: $(GIR_TO_CC) sample/test.gir
	$(GIR_TO_CC) sample/test.gir -o sample/test.cc
sample/test.gir: $(GHC_TO_GIR) $(BUILTIN_GHC) sample/test.ghc
	$(GHC_TO_GIR) $(BUILTIN_GHC) sample/test.ghc -o sample/test.gir

sample/tarai: sample/tarai.cc ghc.h
	$(CXX) $(CXXFLAGS) -O3 sample/tarai.cc -o sample/tarai
sample/tarai.cc: $(GIR_TO_CC) sample/tarai.gir
	$(GIR_TO_CC) sample/tarai.gir -o sample/tarai.cc
sample/tarai.gir: $(GHC_TO_GIR) $(BUILTIN_GHC) sample/tarai.ghc
	$(GHC_TO_GIR) $(BUILTIN_GHC) sample/tarai.ghc -o sample/tarai.gir

sample/tarai_reordered: sample/tarai_reordered.cc ghc.h
	$(CXX) $(CXXFLAGS) -O3 sample/tarai_reordered.cc -o sample/tarai_reordered
sample/tarai_reordered.cc: $(GIR_TO_CC) sample/tarai_reordered.gir
	$(GIR_TO_CC) sample/tarai_reordered.gir -o sample/tarai_reordered.cc
sample/tarai_reordered.gir: $(GHC_TO_GIR) $(BUILTIN_GHC) sample/tarai_reordered.ghc
	$(GHC_TO_GIR) $(BUILTIN_GHC) sample/tarai_reordered.ghc -o sample/tarai_reordered.gir

sample/primes: sample/primes.cc ghc.h
	$(CXX) $(CXXFLAGS) -O3 sample/primes.cc -o sample/primes
sample/primes.cc: $(GIR_TO_CC) sample/primes.gir
	$(GIR_TO_CC) sample/primes.gir -o sample/primes.cc
sample/primes.gir: $(GHC_TO_GIR) $(BUILTIN_GHC) sample/primes.ghc
	$(GHC_TO_GIR) $(BUILTIN_GHC) sample/primes.ghc -o sample/primes.gir

sample/hanoi: sample/hanoi.cc ghc.h
	$(CXX) $(CXXFLAGS) -O3 sample/hanoi.cc -o sample/hanoi
sample/hanoi.cc: $(GIR_TO_CC) sample/hanoi.gir
	$(GIR_TO_CC) sample/hanoi.gir -o sample/hanoi.cc
sample/hanoi.gir: $(GHC_TO_GIR) $(BUILTIN_GHC) sample/hanoi.ghc
	$(GHC_TO_GIR) $(BUILTIN_GHC) sample/hanoi.ghc -o sample/hanoi.gir

sample/queen: sample/queen.cc ghc.h
	$(CXX) $(CXXFLAGS) -O3 sample/queen.cc -o sample/queen
sample/queen.cc: $(GIR_TO_CC) sample/queen.gir
	$(GIR_TO_CC) sample/queen.gir -o sample/queen.cc
sample/queen.gir: $(GHC_TO_GIR) $(BUILTIN_GHC) sample/queen.ghc
	$(GHC_TO_GIR) $(BUILTIN_GHC) sample/queen.ghc -o sample/queen.gir
