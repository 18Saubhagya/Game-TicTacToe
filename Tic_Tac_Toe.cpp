#include<bits/stdc++.h>
using namespace std;
class TicTacToe
{
    char input1,input2;
    string player1,player2;
    char grid[3][3];
    public:
    TicTacToe(string name1,string name2)
    {
        player1=name1;
        player2=name2;
        input1='X';
        input2='O';
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
                grid[i][j]=='-';
        }
    }
    int input(string name)
    {
        int r,c,i,j;
        cin.ignore();
        cout<<"Player of Current turn: "<<name<<endl;
        cout<<"Choose a row number (0 to 2)"<<endl;
        cin>>r;
        while(r>2||r<0)
        {
            cout<<r<<" is not a valid row number."<<endl;
            cout<<"Choose a row number (0 to 2)"<<endl;
            cin>>r;
        }
        cout<<"Choose a column number (0 to 2)"<<endl;
        cin>>c;
        while(c>2||c<0)
        {
            cout<<c<<" is not a valid row number."<<endl;
            cout<<"Choose a column number (0 to 2)"<<endl;
            cin>>c;
        }
        if(grid[r][c]=='X'||grid[r][c]=='O')
            return 0;
        if(name==player1)
            grid[r][c]=input1;
        else
            grid[r][c]=input2;
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(grid[i][j]=='X'||grid[i][j]=='O')
                    cout<<grid[i][j]<<" ";
                else
                    cout<<"- ";
            }
            cout<<"\n";
        }
        return 1;
    }
    int check(char move)
    {
        if(grid[0][0]==move&&grid[0][1]==move&&grid[0][2]==move)
            return 1;
        else if(grid[0][0]==move&&grid[1][0]==move&&grid[2][0]==move)
            return 1;
        else if(grid[0][0]==move&&grid[1][1]==move&&grid[2][2]==move)
            return 1;
        else if(grid[0][1]==move&&grid[1][1]==move&&grid[2][1]==move)
            return 1;
        else if(grid[0][2]==move&&grid[1][2]==move&&grid[2][2]==move)
            return 1;
        else if(grid[0][2]==move&&grid[1][1]==move&&grid[2][0]==move)
            return 1;
        else if(grid[1][0]==move&&grid[1][1]==move&&grid[1][2]==move)
            return 1;
        else if(grid[2][0]==move&&grid[2][1]==move&&grid[2][2]==move)
            return 1;
        else
            return 0;
    }
};
int main()
{
    string choice,name1,name2,first,chance,second,winner;
    int turn=1,flag=0,Check;
    cout<<"***********************TIC TAC TOE***********************"<<endl;
    do
    {
        cout<<"Enter a Name for Player A: "<<endl;
        cin>>name1;
        cout<<"Enter a Name for Player B: "<<endl;
        cin>>name2;
        cout<<"Who Plays first, "<<name1<<" or "<<name2<<endl;
        cin>>first;
        while(first!=name2&&first!=name1)
        {
            cout<<first<<" is not a registered player"<<endl;
            cout<<"Who Plays first, "<<name1<<" or "<<name2<<endl;
            cin>>first;
        }
        if(first==name1)
            second=name2;
        else
            second=name1;
        int i,j;
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                    cout<<"- ";
            }
            cout<<"\n";
        }
        TicTacToe game(first,second);
        do
        {
            if(turn%2==1)
                chance=first;
            else
                chance=second;
            Check=game.input(chance);
            while(Check!=1)
            {
                cout<<"Entered space is already occupied."<<endl;
                Check=game.input(chance);
            }
            if(turn>=5)
            {
                char move;
                if(turn%2==1)
                    move='X';
                else
                    move='O';
                int result=game.check(move);
                if(result==1)
                {
                    flag=1;
                    if(turn%2==1)
                        winner=first;
                    else
                        winner=second;
                    break;
                }
            }
            turn++;
        }
        while(turn<=9);
        cout<<"Game is over: "<<endl;
        if(flag==1)
        {
            cout<<winner<<" wins!! Congratulations"<<endl;
        }
        else
        {
            cout<<"It is a tie!!"<<endl;
        }
        cout<<"Would you like to play again? (Y/N)"<<endl;
        cin>>choice;
        while(choice!="Y"&&choice!="y"&&choice!="N"&&choice!="n")
        {
            cout<<choice<<" is not a valid option"<<endl;
            cout<<"Would you like to play again? (Y/N)"<<endl;
            cin>>choice;
        }
        if(choice=="N"||choice=="n")
            cout<<"Good Bye! Have a nice Day :)"<<endl;
    }
    while(choice=="Y"||choice=="y");
    return 0;
}
