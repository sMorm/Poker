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
    toReturn = faceArray[card_.getFace()]+"\tof   "+suitArray[card_.getSuit()];
    return toReturn;
}
// END OF CARD CLASS
/***************************************/



