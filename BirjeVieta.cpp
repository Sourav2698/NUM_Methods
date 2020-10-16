//Code of Birje-Vieta method for Polynomial Root Finding : written by Sourav Bera(Roll No. - 16053)
//*************************************************************************************************

#include<iostream>
#include<cmath>
using namespace std;

void BirjeVieta(int MAXIT, double eps, double x, double a[], int N){
    int j = 1;          //root Counter
    int M;
    int n = N;          //initialising polynomial degree counter
    double y;
    double b[n+1], c[n+1];
    double d = a[0];
    for(int i = 0; i<=n; i++) { //normalising the co-efficients to make the leading co-efficient 1 
        a[i] = a[i]/d;
    }

    do{
        M = 0;          //Newton-Raphson counter 
        n = N + 1 - j;  //current degree of polynomial
        do{
            b[0] = 1.;
            c[0] = 1.;
            for(int i = 1; i <= n; i++){
                b[i] = a[i] + x*b[i-1];
                c[i] = b[i] + x*c[i-1];
            }

            y = x - b[n]/c[n-1];

            if(abs(y - x) < eps){
                cout<<"Root no. - "<<j<<" after "<<M<<" iterations is "<<y<<endl;
                j += 1;
                for(int i = 1; i <= n - 1; i++) a[i] = b[i];    //updating the co-efficients for next iteration step
                break;
            }
        M = M + 1;
        x = y;
        if(M > MAXIT){  //exit condition when possibility of root-finding is exhausted
            cout<<"No more roots found: Maximum iterations reached !"<<endl;
            j += 1;
            exit(1);
        }
    
        }while(M <= MAXIT);
        x = y;

    }while(j < N);
    cout<<"Root no. - "<<j<<" is "<<(-a[1])<<endl;
}




int main(){
int MAXIT = 200;           //Maximum iterations
double eps = 1e-08;        //Tolerance
double x0 = 1.2;           //Initial guess value
int n = 4;
//double a[] = {1., 0., -15., 10., 24.};     //test func with roots (-1, 2, 3, -4)
double a[] = {9., 30., 34., 30., 25};        //a0*x^{n} + a1*x^{n-1} + ... + a1*x + a0 // assignment func

BirjeVieta(MAXIT, eps, x0, a, n);
return 0;
}