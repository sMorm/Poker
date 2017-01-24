#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "deck.h"

void pairDemo();
void threeKindDemo();
void straightDemo();
void flushDemo();
int main(){    

    //pairDemo();
    //threeKindDemo();
    //straightDemo();
    //flushDemo();
    game testGame;

    
    return 0;
}

/*
    This demo function tests to see if the deal card and shuffle card functions work properly. It will show the size of the initial deck(52), deal 5 cards to three players. Finally it will show how many cards are left in the deck(37).
*/
void pairDemo(){
    DeckOfCards deck;
    cout<<deck.getSize()<<endl;
    deck.shuffleDeck();
    deck.shuffleDeck();
    deck.shuffleDeck();
    deck.shuffleDeck();
    deck.shuffleDeck();
    deck.shuffleDeck();
    Hand hand1(deck);
    Hand hand2(deck);
    Hand hand3(deck);
    
    hand1.showHand();
    hand2.showHand();
    hand3.showHand();
    
    cout<<deck.getSize()<<endl;
    if(hand3.isPair()){
        cout << "Hand 3 has a pair!"<<endl;
    }
    if(hand3.isTwoPair()){
        cout << "Hand has two pairs!"<<endl;
    }
    cout<<deck.getSize()<<endl;
}

void threeKindDemo(){
        DeckOfCards deck;
    cout<<deck.getSize()<<endl;
    for(int i = 0; i < 21; ++i){
        deck.shuffleDeck();
    }
    Hand hand1(deck);
    Hand hand2(deck);
    Hand hand3(deck);
    
    hand1.showHand();
    hand2.showHand();
    hand3.showHand();
    if(hand2.isThreeKind()){
        cout << "Hand 3 is three of a kind."<<endl;
    }
    
}
void straightDemo(){
    Card one(12, 1);
    Card two(11, 2);
    Card three(10, 3);
    Card four(9, 0);
    Card five(8, 1);
    vector<Card> set;
    set.push_back(one);
    set.push_back(two);
    set.push_back(three);
    set.push_back(four);
    set.push_back(five);
    Hand test(set);
    test.showHand();
    if(test.isStraight())
        cout<<"Hand is straight.";
}

void flushDemo(){
    Card one(2, 1);
    Card two(1, 1);
    Card three(0, 1);
    Card four(9, 1);
    Card five(8, 1);
    vector<Card> set;
    set.push_back(one);
    set.push_back(two);
    set.push_back(three);
    set.push_back(four);
    set.push_back(five);
    Hand test(set);
    test.showHand();
    if(test.isFlush())
        cout<<"Hand is a flush"<<endl;
    test.showHand();
}

void gameEngine(){



}
