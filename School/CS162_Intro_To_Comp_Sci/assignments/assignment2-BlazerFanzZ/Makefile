CC=g++
exe_file=run_catalog

all:$(exe_file)

$(exe_file): catalog.o catalog.hpp run_wizard.cpp
	$(CC) catalog.o run_wizard.cpp -o $(exe_file)

catalog.o: catalog.hpp catalog.cpp
	$(CC) -c catalog.cpp

clean:
	rm -f *.o $(exe_file)