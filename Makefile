all: MyDynArray 

MyDynArray:
	g++ -std=c++0x main.cpp card.cpp DeckOfCards.cpp hand.cpp game.cpp -o main
	./main
clean:
	rm MyDynArray 