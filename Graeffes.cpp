//Code of Graeffe's method for Polynomial Root Finding : written by Sourav Bera(Roll No. - 16053)
//***********************************************************************************************

#include<iostream>
#include<cmath>
using namespace std;


double func(long double a[], int N, long double x){ //forms the func with the co-efficients as input
    long double f = 0;
for(int i = 0; i<=N; i++){
    f += a[i]*pow(x, i);
}
return f;
}


void Graeffes(int MAXIT, double eps, long double a[], int N){
long double b[N+1];     //storing the updated co-efficients 
long double ai[N+1];    //stores the initial co-efficients
for(int i = 0; i<=N; i++) ai[i] = a[i]; //storing the initial co-efficients

int m = 0;  //Number of iterations counter
int j = 0;  
long double sum = 0.;
do{
    b[0] = a[0]*a[0];
    b[N] = a[N]*a[N];
    for(int k = 1; k<N; k++){
        j = 1;
        sum = 0;
        do{
            sum += pow(-1, j)*2.*a[k-j]*a[k+j];
            j += 1;
        }while(k-j >= 0 && k-j <= N && j+k >= 0 && j+k <= N);
        b[k] = a[k]*a[k] + sum;
    }

    for(int k = 0; k<= N; k++){
        a[k] = b[k];    //updating the co-efficients for next iteration
    } 
    m += 1;

}while(m < MAXIT);


for(int i = 1; i<=N; i++){

    long double root = pow(abs(b[N-i]/b[N-i+1]), 1./pow(2, MAXIT));
    if(abs(func(ai, N, root)) > eps && abs(func(ai, N, -root)) > eps) 
        cout<<"Root no. "<<i<<" is complex with modulus : "<<root<<endl;
    else{
    if(abs(func(ai, N, root)) > eps) root = -root ; 
    cout<<"Root no. "<<i<<" is  : "<<root<<endl;
    }

    
}

}


int main(){
int MAXIT = 11;         //Max no. of iterations
double eps = 1e-04;     //Tolerance value
int N = 4;              //Degree of polynomial
long double a[] = {25., 30., 34., 30., 9.};         //co-efficients : a0 + a1*x + a2*x^{2}... + an*x^{n} //assignment func
//long double a[] = {24., -50., 35., -10., 1.};     //co-efficients of test func with roots (-1, 2, 3, -4)

Graeffes(MAXIT, eps, a, N);
return 0;

}