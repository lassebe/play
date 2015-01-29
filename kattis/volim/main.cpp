#include <iostream>
using namespace std;

int main(){
    int player;
    int questions;
    char answer;
    int time=210;
    int roundTime=0;
    cin >> player;
    cin >> questions;
    for(int i=0; i < questions; ++i){
        cin >> roundTime;
        cin >> answer;
        time-= roundTime;
        if(time <= 0){
            cout<<player<<endl;
            cin.get();
            return 0;
        }
        if(answer == 'T'){
            player++;
            if(player == 9)
                player = 1;
        }

    }
    cout<<player<<endl;
    cin.get();
    return 0;
}
