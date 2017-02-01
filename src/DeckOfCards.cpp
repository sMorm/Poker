#include "deck.h"
// START OF DECKOFCARDS CLASS
/*
    Our default constructor has a nested loop
    that allows us to create 52 cards. After 
    they have been created, they will be placed
    inside of our vector "deck". Finally, they will be randomly shuffled using the function 'random_shuffle' from the <algorithm> library.
*/
DeckOfCards::DeckOfCards(){
    for(int face = 0; face < 13 ; ++face){
        for(int suit = 0; suit < 4; ++suit){
            Card toPush(face, suit);
            deck.push_back(toPush);
        }
    }
    currentCard = 52;
    random_shuffle(deck.begin(),deck.end());
}

int DeckOfCards::getSize(){return currentCard;}
vector<Card> DeckOfCards::getUsedDeck(){return usedCards;}
void DeckOfCards::shuffleDeck(){
    random_shuffle(deck.begin(), deck.end());
}
/*
    Our dealCard function allows us to pop back the
    last card in our deck, removes it, and finally
    increments the currentCard count to keep track
    of how many cards have been removed from the deck.
    
    Our usedCards deck allows us to determine what cards have been dealt in order to increase our chance of having a better hand when determining what cards are unused in the deck.
*/
Card DeckOfCards::dealCard(){
    if(moreCards()){
    Card toReturn = deck.back();
    usedCards.push_back(deck.back());
    deck.pop_back();
    currentCard--;
    return toReturn;
    }
    throw "No cards left";
}
/*
    The moreCards function determines if more than 52 cards have been dealt.
*/
bool DeckOfCards::moreCards(){
    if(currentCard == 0)
        return false;
    else 
        return true;
}
// END OF DECK CLASS
//*********************************

