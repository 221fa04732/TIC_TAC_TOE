#include<bits/stdc++.h>
using namespace std;

char button;

void instructionList()
{
    cout<<"\t------------------------------------------------\n";
    cout<<"\t|                                              |\n";
    cout<<"\t|           Your Move -> 'X'(Cross)            |\n";
    cout<<"\t|          Computer Move -> '0'(Zero)          |\n";
    cout<<"\t|                                              |\n";
    cout<<"\t|  - Tic-Tac-Toe is played on a 3x3 grid.      |\n";
    cout<<"\t|  - Two players take turns marking a cell     |\n";
    cout<<"\t|    in the grid with either 'X' or 'O'.       |\n";
    cout<<"\t|  - The player who succeeds in placing        |\n";
    cout<<"\t|    three of their marks in a horizontal,     |\n";
    cout<<"\t|    vertical, or diagonal row wins.           |\n";
    cout<<"\t|  - If all 9 cells are filled without any     |\n"; 
    cout<<"\t|    player winning, the game ends in a draw.  |\n";
    cout<<"\t|                                              |\n";
    cout<<"\t------------------------------------------------\n";
}

void startQuit()
{
    cout<<"\t- S --> Start\n";
    cout<<"\t- I --> Instruction\n";
    cout<<"\t- Q --> Quit\n";
    cout<<"\tChoose any one of the above option : ";
    cin>>button;
    while(button!='Q' && button!='S')
    {
        if(button=='I')
        {
            instructionList();
        }
        else 
        {
            cout<<"\n\t\t--  Enter a valid input  --\n";
        }
        cout<<"\t- S --> Start\n";
        cout<<"\t- I --> Instruction\n";
        cout<<"\t- Q --> Quit\n";
        cout<<"\tChoose any one of the given option : ";
        cin>>button;
    }
    return;
}

void resumeQuit()
{
    cout<<"\t- R --> Resume\n";
    cout<<"\t- I --> Instruction\n";
    cout<<"\t- Q --> Quit\n";
    cout<<"\tChoose any one of the given option : ";
    cin>>button;
    while(button!='Q' && button!='R')
    {
        if(button=='I')
        {
            instructionList();
        }
        else 
        {
            cout<<"\n\t\t--  Enter a valid input  --\n";
        }
        cout<<"\t- R --> Resume\n";
        cout<<"\t- I --> Instruction\n";
        cout<<"\t- Q --> Quit\n";
        cout<<"\tChoose any one of the given option : ";
        cin>>button;
    }
    return;
}

bool checkWinner(vector<vector<char>>&grid, char winner)
{
    for(int i=0;i<3;i++)
    {
        if((grid[i][0]==winner && grid[i][1]==winner && grid[i][2]==winner) || (grid[0][i]==winner && grid[1][i]==winner && grid[2][i]==winner))
        {
            return 1;
        }
    }
    return 0;
}

bool computerTurn(vector<vector<char>>&grid, vector<vector<int>>&gridDefination)
{
    int randomIndex=rand()%gridDefination.size();
    int x=gridDefination[randomIndex][0];
    int y=gridDefination[randomIndex][1];
    cout<<"\n\tComputer Turn => Choose ( "<<x<<" , "<<y<<" )\n";
    grid[x][y]='0';
    gridDefination.erase(gridDefination.begin()+randomIndex);
    return checkWinner(grid,'0');
}

bool yourTurn(vector<vector<char>>&grid, vector<vector<int>>&gridDefination)
{
    cout<<"\tChoose any one grid cell : {";
    for(int i=0;i<gridDefination.size();i++)
    {
        cout<<" ("<<gridDefination[i][0]<<", "<<gridDefination[i][1]<<")";
    }
    cout<<"}\n\tYour Turn => ";
    int x,y,validCell=1;
    cin>>x>>y;
    while(validCell)
    {
        for(int i=0;i<gridDefination.size();i++)
        {
            if(gridDefination[i][0]==x && gridDefination[i][1]==y)
            {
                validCell=0;
                gridDefination.erase(gridDefination.begin()+i);
            }
        }
        if(validCell==1)
        {
            cout<<"\n\t\t--  Invalid grid cell  --\n";
            cout<<"\tChoose any one grid cell : {";
            for(int i=0;i<gridDefination.size();i++)
            {
                cout<<" ("<<gridDefination[i][0]<<", "<<gridDefination[i][1]<<")";
            }
            cout<<"}\n\tYour Turn => ";
            cin>>x>>y;
        }
    }
    grid[x][y]='X';
    return checkWinner(grid,'X');
}

int takeStep(vector<vector<char>>&grid, vector<vector<int>>&gridDefination)
{
    while(gridDefination.size()!=0)
    {
        if(gridDefination.size()!=0 && computerTurn(grid,gridDefination))
        {
            return 2;
        }
        if(gridDefination.size()!=0 && yourTurn(grid,gridDefination))
        {
            return 1;
        }
    }
    return 0;
}

void printGrid(vector<vector<char>>grid)
{
    cout<<"\n";
    for(int i=0;i<3;i++)
    {
        cout<<"\t";
        for(int j=0;j<3;j++)
        {
            cout<<grid[i][j]<<"  ";
        }
        cout<<"\n";
    }
}

int main()
{
    cout<<"\n\t----------------------\n";
    cout<<"\t|  TIC TAC TOE GAME  |";
    cout<<"\n\t----------------------\n\n";

    startQuit();
    while(button=='S' || button=='R')
    {
        vector<vector<char>>grid(3,vector<char>(3,'.'));
        vector<vector<int>>gridDefination={{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2}};
        int result=takeStep(grid,gridDefination);
        printGrid(grid);
        cout<<"\n\t------------------\n";
        if(result==0)
        {
            cout<<"\t|      Draw      |\n";
        }
        else if(result==1)
        {
            cout<<"\t|     You Win    |\n";
        }
        else 
        {
            cout<<"\t|  Computer Win  |\n";
        }
        cout<<"\t------------------\n";
        resumeQuit();
    }
    cout<<"\n\t-----------------------------------------------\n";
    cout<<"\t|  HOPE YOU HAVE A LOT OF FUN WITH THIS GAME  |\n";
    cout<<"\t|               -- THANK YOU --               |\n";
    cout<<"\t-----------------------------------------------\n\n\n";
}