#make file compilation
compiler=cc

mypreprocessor: main.o comment_removal.o file_inclusion.o macro_handler.o
	$(compiler) $^ -o $@
	
main.o:main.c
	$(compiler) -c $^
comment_removal.o:comment_removal.c
	$(compiler) -c $^
file_inclusion.o:file_inclusion.c
	$(compiler) -c $^
macro_handler.o:macro_handler.c
	$(compiler) -c $^
	
clear :
	@echo "cleaning up..."
	@ rm -rv *.o
