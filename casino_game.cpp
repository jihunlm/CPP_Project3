#include <iostream>
#include <string>
#include <cstdlib> // to generate random numbers
#include <ctime>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

void rules();

class gamer {
    public:
    string name;
    int money = 1000;
};

int get_rank(std::string input) {
    std::stringstream ss(input);
    std::string s;
    // keep extracting strings, last one would be your 'int' rank
    for(; ss >> s; );
    return std::atoi(s.c_str());
}

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
    
    ofstream oFile;
    oFile.open("RANK.txt", ios::binary|ios::app);
    oFile << num_try << "," << player.name << "," << num_try << endl;

    std::fstream infile("RANK.txt");
    std::vector<std::string> v;
    std::string line;
    std::getline(infile, line);
    for( ; getline( infile, line ); )
        v.push_back(line);
    std::sort(v.begin(), v.end(), [](std::string s1, std::string s2) -> bool { return get_rank(s1) > get_rank(s2); });
    for(int i = 0;i < 10;i++)   
        infile << i + 1 << "," << v[i].substr(v[i].find(",") + 1) << endl;
    return 0;

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

