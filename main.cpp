#include <iostream>
#include <istream>
#include <cstdlib>
using namespace std;

int pl1_score = 0;
int com_score = 0;

int rand_num(){
    int n = rand() % 6 + 1;
    return n;
}
int print_score(){
    cout << "\n The score is:\nPLayer: " << pl1_score << "\tComputer: " << com_score;
    return 0;
}
string who_won(int a, int b){
    if (a>b){
        return "W";
    } else if (a<b) {
        return "L";
    } else {
        return "D";
    }
}
int game_play(){
    int pl1_num = 0;
    int com_num = 0;

    while(pl1_score < 5 && com_score < 5) {
        pl1_num = rand_num();
        com_num = rand_num();

        if (who_won(pl1_num, com_num) == "W") {
            pl1_score++;
            cout << "\nPlayer wins this round!";
            print_score();
            cout << "\nPress ENTER to continue";
            cin.ignore();
        } else if (who_won(pl1_num, com_num) == "L") {
            com_score++;
            cout << "\nComputer wins this round!";
            print_score();
            cout << "\nPress ENTER to continue";
            cin.ignore();
        } else {
            cout << "\nIt's a draw!";
            print_score();
            cout << "\nPress ENTER to continue";
            cin.ignore();
        }
    }
    if(who_won(pl1_score, com_score) == "W"){
        cout << "YOU WON!";
    }else{
        cout << "YOU LOST!";
    }
    return 0;
}

int main() {
    cout << "\t Let's roll some dice!" << endl;
    cout << "@@@@@@@@ Press enter to begin @@@@@@@@" << endl;
    cin.ignore();
    game_play();

    return 0;
}

