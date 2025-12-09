all:
	g++ -std=c++14 -pthread PhoneLine.cpp PhoneLine_sm.cpp test.cpp -lgtest -lgtest_main -pthread -o test_app
	./test_app

install:
	sudo apt-get install libgtest-dev

clean:
	rm -f test_app


