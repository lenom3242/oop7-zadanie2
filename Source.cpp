#include <iostream>
#include <ctime>
using namespace std;
class Game;
class Helper {
private:
	Game *lol;
public:
	void help();
	Helper(Game *n_lol) : lol(n_lol) {}
};
class Game {
private:
	int digits[4];
	int tries = 0;
public:
	void givevar(int digit) {
		tries++;
		int pdigits[4];
		char check[4] = { '*','*','*','*' };
		int counter = 0;
		pdigits[0] = digit / 1000; pdigits[1] = (digit / 100) % 10, pdigits[2] = (digit % 100) / 10; pdigits[3] = digit % 10; cout << endl;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (pdigits[i] == digits[j]) {
					check[i] = '#';
					break;
				}
			}
		}
		for (int i = 0; i < 4; i++)
			if (pdigits[i] == digits[i])
				check[i] = '@';
		for (int i = 0; i < 4; i++)
			if (check[i] == '@')
				counter++;
		for (int i = 0; i < 4; i++)
			cout << check[i];
		cout << endl;
		if (counter == 4) {
			cout << "You've won the game!\n";
			cout << "You've spent " << tries << " Tries\n";
			exit(1);
		}
		
			
	}
	friend void Helper::help();
	friend class Helper;
	Game() {
		int random;
		for (int i = 0; i < 4; i++) {
			random = rand() % 9;
			for (int j = 0; j < 4; j++) {
				if (random == digits[j]) {
					while (random == digits[j]) {
						random = rand() % 9;
					}
				}
				else {
					continue;
				}
			}
			digits[i] = random;
		}
		for (int i = 0; i < 4; i++)
			cout << digits[i];
		cout << endl;
	}
};
void Helper::help() {
	cout << "Please enter the digit to uncover\n";
	int digit;
	cin >> digit;
	cout << lol->digits[digit] << endl;
}
void main() {
	srand(time(0));
	Game var;
	Helper total(&var);
	while (true) {
		cout << "Please enter the number you want to guess:\n";
		int number;
		cin >> number;
		var.givevar(number);
		cout << "Do you want to see the tip?Y or N\n";
		char Z;
		cin >> Z;
		Z = toupper(Z);
		if (Z == 'Y') {
			total.help();
		}
		else {
			cout << "Please enter the number you want to guess:\n";
			number = 0;
			cin >> number;
			var.givevar(number);
		}
	}

}
