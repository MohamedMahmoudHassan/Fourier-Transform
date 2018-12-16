#include <bits/stdc++.h>
#include "basic functions.h"

using namespace std;

const int N = 1e3+5;

int n;

my_complex in[N], out[N];

int main()
{

    cout << "Enter the number of N-points:\n";
    cin >> n;

    cout<<"Enter the sequence x(n):\n";
    for(int i = 0; i < n; i++)
        cin >> in[i].real;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            my_complex omega = clc_omega(i * j, n);
            my_complex term = complex_multiplication(omega, in[j]);

            out[i] = complex_addation(out[i], term);
        }
    }

    cout << "X[K] = {";
    for(int i = 0; i < n; i++){
        p_real(out[i]);
        p_sign(out[i]);
        p_img(out[i]);
        cout << (i < n-1 ? ", " : "}\n") ;
    }

    cout << "Magnitude of x[k] ( |X[K]| ) = {";
    for(int i = 0; i < n; i++)
        cout << out[i].magnitude() << (i < n-1 ? ", " : "}\n") ;

    cout << "Phase of x[k] = {";
    for(int i = 0; i < n; i++)
        cout << out[i].phase() << (i < n-1 ? ", " : "}\n") ;

    return 0;
}
