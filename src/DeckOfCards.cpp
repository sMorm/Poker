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

