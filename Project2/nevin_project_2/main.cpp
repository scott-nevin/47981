/*
 *  Scott Nevin
 *  November 21, 2013
 *  Purpose: Ballistic trajectory game
 *  Project 2
 *
 */

//Libraries
#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;

//Global variables and constants
const float G = 9.8;
const float PI = 3.14;

//Function prototypes
void input(int &, int &);
bool hitMiss(float, int, char);
int  ballDst(int, int);
int  plcTnk();
int  getDiff();
void hitDisp(bool, int, int);
int  play(int&, int, int&, int, int&, char&);

//Begin execution here
int main(){

    //Declare variables
    int attempt=1, tnkPos, score=0, diff, ammo=20, att=0;
    float dist;
    bool hit, bonus;
    char choice, b;

    //Display title and story
    cout<<"\n\n Fatal Trajectory \n\n"<<endl;
    cout<<"You're under attack!\nOutside your base, several tanks appear"<<endl;
    cout<<"There is a thick fog and you won't be able to destroy the tank by sight."<<endl;
    cout<<"The tanks will come within 1000 meters."<<endl;
    cout<<"Input the angle to aim your cannon and the speed to fire the projectile."<<endl;
    cout<<"You have 20 shots to destroy as many as you can.\n\n"<<endl;

    //Get the system time
    unsigned seed = time(0);

    //seed random number generator
    srand(seed);

    do{
        //place tank
        tnkPos = plcTnk();

        //Prompt for difficulty
        diff =  getDiff();
        cout<<endl<<endl;
        
        //Loop for tank destruction
        for (int attmpt = 1; attmpt<20; attmpt++){ 
            
            //reset bonus to 0
            b = 0;
            
            //call main gameplay function
            play(tnkPos, diff, score, ammo, att, b);
            ammo--;
            
            //Bonus shot rewarding system
            //increment shots remaining message
            //decrement for loop
            if (b == 1){
                ammo++;
                attempt--;
            }
            
        }
        
        cout<<"score = "<<score<<endl; 
        cout<<"# of hits = "<<score/50<<endl;
        
        cout<<"Play again? type Y to play again"<<endl;
        cin>>choice;
        
    }while(choice=='y'||choice=='Y');

    return 0;
}

//function for selecting difficulty
int getDiff(){

    char chc;
    int diff;

    //Prompt for difficulty
    cout<<"Please select your difficulty"<<endl;
    cout<<"Type e for easy, type h for hard"<<endl;
    cin>>chc;

    //validate input
    while(chc!='e'&&chc!='E' && chc!='h'&&chc!='H'){
        cout<<"Invalid choice, type E or H"<<endl;
        cin>>chc;
        cout<<endl;
    }

    //initialize difficulty by setting explosive blast radius
    if(chc == 'e'||chc == 'E'){
        cout<<"Easy mode activated!"<<endl;
        cout<<"Cluster bombs enabled"<<endl;
        cout<<"Blast radius: 70m"<<endl;
        diff = 70;
    }
    else if(chc == 'h'||chc == 'H'){
        cout<<"Hard mode!"<<endl;
        cout<<"projectile blast radius: 30m"<<endl;
        diff = 30;
    }
    return diff;
}

//Function to place tank
int plcTnk(){

    int x;
    x = 1 + rand() % 999;
    return x;

}

//Function for user firing input
void input(int &a,int &p){
    
        //Prompt the user for inputs
        do{
        cout<<"Input firing angle (0-90)"<<endl;
        cin>>a;
    }while(a>90||a<0);
        do{
        cout<<"Input projectile power in meters per second (1-100)"<<endl;
        cin>>p;
        }while(p>100||p<0);
}

//Function calculating where projectile hits
int ballDst(int a, int p){

    float d;
    
    d = ((p*p)*sin(2*(a*(PI/180))))/G;
    return d;
}

//Function testing if projectile hit
bool hitMiss(float dist, int t, char diff){
    
    //test if projectiles blast radius hit tank
    if (dist > t-diff && dist < t+diff){
        return true;
    }
    else
        return false;
}

//Function for displaying hit information
void hitDisp(bool hit, int d, int t){

    if(hit==true){
        cout<<"Target hit!"<<endl;
        cout<<"Tank was at "<<t<<"m"<<endl;
    }
    if(hit==false){
        cout<<"Target missed..."<<endl;

        //Display if too close or too far
        if(d<t-10){
            cout<<"Shot too close"<<endl;
        }
        else if(d>t+10){
            cout<<"Shot too far"<<endl;
        }
    }
    cout<<endl<<endl;
}

//function for general gameplay
int play(int &tnkPos, int diff, int &score, int ammo, int &att, char &b){

    int ang, power;
    float dist;
    bool hit;
    
    //show how many shots left
    cout<<"Tank is approx. "<<tnkPos<<" meters away."<<endl;
    cout<<"You have "<<ammo<<" shots left."<<endl;

    //Prompt user for firing instructions
    input (ang, power);

    //calculate projectile distance
    dist = ballDst(ang, power);
    cout<<endl<<endl;

    //test if hit or miss
    hit = hitMiss(dist, tnkPos, diff);
    cout<<"your projectile hit "<<dist<<" meters"<<endl<<endl;

    //Display if hit or miss
    hitDisp(hit, dist, tnkPos);
    
    //increment bonus tester
    att++;

    //if hit, move tank, increment score
    if(hit==true){
        
        tnkPos = plcTnk();
        score+=50;
        
        //if tank was destroyed on first try, reward with extra shot
        if(att==1){
            cout<<"Hole in one bonus!"<<endl;
            cout<<"Extra shot rewarded"<<endl<<endl;
            b = 1;
        }
        //reset number of attempts for next tank to 0
        cout<<"Another tank spotted!"<<endl<<endl;
        att=0;
    }
    return score;

}

