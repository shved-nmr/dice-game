#include <iostream>
#include <istream>
#include <cstdlib>
#include <ctime>
using namespace std;

int rand_num(){
    srand(time(0));
    int n = (rand() % 6 + 1);
    return n;
}
int game_play(){
    int pl1_num = 0;
    int com_num = 0;

    pl1_num = rand_num();
    com_num = rand_num();

    if(pl1_num > com_num){
        cout << "Player wins this round!";
    } else if (pl1_num == com_num){
        cout << "It's a draw!";
    } else{
        cout << "Computer wins this round!";
    }
}

int main() {
    cout << "\t Let's roll some dice!" << endl;
    cout << "@@@@@@@@ Press enter to begin @@@@@@@@" << endl;
    cin.ignore();
    game_play();

    return 0;
}

