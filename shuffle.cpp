#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;


class Card_Shuffler
{
private:
	int *deck;
	int cardCounter;
	int numDecks;
public:
	int swap(int *element1, int *element2)
	{
		int temp = *element1;
		*element1 = *element2;
		*element2 = temp;
		return *element1;
	}
	void shuffle(int card[])
	{
		srand(time(NULL));
		int nSwap = 1000;
		int index1, index2;
		while (nSwap--)
		{
			index1 = rand() % 52 * numDecks;
			index2 = rand() % 52 * numDecks;
			swap(&card[index1], &card[index2]);
		}
	}
	Card_Shuffler(int numdecks)
	{
		numDecks = numdecks;
		cardCounter = 0;
		deck = new int[52*numDecks];				// allocate the memory on the heap
		for (int i =0; i < 52*numDecks; i++)		// initializing the array based on numdecks
		{
			deck[i] = i;							// set each "card"
		}
		shuffle(deck);
	}
	int getCard()
	{
		return deck[cardCounter++];
	}
	~Card_Shuffler()
	{
		delete [] deck;								// deletes deck from the heap
	}
};

class Dealer
{
private:
	string name;
	int card;
public:
	Dealer(string dealer_name)
	{
		name = dealer_name;
	}
	int dealCard(Card_Shuffler shuffler)
	{
		card = shuffler.getCard();
		return card;
	}
};

class Player
{
private:
	string name;
	int card[7];
	int numCards;
public:
	Player(string my_name)
	{
		name = my_name;
		numCards = 0;
	}
	void getCard(int num)
	{
		num = num & 13;
		if (numCards < 7)
			card[numCards++] = num;
		else
			cout << "Your hand is full \n";
	}
	void displayHand()
	{
		for (int i = 0; i < numCards; i++)
		{
			cout << card[i] << endl;
		}
	}
};

int main ()
{
	int numdecks = 0;
	cout << "How many decks do you want? ";
	cin >> numdecks;
	Card_Shuffler deck(numdecks);
	Dealer casino("Bicycle");
	Player p1("Gene");

	cout << "Here's a card. \n";
	p1.getCard(casino.dealCard(deck));		// player asks the dealer for a card, dealer asks the deck for a card
	p1.displayHand();
	cout << "Here's a card. \n";
	p1.getCard(casino.dealCard(deck));
	p1.displayHand();
	system("pause");
	return 0;
}