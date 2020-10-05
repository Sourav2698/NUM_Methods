//Code of Secant and Regula-Flasi written by Sourav Bera

#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

double f(double x){
    double F;
    F = 25.*pow(x, 4) - 0.5*pow(x, 2) - 2.;
    return F;
}

void Secant(double eps, int N, double a, double b){
    int count = 1;
    double Df, y;
    double x0 = a;
    double x1 = b;
    int Flag = 0;
     do {
    y = x1 - (f(x1)*(x1 - x0))/(f(x1) - f(x0));
    Df = abs(y - x1)/abs(x1);
    if(Df < eps || abs(f(y)) < eps){
      cout<<"Root (in Secant Method) after "<<count<<" interations is  : "<<y<<endl;
      Flag = 1;
      break;
    }
    count += 1;
    x0 = x1;
    x1 = y;

 } while(count <= N); 

 if(Flag == 0) cout<<"Error : Root does the converge"<<endl;
}

void Regula_Falsi(double eps, int N, double a, double b){
    int count = 1;
    double Di;
    double Df; 
    double y;
    double x0 = a;
    double x1 = b;
    int Flag = 0;
    do{
        Di = abs(x1 - x0);
        Df = Di;
        y = (x0*f(x1) - x1*f(x0))/(f(x1) - f(x0));
        if(abs(f(y))<eps){
            cout<<"Root (in Regula-Falsi Method) after "<<count<<" iterations is : "<<y<<endl;
            Flag = 1;
            break;
        }
        if(f(x0)*f(y) < 0) {
            x1 = y;
        }
        if(f(x1)*f(y) < 0){
            x0 = y;
        }
        if(f(x0)*f(y) > 0 && f(x1)*f(y) > 0) cout<<"Root is not there within the given interval"<<endl;
        Df = abs(x1 - x0);
    count += 1;

    }while(count<=N && Df<Di);
    if(Flag == 0) cout<<"Error : Root does not converge"<<endl;
}

int main(){
    int N = 200;
    double eps = 1e-05;
    double a = 0.1; //small
    double b = 0.9; //large
    Secant(eps, N, a, b);
    Regula_Falsi(eps, N, a, b);
    return 0;

}