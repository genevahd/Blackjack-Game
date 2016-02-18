// THIS PROGRAM SHOULD BE EXECUTED WITH A FULLSCREEN OR WIDE VIEWING TERMINAL
// IN ORDER TO HAVE THE BEST GAMEPLAY POSSIBLE (AT LEAST 140 CHARACTERS WIDE)

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctime>

using namespace std;

// shuffles the deck randomly
void shuffle(int card[], int nSwap)
{
	srand(time(NULL));
	for (int i = 0; i < nSwap; i++)
	{
		swap(card[rand() % 208], card[rand() % 208]);
	}
	return;
}

// determines what card the ticket number corresponds to
int determineCardInformation(int ticketNumber, int* deck, int* suit, int* cardNumber)
{
	// gets deck index
	if (ticketNumber < 52)          *deck = 0;
	else if (ticketNumber < 104)    *deck = 1;
	else if (ticketNumber < 156)    *deck = 2;
	else                           *deck = 3;

	// gets card number
	*cardNumber = ticketNumber % 13;

	// gets suit number
	ticketNumber = ticketNumber % 52;
	if (ticketNumber < 13)          *suit = 0;
	else if (ticketNumber < 26)     *suit = 1;
	else if (ticketNumber < 39)     *suit = 2;
	else                           *suit = 3;

	// returns the card index
	return *cardNumber;
}

// converts the card number to the name of the card
string cardNumToText(int cardNumber)
{
	if (cardNumber == 1)
		return "ace";
	else if (cardNumber == 2)
		return "2";
	else if (cardNumber == 3)
		return "3";
	else if (cardNumber == 4)
		return "4";
	else if (cardNumber == 5)
		return "5";
	else if (cardNumber == 6)
		return "6";
	else if (cardNumber == 7)
		return "7";
	else if (cardNumber == 8)
		return "8";
	else if (cardNumber == 9)
		return "9";
	else if (cardNumber == 10)
		return "10";
	else if (cardNumber == 11)
		return "jack";
	else if (cardNumber == 12)
		return "queen";
	else if (cardNumber == 13)
		return "king";
}

// converts the suit number to the name of the suit
string suitToText(int suit)
{
	if (suit == 1)
		return "spades";
	else if (suit == 2)
		return "hearts";
	else if (suit == 3)
		return "diamonds";
	else if (suit == 4)
		return "clubs";
}

// displays the card
void displayCard(int suit, int cardNumber)
{
	cout << cardNumToText(cardNumber + 1) << " of " << suitToText(suit + 1) << endl;
}

struct person {
	int id;
	string first_name;
	int nChips;
	int ticket_number[18];
	bool isWithdrawn;
};

// prints person information
void printPerson(person p)
{
	cout << p.id << " " << p.first_name << " " << p.nChips << endl;
}

// prints dealers first card
void printDealerFirstCard(person d, int* deck, int* suit, int* cardNumber)
{
	cout << d.first_name << endl;
	int currTicket = d.ticket_number[0];
	determineCardInformation(currTicket, deck, suit, cardNumber);
	displayCard(*suit, *cardNumber);
}

// converts card number and suit number to a string
string printHand(int cardNumber, int suit)
{
	string ret = cardNumToText(cardNumber) + " of " + suitToText(suit);
	return ret;
}

// displays all players first two cards
void printPlayerCards(person p[], int nPlayers, int* deck, int* suit, int* cardNumber)
{
	for (int i = 0; i < nPlayers; i++)
	{
		cout << left << setw(20) << p[i].first_name;
	}
	cout << endl;

	for (int k = 0; k < 2; k++)
	{
		for (int j = 0; j < nPlayers; j++)
		{
			int currTicket = p[j].ticket_number[k];
			determineCardInformation(currTicket, deck, suit, cardNumber);
			cout << left << setw(20) << printHand(*cardNumber + 1, *suit + 1);
		}
		cout << endl;
	}

}

// prints a persons hand
void printHand(person p, int* deck, int* suit, int* cardNumber) {
	cout << p.first_name << endl;
	int cardNum = 0;
	int currTicket = p.ticket_number[cardNum];
	// while the currTicket is a valid card
	while (currTicket >= 0)
	{
		determineCardInformation(currTicket, deck, suit, cardNumber);
		displayCard(*suit, *cardNumber);
		currTicket = p.ticket_number[++cardNum];
	}
}

// calculates the score of a players hand
int calculatePoints(person p, int* deck, int* suit, int* cardNumber)
{
	int i = 0;
	int score = 0;
	int cardValue = 0;
	int nAces = 0;

	int currTicket = p.ticket_number[i];

	while (currTicket >= 0)
	{
		determineCardInformation(currTicket, deck, suit, cardNumber);

		if (*cardNumber + 1 == 1)       // ace is 1 or 11
		{
			if (score + 11 > 21)
			{
				cardValue = 1;
				score = score + cardValue;
			}
			else
			{
				nAces++;
				score = score + 11;
			}

		}
		else if (*cardNumber + 1 == 2)
		{
			cardValue = 2;
			score = score + cardValue;
		}
		else if (*cardNumber + 1 == 3)
		{
			cardValue = 3;
			score = score + cardValue;
		}
		else if (*cardNumber + 1 == 4)
		{
			cardValue = 4;
			score = score + cardValue;
		}
		else if (*cardNumber + 1 == 5)
		{
			cardValue = 5;
			score = score + cardValue;
		}
		else if (*cardNumber + 1 == 6)
		{
			cardValue = 6;
			score = score + cardValue;
		}
		else if (*cardNumber + 1 == 7)
		{
			cardValue = 7;
			score = score + cardValue;
		}
		else if (*cardNumber + 1 == 8)
		{
			cardValue = 8;
			score = score + cardValue;
		}
		else if (*cardNumber + 1 == 9)
		{
			cardValue = 9;
			score = score + cardValue;
		}
		else if (*cardNumber + 1 == 10)
		{
			cardValue = 10;
			score = score + cardValue;
		}
		else if (*cardNumber + 1 == 11)
		{
			cardValue = 10;
			score = score + cardValue;
		}
		else if (*cardNumber + 1 == 12)
		{
			cardValue = 10;
			score = score + cardValue;
		}
		else if (*cardNumber + 1 == 13)
		{
			cardValue = 10;
			score = score + cardValue;
		}

		if (nAces > 0 && score > 21)
		{
			score -= 10;
			--nAces;
		}
		currTicket = p.ticket_number[++i];
	}
	return score;
}

int main()
{
	srand(time(NULL));
	const int NDECKS = 4;
	const int NSUITS = 4;
	const int NCARDS = 13;
	const int NSWAPS = 1000;
	const int CHIPVALUE = 10;
	const int TOTALCARDS = 208;

	// declare 4 deck array
	int tickets[TOTALCARDS];

	// assign all the tickets in order
	for (int i = 0; i < TOTALCARDS; i++)
	{
		tickets[i] = i;
	}

	int* deck = new int;
	int* suit = new int;
	int* cardNumber = new int;

	// STAGE 1

	// shuffles the 4 decks
	shuffle(tickets, NSWAPS);

	// read input files
	ifstream inPlayer("player.txt");
	ifstream inDealer("dealer.txt");

	// list of all the players
	person listOfPlayers[7];

	// list of all the dealers
	person listOfDealers[7];

	if (inPlayer.is_open())
	{
		// create players and add them to array
		for (int i = 0; i < 7; i++)
		{
			person player;
			inPlayer >> player.id;
			inPlayer >> player.first_name;
			inPlayer >> player.nChips;
			// assign all values in ticket_number to -1 so that we know
			// how many cards in the array are actual cards
			for (int j = 0; j < 18; j++)
			{
				player.ticket_number[j] = -1;
			}
			player.isWithdrawn = 0;
			listOfPlayers[i] = player;
		}
	}
	else
	{
		// gives error output and exits program if file not found
		cout << "Error reading player.txt" << endl;
		exit(1);
	}
	inPlayer.close();

	if (inDealer.is_open())
	{
		// create dealers and add them to array
		for (int i = 0; i < 7; i++)
		{
			person dealer;
			inDealer >> dealer.id;
			inDealer >> dealer.first_name;
			inDealer >> dealer.nChips;
			// assign all values in ticket_number to -1 so that we know
			// how many cards in the array are actual cards
			for (int j = 0; j < 18; j++)
			{
				dealer.ticket_number[j] = -1;
			}
			dealer.isWithdrawn = 0;
			listOfDealers[i] = dealer;
		}
	}
	else
	{
		// gives error output and exits program if file not found
		cout << "Error reading dealer.txt" << endl;
		exit(1);
	}
	inDealer.close();

	cout << endl;

	int nPlayers = -1;
	//int nPlayers = 7;

	// define a counter to the number of cards dealt
	int ticketCounter = 0;

	while (nPlayers != 0)	// Logical Bug: have to stop the game.
	{

		do
		{
			cout << "How many players would like to play? (0 to quit): ";
			cin >> nPlayers;
		} while (nPlayers < 0 || nPlayers > 7);

		cout << endl;


		// quit game if no players
		if (nPlayers == 0)
		{
			// print player information
			for (int i = 0; i < 7; i++)
			{
				printPerson(listOfPlayers[i]);
			}
			cout << endl;
			cout << "Thanks for playing!" << endl;
			return 0;
		}

		// 20 random swaps from player list
		for (int i = 0; i < 20; i++)
		{
			int j = rand() % 7;
			int k = rand() % 7;
			swap(listOfPlayers[j], listOfPlayers[k]);
		}

		// assign players
		// Need to use dynamic allocation of memory.
		// works because i make the size of array as a constant: person currentPlayers[7];
		// But this is not correct, because we need to specify the number of players at the run time.
		// the proper solution is to use HEAP.
		// One important thing to prevent the MEMORY LEAK is to release the resources after the usage.
		// delete[] currentPlaysers

		person* currentPlayers = new person[nPlayers];

		//person currentPlayers[nPlayers];





		for (int i = 0; i < nPlayers; i++)
		{
			currentPlayers[i] = listOfPlayers[i];
		}

		// assign random dealer
		person currentDealer;
		int currentDealerIndex = rand() % 7;
		currentDealer = listOfDealers[currentDealerIndex];



		// STAGE 2

		// deal two cards to each player
		for (int i = 0; i < nPlayers; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				// deal a card to the player and increment counter
				currentPlayers[i].ticket_number[j] = tickets[ticketCounter++];
			}
		}

		// deal 1 card to the dealer
		currentDealer.ticket_number[0] = tickets[ticketCounter++];

		// STAGE 3 AND 4

		// prints dealers first card
		printDealerFirstCard(currentDealer, deck, suit, cardNumber);
		cout << endl;

		// prints players first 2 cards
		// NEEDS A FULLSCREEN TERMINAL/CONSOLE FOR BEST VIEW WITH MORE PLAYERS
		printPlayerCards(currentPlayers, nPlayers, deck, suit, cardNumber);
		cout << endl;

		for (int a = 0; a < nPlayers; a++)
		{
			int user_input = 0;
			int totalScore = 0;

			do
			{
				printHand(currentPlayers[a], deck, suit, cardNumber);
				totalScore = calculatePoints(currentPlayers[a], deck, suit, cardNumber);

				cout << "Your total score: " << totalScore << endl;

				if (totalScore < 21)
				{
					cout << endl << "Enter (1) to hit or (2) to pass: ";

					cin >> user_input;

					cout << endl;

					if (user_input == 1)
					{
						for (int i = 0; i < 18; i++)
						{
							if (currentPlayers[a].ticket_number[i] == -1)
							{
								currentPlayers[a].ticket_number[i] = tickets[ticketCounter++];
								i = 18;
							}
						}
					}
				}
				else if (totalScore > 21)
				{
					currentPlayers[a].isWithdrawn = 1;
					cout << "You busted!" << endl << endl;
				}
				else if (totalScore == 21)
				{
					cout << "Nice hand!" << endl << endl;
				}
			} while (user_input != 2 && totalScore < 21);
		}

		int dealerScore = 0;
		do
		{
			for (int i = 1; i < 18; i++)
			{
				if (currentDealer.ticket_number[i] == -1)
				{
					currentDealer.ticket_number[i] = tickets[ticketCounter++];
					i = 18;
				}
			}
			dealerScore = calculatePoints(currentDealer, deck, suit, cardNumber);
			printHand(currentDealer, deck, suit, cardNumber);
			cout << "Dealer score: " << dealerScore << endl << endl;

			if (dealerScore > 21)
			{
				currentDealer.isWithdrawn = 1;
			}
		} while (dealerScore < 17);

		// STAGE 5

		cout << "==========Results==========" << endl << endl;

		cout << "Dealer score: " << dealerScore << endl << endl;

		for (int i = 0; i < nPlayers; i++)
		{
			string playerName = currentPlayers[i].first_name;
			int playerScore = calculatePoints(currentPlayers[i], deck, suit, cardNumber);

			// if player busts then casino wins
			if (currentPlayers[i].isWithdrawn == true)
			{
				cout << playerName << endl;
				cout << "Your total score: " << playerScore << endl;
				cout << "You lost!" << endl;
				--listOfPlayers[i].nChips;
				listOfDealers[currentDealerIndex].nChips++;
			}
			// if player does not bust and dealer busts then player wins
			else if (currentPlayers[i].isWithdrawn == false && currentDealer.isWithdrawn == true)
			{
				cout << playerName << endl;
				cout << "Your total score: " << playerScore << endl;
				cout << "You won!" << endl;
				listOfPlayers[i].nChips++;
				--listOfDealers[currentDealerIndex].nChips;
			}
			else
			{
				// if player beats dealer
				if (playerScore > dealerScore)
				{
					cout << playerName << endl;
					cout << "Your total score: " << playerScore << endl;
					cout << "You won!" << endl;
					listOfPlayers[i].nChips++;
					--listOfDealers[currentDealerIndex].nChips;
				}
				// if dealer beats player
				else if (playerScore < dealerScore)
				{
					cout << playerName << endl;
					cout << "Your total score: " << playerScore << endl;
					cout << "You lost!" << endl;
					--listOfPlayers[i].nChips;
					listOfDealers[currentDealerIndex].nChips++;
				}
				// if player ties dealer
				else if (playerScore == dealerScore)
				{
					cout << playerName << endl;
					cout << "Your total score: " << playerScore << endl;
					cout << "You pushed!" << endl;
				}
			}
			cout << endl;
		}
		cout << "===========================" << endl << endl;

		// if more than 3 decks have been dealt, shuffle the deck
		if (ticketCounter >= 156)
		{
			shuffle(tickets, NSWAPS);
			ticketCounter = 0;
		}
	}

	return 0;
}