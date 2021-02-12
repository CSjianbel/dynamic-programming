CC = clang++ 
FLAGS = -std=c++17 -Wshadow -Wall -Wno-unused-result 

brute = bruteBestSum
memo = memoBestSum

$(brute):

	$(CC) $(FLAGS) -O2 -o $(brute) $(brute).cpp

$(memo):

	$(CC) $(FLAGS) -O2 -o $(memo) $(memo).cpp

clean: 
	rm -f $(memo)
	rm -f $(brute)
