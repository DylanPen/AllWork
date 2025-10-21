CC=g++ --std=c++20 -g
exe_file=nn
test_file=nn_test

$(exe_file): main.cpp nn.o node.o sigmoid.o
	$(CC) main.cpp nn.o node.o sigmoid.o -o $(exe_file)

test: test.cpp nn.o node.o sigmoid.o
	$(CC) test.cpp nn.o node.o sigmoid.o -o $(test_file)

nn.o: nn.h nn.cpp
	$(CC) -c nn.cpp

node.o: node.h node.cpp
	$(CC) -c node.cpp

sigmoid.o: sigmoid.h sigmoid.cpp
	$(CC) -c sigmoid.cpp

clean: 
	rm -f *.o $(exe_file) $(test_file)