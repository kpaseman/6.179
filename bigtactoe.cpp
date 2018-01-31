//
//  final_proj.cpp
//  6.179
//
//

#include <iostream>
#include <map>
#include <set>
using namespace std;

char square[10][10] = {{'o','1','2','3','4','5','6','7','8','9'},{'o','1','2','3','4','5','6','7','8','9'},{'o','1','2','3','4','5','6','7','8','9'},{'o','1','2','3','4','5','6','7','8','9'},{'o','1','2','3','4','5','6','7','8','9'},
    {'o','1','2','3','4','5','6','7','8','9'},{'o','1','2','3','4','5','6','7','8','9'},{'o','1','2','3','4','5','6','7','8','9'},{'o','1','2','3','4','5','6','7','8','9'},{'o','1','2','3','4','5','6','7','8','9'}};


char games[10] = {'o','1','2','3','4','5','6','7','8','9'};
map<int, char> player_type;
map<int, int> switcher; 

/*********************************************
 
    FUNCTION TO RETURN GAME STATUS
    1 FOR GAME IS OVER WITH RESULT
    -1 FOR GAME IS IN PROGRESS
    O GAME IS OVER AND NO RESULT
 **********************************************/
int checkwin(int x)
{
    if (x < 1|| x > 9)
    {
        cout << "Invalid game location" << endl;
        return -1;
        
    }
    else
    {
        if (square[x][1] == square[x][2] && square[x][2] == square[x][3])
            
            return 1;
        else if (square[x][4] == square[x][5] && square[x][5] == square[x][6])
            
            return 1;
        else if (square[x][7] == square[x][8] && square[x][8] == square[x][9])
            
            return 1;
        else if (square[x][1] == square[x][4] && square[x][4] == square[x][7])
            
            return 1;
        else if (square[x][2] == square[x][5] && square[x][5] == square[x][8])
            
            return 1;
        else if (square[x][3] == square[x][6] && square[x][6] == square[x][9])
            
            return 1;
        else if (square[x][1] == square[x][5] && square[x][5] == square[x][9])
            
            return 1;
        else if (square[x][3] == square[x][5] && square[x][5] == square[x][7])
            
            return 1;
        else if (square[x][1] != '1' && square[x][2] != '2' && square[x][3] != '3'
                 && square[x][4] != '4' && square[x][5] != '5' && square[x][6] != '6'
                 && square[x][7] != '7' && square[x][8] != '8' && square[x][9] != '9')
            
            return 0;
        else
            return -1;
    }

}

int check_whole()
{
    
        if (games[1] == games[2] && games[2] == games[3] && games[1] != '-')
            
            return 1;
        else if (games[4] == games[5] && games[5] == games[6] && games[1] != '-')
            
            return 1;
        else if (games[7] == games[8] && games[8] == games[9] && games[1] != '-')
            
            return 1;
        else if (games[1] == games[4] && games[4] == games[7] && games[1] != '-')
            
            return 1;
        else if (games[2] == games[5] && games[5] == games[8] && games[1] != '-')
            
            return 1;
        else if (games[3] == games[6] && games[6] == games[9] && games[1] != '-')
            
            return 1;
        else if (games[1] == games[5] && games[5] == games[9] && games[1] != '-')
            
            return 1;
        else if (games[3] == games[5] && games[5] == games[7] && games[1] != '-')
            
            return 1;
        else if (games[1] != '1' && games[2] != '2' && games[3] != '3'
                 && games[4] != '4' && games[5] != '5' && games[6] != '6'
                 && games[7] != '7' && games[8] != '8' && games[9] != '9')
            
            return 0;
        else
            return -1;
    

}



/*******************************************************************
 FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
 ********************************************************************/


void board()
{
    cout << "\n\n\tTic Tac Toe\n\n";
    
    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << endl;
    cout << "     |     |      \033[1;31m|\033[0m    |     |      \033[1;31m|\033[0m    |     |     " << endl;
    cout << "  " << square[1][1] << "  |  " << square[1][2] << "  |  " << square[1][3] << "   \033[1;31m|\033[0m "<<square[2][1]<<"  |  "<<square[2][2]<<"  |  "<<square[2][3]<<"   \033[1;31m|\033[0m "<<square[3][1]<<"  |  "<<square[3][2]<<"  |  "<<square[3][3]<< endl;
    
    cout << "_____|_____|______\033[1;31m|\033[0m____|_____|______\033[1;31m|\033[0m____|_____|_____" << endl;
    cout << "     |     |      \033[1;31m|\033[0m    |     |      \033[1;31m|\033[0m    |     |     " << endl;
    
    cout << "  " << square[1][4] << "  |  " << square[1][5] << "  |  " << square[1][6] << "   \033[1;31m|\033[0m "<<square[2][4]<<"  |  "<<square[2][5]<<"  |  "<<square[2][6]<<"   \033[1;31m|\033[0m "<<square[3][4]<<"  |  "<<square[3][5]<<"  |  "<<square[3][6]<< endl;
    
    cout << "_____|_____|______\033[1;31m|\033[0m____|_____|______\033[1;31m|\033[0m____|___________" << endl;
    cout << "     |     |      \033[1;31m|\033[0m    |     |      \033[1;31m|\033[0m    |     |     " << endl;
    
    cout << "  " << square[1][7] << "  |  " << square[1][8] << "  |  " << square[1][9] << "   \033[1;31m|\033[0m "<<square[2][7]<<"  |  "<<square[2][8]<<"  |  "<<square[2][9]<<"   \033[1;31m|\033[0m "<<square[3][7]<<"  |  "<<square[3][8]<<"  |  "<<square[3][9]<< endl;
    
    cout << "     |     |      \033[1;31m|\033[0m    |     |      \033[1;31m|\033[0m    |     |     " << endl;
    cout<<"\033[1;31m_____________________________________________________\033[0m"<<endl<<endl;
    cout << "     |     |      \033[1;31m|\033[0m    |     |      \033[1;31m|\033[0m    |     |     " << endl;
    cout << "  " << square[4][1] << "  |  " << square[4][2] << "  |  " << square[4][3] << "   \033[1;31m|\033[0m "<<square[5][1]<<"  |  "<<square[5][2]<<"  |  "<<square[5][3]<<"   \033[1;31m|\033[0m "<<square[6][1]<<"  |  "<<square[6][2]<<"  |  "<<square[6][3]<< endl;
    
    cout << "_____|_____|______\033[1;31m|\033[0m____|_____|______\033[1;31m|\033[0m____|_____|_____" << endl;
    cout << "     |     |      \033[1;31m|\033[0m    |     |      \033[1;31m|\033[0m    |     |     " << endl;
    
    cout << "  " << square[4][4] << "  |  " << square[4][5] << "  |  " << square[4][6] << "   \033[1;31m|\033[0m "<<square[5][4]<<"  |  "<<square[5][5]<<"  |  "<<square[5][6]<<"   \033[1;31m|\033[0m "<<square[6][4]<<"  |  "<<square[6][5]<<"  |  "<<square[6][6]<< endl;
    
    cout << "_____|_____|______\033[1;31m|\033[0m____|_____|______\033[1;31m|\033[0m____|___________" << endl;
    cout << "     |     |      \033[1;31m|\033[0m    |     |      \033[1;31m|\033[0m    |     |     " << endl;
    
    cout << "  " << square[4][7] << "  |  " << square[4][8] << "  |  " << square[4][9] << "   \033[1;31m|\033[0m "<<square[5][7]<<"  |  "<<square[5][8]<<"  |  "<<square[5][9]<<"   \033[1;31m|\033[0m "<<square[6][7]<<"  |  "<<square[6][8]<<"  |  "<<square[6][9]<< endl;
    
    cout << "     |     |      \033[1;31m|\033[0m    |     |      \033[1;31m|\033[0m    |     |     " << endl;
    cout<<"\033[1;31m_____________________________________________________\033[0m"<<endl<<endl;
    cout << "     |     |      \033[1;31m|\033[0m    |     |      \033[1;31m|\033[0m    |     |     " << endl;
    cout << "  " << square[7][1] << "  |  " << square[7][2] << "  |  " << square[7][3] << "   \033[1;31m|\033[0m "<<square[8][1]<<"  |  "<<square[8][2]<<"  |  "<<square[8][3]<<"   \033[1;31m|\033[0m "<<square[9][1]<<"  |  "<<square[9][2]<<"  |  "<<square[9][3]<< endl;
    
    cout << "_____|_____|______\033[1;31m|\033[0m____|_____|______\033[1;31m|\033[0m____|_____|_____" << endl;
    cout << "     |     |      \033[1;31m|\033[0m    |     |      \033[1;31m|\033[0m    |     |     " << endl;
    
    cout << "  " << square[7][4] << "  |  " << square[7][5] << "  |  " << square[7][6] << "   \033[1;31m|\033[0m "<<square[8][4]<<"  |  "<<square[8][5]<<"  |  "<<square[8][6]<<"   \033[1;31m|\033[0m "<<square[9][4]<<"  |  "<<square[9][5]<<"  |  "<<square[9][6]<< endl;
    
    cout << "_____|_____|______\033[1;31m|\033[0m____|_____|______\033[1;31m|\033[0m____|___________" << endl;
    cout << "     |     |      \033[1;31m|\033[0m    |     |      \033[1;31m|\033[0m    |     |     " << endl;
    
    cout << "  " << square[7][7] << "  |  " << square[7][8] << "  |  " << square[7][9] << "   \033[1;31m|\033[0m "<<square[8][7]<<"  |  "<<square[8][8]<<"  |  "<<square[8][9]<<"   \033[1;31m|\033[0m "<<square[9][7]<<"  |  "<<square[9][8]<<"  |  "<<square[9][9]<< endl;
    
    cout << "     |     |      \033[1;31m|\033[0m    |     |      \033[1;31m|\033[0m    |     |     " << endl;
    
}
int main()
{
    int player = 2;
    int i,choice, x;    
    char mark;
    int currentboard= -1;
    player_type[1] = 'X';
    player_type[2] = 'O';
    switcher[1] = 2;
    int preboard;
    switcher[2] = 1; 
    do
    {
        
        board();
        jump:
        bool validMove=false;
        for(int i=1;i<10;i++){
            int temp = games[i] - '0';
            if(currentboard==temp){
                validMove=true;
            }
        }
        if(!validMove)
            currentboard=-1;
        if(currentboard<0){
            cout<<"Enter a board number between 1 and 9: ";
            cin>>currentboard;
        }
        for(int i=1;i<10;i++){
            int temp = games[i] - '0';
            if(currentboard==temp){
                validMove=true;
            }
        }
        if(!validMove){
            cout<<"Invalid board number"<<endl;
            currentboard=-1;
            goto jump;
        }

        player= switcher[player];
        cout << "Player " << player << ", enter a spot number in board " << currentboard << ":"<< endl; 
        cin >> choice;
        mark= player_type[player];
        preboard=currentboard;
        if (choice == 1 && square[currentboard][1] == '1'){
        
            square[currentboard][1] = mark;
            currentboard=choice;
         }
        else if (choice == 2 && square[currentboard][2] == '2'){
        
            square[currentboard][2] = mark;
            currentboard=choice;
        }
        else if (choice == 3 && square[currentboard][3] == '3'){
        
        square[currentboard][3] = mark;
        currentboard=choice;}
        else if (choice == 4 && square[currentboard][4] == '4'){
        
        square[currentboard][4] = mark;currentboard=choice;}
        else if (choice == 5 && square[currentboard][5] == '5'){
        
        square[currentboard][5] = mark;currentboard=choice;}
        else if (choice == 6 && square[currentboard][6] == '6'){
        
        square[currentboard][6] = mark;currentboard=choice;}
        else if (choice == 7 && square[currentboard][7] == '7'){
        
        square[currentboard][7] = mark;currentboard=choice;}
        else if (choice == 8 && square[currentboard][8] == '8'){
        
        square[currentboard][8] = mark;currentboard=choice;}
        else if (choice == 9 && square[currentboard][9] == '9'){
        
        square[currentboard][9] = mark;currentboard=choice;}
        else
        {
            cout<<"Invalid move. Enter a new spot number:";
            player = switcher[player];
            cin.ignore();
            cin.get();
        }
        x = checkwin(preboard);
        if (x == 1)
        {
            games[preboard] = player_type[player];
            for(int i=1;i<10;i++){
                square[preboard][i]=player_type[player];
            }

        }
        else
        {
            if (x == 0)
            {
                games[preboard] = '-';
                for(int i=1;i<10;i++){
                    square[preboard][i]='-';
                }

            }

        }

        i = check_whole();

    }while(i==-1);
    board();
    if(i==1)
    
    cout<<"==>\aPlayer "<<player<<" win ";
    else
    cout<<"==>\aGame draw";
    
    cin.ignore();
    cin.get();
    return 0;
}