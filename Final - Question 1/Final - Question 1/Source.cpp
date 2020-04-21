#include <iostream>
#include <string>
using namespace std;


class ship {
private:
	int hullPoints;
	int xloc;
	int yloc;
	string name;
public:
	void setName(string s) {
		this->name = s;
	}

	void setxLoc(int x) {
		this->xloc = x;
	}

	void setyLoc(int y) {
		this->yloc = y;
	}

	void setHP(int hp) {
		this->hullPoints = hp;
	}

	string getName() {
		return this->name;
	}

	int getxLoc() {
		return this->xloc;
	}

	int getyLoc() {
		return this->yloc;
	}

	int getHP() {
		return this->hullPoints;
	}

	virtual void fireWeapons() = 0;
};

class Carrier : public ship {
public:
	Carrier() : ship() {
		this->setHP(5);
		this->setName("USS Enterprise");
	}

	void fireWeapons() override {
		cout << "Launching Planes!" << endl;
	}

};

class Battleship : public ship {
public:
	Battleship() : ship() {
		this->setHP(4);
		this->setName("USS Missouri");
	}

	void fireWeapons() override {
		cout << "Firing 16 inch guns! This is gonna be loud!" << endl;
	}

};

class Destroyer : public ship {
public:
	Destroyer() : ship() {
		this->setHP(3);
		this->setName("USS Taylor");
	}

	void fireWeapons() override {
		cout << "Deploying Depthcharges!" << endl;
	}

};

class Sneaky : public ship {
public:
	Sneaky() : ship() {}

	void fireWeapons() override {
		cout << "Firing Torpedos!" << endl;
	}
};

class Submarine : public Sneaky {
public:
	Submarine() : Sneaky() {
		this->setHP(3);
		this->setName("USS Narwhal");
	}
};

class PTBoat : public Sneaky {
public:
	PTBoat() : Sneaky() {
		this->setHP(2);
		this->setName("PT-73");
	}
};

class Game {
private:
	char Board[10][10];
	Carrier cv;
	Battleship bb;
	Destroyer dd;
	Submarine ss;
	PTBoat pt;
public:

	Game() {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				Board[i][j] = ' ';
			}
		}
	}

	void printBoat() {
		cout << "  ";
		for (int col = 0; col < 10; col++) {
			cout << col << "   ";
		}
		cout << endl;
		for (int i = 0; i < 10; i++) {
			cout << i << " ";
			for (int j = 0; j < 10; j++) {
				cout << Board[i][j] << " | ";
			}
			cout << "\n------------------------------------------\n";
		}
	}

	bool checkEmpty(int size, int x, int y, char dir) {
		int i = x;
		int j = y;
		if (dir == 'h') {
			while (j < 10) {
				if (Board[i][j] == ' ') {
					j++;
					size--;
					if (size == 0) {
						return true;
					}
					continue;
				}
				return false;
			}
		}
		j = y;
		if (dir == 'v') {
			while (i < 10) {
				if (Board[j][i] == ' ') {
					size--;
					i++;
					if (size == 0) {
						return true;
					}
					continue;
				}
				return false;
			}
		}

		return false;
	}

	bool validPlacement(char ship, int x, int y, char dir) {

		int i = x;
		int j = y;
		int steps = 0;
		if (dir == 'h') {
			while (i < 10) {
				if (Board[i][j] == ' ') {
					steps++;
					if (steps == 2) {
						return true;
					}
				}
				j++;
			}
		}

		if (dir == 'v') {
			while (i < 10) {
				if (Board[i][j] == ' ') {
					steps++;
					if (steps == 2) {
						return true;
					}
				}
				i++;
			}
		}

		return false;
	}

	void markShip(int size, int x, int y, char dir) {

		if (checkEmpty(size, x, y, dir)) {

			if (dir == 'h') {
				while (size != 0) {
					Board[x][y++] = 'X';
					size--;
				}
			}
			else {
				while (size != 0) {
					Board[x++][y] = 'X';
					size--;
				}
			}

		}
		else {
			cout << "The Area is already Occupied\n";
		}

		printBoat();
	}

	void placeShips() {
		int x, y; char dir;
		cout << "Enter x for Carrier: ";
		cin >> x;
		cout << "Enter y for Carrier: ";
		cin >> y;
		cout << "Enter Direction: (h/v) ";
		cin >> dir;
		if (validPlacement('X', x, y, dir)) {
			cv.setxLoc(x);
			cv.setyLoc(y);
			markShip(cv.getHP(), cv.getxLoc(), cv.getyLoc(), dir);
		}
		else {
			cout << "Not valid Placement\n";
		}

		cout << "Enter x for Submarine: ";
		cin >> x;
		cout << "Enter y for Submarine: ";
		cin >> y;
		cout << "Enter Direction: (h/v) ";
		cin >> dir;
		if (validPlacement('X', x, y, dir)) {
			bb.setxLoc(x);
			bb.setyLoc(y);
			markShip(bb.getHP(), bb.getxLoc(), bb.getyLoc(), dir);
		}
		else {
			cout << "Not valid Placement\n";
		}

		cout << "Enter x for Destroyer: ";
		cin >> x;
		cout << "Enter y for Destroyer: ";
		cin >> y;
		cout << "Enter Direction: (h/v) ";
		cin >> dir;
		if (validPlacement('X', x, y, dir)) {
			dd.setxLoc(x);
			dd.setyLoc(y);
			markShip(dd.getHP(), dd.getxLoc(), dd.getyLoc(), dir);
		}
		else {
			cout << "Not valid Placement\n";
		}

		cout << "Enter x for Spaceship: ";
		cin >> x;
		cout << "Enter y for Spaceship: ";
		cin >> y;
		cout << "Enter Direction: (h/v) ";
		cin >> dir;
		if (validPlacement('X', x, y, dir)) {
			ss.setxLoc(x);
			ss.setyLoc(y);
			markShip(ss.getHP(), ss.getxLoc(), ss.getyLoc(), dir);
		}
		else {
			cout << "Not valid Placement\n";
		}

		cout << "Enter x for PTBoat: ";
		cin >> x;
		cout << "Enter y for PTBoat: ";
		cin >> y;
		cout << "Enter Direction: (h/v) ";
		cin >> dir;
		if (validPlacement('X', x, y, dir)) {
			pt.setxLoc(x);
			pt.setyLoc(y);
			markShip(pt.getHP(), pt.getxLoc(), pt.getyLoc(), dir);
		}
		else {
			cout << "Not valid Placement\n";
		}
	}
};

int main() {

	Game G;
	G.printBoat();
	G.placeShips();
	system("pause");
	return 0;
}