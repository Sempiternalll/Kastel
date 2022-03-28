#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;
struct KCard
{
    string Name;
    int Number;
};
int main()
{
    int i, UNumber;
    KCard Card[45];
    for(i = 0; i < 15; i++){
        Card[i].Name = "Zombie";
        Card[i].Number = i + 1;
    }
    for(i = 15; i < 30; i++){
        Card[i].Name = "Mummy";
        Card[i].Number = i - 14;
    }
    for(i = 30; i < 45; i++){
        Card[i].Name = "Pumpkin";
        Card[i].Number = i - 29;
    }
    cout << "Enter the Number of Players" << endl;
    cin >> UNumber;

}
