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
int ballDst(int, int);
int plcTnk();
int getDiff();

//Begin execution here
int main(){

    //Declare variables
    int ang, power, attempt, tnkPos, diff=10;
    float dist;
    bool hit;
    char choice;//Choice for difficulty

    //Display title and story
    cout<<"\n\n Fatal Trajectory \n\n"<<endl;
    cout<<"You're under attack!\nOutside your base is a tank, preparing to destroy your army."<<endl;
    cout<<"There is a thick fog and you won't be able to destroy the tank by sight."<<endl;
    cout<<"Your shotty sonar has determined the tank is within 1000 meters."<<endl;
    cout<<"Input the angle to aim your cannon and the speed to fire the projectile."<<endl;
    cout<<"You'll have to destroy the tank within _ attempts or it will destroy you.\n\n"<<endl;

    //Get the system time
    unsigned seed = time(0);

    //seed random number generator
    srand(seed);

    //place tank
    tnkPos = plcTnk();

    //Prompt for difficulty
    diff =  getDiff();

    do{

        //Prompt user for firing instructions
        input (ang, power);

        //calculate projectile distance
        dist = ballDst(ang, power);

        cout<<"your projectile hit "<<dist<<" meters"<<endl;

        //test if hit or miss
        hit = hitMiss(dist, tnkPos, diff);

        //Display if hit or miss
        if(hit==true){
            cout<<"Target hit!"<<endl;
        }
        if(hit==false){
            cout<<"Target missed :("<<endl;
        }

        //Display if too close or too far
        if(dist<tnkPos-10){
            cout<<"Too close"<<endl;
        }
        else if(dist>tnkPos+10){
            cout<<"Too far"<<endl;
        }

      }while(hit==false);

    cout<<"tank was at "<<tnkPos<<" meters"<<endl;

    //if miss, repeat firing

    //if hit, move tank

    //


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
    while(chc=='e'||chc=='E' || chc=='h'||chc=='H'){
        cout<<"Invalid choice, type E or H"<<endl;
        cin>>chc;
    }

    //initialize difficulty by setting explosive blast radius
    if(chc == 'e'||chc == 'E'){
        cout<<"Easy mode activated!"<<endl;
        cout<<"Cluster bombs enabled"<<endl;
        diff = 20;
    }
    else if(chc == 'h'||chc == 'H'){
        cout<<"Hard mode enabled!"<<endl;
        cout<<"projectile blast radius: 10m"<<endl;
        diff = 10;
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
        cout<<"Input projectile power in meters per second (1-100)"<<endl;
        cin>>p;
        }while(a>90||p>100||a<0||p<0);
}

//Function calculating where projectile hits
int ballDst(int a, int p){

    float d;
    d = ((p*p)*sin(2*(a*(PI/180))))/G;
    return d;
}

//Function testing if projectile hit
bool hitMiss(float dist, int t, char diff){

    if (dist > t-diff && dist < t+diff){
        return true;
    }
    else
        return false;
}

