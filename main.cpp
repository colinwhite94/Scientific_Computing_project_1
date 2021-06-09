// Author: Coin White
// Date: May 31, 2018
// Project: Project 1
// Description:
// 1. Creating a function that takes as input parameters D, d, and n and the deployment angle δ
// 2. return the strain energy.
// 3. Using this function, run from δ=0-90o (0-π/2)and plot strain energy curve to visualize the strain energy through the deployment.
// 4. The number of stable positions (where the strain energy is equal to zero) is the major concern.
// 5. If there is an additional point where the curve drops to zero (strain energy is always
// zero at δ=0 due to the assumptions, so one additional to the 0 @δ=0), the proposed dimensions of D, d, and n is considered
// bistable. The way you are to determine this is by evaluating the derivative along the curve.
//
// The code determines bistability and tell the user if it is bistable or not.
//
// This will have to be done numerically
// as the analytical derivative is very hard to determine. Plot a curve of the derivative along the same range of
// deployment angles. You may use C++ or MATLAB or a combination of the two. You should test AT LEAST these three cases:

//note: c++ uses radians
#include <iostream>
#include <cmath>
using namespace std;

double D=0; //outer diameter
double d=0; //inner diameter
double n=0; //number of sides
double b=0; //side length b
double c0 = 0; //length of c when delta is zero
double pihalf =0; //pi divided by 2
double deriv =0; //this stores the derivative of strain energy with respect to delta
double pi = 3.14159265359; //pi
double delta1 = 0; //delta (deployment angle)
double delta2 = 0; //delta (deployment angle increment)
double delta3 = 0; //delta (deployment angle increment)
double c1 = 0; //side length c
double c2 = 0; //side length c increment
double c3 = 0; //side length c increment
double ep1 = 0; //strain
double ep2 = 0; //strain increment
double ep3 = 0; //strain increment
double w1 = 0; //strain energy
double w2 = 0; //strain energy increment
double w3 = 0; //strain energy increment
int i=0;

int main() {

    //ask user for input. Outer diameter, inner diameter, and number of sides
    cout << "Enter D, the outer diameter of the cylinder" << endl;
    cin >> D;
    cout << "Enter d, the inner diameter of the cylinder" << endl;
    cin >> d;
    cout << "Enter n, the number of sides on the cylinder" << endl;
    cin >> n;
    cout << "I will step through the deployment angle δ, and give data for a graph" << endl;

    //getting c0. (C when delta is zero)
    delta1 = 0;
    b = D*sin(acos(d/D)-(pi/n)); //this equation works.
    c0 = sqrt(pow(D*sin(pi/n+asin(b*cos(delta1)/D)),2)+pow(b*sin(delta1),2));
    pihalf = pi/2;

    //this creates increments delta and creats a delta vs. strain energy table
    for (double delta1=0; delta1<pihalf; delta1=delta1+.000001)
    {
        //to obtain a central difference numerical derivative I made this for loop that gets 3 values at a time needed to do a central difference.
        c1 = sqrt(pow(D*sin(pi/n+asin(b*cos(delta1)/D)),2)+pow(b*sin(delta1),2));
        ep1 = (c1-c0)/c0;
        w1 = .5*pow(ep1,2);

        //incrementing delta (the independent variable)
        delta2=delta1+.000001;

        //obtaining the strain energy (the dependant variable)
        c2 = sqrt(pow(D*sin(pi/n+asin(b*cos(delta2)/D)),2)+pow(b*sin(delta2),2));
        ep2 = (c2-c0)/c0;
        w2 = .5*pow(ep2,2);

        //incrementing delta (the independent variable)
        delta3=delta2+.000001;

        //obtaining the strain energy (the dependant variable)
        c3 = sqrt(pow(D*sin(pi/n+asin(b*cos(delta3)/D)),2)+pow(b*sin(delta3),2));
        ep3 = (c3-c0)/c0;
        w3 = .5*pow(ep3,2);


        //Now with three three increments of the independent and dependant variable, I can make a numerical derivative with the central difference.
        deriv = (w3-w1)/(delta3-delta1);

        //this tells me bi stability. Every time the derivative goes below zero, i increases by 1.
        //At the end of the program, if i is greater than one, I know it is at least bi-stable
        if (deriv < 0)
        {
            i++;
        }
        else
        {

        }

        //resenting the 3 points for the next round of derivative finding in the for loop
        c1 = c2; //reindexing time
        c2 = c3; //reindexing time
        w1 = w2; //reindexing altitude
        w2 = w3; //reindexing altitude
        delta1 = delta2; //reindexing altitude
        delta2 = delta3; //reindexing altitude

        //printing the results
        cout << delta2 << "\t" << "\t" <<  w2 << "\t" << "\t" << deriv <<  endl;
    }
    //this tells me if something is bi-stable.
    if (i>=1)
    {
        cout << "this IS bistable";
    }
    else
    {
        cout << "this is NOT bistable";
    }
    return 0;
}
