
GHC_TO_WAM = ./ghc_to_wam.pl
WAM_TO_CC = ./wam_to_cc.pl
BUILTIN_GHC = ./builtin.ghc

all:: sample/hello sample/test sample/tarai sample/primes

sample/hello: sample/hello.cc ghc.h
	g++ --std=c++11 -Wall -g -I. sample/hello.cc -o sample/hello
sample/hello.cc: $(WAM_TO_CC) sample/hello.wam
	$(WAM_TO_CC) sample/hello.wam -o sample/hello.cc
sample/hello.wam: $(GHC_TO_WAM) $(BUILTIN_GHC) sample/hello.ghc
	$(GHC_TO_WAM) $(BUILTIN_GHC) sample/hello.ghc -o sample/hello.wam

sample/hello_to_file: sample/hello_to_file.cc ghc.h
	g++ --std=c++11 -Wall -g sample/hello_to_file.cc -o sample/hello_to_file
sample/hello_to_file.cc: $(WAM_TO_CC) sample/hello_to_file.wam
	$(WAM_TO_CC) sample/hello_to_file.wam -o sample/hello_to_file.cc
sample/hello_to_file.wam: $(GHC_TO_WAM) $(BUILTIN_GHC) sample/hello_to_file.ghc
	$(GHC_TO_WAM) $(BUILTIN_GHC) sample/hello_to_file.ghc -o sample/hello_to_file.wam

sample/test: sample/test.cc ghc.h
	g++ --std=c++11 -Wall -g -I. sample/test.cc -o sample/test
sample/test.cc: $(WAM_TO_CC) sample/test.wam
	$(WAM_TO_CC) sample/test.wam -o sample/test.cc
sample/test.wam: $(GHC_TO_WAM) $(BUILTIN_GHC) sample/test.ghc
	$(GHC_TO_WAM) $(BUILTIN_GHC) sample/test.ghc -o sample/test.wam

sample/tarai: sample/tarai.cc ghc.h
	g++ --std=c++11 -Wall -g -O3 -I. sample/tarai.cc -o sample/tarai
sample/tarai.cc: $(WAM_TO_CC) sample/tarai.wam
	$(WAM_TO_CC) sample/tarai.wam -o sample/tarai.cc
sample/tarai.wam: $(GHC_TO_WAM) $(BUILTIN_GHC) sample/tarai.ghc
	$(GHC_TO_WAM) $(BUILTIN_GHC) sample/tarai.ghc -o sample/tarai.wam

sample/primes: sample/primes.cc ghc.h
	g++ --std=c++11 -Wall -g -I. sample/primes.cc -o sample/primes
sample/primes.cc: $(WAM_TO_CC) sample/primes.wam
	$(WAM_TO_CC) sample/primes.wam -o sample/primes.cc
sample/primes.wam: $(GHC_TO_WAM) $(BUILTIN_GHC) sample/primes.ghc
	$(GHC_TO_WAM) $(BUILTIN_GHC) sample/primes.ghc -o sample/primes.wam
