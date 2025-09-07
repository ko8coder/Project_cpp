#include<iostream>
#include<cmath>
#include<string>
using namespace std;

enum enPapStnSci { Stone=1, Paper=2, Scissors=3};
short ChooseNumber(string Message, short From, short To)
{
    short Num;
    do
    {
        cout<<Message;
        cin>>Num;
    }
    while(Num<From || Num>To);
    return Num;
}

short RandomNumber(short From, short To)
{
    short RandNum = rand()%(To-From+1)+From;
    return RandNum;
}

struct stRounds
{
    string Player;
    string Computer;
    short Result;
};

struct stGame
{
    short win;
    short lose;
    short Draw;
};

string GetChar(short Num)
{
    switch(Num)
    {
    case 1:
        return "Stone";
    case 2:
        return "Paper";
    case 3:
        return "Scissors";
    default:
        return "Stone";
    }
}
short GetRoundResult(string Pl1, string Comp)
{

    if (Pl1 == Comp)
    {
        return 0;
    }
    else if ((Pl1 == "Paper" && Comp == "Stone") ||
             (Pl1 == "Stone" && Comp == "Scissors") ||
             (Pl1 == "Scissors" && Comp == "Paper"))
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
string GetRoundStatus (short wld)
{
    switch(wld)
    {
    case 1:

        return "Player1";
    case 0:
        return "No Winner";
    case -1:
        return "Computer";
    }
}

enPapStnSci ChooseToPlay(short Num)
{
    return enPapStnSci (Num);
}

void ProgressGame(short round,stGame& GameOver)
{

    if (round==0)
        GameOver.Draw++;
    else if (round==-1)
        GameOver.lose++;
    else
        GameOver.win++;
}

void ScreenColor(string Wld)
{
    if (Wld=="Player1")
        system("color 02");
    else if (Wld=="Computer")
        system("color 04");
    else
        system("color 06");
}

void PrintRoundResult(string Pl1, string Comp, short i, stGame& GameOver)
{
    stRounds Round;
    Round.Player=Pl1;
    Round.Computer=Comp;
    Round.Result=GetRoundResult(Pl1,Comp);
    ProgressGame(Round.Result,GameOver);
    string Wld = GetRoundStatus(Round.Result);//Wdl =====>>> W Winner; l looser; d Draw

    cout<<"\n_________________ Round ["<<i<<"] __________________________"<<endl;
    cout<<"\nPlayer1   Choice is: "<<Round.Player;
    cout<<"\nComputer  Choice is: "<<Round.Computer;
    cout<<"\nRound Winner       : ["<<Wld<<"]"<<endl;
    cout<<"\n______________________________________________________\n"<<endl;

    ScreenColor(Wld);


}

void ChoiceFunc(short NumPlayer, short NumComp, short i,stGame& GameOver)
{
    string PlayerChoice = GetChar(ChooseToPlay(NumPlayer));
    string CompChoice = GetChar(ChooseToPlay(NumComp));
    PrintRoundResult(PlayerChoice,CompChoice,i, GameOver);
}

string GetFinalWinner(stGame& GameOver)
{
    if (GameOver.win > GameOver.lose)
        return "Player1";
    else if (GameOver.win < GameOver.lose)
        return "Computer";
    else
        return "Draw";
}

void StartFunc()
{
    char PlayAgain;
    do
    {
        system("CLS");
        system("color 02");
        stGame GameOver = {0, 0, 0};
        short i=1;
        short NumberOfRounds = ChooseNumber("\nHow Many Rounds 1 to 10 ?\n",1,10);
        do
        {
            cout<<"\nRound ["<<i<<"] Begins :"<<endl;
            short NumPlayer = ChooseNumber("\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors ? ",1,3);
            short NumComp = RandomNumber(1,3);
            ChoiceFunc(NumPlayer,NumComp,i,GameOver);
            i++;
        }
        while(i<= NumberOfRounds);
        cout<<"\n_________________ ** Game Over ** __________________________"<<endl;
        cout<<"\n___________________________________________________________\n"<<endl;
        cout<<"\nGame Rounds          : "<<NumberOfRounds;
        cout<<"\nPlayer One Won Times : "<<GameOver.win;
        cout<<"\nComputer Won Times   : "<<GameOver.lose;
        cout<<"\nDraw   Times         : "<<GameOver.Draw;
        cout <<"\nFinal Winner         : "<< GetFinalWinner(GameOver);
        ScreenColor(GetFinalWinner(GameOver));
        cout<<"\n______________________________________________________\n"<<endl;
        cout<<"\nDo You Want To Play Again y/n"<<endl;
        cin>>PlayAgain;

    }
    while(PlayAgain=='y' || PlayAgain=='Y');
}

int main()
{
    srand((unsigned)time(NULL));

    StartFunc();

    return 0;
}
