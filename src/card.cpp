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
    toReturn = faceArray[card_.getFace()]+"\tof   "+suitArray[card_.getSuit()];
    return toReturn;
}
// END OF CARD CLASS
/***************************************/



