/*
   Computing III -- project - Problem #2
   deck.h
   Author : Serey Morm
   Due    : May 1st, 2016
   *******************************************
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#ifndef DECK_H
#define DECK_H
using namespace std;

//Made size 5, easier to differentiate hierachy of
//suits, first value is null
/*
♠ U+2660 Black Spade Suit
♡ U+2661 White Heart Suit
♢ U+2662 White Diamond Suit
♣ U+2663 Black Club Suit
♤ U+2664 White Spade Suit
♥ U+2665 Black Heart Suit
♦ U+2666 Black Diamond Suit
♧ U+2667 White Club Suit
*/
/*
  These string arrays will make it easier to differentiate each rank of our deck of cards. Especially with the faces.
 */
static string suitArray[4] = {"♣CLUBS♧", "♥HEARTS♡", "♦DIAMONDS♢", "♠SPADES♤"};
static string faceArray[13] ={
    "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"
};
/*
  Our most basic object is 'Card'. Card will simply represent a card that has a face and a suit.
 */
class Card{
    //Allows deck to access Card
    friend class Deck;
private:
    int face;
    int suit;
public:
    /*
      The card constructur takes two integers that will later on be used to represent
      a face or a suit based on the two array we have set.
     */
    Card(int face, int suit);
    /*
      The = operator for the card class allows us to assign cards directly and do a 
      shallow copy.
     */
    Card& operator=(const Card& arg);
    /*
      This function simply allows us to print the suit and face of the card given.
     */
    string toString(Card card_);
    /*
     Getter functions.
     */
    int getFace();
    int getSuit();
};

class DeckOfCards{
    friend class Hand;
private:
    vector<Card> deck;
    vector<Card> usedCards;
    int currentCard;
public:
    DeckOfCards();
    int getSize();
    vector<Card> getUsedDeck();
    void shuffleDeck();
    Card dealCard();
    bool moreCards(); 
};

class Hand{
private:
    vector<Card> hand;
    int draw[5] = {0,0,0,0,0};
    //this array will tell us what card should be replaced and drawn with a new card.
public:
    Hand(vector<Card> cards);
    Hand(DeckOfCards &deck);
    vector<Card> getHand();
    int* getDraw();
    Card getCard(int index);
    void setCard(Card &card_, int index);
    void sortSuit();
    void sortFace();
    void showHand();
    bool isPair();
    bool isTwoPair();
    bool isThreeKind();
    bool isFourKind();
    bool isFlush();
    bool isStraight();
    int handType();
    int highestCard();
};

class game{
private:
    int winChance[7];
public:
    game();


};

#endif
