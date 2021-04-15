#include <iostream>
#include <istream>
#include <cstdlib>
using namespace std;

//function declarations
bool who_won(int a, int b);
int print_score();
int rand_num();
int game_play();

//Global Variables
int pl1_score = 0;
int pl2_score = 0;
string pl1_name;
string pl2_name;
bool isSecond = true;
int first = 0;

int main() {
    cout << "\t Let's roll some dice!" << endl;
    cout << "Let's start with an introduction" << endl;
    cout << "Enter your name, Player 1:";
    cin >> pl1_name;
    cout << "Enter your name, Player 2:";
    cin >> pl2_name;
    game_play();

    return 0;
}


int rand_num(){
    int n = 0;

    if (isSecond) {
        n = rand() % 6 + 1;
        isSecond = !isSecond;
        first = n;
    } else {
        n = rand() % 6 + 1;
        while(n == first){
            n = rand() % 6 + 1;
        }
        isSecond = !isSecond;
    }
    return n;
}


int print_score(){
    cout << "\n\tThe score is:\n** "<< pl1_name << ": " << pl1_score << "\t" << pl2_name << ": " << pl2_score << " **";
    return 0;
}


bool who_won(int a, int b) {
    return a >= b;
}


int game_play(){
    int pl1_num = 0;
    int pl2_num = 0;

    while(pl1_score < 5 && pl2_score < 5) {
        cout << "\n" << pl1_name <<", press enter to roll the dice!" << endl;
        cin.ignore();
        cout << "Your number is " << (pl1_num = rand_num()) << endl;
        cout << "\n" << pl2_name << ", press enter to roll the dice!";
        cin.ignore();
        cout << "Your number is " << (pl2_num = rand_num()) << "\n" << endl;

        if (who_won(pl1_num, pl2_num)) {
            pl1_score++;
            cout << pl1_name << " wins this round!";
            print_score();
            cout << "\nPress ENTER to continue";
            cin.ignore();
        } else {
            pl2_score++;
            cout << pl2_name << " wins this round!";
            print_score();
            cout << "\nPress ENTER to continue";
            cin.ignore();
        }
    }
    if(who_won(pl1_score, pl2_score)){
        cout << "\n" << pl1_name << " IS THE WINNER!";
    }else{
        cout << "\n" << pl2_name << " IS THE WINNER!";
    }
    return 0;
}