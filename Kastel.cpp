
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;
struct KCard
{
    char Name[8];
    int Number;
};
void AddCard(KCard TCard[][6], int b, KCard c)
{
    int i;
    for(i = 0; 1; i++){
        if(TCard[b][i].Number == 0){
            strcpy(TCard[b][i].Name, c.Name);
            TCard[b][i].Number = c.Number;
            break;
        }
    }
}
void ReplaceCard(int c1, KCard Card1[], KCard Card2[], KCard Card3[], KCard Card[], int i)
{
    int j, t = rand() % 45;
    if(c1 == 1){
        strcpy(Card1[i].Name, Card[t].Name);
        Card1[i].Number = Card[t].Number;
    }
    if(c1 == 2){
        strcpy(Card2[i].Name, Card[t].Name);
        Card2[i].Number = Card[t].Number;
    }
    if(c1 == 3){
        strcpy(Card3[i].Name, Card[t].Name);
        Card3[i].Number = Card[t].Number;
    }
}
void CleanTable(KCard TCard[][6], int PNumber)
{
    int i, j;
    for(i = 0; i < PNumber; i++){
        for(j = 0; j < 6; j++)
            TCard[i][j].Number = 0;
    }
}
void BuildCards(KCard Card[])
{
    int i;
    for (i = 0; i < 15; i++){
        strcpy(Card[i].Name, "Zombie");
        Card[i].Number = i + 1;
    }
    for (i = 15; i < 30; i++){
        strcpy(Card[i].Name, "Mummy");
        Card[i].Number = i - 14;
    }
    for (i = 30; i < 45; i++){
        strcpy(Card[i].Name, "Pumpkin");
        Card[i].Number = i - 29;
    }
}
void DealCards(KCard Card1[], KCard Card2[], KCard Card3[], KCard Card[], int PNumber)
{
    BuildCards(Card); // ساخت کارت ها
    int i, t, j;
    for(i = 0; i < PNumber; i++){
        t = rand() % 45;
        strcpy(Card1[i].Name, Card[t].Name);
        Card1[i].Number = Card[t].Number;
        t = rand() % 45;
        strcpy(Card2[i].Name, Card[t].Name);
        Card2[i].Number = Card[t].Number;
        t = rand() % 45;
        strcpy(Card3[i].Name, Card[t].Name);
        Card3[i].Number = Card[t].Number;
    }
}
int main()
{
    srand(time(0));
    int i, j, k, m, n, PNumber, t, c1, c2, c3, c4;
    cout << "Enter the Number of Players (2 - 6)" << endl;
    cin >> PNumber; // تعداد بازیکنان
    while(PNumber != 2 && PNumber != 3 && PNumber != 4 && PNumber != 5 && PNumber != 6){
        cout << "Error! Enter again" << endl;
        cin >> PNumber;
    }
    KCard Card[45], Card1[PNumber], Card2[PNumber], Card3[PNumber], u;
    DealCards(Card1, Card2, Card3, Card, PNumber); // پخش کردن کارت ها بین بازیکنان
    KCard TCard[PNumber][6]; // کارت های روی میز
    CleanTable(TCard, PNumber);
    bool q = true;
    system("cls");
    for(i = 0; q == true; i++){
        for(j = 0; j < PNumber; j++){ // نمایش کارت های روی میز
            cout << "Player " << j + 1 << ": ";
            for(k = 0; TCard[j][k].Number != 0; k++)
                 cout << TCard[j][k].Name << TCard[j][k].Number << " ";
            cout << endl;
        }
        cout << "Player " << i + 1 << " turn" << endl;
        Pick_Menu:
        cout << "Pick one card" << endl;
        cout << "1. " << Card1[i].Name << Card1[i].Number << endl;
        cout << "2. " << Card2[i].Name << Card2[i].Number << endl;
        cout << "3. " << Card3[i].Name << Card3[i].Number << endl;
        cin >> c1;
        if(c1 == 1){
            strcpy(u.Name, Card1[i].Name);
            u.Number = Card1[i].Number;
        }
        if(c1 == 2){
            strcpy(u.Name, Card2[i].Name);
            u.Number = Card2[i].Number;
        }
        if(c1 == 3){
            strcpy(u.Name, Card3[i].Name);
            u.Number = Card3[i].Number;
        }
        if(c1 != 1 && c1 != 2 && c1 != 3){
            cout << "Error! Pick again" << endl;
            goto Pick_Menu;
        }
        Choice_Menu:
        cout << "Choose what to do with the card" << endl;
        cout << "1. Add to yours" << endl;
        cout << "2. Replace the similar card on another player" << endl;
        cout << "0. Back" << endl;
        cin >> c2;
        if(c2 == 0) goto Pick_Menu;
        if(c2 == 1) AddCard(TCard, i, u); // اضافه کردن کارت جلوی بازیکن
        if(c2 == 2){ // گذاشتن کارت روی کارت بازیکن دیگر
            Player_Section:
            cout << "choose player" << endl;
            cout << "0. Back" << endl;
            for(j = 0; j < PNumber; j++){
                if(j == i) continue;
                cout << j + 1 << ". Player " << j + 1 << endl;
            }
            cin >> c3;
            if(c3 == 0) goto Choice_Menu;
            bool p = false;
            for(j = 1; j <= PNumber; j++){
                if(j == c3){
                    p = true;
                    break;
                }
            }
            if(p == false){ // درصورت اشتباه بودن گزینه
                cout << "Error! Choose again" << endl;
                goto Player_Section;
            }
            Replace_Options:
            cout << "Choose card to replace" << endl;
            cout << "0. Back" << endl;
            for(j = 0; j < 6 && TCard[c3 - 1][j].Number != 0; j++){ // نمایش کارت های بازیکن انتخاب شده
                cout << j + 1 << ". " << TCard[c3 - 1][j].Name << TCard[c3 - 1][j].Number << endl;
            }
            cin >> c4;
            if(c4 == 0) goto Player_Section;
            if(strcmp(TCard[c3 - 1][c4 - 1].Name, u.Name) == 0) TCard[c3 - 1][ c4 - 1].Number = u.Number; // درصورت قابل انجام بودن
            else{ // درصورت قابل انجام نبودن
                cout << "Not possible! Choose again" << endl;
                goto Replace_Options;
            }
        }
        if(c2 != 0 && c2 != 1 && c2 != 2){ // گزینه اشتباه
            cout << "Error! Choose again" << endl;
            goto Choice_Menu;
        }
        ReplaceCard(c1, Card1, Card2, Card3, Card, i); // جایگذاری کارت جدید جای کارت استفاده شده
        for(j = 0; j < PNumber; j++){ // درصورت وجود دو کارت تکراری جلوی یک نفر
            for(k = 0; TCard[j][k + 1].Number != 0 && k < 5; k++){
                for(m = k + 1; TCard[j][m].Number != 0 && m < 6; m++){
                    if(strcmp(TCard[j][k].Name, TCard[j][m].Name) == 0 && TCard[j][k].Number == TCard[j][m].Number){
                        TCard[j][m].Number = 0;
                        for(n = m; TCard[j][n].Number != 0 && n < 5; n++){
                            strcpy(TCard[j][n].Name, TCard[j][n + 1].Name);
                            TCard[j][n].Number = TCard[j][n + 1].Number;
                        }
                        TCard[j][n + 1].Number = 0;
                    }
                }
            }
        }
        for(j = 0; j < PNumber; j++){ // بررسی شرط پایان بازی
            if(TCard[j][5].Number != 0){
                q = false;
                break;
            }
        }
        if(i == PNumber - 1) i = -1; // شروع دور بعدی
        system("cls");
    }
    int sum[PNumber], Max = 0;
    for(i = 0; i < PNumber; i++){ // جمع زدن عددهای جلوی هر بازیکن
        sum[i] = 0;
        for(j = 0; j < 6; j++)
            sum[i] += TCard[i][j].Number;
    }
    for(i = 1; i < PNumber; i++) // بررسی بازیکن با بیشترین عدد
        if(sum[Max] < sum[i]) Max = i;
    cout << "Player " << Max + 1 << " won";
}
