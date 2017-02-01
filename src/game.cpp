#include "deck.h"
 
 game::game(){
 	srand(time(0));


 	/*
 				START OF INITIALIZATION SECTION
		FROM THIS SECTION ON; THIS PART SETS UP THE GAME, DECK, ASKS IF PLAYERS WANT TO 
		DRAW CARDS OR NOT
 	*/
    DeckOfCards playDeck;
    int num =rand() % 45 + 1;
    for(int i = 0; i <= num; i ++)
        playDeck.shuffleDeck();
    int numPlayers;
    cout << "How many players will be playing? [2-7](Including Dealer) : ";
    cin >> numPlayers;
    while(numPlayers > 7 || numPlayers < 2){
        cout << "The number of players participating must range from 2 to 7. Please try again : ";
        cin >>numPlayers;
    }
    vector<Hand> players;
    vector<Card> cards;
    for(int i = 0; i < numPlayers; ++i){
        for(int j = 0; j < 5; ++j){
            cards.push_back(playDeck.dealCard());
        }
        Hand pushHand(cards);
        cards.clear();
        players.push_back(pushHand);
    }
    for(int i = 1; i < numPlayers; ++i){
        players[i].sortFace();
        cout << "\n<<Player #" << i <<"'s hand>>\n";
        players[i].showHand();
        cout << "——————————————————————————\n";
    }
    //////////////////////////////////////////////////////
    int Dealer = players[0].handType();
    if(Dealer == 5 || Dealer == 6){
        cout << "Dealer will not be drawing.";
    }
    /*
        If the dealer has three of a kind, draw cards for a better chance of getting
        four of a kind.
    */
    if(Dealer == 3 || Dealer == 2 || Dealer == 1)
    {   
        int * drawArr = players[0].getDraw();//hold array of which cards to draw
        for(int i = 0; i < 5; ++i){
            if(drawArr[i] == 1){
                Card toDraw = playDeck.dealCard();
                players[0].setCard(toDraw, i);
            }
        }
        players[0].showHand();
    }

    int player, cardNumber, sumDraw = 0, numCards;
    int userDecision;
    int * drawArr; 
    for(int i = 1; i < numPlayers; ++i){
        player = players[i].handType();
        drawArr = players[i].getDraw();
        if(player == 1 || player == 2 || player == 3){
            cout << "ALERT : PLAYER #" << i << endl;
            cout << "Swapping the following cards will increase your chance of getting a better hand !\n";
            for(int j = 0; j < 5; ++j){
                if(drawArr[j] == 1){
                    sumDraw++;
                    cout << players[i].getCard(j).toString(players[i].getCard(j))<< "\t\t[" << j << "]" << endl;
                }
            }
            cout << "Player #" <<i<<" would you like to draw a new card? [1]yes or [0]no' : ";
                cin >> userDecision;
                while(userDecision != 1 && userDecision != 0){
                    cout << "Invalid input, enter '1' for yes, '0' for no : ";
                    cin >> userDecision;
                }
                if(userDecision == 1){
                    cout << "How many would you like to swap out?\n";
                    cin >> numCards;
                    while(numCards > sumDraw){
                        cout << "Swapping out this many cards will not yield a good hand. Enter a smaller amount : ";
                        cin >> numCards;
                    }
                    for(int i = 0; i < numCards; ++i){
                    cout << "Enter the order card is placed in the brackets[] : ";
                    cin >> cardNumber;
                    while(drawArr[cardNumber] != 1){
                        cout << "Wrong card index, look at your availability and try again : ";
                        cin >> cardNumber;
                    }
                    Card toDraw = playDeck.dealCard();
                    players[i].setCard(toDraw, cardNumber);
                }

                }
                    cout << endl;        
        }
        cout << "Player #" <<i<<"'s new hand : \n";
        players[i].showHand();
        sumDraw = 0;
    }

    /*
		END OF INITIALIZATION SECTION
    */

	int bestHand = -1, max = 0;
 	for(int i = 1; i < numPlayers; i ++){
 		winChance[i] = players[i].handType();
 		if(winChance[i] > max)
 			bestHand = i+1;
}

 	sort(winChance, winChance + numPlayers);
 	if(winChance[0] == winChance[numPlayers-1]){
 		int bestCard[numPlayers];
 		int winner, maxCard = 0;
 		for(int i = 0; i <numPlayers; i++){
 			if(players[i].highestCard() > maxCard){
 				winner = i;
 				maxCard = players[i].highestCard();
 			}
 		}
	}
	if(bestHand > -1){
		cout << "###########################################\n#\n";
		cout << "#      \tPlayer #" << bestHand-1 << " wins!!\n#\n";
		cout << "###########################################\n";
	}
	else
		if(bestHand == -1)
			cout << "Dealer wins!\n";

}















 