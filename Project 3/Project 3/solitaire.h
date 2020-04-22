#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<string>
#include<ctime>
using namespace std;

class Node
{
public:
	string value;
	Node* next;
	Node(string val) :value(val), next(nullptr) {}
};
class Stack
{
private:
	Node* head;
	int count;
public:
	int hideCount;
	Stack() :head(nullptr), count(0), hideCount(0) {}
	~Stack() {
		for (Node* curr = head; curr; curr = head) {
			head = head->next;
			delete curr;
		}
	}
	int size() { return count; }
	bool empty() { return count <= 0; }
	void push(string value) {
		if (!head) head = new Node(value);
		else {
			Node* curr = head;
			while (curr->next) curr = curr->next;
			curr->next = new Node(value);
		}
		count++;
	}
	string pop() {
		if (!head)
			throw new exception("Error: Pop from empty stack.");
		string value;
		if (!head->next) {
			value = head->value;
			delete head;
			head = nullptr;
			count--;
			if (hideCount == count)hideCount--;
			if (hideCount < 0)hideCount = 0;
			return value;
		}
		Node* prev = nullptr;
		Node* curr = head;
		while (curr->next) {
			prev = curr;
			curr = curr->next;
		}
		prev->next = nullptr;
		value = curr->value;
		delete curr;
		count--;
		if (hideCount == count)hideCount--;
		return value;
	}
	string top()
	{
		if (!head)return "";
		Node* curr = head;
		while (curr->next)
			curr = curr->next;
		return curr->value;
	}
	string get(int number) {
		if (number <= 0 || number > size()) return "";
		int c = 1;
		Node* curr = head;
		while (curr->next && c < number) {
			curr = curr->next;
			c++;
		}
		if (c == number)
			return (number > hideCount) ? curr->value : "?";
		return "";
	}
};
class Queue
{
private:
	Node* head;
	int count;
public:
	Queue() :head(nullptr), count(0) {}
	~Queue() {
		for (Node* curr = head; curr; curr = head) {
			head = head->next;
			delete curr;
		}
		count = 0;
	}
	int size() { return count; }
	bool empty() { return count <= 0; }
	void enque(string value) {
		if (!head) head = new Node(value);
		else {
			Node* curr = head;
			while (curr->next) curr = curr->next;
			curr->next = new Node(value);
		}
		count++;
	}
	string deque() {
		if (!head)
			throw new exception("Error: Pop from empty stack.");
		Node* curr = head;
		head = head->next;
		string value = curr->value;
		delete curr;
		count--;
		return value;
	}
	string front() {
		if (!head) return "";
		return head->value;
	}
	string print() {
		string str = "";
		for (Node* curr = head; curr; curr = curr->next) {
			str = str + curr->value + " ";
		}
		return str;
	}
	void sortIncreasingOrder() {
		Node* node = head;
		for (int i = 0; i < size() - 1; i++, node = node->next) {
			Node* minNode = node;
			Node* nextNode = node->next;
			for (int j = i + 1; j < size(); j++, nextNode = nextNode->next)
				if (compare(nextNode->value, minNode->value) < 0)
					minNode = nextNode;
			string temp = minNode->value;
			minNode->value = node->value;
			node->value = temp;
		}
	}
	void sortDecreasingOrder() {
		Node* node = head;
		for (int i = 0; i < size() - 1; i++, node = node->next) {
			Node* maxNode = node;
			Node* nextNode = node->next;
			for (int j = i + 1; j < size(); j++, nextNode = nextNode->next)
				if (compare(nextNode->value, maxNode->value) > 0)
					maxNode = nextNode;
			string temp = maxNode->value;
			maxNode->value = node->value;
			node->value = temp;
		}
	}
	int compare(string c1, string c2) {
		string cards[52] = { "AH","AD","AS","AC","2H","2D","2S","2C","3H","3D","3S","3C",
			"4H","4D","4S","4C","5H","5D","5S","5C","6H","6D","6S","6C","7H","7D","7S","7C",
			"8H","8D","8S","8C","9H","9D","9S","9C","10H","10D","10S","10C",
			"JH","JD","JS","JC","QH","QD","QS","QC","KH","KD","KS","KC" };
		int index1 = 0, index2 = 0;
		for (int i = 0; i < 52; i++) {
			if (c1 == cards[i])index1 = i;
			if (c2 == cards[i])index2 = i;
		}
		return index1 == index2 ? 0 : index1 > index2 ? 1 : -1;
	}
};

class Solitaire
{
private:
	Stack heartPile;
	Stack diamondPile;
	Stack spadePile;
	Stack clubsPile;
	Stack pile[7];
	Queue discardPile;
	Queue deck;
	Queue dealtDeck;
	int completeFlips;
	int score;

public:
	Solitaire() {
		string cards[52] = { "AH","2H","3H","4H","5H","6H","7H","8H","9H","10H","JH","QH","KH",
			"AD","2D","3D","4D","5D","6D","7D","8D","9D","10D","JD","QD","KD",
			"AS","2S","3S","4S","5S","6S","7S","8S","9S","10S","JS","QS","KS",
			"AC","2C","3C","4C","5C","6C","7C","8C","9C","10C","JC","QC","KC" };
		for (int i = 0; i < 52; i++) {
			deck.enque(cards[i]);
		}
		completeFlips = 0;
		score = 0;
	}

	int getMaxPileSize() {
		int m = 0;
		for (int i = 0; i < 7; i++)
			m = pile[i].size() > m ? pile[i].size() : m;
		return m;
	}

	void shuffleDeck()
	{
		srand((unsigned int)time(0));
		deck.~Queue();
		string cards[52] = { "AH","2H","3H","4H","5H","6H","7H","8H","9H","10H","JH","QH","KH",
			"AD","2D","3D","4D","5D","6D","7D","8D","9D","10D","JD","QD","KD",
			"AS","2S","3S","4S","5S","6S","7S","8S","9S","10S","JS","QS","KS",
			"AC","2C","3C","4C","5C","6C","7C","8C","9C","10C","JC","QC","KC" };
		for (int i = 52; i > 0; i--) {
			for (int j = 0, k = 0, num = rand() % i; j < 52; j++) {
				if (cards[j] != "" && k++ == num) {
					deck.enque(cards[j]);
					cards[j] = "";
					break;
				}
			}
		}
	}
	void initData()
	{
		int c = 0;
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j <= i; j++) {
				pile[i].push(deck.deque());
			}
			pile[i].hideCount = pile[i].size() - 1;
		}
	}

	int display()
	{
		cout << left;
		cout << "                    " << "ALI BAYDOUN" << "'s SOLITAIRE GAME" << endl;
		cout << "Heart Pile: " << setw(3) << (!heartPile.empty() ? heartPile.top() : "0")
			<< " Diamond Pile: " << setw(3) << (!diamondPile.empty() ? diamondPile.top() : "0")
			<< " Spade Pile: " << setw(3) << (!spadePile.empty() ? spadePile.top() : "0")
			<< " Clubs Pile: " << setw(3) << (!clubsPile.empty() ? clubsPile.top() : "0") << endl;
		int i = 1, maxSize = getMaxPileSize();
		cout << "Pile 1: " << setw(3) << pile[0].get(i)
			<< " Pile 2: " << setw(3) << pile[1].get(i)
			<< " Pile 3: " << setw(3) << pile[2].get(i)
			<< " Pile 4: " << setw(3) << pile[3].get(i)
			<< " Pile 5: " << setw(3) << pile[4].get(i)
			<< " Pile 6: " << setw(3) << pile[5].get(i)
			<< " Pile 7: " << setw(3) << pile[6].get(i) << endl;
		for (i = 2; i <= maxSize; i++) {
			cout << "        " << setw(3) << pile[0].get(i)
				<< "         " << setw(3) << pile[1].get(i)
				<< "         " << setw(3) << pile[2].get(i)
				<< "         " << setw(3) << pile[3].get(i)
				<< "         " << setw(3) << pile[4].get(i)
				<< "         " << setw(3) << pile[5].get(i)
				<< "         " << setw(3) << pile[6].get(i) << endl;
		}
		cout << "Deck: " << setw(3) << (!deck.empty() ? "?" : "0")
			<< "   Discard: " << (!discardPile.empty() ? discardPile.print() : "0") << endl;
		cout << "\nOptions: \n\n1) Move card to Sort Pile  \n2) Move card(s) in Piles or Discard \n3) Flip Cards" << endl;
		cout << "\nYour selection: ";
		int option;
		cin >> option;
		while (option < 1 || option > 3) {
			cout << "Invalid option, Select again: ";
			cin >> option;
		}
		return option;
	}

	void play()
	{
		cout << "Start deck:\n" << deck.print();
		deck.sortIncreasingOrder();
		cout << "\n\nAfter sort increasing order deck:\n" << deck.print();
		deck.sortDecreasingOrder();
		cout << "\n\nAfter sotr decreasing order deck:\n" << deck.print();
		shuffleDeck();
		cout << "\n\nAfter shuffle(randomize) deck:\n" << deck.print() << "\n\n\n\n";

		initData();
		while (true)
		{
			int option = display();
			if (option == 1) {
				moveCardToSortPileMenu();
			}
			else if (option == 2) {
				moveCardsToPileMenu();
			}
			else if (option == 3) {
				flipCards();
				if (completeFlips == 3) {
					score = heartPile.size() * 10 + diamondPile.size() * 10 + clubsPile.size() * 10 + spadePile.size() * 10;
					cout << "You lose, your score is = " << score << endl;
					break;
				}
			}
			score = heartPile.size() * 10 + diamondPile.size() * 10 + clubsPile.size() * 10 + spadePile.size() * 10;
			if (heartPile.size() == 13 && diamondPile.size() == 13 && clubsPile.size() == 13 && spadePile.size() == 13) {
				cout << "You win, your score is = " << score << endl;
				break;
			}
			cout << endl << "-------------------------------------------------------------------------------------" << endl;
		}
		cout << endl;
	}

	void moveCardToSortPileMenu()
	{
		cout << "\nFrom where you want to select card:" << endl;
		cout << "1: Pile 1 (" << pile[0].top() << ")" << endl;
		cout << "2: Pile 2 (" << pile[1].top() << ")" << endl;
		cout << "3: Pile 3 (" << pile[2].top() << ")" << endl;
		cout << "4: Pile 4 (" << pile[3].top() << ")" << endl;
		cout << "5: Pile 5 (" << pile[4].top() << ")" << endl;
		cout << "6: Pile 6 (" << pile[5].top() << ")" << endl;
		cout << "7: Pile 7 (" << pile[6].top() << ")" << endl;
		cout << "8: Discard (" << discardPile.front() << ")" << endl;
		cout << "Your Selection: ";
		int option;
		cin >> option;
		while (option < 1 || option > 8) {
			cout << "Invalid option, Select again: ";
			cin >> option;
		}
		if (1 <= option && option <= 7) {
			if (pile[option - 1].empty()) cout << "Pile " << option << " have no card" << endl;
			else {
				if (moveCardToSortPile(pile[option - 1].top()))
					string temp = pile[option - 1].pop();
				else cout << "Card can't move to sort pile" << endl;
			}
		}
		else if (option == 8) {
			if (discardPile.empty()) cout << "Discard have no card" << endl;
			else {
				if (moveCardToSortPile(discardPile.front())) {
					string temp = discardPile.deque();
					if (!deck.empty()) discardPile.enque(deck.deque());
				}
				else cout << "Card can't move to sort pile" << endl;
			}
		}
	}
	bool moveCardToSortPile(string card) {
		char suit = card[card.size() - 1];
		string cardNumber = card.substr(0, card.size() - 1);
		if (suit == 'H') {
			string sortPileCardNumber = (!heartPile.empty()) ? (heartPile.top().substr(0, heartPile.top().size() - 1)) : "";
			if (isOneHigh(sortPileCardNumber, cardNumber)) {
				heartPile.push(card);
				return true;
			}
		}
		else if (suit == 'D') {
			string sortPileCardNumber = (!diamondPile.empty()) ? (diamondPile.top().substr(0, diamondPile.top().size() - 1)) : "";
			if (isOneHigh(sortPileCardNumber, cardNumber)) {
				diamondPile.push(card);
				return true;
			}
		}
		else if (suit == 'S') {
			string sortPileCardNumber = (!spadePile.empty()) ? (spadePile.top().substr(0, spadePile.top().size() - 1)) : "";
			if (isOneHigh(sortPileCardNumber, cardNumber)) {
				spadePile.push(card);
				return true;
			}
		}
		else if (suit == 'C') {
			string sortPileCardNumber = (!clubsPile.empty()) ? (clubsPile.top().substr(0, clubsPile.top().size() - 1)) : "";
			if (isOneHigh(sortPileCardNumber, cardNumber)) {
				clubsPile.push(card);
				return true;
			}
		}
		return false;
	}
	bool isOneHigh(string previous, string current) {
		return (previous == "" && current == "A") || (previous == "A" && current == "2") || (previous == "2" && current == "3")
			|| (previous == "3" && current == "4") || (previous == "4" && current == "5") || (previous == "5" && current == "6")
			|| (previous == "6" && current == "7") || (previous == "7" && current == "8") || (previous == "8" && current == "9")
			|| (previous == "9" && current == "10") || (previous == "10" && current == "J") || (previous == "J" && current == "Q") || (previous == "Q" && current == "K");
	}

	void moveCardsToPileMenu()
	{
		cout << "\nFrom where you want to select card:" << endl;
		cout << "1: Pile 1 (" << pile[0].top() << ")" << endl;
		cout << "2: Pile 2 (" << pile[1].top() << ")" << endl;
		cout << "3: Pile 3 (" << pile[2].top() << ")" << endl;
		cout << "4: Pile 4 (" << pile[3].top() << ")" << endl;
		cout << "5: Pile 5 (" << pile[4].top() << ")" << endl;
		cout << "6: Pile 6 (" << pile[5].top() << ")" << endl;
		cout << "7: Pile 7 (" << pile[6].top() << ")" << endl;
		cout << "8: Discard (" << discardPile.front() << ")" << endl;
		cout << "Your Selection: ";
		int option;
		cin >> option;
		while (option < 1 || option > 8) {
			cout << "Invalid option, Select again: ";
			cin >> option;
		}
		if (1 <= option && option <= 7) {
			if (pile[option - 1].empty()) cout << "Pile " << option << " have no card" << endl;
			else {
				int maxCardCount = pile[option - 1].size() - pile[option - 1].hideCount, cardCount = 1;
				if (maxCardCount > 1) {
					cout << "How many cards you want to move (1-" << maxCardCount << "): ";
					cin >> cardCount;
				}
				cout << "Enter pile number(1-7) where you want to place card (not include pile " << option << "): ";
				int pilenum;
				cin >> pilenum;
				while (pilenum < 1 || pilenum > 7 || pilenum == option) {
					cout << "Invalid pile number, Select again: ";
					cin >> pilenum;
				}
				if (canMoveCardToPile(pile[option - 1].get(pile[option - 1].size() - cardCount + 1), pilenum)) {
					for (int i = cardCount; i >= 1; i--)
						pile[pilenum - 1].push(pile[option - 1].get(pile[option - 1].size() - i + 1));
					for (int i = cardCount; i >= 1; i--)
						string temp = pile[option - 1].pop();
				}
				else cout << "Card can't move to pile" << endl;
			}
		}
		else if (option == 8) {
			if (discardPile.empty()) cout << "Discard has no card" << endl;
			else {
				cout << "Enter pile number(1-7) where you want to place card: ";
				int pilenum;
				cin >> pilenum;
				while (pilenum < 1 || pilenum > 7) {
					cout << "Invalid pile number, Select again: ";
					cin >> pilenum;
				}
				if (canMoveCardToPile(discardPile.front(), pilenum)) {
					pile[pilenum - 1].push(discardPile.front());
					string temp = discardPile.deque();
					if (!deck.empty()) discardPile.enque(deck.deque());
				}
				else cout << "Card can't move to pile" << endl;
			}
		}
	}
	bool canMoveCardToPile(string card, int pilenum) {
		char cardSuit = card[card.size() - 1];
		string cardNumber = card.substr(0, card.size() - 1);
		string pileCard = pile[pilenum - 1].top();
		char pileCardSuit = (pileCard != "") ? pileCard[pileCard.size() - 1] : ' ';
		string pileCardNumber = (pileCard != "") ? pileCard.substr(0, pileCard.size() - 1) : "";
		if (isDiffrentColor(pileCardSuit, cardSuit) && isOneLow(pileCardNumber, cardNumber)) {
			return true;
		}
		return false;
	}
	bool isOneLow(string previous, string current) {
		return (previous == "" && current == "K") || (previous == "K" && current == "Q") || (previous == "Q" && current == "J")
			|| (previous == "J" && current == "10") || (previous == "10" && current == "9") || (previous == "9" && current == "8")
			|| (previous == "8" && current == "7") || (previous == "7" && current == "6") || (previous == "6" && current == "5")
			|| (previous == "5" && current == "4") || (previous == "4" && current == "3") || (previous == "3" && current == "2") || (previous == "2" && current == "A");
	}
	bool isDiffrentColor(char previous, char current) {
		return ((previous == 'C' || previous == 'S') && (current == 'H' || current == 'D'))
			|| ((previous == 'H' || previous == 'D') && (current == 'C' || current == 'S'))
			|| (previous == ' ');
	}

	void flipCards() {
		if (deck.empty()) {
			while (!dealtDeck.empty())
				deck.enque(dealtDeck.deque());
			while (!discardPile.empty())
				deck.enque(discardPile.deque());
			completeFlips++;
			cout << "\nComplete deck flips = " << completeFlips << "\n\n";
		}
		while (!discardPile.empty())
			dealtDeck.enque(discardPile.deque());
		if (!deck.empty()) discardPile.enque(deck.deque());
		if (!deck.empty()) discardPile.enque(deck.deque());
		if (!deck.empty()) discardPile.enque(deck.deque());
	}

};
