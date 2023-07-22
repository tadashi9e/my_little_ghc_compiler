# My Little Guarded Horn Clauses Compiler Construction Project

## Overview

This project aims to implement a tiny compier for Guarded Horn Clauses (GHC).

Currently, this is written in SWI-Prolog and C++ (I hope this will be a self-hosting compiler in future).

GHC is a logic programming language used in artificial intelligence and knowledge representation.

The compiler translates GHC code into an intermediate representation (GIR - GHC Intermediate Representation) and further converts it to executable C++ code.

GIR is almost WAM(Warren't Abstract Machine), but not same because GHC is comitted choise language.

## Project Structure

This repository contains following files:

- `sample/*.ghc`: Sample GHC code files for testing and experimentation.
- `Makefile`: Makefile to compile the sample GHC files and generate executable output.
- `ghc_to_gir.pl`: GHC to GIR translator written in Prolog.
- `gir_to_cc.pl`: GIR to C++ translator written in Prolog.
- `kvs.pl`: Utility predicates file used in ghc_to_gir.pl and gir_to_cc.pl.

## Requirements

- SWI-Prolog: Install SWI-Prolog to execute the Prolog-based translators.
- C++ Compiler (g++): Required to compile the generated C++ code.

## Getting Started

1. Install SWI-Prolog and g++ on your system.

2. Clone this repository and navigate to the project directory.

3. Type `make` in the terminal. This will perform the following tasks:
   - Convert GHC files in `sample/` to GIR files.
   - Translate GIR files to C++ code.
   - Generate executable files from the C++ code.

4. Find the generated GIR files in `sample/` with a '.gir' extension.
   Find the compiled executables in `sample/` without any extension.

## Limitation

This is my personal hobby project.

- Translators lack error detection and error reporting.
- Garbage collections not implemented yet.

## In Future...

- Add indexing operations to GIR such as 'switch-on-xxx' in WAM.
- Support multithreading.
- Implement garbage collection.

## License

MIT License.
