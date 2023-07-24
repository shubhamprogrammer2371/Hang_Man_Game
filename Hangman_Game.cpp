#include <iostream>
#include <ctime>
#include <conio.h>

using namespace std;

int user_win = 0, jailer_win = 0;

int checkGuess(char guess, string real_month, string &hidden_month)
{
    int matches = 0;
    for (int i = 0; i < real_month.length(); i++)
    {
        if (guess == hidden_month[i])
            return 0;
        if (guess == real_month[i])
        {
            hidden_month[i] = guess;
            matches++;
        }
    }
    return matches;
}

void hang_man(char state, string message)
{
    string head = "|", hang = "********", lever = "_|_";
    if (state == 'f')
    {
        head = " ";
        lever = "_\\_";
    }
    if (state == 'h')
    {
        hang = "        ";
        lever = "_/_";
    }

    cout << "\t\t\t\t_____________________________" << endl;
    cout << "\t\t\t\t|             " << head << "             |" << endl;
    cout << "\t\t\t\t|             O             |" << endl;
    cout << "\t\t\t\t|            / \\            |\t\t  " << message << endl;
    cout << "\t\t\t\t|             |             |\t\t/" << endl;
    cout << "\t\t\t\t|            / \\            |\t      O " << endl;
    cout << "\t\t\t\t|     ****" << hang << "****      |\t" << lever << "  / \\ " << endl;
    cout << "\t\t\t\t|     |              |      |\t| |   | " << endl;
    cout << "\t\t\t\t|     |              |      |\t| |  / \\ " << endl;
    cout << "\t\t\t\t=============================================" << endl;
}

void play()
{
    int tries = 3;
    string message = "You have 3 chances", month, months[] = {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};
    char letter;

    srand(time(0));
    int month_number = rand() % 12;
    month = months[month_number];

    string hide_month(month.length(), 'X');

    system("cls");
    while (tries != 0)
    {
        hang_man('n', message);
        cout << "\t\t\t\tLife :- " << tries << endl;
        cout << "\t\t\t\tThe hidden month is :- " << hide_month << endl;
        cout << "\t\t\t\tGuess a letter :- ";
        cin >> letter;
        system("cls");

        if (checkGuess(letter, month, hide_month) == 0)
        {
            message = "Incorrect Letter";
            tries--;
        }
        else
            message = "Nice! Correct Guess :)";

        if (hide_month == month)
        {
            user_win++;
            hang_man('f', "You are Free!! Enjoy your Life.");
            cout << "\t\t\t\tLife :- " << tries << endl;
            cout << "\t\t\t\tThe month is :- " << month << endl;
            break;
        }
    }
    if (tries == 0)
    {
        jailer_win++;
        hang_man('h', "You are Hanged!!!");
        cout << "\t\t\t\tLife :- " << tries << endl;
        cout << "\t\t\t\tThe month is :- " << month << endl;
    }
    cout << "\n\t\t\t\t------ Scores ------\n\t\t\t\tYou :- " << user_win << "\n\t\t\t\tJailer :- " << jailer_win;
}

void instructions()
{
    cout << "********** INSTRUCTIONS ************\n\n";
    cout << "1) You have to guess a word from the months of a year.\n2) After you guessed the month then type any letter of the month and press enter.\n3) If the typed letter matches the alphabet of that month then you will be saved from hangingto the death and your life will not be deducted.\n4) But if you guessed the wrong letter than the ife will be deducted by '1'.\n5) After you have finished with your lives then you will be hanged by the jailer till the death :(\n6) If you have guessed and typed the right letters of the month name then you will be free and ready to live your life happily!!\n7) You will be getting '3' lives per game.\n8) Let's play the game and get free from jailer rather than hanging till death.\n\n";
}
int main()
{
    int choice;
    while (1)
    {
        system("cls");
        cout << "******** Hang Man Game ***********\n\n";
        cout << "1) Start the Game\n2) Instrictions\n3) Exit\n";
        cout << "Enter your choice :- ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            play();
            cout << "\nPress any key to continue ";
            getch();
            break;
        case 2:
            system("cls");
            instructions();
            cout << "Press any key to continue ";
            getch();
            break;
        case 3:
            system("cls");
            cout << "I hope you like the game :)\n";
            cout << "Press any key to exit the game ";
            getch();
            exit(0);
            break;
        default:
            cout << "\nInvalid Input";
            break;
        }
    }
    return 0;
}