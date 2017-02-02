
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
#include "deck.h"
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
}

vector<Card> Hand::getHand(){return hand;}
Card Hand::getCard(int index){return hand[index];}
int* Hand::getDraw(){return draw;}

void Hand::setCard(Card &card_, int index){
    hand[index] = card_;
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

OLD PAIR FUNCTION
        for(int i = 0; i < 5; ++i){
        for(int j = i+1; j < 5; j++)
            if(hand[i].getFace() == hand[i+1].getFace())
                return true;
        }

*/
bool Hand::isPair(){
    bool CASE1, CASE2, CASE3, CASE4;
    sortFace();
    if(isFourKind() || isThreeKind() || isTwoPair())
        return false;
    CASE1 = hand[0].getFace() == hand[1].getFace();

    CASE2 = hand[1].getFace() == hand[2].getFace();
    
    CASE3 = hand[2].getFace() == hand[3].getFace();

    CASE4 = hand[3].getFace() == hand[4].getFace();
    if(CASE1){
        draw[2] = 1;
        draw[3] = 1;
        draw[4] = 1;
        return true;
    }
    if(CASE2){
        draw[0] = 1;
        draw[3] = 1;
        draw[4] = 1;
        return true;
    }
    if(CASE3){
        draw[0] = 1;
        draw[1] = 1;
        draw[4] = 1;
        return true;
    }
    if(CASE4){
        draw[0] = 1;
        draw[1] = 1;
        draw[2] = 1;
        return true;
    }


    return false; // just in case;
}
/*
    Sort them by faces, leaves us with three cases to check :
    a a b c c
    b a a c c
    a a c c b

*/
bool Hand::isTwoPair(){
    bool CASE1, CASE2, CASE3;
    sortFace();
    if(isFourKind() || isThreeKind())
        return false;

    CASE1 = hand[0].getFace() == hand[1].getFace()
         && hand[2].getFace() == hand[3].getFace();

    CASE2 = hand[0].getFace() == hand[1].getFace()
         && hand[3].getFace() == hand[4].getFace();
    
    CASE3 = hand[1].getFace() == hand[2].getFace()
         && hand[3].getFace() == hand[4].getFace();

    if(CASE1){
        draw[4] = 1;
        return true;
    }
    if(CASE2){
        draw[2] = 1;
        return true;
    }
    if(CASE3){
        draw[0] = 1;
        return true;
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
    if(isFourKind() || isFlush() || isStraight())
        return false;
    CASE1 = hand[0].getFace() == hand[1].getFace()
         && hand[1].getFace() == hand[2].getFace();
    
    CASE2 = hand[1].getFace() == hand[2].getFace()
         && hand[2].getFace() == hand[3].getFace();
    
    CASE3 = hand[2].getFace() == hand[3].getFace()
         && hand[3].getFace() == hand[4].getFace();

    if(CASE1){
        draw[3] = 1;
        draw[4] = 1;
        return true;
    }
    if(CASE2){
        draw[0] = 1;
        draw[4] = 1;
        return true;
    }
    if(CASE3){
        draw[0] = 1;
        draw[1] = 1;
        return true;
    }
    return false;
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

int Hand::handType(){
    if(isStraight())
        return 6;
    if(isFlush())
        return 5;
    if(isFourKind())
        return 4;
    if(isThreeKind())
        return 3;
    if(isTwoPair())
        return 2;
    if(isPair())
        return 1;
    return 0;
}

int Hand::highestCard(){
    int max = -1;
    for(int i = 0; i < 5; i++){
        if(hand[i].getFace() == 12)
            return 12;
        if(hand[i].getFace() > max)
            max = hand[i].getFace();
    }
    return max;

}