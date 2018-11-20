CC = g++
FLAGS = -ggdb -Wall -Werror -std=c++17 -fsanitize=address -fno-omit-frame-pointer
FILES = Source.cpp InputStream.cpp Token.cpp lexical.cpp ll.cpp Para.cpp Exp.cpp datalogProgram.cpp
H_FILES = datalogProgram.h Domain.h Exp.h Fact.h HeadPred.h InputStream.h lexical.h ll.h Para.h Pred.h Query.h Rule.h\
		  Scheme.h Token.h

lab2: $(FILES) $(H_FILES)
	$(CC) $(FLAGS) $(FILES) -o lab2

clean:
	rm -f lab2

tests:
	@echo ' ' 
	@echo Running Input 1 - Should pass
	@echo ==============================================
	- ./lab2 in1.txt
	@echo ==============================================
	@echo ' ' 
	@echo Running Input 2 - Should fail
	@echo ==============================================
	- ./lab2 in2.txt
	@echo ==============================================
	@echo ' ' 
	@echo Running Input 3 - Should fail
	@echo ==============================================
	- ./lab2 in3.txt
	@echo ==============================================
	@echo ' ' 
	@echo Running Input 4 - Should fail
	@echo ==============================================
	- ./lab2 in4.txt
	@echo ==============================================
	@echo ' ' 
	@echo Running Input 5 - Should fail
	@echo ==============================================
	- ./lab2 in5.txt
	@echo ==============================================
	@echo ' ' 
	@echo Running Input 6 - Should fail
	@echo ==============================================
	- ./lab2 in6.txt
	@echo ==============================================
	@echo ' ' 
	@echo Running Input 7 - Should fail
	@echo ==============================================
	- ./lab2 in7.txt
	@echo ==============================================
	@echo ' ' 
	@echo Running Input 8 - Should pass
	@echo ==============================================
	- ./lab2 in8.txt
	@echo ==============================================
	@echo ' ' 
	@echo Running Input 9 - Should pass
	@echo ==============================================
	- ./lab2 in9.txt
	@echo ==============================================
	@echo ' ' 
	@echo Running Input 10 - Should pass
	@echo ==============================================
	- ./lab2 in10.txt
	@echo ==============================================

