# Poker
A poker game that uses data from the deck to better the user's chances of winning against the computer.

This program consists of three main classes.

They are : 
	Card
	DeckOfCards
	Hand

Card : 
	Consists of an integer hold to the face and suit of a card. There is a corresponding array that allows you to access the certain type of suit or faces.

	There are also 3 public member functions. Two getters for both data members, and
	finally a 'toString' function that uses the static array to returning a string that
	corresponds to the suit and faces integer value.

DeckOfCards : 
	Consists of a vector of cards called 'deck' and also another vector of cards called
	'usedCards' that will be used for a "smarter" implementation of drawing cards. Also,
	there is an integer data member named 'currentCard' that keeps track of how many
	cards are left in the deck for easier access.

	Public member fuctions consists of the constructor that will initialize 52 unique cards, getters, dealCard, moreCards, and finally a function that will shuffle the vector of cards.

Hand :
	The hand class consists of two data members. The first is a vector of cards that will be used to hold each player's five cards. The other member is an array that will allow us to access what cards should be swapped in order for the dealer to have a better chance of getting a flush or a straight.

	Public member functions consists of many getters and setters. The most important functions has to be the sorting functions that makes it easier for us to decide that hand the player has.

To make the dealer "Smarter", the program will decide whether the dealer has the hands :
	straight
	flush
	two pairs
	three of a kind
	or four of a kind

if the hand is a pair, two pairs, or four of a kind, the dealer will swap out cards that will give them a better chance of upgrading to the next tier.

And for the players, they will be given the option to swap out the card of their choice.

In order the run the program, navigate to the directory in terminal and run the command "make".

Follow the instructions afterwards to play the game.
