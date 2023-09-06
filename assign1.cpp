#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
/******************************************************
** Program: assign1.cpp
** Author: tanish hupare
** Date: 10/9/2022
** Description: This program is acting as a bowling smulation and it supposed to act as a virtual way of bowling. 
** Input: the program takes in user players name and asks the user to input roll as a way to act as a roll. Finally it also asks the player to play again.
** Output: this program outputs the users rolls and the amount of pin hits and does this in a scoreboard format. it has the number of frames and two rolls for each frame, finally it has a running total.
******************************************************/
using namespace std;

/******************************************************
** function player_name(string name)
** description: this function gets player name and stores it into this functions
** Parameters: string name
** Pre-conditions: the string name has to be declared in int main
** Post-conditions: then this function can be passed through reference.
******************************************************/

void player_name(string &name){

    cout << endl;
   cout << "Hey player welcome to the bowling simuliation !! " << endl << endl;
   cout << "Please enter your name: ";
   getline(cin, name);
   cout << endl;

   cout << "Welcome to the game " << name << " !!";
   cout << endl;
   cin.clear();

}

/******************************************************
** function roll_one(string one_roll_one)
** description: this function gets the users input for being able to roll to hit the pin for roll 1.
** Parameters: string one_roll_one
** Pre-conditions: this has to be declared in int main.
** Post-conditions: this function is called and uses the enter information on other functions.
******************************************************/

void roll_one(string &one_roll_one){

    cout << endl;
    cout << "Player click eneter to roll: ";
    getline(cin,one_roll_one);
    cin.clear();
    cout << endl;


}

/******************************************************
** function roll_two(string one_roll_two)
** description: this function gets the users input for being able to roll to hit the pin for roll 2.
** Parameters: string two_roll_two
** Pre-conditions: this has to be declared in int main.
** Post-conditions: this function is called and uses the enter information on other functions.
******************************************************/

void roll_two(string &two_roll_two){

    cout << "Player click enter to roll again: ";
    getline(cin,two_roll_two);
    cin.clear();
    cout  << endl;

}

/******************************************************
** function roll_three(string three_roll_three)
** description: this function gets the users input for being able to roll to hit the pin for roll 3 for the 10th frame.
** Parameters: string three_roll_three
** Pre-conditions: this has to be declared in int main.
** Post-conditions: this function is called and uses the enter information on other functions.
******************************************************/

void roll_three(string three_roll_three){

    cout << "player click enter to roll for the third time: ";
    getline(cin, three_roll_three);
    cin.clear();
    cout << endl;

}

/******************************************************
** function strike_tenth_frame(int pin1[], int pin2[], int pin3[], int index, int &runningtotal, int totalboard[])
** description: this function sets up the 3rd roll when the user gets a strike on 10th frame and after that it acts like a new roll with its own array
** Parameters: int pin1[], int pin2[], int pin3[], int index, int &runningtotal, int totalboard[] 
** Pre-conditions: pin1, pin2 and pin3 array are being intizalied in int main and also the running total and the array for total.
** Post-conditions: this function then is called in the scoreboard and the function that calculates the running total.
******************************************************/


void strike_tenth_frame(int pin1[], int pin2[], int pin3[], int rand_hits, int rand_hits2, int index, int &runningtotal, int totalboard[]);

/******************************************************
** function func_spare(int pin1[], int pin2[], int &pin1_hit, int i)
** description: this functions helps calculate the spare for all the bowls that the player makes
** Parameters: int pin1[], int pin2[], int &pin1_hit, int i 
** Pre-conditions: pin1, pin2 and pin3 array are being intizalied in int main and pin1_hit is being declared in another function while I is an index for the for loop.
** Post-conditions: this function then is called in the scoreboard and role_one_two and also the function that calculates the running total.
******************************************************/

void func_spare(int pin1[], int pin2[], int &pin1_hit, int i){

    if(pin1[i-1] + pin2[i-1] == 10 && pin1[i-1] != 10 && i >= 0){

        pin1_hit = pin1_hit * 2;
        

    }
}

/******************************************************
** function func_strike(int pin1[], int &pin1_hit, int &pin2_hit, int i) 
** description: this functions helps calculate the strike for all the bowls that the player makes
** Parameters: int pin1[], int pin2[], int &pin1_hit, int i 
** Pre-conditions: pin1, pin2 and pin3 array are being intizalied in int main and pin1_hit is being declared in another function while I is an index for the for loop.
** Post-conditions: this function then is called in the scoreboard and role_one_two and also the function that calculates the running total.
******************************************************/

void func_strike(int pin1[], int &pin1_hit, int &pin2_hit, int i){

     if(pin1[i-1] == 10 && i >= 0){
        
        pin1_hit = pin1_hit * 2;
        pin2_hit = pin2_hit * 2;
  
    }

}



/******************************************************
** role_one_two(int pin1[], int pin2[],int pin3[], int index, int &runningtotal, int totalboard[]) 
** description: this functions helps calculate all the pin hits for role one and two for all the bowls that the player makes
** Parameters: int pin1[], int pin2[],int pin3[], int index, int &runningtotal, int totalboard[];
** Pre-conditions: pin1, pin2 and pin3 array are being intizalied in int main and pin1_hit is being declared in another function while I is an index for the for loop.
** Post-conditions: this function then is called in the scoreboard and role_one_two and also the function that calculates the running total.
******************************************************/

int role_one_two(int pin1[], int pin2[],int pin3[], int index, int &runningtotal, int totalboard[]){

    string roll;

        roll_one(roll);    
     
        int rand_hits =  rand() % 11;
        int rand_hits2 = rand() % (11 - rand_hits);
        pin1[index] = rand_hits;
    
        cout << "You knocked down: " << pin1[index] << " For pin 1"<< endl << endl;

        if(rand_hits != 10 || pin1[9] == 10){           

            roll_two(roll);
 
            pin2[index] = rand_hits2;

            cout << "you knocked down: " << pin2[index] << " for Pin 2" << endl << endl;


            if((pin1[9] == 10 || (pin1[9] + pin2[9] == 10 ))){

          

            strike_tenth_frame( pin1, pin2, pin3, rand_hits, rand_hits2,  index, runningtotal, totalboard); 

            }

        }
        
        func_spare(pin1, pin2, rand_hits, index);
        func_strike(pin1, rand_hits, rand_hits2, index);

        runningtotal += rand_hits;
        runningtotal += rand_hits2;

        totalboard[index] = runningtotal;

        
        cout << "Running total: " << runningtotal << endl;
}

/******************************************************
** function strike_tenth_frame(int pin1[], int pin2[], int pin3[], int index, int &runningtotal, int totalboard[])
** description: this function sets up the 3rd roll when the user gets a strike on 10th frame and after that it acts like a new roll with its own array
** Parameters: int pin1[], int pin2[], int pin3[], int index, int &runningtotal, int totalboard[] 
** Pre-conditions: pin1, pin2 and pin3 array are being intizalied in int main and also the running total and the array for total.
** Post-conditions: this function then is called in the scoreboard and the function that calculates the running total and also that stores pin1, pin2, and pin3.
******************************************************/

void strike_tenth_frame(int pin1[], int pin2[], int pin3[],int rand_hits , int rand_hits2 ,int index, int &runningtotal, int totalboard[]){

    string roll;

    roll_three(roll);
        
    int rand_hits3 = rand() % 11;
    pin3[index] = rand_hits3;

    cout << "You knocked down: " << pin3[index] << " for pin 3" << endl << endl;
    runningtotal += rand_hits3;
        
    totalboard[index] =runningtotal;


}

/******************************************************
** function score_board(int pin1[], int pin2[], int pin3[], int index, int runningtotal, int totalboard[], string name)
** description: this function prints out the entire score board and has the all the print bowl and print total in it.
** Parameters: int pin1[], int pin2[], int pin3[], int index, int runningtotal, int totalboard[], string name 
** Pre-conditions: pin1, pin2 and pin3, totalboard[] and string name are being intizalied in int main and also the running total and the array for total.
** Post-conditions: this function then is called in the print_frame.
******************************************************/

void score_board(int pin1[], int pin2[], int pin3[], int index, int runningtotal, int totalboard[], string name);

/******************************************************
** function frame_roll(int pin1[], int pin2[],int pin3[], int &runningtotal, int totalboard[], string name)
** description: this functions is the for loop for the scoreboard so it the most important part of the code.
** Parameters: int pin1[], int pin2[],int pin3[], int &runningtotal, int totalboard[], string name. 
** Pre-conditions: pin1, pin2 and pin3, totalboard[] and string name are being intizalied in int main and also the running total and the array for total.
** Post-conditions: this function then is called in the int main.
******************************************************/

void frame_roll(int pin1[], int pin2[],int pin3[], int &runningtotal, int totalboard[], string name){

    for(int i = 0; i < 10; i++){

        role_one_two(pin1,pin2, pin3, i, runningtotal, totalboard);
        
        cout << "Frame: " << i + 1 << endl;

        score_board(pin1,pin2, pin3, i, runningtotal, totalboard, name);
        
        
        
    }

    cout << endl;

}

/******************************************************
** function print_bowls(int pin1[], int pin2[], int pin3[], int totalboard[])
** description: this functions is all conditions that help print out the right information in the scoreboard.
** Parameters: int pin1[], int pin2[], int pin3[], int totalboard[]. 
** Pre-conditions: pin1, pin2 and pin3, totalboard[] are being intizalied in int main and also the running total and the array for total.
** Post-conditions: this function then is called in the scoreboard function.
******************************************************/

void print_bowls(int pin1[], int pin2[], int pin3[], int totalboard[]){
   
    for(int i = 0; i < 10; i++){


        if(i == 9 && pin1[i] == 10){
            cout << "|X " << " " << pin2[i] << "  " << pin3[i] << "||";
        
        }else if(i == 9 && (pin1[i] + pin2[i] == 10)){
            cout << pin1[i] << " " << " /" << "  " << pin3[i] << "||";
        
        }else if(pin1[i] != 10 && (pin1[i] + pin2[i] == 10)){
        
            cout << "|" << pin1[i] <<  "   /|";

        
        }else if(pin1[i] == 10){
            cout << "|X    |";
         
        } 
        else if(pin1[i] == 0 && pin2[i] == 0){
            cout << "|" << "-   " << "-" << "|";
        
        }else if(pin1[i] == 0){
            cout << "|" << "-   " << pin2[i] << "|";

        }else if(pin2[i] == 0){
            cout << "|" << pin1[i] << "   -" << "|";

        }
        else if((pin1[i] != 10) && (pin2[i] != 10) && (pin1[i] != -1) && (pin2[i] != -1) && (pin1[i] != 0) && (pin2[i] != 0)){
            cout << "|" << pin1[i] << "   " << pin2[i] << "|"; 
        }
    


   }
}

/******************************************************
** function print_totals(int pin1[], int pin2[], int totalboard[])
** description: this functions is all conditions that help print out the right information in the scoreboard for the runnning total.
** Parameters: int pin1[], int pin2[], int totalboard[]
** Pre-conditions: pin1, pin2 and pin3, totalboard[] are being intizalied in int main and also the running total and the array for total.
** Post-conditions: this function then is called in the scoreboard function.
******************************************************/

void print_totals(int pin1[], int pin2[], int totalboard[]){

    for(int i=0; i < 10; i++){

        if(pin1[i] == 10 || (pin1[i] + pin2[i] == 10)){
            cout << "| " << totalboard[i] << "  |"; 

        }else if(totalboard[i] == -1 || pin1[i] == 10 || (pin1[i] + pin2[i] == 10)){
            cout << "|  " << "-" << "  |";    
        }else if(totalboard[i] < 10){
            cout << "|  " << totalboard[i] << "  |"; 

        }else if(totalboard[i] > 99){
            cout << "|" << totalboard[i] << "  |";
        }
        else if( totalboard[i] > 9){
            cout << "|  " << totalboard[i] << " |";
        }
    }
    
}   

/******************************************************
** function score_board(int pin1[], int pin2[], int pin3[], int index, int runningtotal, int totalboard[], string name)
** description: this function prints out the entire score board and has the all the print bowl and print total in it.
** Parameters: int pin1[], int pin2[], int pin3[], int index, int runningtotal, int totalboard[], string name 
** Pre-conditions: pin1, pin2 and pin3, totalboard[] and string name are being intizalied in int main and also the running total and the array for total.
** Post-conditions: this function then is called in the print_frame.
******************************************************/

void score_board(int pin1[], int pin2[], int pin3[], int index, int runnningtotal, int totalboard[], string name){
    

    cout << "|  1  ||  2  ||  3  ||  4  ||  5  ||  6  ||  7  ||  8  ||  9  ||  10   || total |" << endl;
    cout << "-----------------------------------------------------------------------------" << endl;
    
  
    print_bowls(pin1, pin2, pin3, totalboard);

    cout << endl;
    print_totals(pin1, pin2, totalboard);
    cout << "    " <<runnningtotal;
    
    
}

/******************************************************
** void playagain_error(int &type_again)
** description: this functions helps calculate all the pin hits for role one and two for all the bowls that the player makes
** Parameters: int &type_again)
** Pre-conditions: type_again is declared in int main.
** Post-conditions: this functions 
******************************************************/

void playagain_error(int &type_again){

    while( type_again != 0 && type_again != 1){
        cout << "This is the wrong input please type 1(yes) or 0(no): ";
        cin >> type_again;
        cin.clear();
    }

}


int main (){

    int playagain = 0;
    do{  

    
    string name;
   
    int pin1[10];
    int pin2[10];
    int pin3[10];
    int totalboard[10];
    int runningtotal = 0;
    //int playagain = 0;

   srand(time(NULL));
    
    for (int a = 0; a < 11; a++) {
        pin1[a] = -1;
        pin2[a] = -1;
        pin3[a] = -1;
        totalboard[a] = -1;        
    } 
    
    player_name(name);

    frame_roll(pin1, pin2, pin3, runningtotal, totalboard, name);

    cout << "Do you want to play again? type 1 for yes or 0 for no: ";
    cin >> playagain;
    playagain_error(playagain);
    cin.ignore();
    
    }while(playagain == 1);

    cout << "Thank you for playing my game !!" << endl;

    return 0;
}