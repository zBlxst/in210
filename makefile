CXX = gcc

LDFLAGS = --coverage
OPTION = -Wall -fexceptions -fprofile-arcs -ftest-coverage

INCS = -I.  -I"." 
OBJS = $(SRC:.c=.o)

SRC = ratp.c  main.c cmocka.o


all: $(OBJS)
	$(CXX) $(LDFLAGS) $(INCS) -o testAll  $(OBJS)

	
exec : all
	testAll.exe
%.o: %.c
	$(CXX) $(OPTION) -c  $< -o $@ $(INCS)
	
clean:
	rm -rf $(OBJS) 


mrproper: clean
	rm -rf testAll
	rm -rf result.xml
	rm -rf *.gcda
	rm -rf *.html
	rm -rf *.gcno
	rm -rf *.cbp
	rm -rf *.gcov
	rm -rf *.depend
	rm -rf *layout
	rm -rf *.css