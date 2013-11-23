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
bool hitMiss(float, int);
int ballDst(int, int);
int plcTnk();

//Begin execution here
int main(){

    //Declare variables
    int ang, power, attempt, tnkPos;
    float dist;
    bool hit;

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

    do{

        //Prompt user for firing instructions
        input (ang, power);

        //calculate projectile distance
        dist = ballDst(ang, power);

        cout<<"your projectile hit "<<dist<<" meters"<<endl;

        //test if hit or miss
        hit = hitMiss(dist, tnkPos);

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

int plcTnk(){

    int x;
    x = 1 + rand() % 999;
    return x;

}

void input(int &a,int &p){
        //Prompt the user for inputs
        do{
        cout<<"Input firing angle (0-90)"<<endl;
        cin>>a;
        cout<<"Input projectile power in meters per second (1-100)"<<endl;
        cin>>p;
        }while(a>90||p>100||a<0||p<0);

}

int ballDst(int a, int p){

    float d;
    d = ((p*p)*sin(2*(a*(PI/180))))/G;
    return d;
}

bool hitMiss(float d, int t){

    if (d < t-10||d > t+10){
        return false;
    }
    else if (d > t-10||d < t+10){
        return true;
    }
}
