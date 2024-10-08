
GHC_TO_GIR = ./ghc_to_gir.pl
GIR_TO_CC = ./gir_to_cc.pl
BUILTIN_GHC = ./builtin.ghc
BUILTIN_GIR = ./builtin.gir

CXX=g++
CXXFLAGS=--std=c++11 -Wall -g -I./include

GHC_HEADERS=include/ghc_dumpdot.h include/ghc.h include/ghc_symbols.h include/ghc_tags.h include/ghc_tagutils.h include/ghc_vm.h include/ghc_vm_ops.h

TARGETS=sample/hello sample/test sample/tarai sample/tarai_reordered \
	sample/primes sample/hanoi sample/queen sample/qsort sample/fibonacci \
	sample/microkanren sample/collatz

all:: $(TARGETS)

clean::
	rm -f $(TARGETS)

builtin.gir: $(GHC_TO_GIR) builtin.ghc
	$(GHC_TO_GIR) $(BUILTIN_GHC) -o $(BUILTIN_GIR)

sample/hello: sample/hello.cc ${GHC_HEADERS}
	$(CXX) $(CXXFLAGS) sample/hello.cc -o sample/hello
sample/hello.cc: $(GIR_TO_CC) $(BUILTIN_GIR) sample/hello.gir
	$(GIR_TO_CC) $(BUILTIN_GIR) sample/hello.gir -o sample/hello.cc
sample/hello.gir: $(GHC_TO_GIR) sample/hello.ghc
	$(GHC_TO_GIR) sample/hello.ghc -o sample/hello.gir

sample/test: sample/test.cc ${GHC_HEADERS}
	$(CXX) $(CXXFLAGS) sample/test.cc -o sample/test
sample/test.cc: $(GIR_TO_CC) $(BUILTIN_GIR) sample/test.gir
	$(GIR_TO_CC) $(BUILTIN_GIR) sample/test.gir -o sample/test.cc
sample/test.gir: $(GHC_TO_GIR) $(BUILTIN_GHC) sample/test.ghc
	$(GHC_TO_GIR) sample/test.ghc -o sample/test.gir

sample/tarai: sample/tarai.cc ${GHC_HEADERS}
	$(CXX) $(CXXFLAGS) -O3 sample/tarai.cc -o sample/tarai
sample/tarai.cc: $(GIR_TO_CC) $(BUILTIN_GIR) sample/tarai.gir
	$(GIR_TO_CC) $(BUILTIN_GIR) sample/tarai.gir -o sample/tarai.cc
sample/tarai.gir: $(GHC_TO_GIR) sample/tarai.ghc
	$(GHC_TO_GIR) sample/tarai.ghc -o sample/tarai.gir

sample/tarai_reordered: sample/tarai_reordered.cc ${GHC_HEADERS}
	$(CXX) $(CXXFLAGS) -O3 sample/tarai_reordered.cc -o sample/tarai_reordered
sample/tarai_reordered.cc: $(GIR_TO_CC) $(BUILTIN_GIR) sample/tarai_reordered.gir
	$(GIR_TO_CC) $(BUILTIN_GIR) sample/tarai_reordered.gir -o sample/tarai_reordered.cc
sample/tarai_reordered.gir: $(GHC_TO_GIR) sample/tarai_reordered.ghc
	$(GHC_TO_GIR) sample/tarai_reordered.ghc -o sample/tarai_reordered.gir

sample/primes: sample/primes.cc ${GHC_HEADERS}
	$(CXX) $(CXXFLAGS) -O3 sample/primes.cc -o sample/primes
sample/primes.cc: $(GIR_TO_CC) $(BUILTIN_GIR) sample/primes.gir
	$(GIR_TO_CC) $(BUILTIN_GIR) sample/primes.gir -o sample/primes.cc
sample/primes.gir: $(GHC_TO_GIR) sample/primes.ghc
	$(GHC_TO_GIR) sample/primes.ghc -o sample/primes.gir

sample/hanoi: sample/hanoi.cc ${GHC_HEADERS}
	$(CXX) $(CXXFLAGS) -O3 sample/hanoi.cc -o sample/hanoi
sample/hanoi.cc: $(GIR_TO_CC) $(BUILTIN_GIR) sample/hanoi.gir
	$(GIR_TO_CC) $(BUILTIN_GIR) sample/hanoi.gir -o sample/hanoi.cc
sample/hanoi.gir: $(GHC_TO_GIR) sample/hanoi.ghc
	$(GHC_TO_GIR) sample/hanoi.ghc -o sample/hanoi.gir

sample/queen: sample/queen.cc ${GHC_HEADERS}
	$(CXX) $(CXXFLAGS) -O3 sample/queen.cc -o sample/queen
sample/queen.cc: $(GIR_TO_CC) $(BUILTIN_GIR) sample/queen.gir
	$(GIR_TO_CC) $(BUILTIN_GIR) sample/queen.gir -o sample/queen.cc
sample/queen.gir: $(GHC_TO_GIR) sample/queen.ghc
	$(GHC_TO_GIR) sample/queen.ghc -o sample/queen.gir

sample/qsort: sample/qsort.cc ${GHC_HEADERS}
	$(CXX) $(CXXFLAGS) sample/qsort.cc -o sample/qsort
sample/qsort.cc: $(GIR_TO_CC) $(BUILTIN_GIR) sample/qsort.gir
	$(GIR_TO_CC) $(BUILTIN_GIR) sample/qsort.gir -o sample/qsort.cc
sample/qsort.gir: $(GHC_TO_GIR) sample/qsort.ghc
	$(GHC_TO_GIR) sample/qsort.ghc -o sample/qsort.gir

sample/fibonacci: sample/fibonacci.cc ${GHC_HEADERS}
	$(CXX) $(CXXFLAGS) sample/fibonacci.cc -o sample/fibonacci
sample/fibonacci.cc: $(GIR_TO_CC) $(BUILTIN_GIR) sample/fibonacci.gir
	$(GIR_TO_CC) $(BUILTIN_GIR) sample/fibonacci.gir -o sample/fibonacci.cc
sample/fibonacci.gir: $(GHC_TO_GIR) sample/fibonacci.ghc
	$(GHC_TO_GIR) sample/fibonacci.ghc -o sample/fibonacci.gir

sample/microkanren: sample/microkanren.cc ${GHC_HEADERS}
	$(CXX) $(CXXFLAGS) sample/microkanren.cc -o sample/microkanren
sample/microkanren.cc: $(GIR_TO_CC) $(BUILTIN_GIR) sample/microkanren.gir
	$(GIR_TO_CC) $(BUILTIN_GIR) sample/microkanren.gir -o sample/microkanren.cc
sample/microkanren.gir: $(GHC_TO_GIR) sample/microkanren.ghc
	$(GHC_TO_GIR) sample/microkanren.ghc -o sample/microkanren.gir

sample/collatz: sample/collatz.cc ${GHC_HEADERS}
	$(CXX) $(CXXFLAGS) sample/collatz.cc -o sample/collatz
sample/collatz.cc: $(GIR_TO_CC) $(BUILTIN_GIR) sample/collatz.gir
	$(GIR_TO_CC) $(BUILTIN_GIR) sample/collatz.gir -o sample/collatz.cc
sample/collatz.gir: $(GHC_TO_GIR) sample/collatz.ghc
	$(GHC_TO_GIR) sample/collatz.ghc -o sample/collatz.gir
