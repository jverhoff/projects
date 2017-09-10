//John Verhoff
//TicTacToe

#include <iostream>
#include <math.h>
#include <string>

using namespace std;

char p = 'x';   //sets up a global variable to determine who's turn it is
string location;

class tictactoe{    //class for the actual game's 3x3 grid, initializes values and sets up functions

    char grid[3][3] = {

        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'},
    };

public:
    void board();
    void input(char location);
    void turns(char player);
    void taken();
    void option(char a);
    void lengthcheck();
    bool xwin();
    bool owin();

    void replay();
};

void tictactoe::board(){        //this function just goes through and displays the current game board

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

void tictactoe::input(char location){    //takes the input from a user and places their piece at the specified location
    int locdig = location-48;
    switch(locdig){
    case 1:
        if(isalpha(grid[0][0])){
            taken();
        }
        else{
            grid[0][0] = p;
        }                   //cases 1-9 are set so they are same as initialized grid
        break;              //makes it easy to enter where you want your piece to go

    case 2:

        if(isalpha(grid[0][1])){
            taken();
        }
        else{
            grid[0][1] = p;
        }
        break;

    case 3:

        if(isalpha(grid[0][2])){
            taken();
        }
        else{
            grid[0][2] = p;
        }
        break;

    case 4:

        if(isalpha(grid[1][0])){
            taken();
        }
        else{
            grid[1][0] = p;
        }
        break;

    case 5:

        if(isalpha(grid[1][1])){
            taken();
        }
        else{
            grid[1][1] = p;
        }
        break;

    case 6:

        if(isalpha(grid[1][2])){
            taken();
        }
        else{
            grid[1][2] = p;
        }
        break;

    case 7:

        if(isalpha(grid[2][0])){
            taken();
        }
        else{
            grid[2][0] = p;
        }
        break;

    case 8:

        if(isalpha(grid[2][1])){
            taken();
        }
        else{
            grid[2][1] = p;
        }
        break;

    case 9:

        if(isalpha(grid[2][2])){
            taken();
        }
        else{
            grid[2][2] = p;
        }
        break;

    }
}
void tictactoe::turns(char player){     //changes current player to alternate turns
    //sets the global variable to other player
    if (player == 'x')
        p = 'o';
    else if(player == 'o')
        p = 'x';
}

void tictactoe::taken(){               //run if location is full, let's the re-enter a location
    string wrongturn;      //variable for a new value
    cout<<endl<<"Error, location taken"<<endl<<endl;    //tells them it's taken
    board();        //displays board again
    cout<<endl<<"Choose again: ";
    cin>>wrongturn;         //lets them choose another location
    option(wrongturn[0]);
    input(wrongturn[0]);       //runs input function with the new location
}

void tictactoe::option(char a){
    int value = a-48;
    string newlocation;        //variable for a new value
    if(value>=10 || value<=0){
        cout<<endl;
        board();
        cout<<endl<<"Input invalid\nMust be from 1-9: ";
        cin>>newlocation;
        location = newlocation;
        lengthcheck();
        option(location[0]);
        input(location[0]);
    }
}

void tictactoe::lengthcheck(){//checks the length of the location and takes a smaller one if its is beyond one char
    if(location.length()>1){
        cout<<"\nWARNING: Program only takes first character input"<<endl<<endl;
        cout<<"Enter one character from 1-9: ";
        cin>>location;
        lengthcheck();
    }
}





bool tictactoe::xwin(){     /*three different types of wins
win 1: two for loops with an if inside - checks horizontal win
win 2: same as win 1, but checks vertical win
win 3: just one if else if group to check for the two diagonal victories
*/

    for(int i = 0; i<3; i++){

        for(int j = 0; j<1;j++){

            if(grid[i][j] == 'x' && grid[i][j+1] == 'x' && grid[i][j+2] == 'x'){
                return true;
            }

        }

    }


    for(int i = 0 ; i < 1; i++){

        for(int j = 0; j<3; j++){

            if(grid[i][j] == 'x' && grid[i+1][j] == 'x' && grid[i+2][j] == 'x'){
                return true;
            }

        }
    }
    if(grid[0][0] == 'x' && grid[1][1] == 'x' && grid[2][2] == 'x'){
        return true;
    }
    else if(grid[0][2] == 'x' && grid[1][1] == 'x' && grid[2][0] == 'x'){
        return true;
    }

    return false;

}
bool tictactoe::owin(){
    // exactly the same as xwin, but changes the check value from 'x' to 'o'

    for(int i = 0; i<3; i++){

        for(int j = 0; j<1;j++){

            if(grid[i][j] == 'o' && grid[i][j+1] == 'o' && grid[i][j+2] == 'o'){
                return true;
            }

        }

    }


    for(int i = 0 ; i < 1; i++){

        for(int j = 0; j<3; j++){

            if(grid[i][j] == 'o' && grid[i+1][j] == 'o' && grid[i+2][j] == 'o'){
                return true;
            }

        }
    }
    if(grid[0][0] == 'o' && grid[1][1] == 'o' && grid[2][2] == 'o'){
        return true;
    }
    else if(grid[0][2] == 'o' && grid[1][1] == 'o' && grid[2][0] == 'o'){
        return true;
    }

    return false;
}



void tictactoe::replay(){

    cout<<"Do you want to play again? (y/n): ";
    char replayop;
    cin>>replayop;
    if(replayop == 'y'){
        tictactoe obj1;             //creates an object for the game: obj1


        int counter = 1;    //creates counter variable to check for a draw

        while(obj1.xwin() == false && obj1.owin()== false && counter <10){
            /*
        while loop to keep running as long as no one wins & counter checks for draw (max of 9 moves)
    */
            cout<<endl;
            obj1.board();   //displays board to start round
            cout << endl << "It is "<< p << "'s turn." << endl; //tells which player's turn it is
            cout <<"\nPlay your move by entering the integer value in the corresponding position: ";
            cin >> location;    //takes input where to place value
            obj1.lengthcheck();

            if(location.length()<2){

            obj1.option(location[0]);
            cout<<endl;

            obj1.input(location[0]);
                                   //sends location to the input function, puts shape on board
            obj1.turns(p);          //changes the turn to other player
            counter++;              //draw counter increments every move
            }

        }

        //while loop ends and these check the outcome of the game

        if(obj1.xwin() == true){ //if xwin is true then x won
            obj1.board();

            cout<<endl<<"Player x is the Winner"<<endl;
        }
        else if(obj1.owin() == true){   //if owin is true then o won
            obj1.board();

            cout<<endl<<"Player o is the Winner"<<endl;
        }
        else if(obj1.xwin() == false && obj1.owin() == false){  //if loop broke and neither won, counter must have reached 9 and kicked out
            //means a draw happened
            obj1.board();

            cout<<endl<<"It was a draw"<<endl;
        }
        cout<<endl;
        obj1.replay();
    }
    else{
        cout<<endl<<"Thank you for playing.\nGoodbye!"<<endl;
    }
}

int main()
{
    tictactoe obj1;             //creates an object for the game: obj1
    cout << "Tic-Tac-Toe Game\n" << endl; //message to start game
    cout << "The objective of Tic-Tac-Toe is to get three of your shapes in a row." << endl;
    cout << "The shapes can in three different orientations: vertically, horizontally, or diagonally\n" << endl;
    cout << "Have fun!" << endl;


    int counter = 1;    //creates counter variable to check for a draw

    while(obj1.xwin() == false && obj1.owin()== false && counter <10){
        /*
    while loop to keep running as long as no one wins & counter checks for draw (max of 9 moves)
*/
        cout<<endl;
        obj1.board();   //displays board to start round
        cout << endl << "It is "<< p << "'s turn." << endl; //tells which player's turn it is
        cout <<"\nPlay your move by entering the integer value in the corresponding position: ";
        cin >> location;    //takes input where to place value
        obj1.lengthcheck();

        if(location.length()<2){

        obj1.option(location[0]);
        cout<<endl;

        obj1.input(location[0]);
                               //sends location to the input function, puts shape on board
        obj1.turns(p);          //changes the turn to other player
        counter++;              //draw counter increments every move
        }

    }

    //while loop ends and these check the outcome of the game

    if(obj1.xwin() == true){ //if xwin is true then x won
        obj1.board();

        cout<<endl<<"Player x is the Winner"<<endl;
    }
    else if(obj1.owin() == true){   //if owin is true then o won
        obj1.board();

        cout<<endl<<"Player o is the Winner"<<endl;
    }
    else if(obj1.xwin() == false && obj1.owin() == false){  //if loop broke and neither won, counter must have reached 9 and kicked out
        //means a draw happened
        obj1.board();

        cout<<endl<<"It was a draw"<<endl;
    }
    cout<<endl;
    obj1.replay();



    return 0;
}
