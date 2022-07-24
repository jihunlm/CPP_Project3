#include <iostream>
#include <string>
#include <cstdlib> // to generate random numbers
#include <ctime>
using namespace std;

void rules();

class gamer {
    public:
    string name;
    int money = 1000;


};

int main() {
    rules();
    gamer player;
    int amount, number, guess;
    int num_try = 0;

    cout << "Enter your name : ";
    cin >> player.name;
    
    srand(time(0));

    while(player.money != 0){
        number = (rand() % 10) + 1;
        cout << "Enter the amount that you are going to bet : ";
        cin >> amount;
        cout << "Enter the number : ";
        cin >> guess;

        if (guess == number){
            player.money *= 10;
	    cout << "You have guessed correct number!\n";
	    cout << "The amount you have right now is : " << player.money << endl;
        }
        else{
            player.money -= amount;
	    cout << "The number you guessed is wrong!\n";
        cout << "The correct number is : " << number << endl;
	    cout << "The amount you have right now is : " << player.money << endl;
        }

	num_try++;

    }
    cout << "You have lost all of your money\n";
    cout << "You have tried " << num_try << " tries.\n";
    cout << "You can check your rank in the 'RANK.txt' file\n"; 
}

void rules(){
    cout << "/////////////////////////////////////////////////////////////////////////////////////\n";
    cout << "\tWelcome to the Casino Game!!!\n";
    cout << "\tYou are going to guess a number between 1 to 10\n";
    cout << "\tIf your guess is correct, you are going to earn 10 times the amount you bet\n";
    cout << "\tBUT, if your guess is wrong, you are going to lose the amount you bet.\n";
    cout << "\tYou will be starting with $1000\n";
    cout << "/////////////////////////////////////////////////////////////////////////////////////\n";
}
