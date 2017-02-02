/* *
 * MIT License
 *
 * Copyright (c) 2016 Serey Morm
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * */

#include <iostream>
#include <string>
#include <stdexcept>
#include "deck.h"
/****************************************/
Card::Card(int face_, int suit_):face(face_),suit(suit_){}

Card & Card::operator=(const Card& arg){
    if(this == &arg)
        return *this;
    suit = arg.suit;
    face = arg.face;
    return *this;
}

int Card::getFace(){return face;}
int Card::getSuit(){return suit;}
/*
    Taking a card as an input, it uses our static array to determine the card's face and suit, converts them into strings, concatenates using the STL string + operator, and finally returns the string for printing.
*/
string Card:: toString(Card card_){
    string toReturn;
    toReturn = faceArray[card_.getFace()]+" of "+suitArray[card_.getSuit()] ;
    return toReturn;
}
// END OF CARD CLASS
/***************************************/

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
/************TESTING PURPOSES*******
Constructor with no cards+Push fun*/
Hand::Hand(vector<Card> cards){
    hand = cards;
}

/*
    Each hand requires a deck, each hand is dealt five cards from the deck.
*/
Hand::Hand(DeckOfCards &Deck){
    for(int i = 0; i < 5; ++i)
        hand.push_back(Deck.dealCard());
}

void Hand::showHand(){
    for(int i = 0; i < 5; ++i){
       cout << hand[i].toString(hand[i]) <<endl;
    }
    cout<<endl;
}

/*
Bubble Sorting
    Sorting Suits will help us determine a flush
    Sorting Faces will help us determine a straight
    Iterators need to be delcared outside in order to swap
    outside the scope
*/
void Hand::sortSuit(){
    int i, j, min;
    for(i=0; i < hand.size(); i++){
        min = i;
        for(j = i+1; j < hand.size(); j++)
            if(hand[j].getSuit() < hand[min].getSuit()){
                min = j;
            }
    Card temp = hand[i];
    hand[i] = hand[min];
    hand[min] = temp;
    }
}
void Hand::sortFace(){
    int i, j, min;
    for(i=0; i < hand.size(); i++){
        min = i;
        for(j = i+1; j < hand.size(); j++)
            if(hand[j].getFace() < hand[min].getFace()){
                min = j;
            }
    Card temp = hand[i];
    hand[i] = hand[min];
    hand[min] = temp;
    }
}

/*
    To save computation time, we return true
    as soon as we find a pair, because that is the function's only purpose, to find ONE pair.

*/
bool Hand::isPair(){
    for(int i = 0; i < 4; ++i){
        for(int j = i+1; j < 4; j++)
            if(hand[i].getFace() == hand[i+1].getFace())
                return true;
        }
    return false;
}
/*
    Loops through the array, when two pair is found, return true immediately to save compilation time.
*/
bool Hand::isTwoPair(){
    int pairCount = 0;
    for(int i = 0; i < 4; ++i){
        for(int j = i+1; j < 5; j++){
            if(hand[i].getFace() == hand[j].getFace()){
                pairCount++;
                if(pairCount == 2){
                    return true;
                }
            }
        }
    }
        return false;
}
/*
    Sorting our hand prior to deciding whether if we have three of a kind will help us narrow down the odds to : 
        CASE 1 : a a a b c
        CASE 2 : b a a a c
        CASE 3 : b c a a a
    http://www.mathcs.emory.edu/~cheung/Courses/170/Syllabus/10/pokerCheck.html
    
    Narrowing it down, we first have to check if our hand is a flush, straight, two pairs, four of a kind, or three of a kind.
*/
bool Hand::isThreeKind(){
   bool CASE1,CASE2,CASE3;
    sortFace();
    //if(isTwoPair()||isThreeKind()||isFourKind()||isFlush()||isStraight())
    //    return false;
    CASE1 = hand[0].getFace() == hand[1].getFace()
         && hand[1].getFace() == hand[2].getFace();
    
    CASE2 = hand[1].getFace() == hand[2].getFace()
         && hand[2].getFace() == hand[3].getFace();
    
    CASE3 = hand[2].getFace() == hand[3].getFace()
         && hand[3].getFace() == hand[4].getFace();
    return (CASE1 || CASE2 || CASE3);
}
/*
    Similar to our three of a kind function, we narrow it down to two possible cases after sorting all five cas.
    CASE1 : a a a a b
    CASE2 : b a a a a
*/
bool Hand::isFourKind(){
    sortFace();
    
    bool CASE1, CASE2;
    CASE1 =    hand[0].getFace() == hand[1].getFace()
            && hand[1].getFace() == hand[2].getFace() 
            && hand[2].getFace() == hand[3].getFace();
    
    CASE2 =    hand[1].getFace() == hand[2].getFace()
            && hand[2].getFace() == hand[3].getFace() 
            && hand[3].getFace() == hand[4].getFace();
    return (CASE1 || CASE2);
}
/*
    Sort the suit, if the first and last item aren't the same, its not a flush, if it is, return true;
*/
bool Hand::isFlush(){
    bool CASE;
    sortSuit();
    CASE = hand[0].getSuit() == hand[4].getSuit();
    return CASE;
}
/*
    Sort the faces, then we check if the differences between each index is equal to 1
*/
bool Hand::isStraight(){
    sortFace();
    for(int i = 0; i < 4; i++){
        if(hand[i+1].getFace() != (hand[i].getFace()+1))
            return false;
    }
    return true;
}



