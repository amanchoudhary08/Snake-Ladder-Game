#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

void draw_line(int n, char ch);
void board();
void gamescore(const string &name1, const string &name2, int p1, int p2);
void play_dice(int &score);

int main()
{
    int player1 = 0, player2 = 0, lastposition;
    string player1name, player2name;

    srand(time(0)); // Initialize random seed
    draw_line(50, '=');
    cout << "\n\n\n\t\tSNAKE LADDER GAME\n\n\n";
    draw_line(50, '=');

    cout << "\n\nEnter Name of Player 1: ";
    getline(cin, player1name);
    cout << "Enter Name of Player 2: ";
    getline(cin, player2name);

    while (player1 < 100 && player2 < 100)
    {
        board();
        gamescore(player1name, player2name, player1, player2);

        cout << "\n---> " << player1name << ", it's your turn! Press Enter to roll the dice.";
        cin.ignore();
        lastposition = player1;
        play_dice(player1);

        if (player1 < lastposition)
            cout << "\nOops!! Snake found! You are at position " << player1 << ".\n";
        else if (player1 > lastposition + 6)
            cout << "\nGreat! You climbed a ladder! You are at position " << player1 << ".\n";

        cout << "\n---> " << player2name << ", it's your turn! Press Enter to roll the dice.";
        cin.ignore();
        lastposition = player2;
        play_dice(player2);

        if (player2 < lastposition)
            cout << "\nOops!! Snake found! You are at position " << player2 << ".\n";
        else if (player2 > lastposition + 6)
            cout << "\nGreat! You climbed a ladder! You are at position " << player2 << ".\n";
    }

    cout << "\n\n\n";
    draw_line(50, '+');
    cout << "\n\n\t\tRESULT\n\n";
    draw_line(50, '+');
    cout << endl;
    gamescore(player1name, player2name, player1, player2);

    if (player1 >= 100)
        cout << player1name << ", you are the winner of the game!\n\n";
    else
        cout << player2name << ", you are the winner of the game!\n\n";

    draw_line(50, '+');
    return 0;
}

void draw_line(int n, char ch)
{
    for (int i = 0; i < n; i++)
        cout << ch;
    cout << endl;
}

void board()
{
    cout << "\n\n";
    draw_line(50, '-');
    cout << "\n\t\tSNAKES AT POSITION\n";
    draw_line(50, '-');
    cout << "  98 -> 28, 95 -> 24, 92 -> 51, 83 -> 19\n";
    cout << "  73 -> 1, 69 -> 33, 64 -> 36, 59 -> 17\n";
    cout << "  55 -> 7, 52 -> 11, 48 -> 9, 46 -> 5\n";
    cout << "  44 -> 22\n\n";

    draw_line(50, '-');
    cout << "\n\t\tLADDERS AT POSITION\n";
    draw_line(50, '-');
    cout << "  8 -> 26, 21 -> 82, 43 -> 77, 50 -> 91\n";
    cout << "  62 -> 96, 66 -> 87, 80 -> 100\n";
    draw_line(50, '-');
    cout << endl;
}

void gamescore(const string &name1, const string &name2, int p1, int p2)
{
    cout << "\n";
    draw_line(50, '~');
    cout << "\n\t\tGAME STATUS\n";
    draw_line(50, '~');
    cout << "\n---> " << name1 << " is at position " << p1;
    cout << "\n---> " << name2 << " is at position " << p2 << "\n";
    draw_line(50, '_');
    cout << endl;
}

void play_dice(int &score)
{
    int dice = (rand() % 6) + 1; // Generate random dice roll (1-6)
    cout << "\nYou rolled a " << dice << "!";
    score += dice;

    // Snakes and ladders
    switch (score)
    {
    case 98:
        score = 28;
        break;
    case 95:
        score = 24;
        break;
    case 92:
        score = 51;
        break;
    case 83:
        score = 19;
        break;
    case 73:
        score = 1;
        break;
    case 69:
        score = 33;
        break;
    case 64:
        score = 36;
        break;
    case 59:
        score = 17;
        break;
    case 55:
        score = 7;
        break;
    case 52:
        score = 11;
        break;
    case 48:
        score = 9;
        break;
    case 46:
        score = 5;
        break;
    case 44:
        score = 22;
        break;
    case 8:
        score = 26;
        break;
    case 21:
        score = 82;
        break;
    case 43:
        score = 77;
        break;
    case 50:
        score = 91;
        break;
    case 62:
        score = 96;
        break;
    case 66:
        score = 87;
        break;
    case 80:
        score = 100;
        break;
    }

    if (score > 100)
        score -= dice; // Prevent overshooting 100
    cout << " Now you are at position " << score << ".\n";
}
