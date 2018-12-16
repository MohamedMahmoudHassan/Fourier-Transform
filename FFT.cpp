#include <bits/stdc++.h>
#include "basic functions.h"

using namespace std;

const int N = 1e3+5;

int n;
vector<int> v, seq;

my_complex in[N], out[N];

vector<int> generate_seq(vector<int> v){
    vector<int> tmp1, tmp2, ret;

    if(v.size() == 1){
        ret.push_back(v.back());
        return ret;
    }

    for(int i = 0; i < v.size(); i+=2)
        tmp1.push_back(v[i]);
    ret = generate_seq(tmp1);

    for(int i = 1; i < v.size(); i+=2)
        tmp2.push_back(v[i]);
    tmp1 = generate_seq(tmp2);

    for(int i : tmp1)
        ret.push_back(i);
    return ret;
}

void calculate(int st = 0, int en = n-1){
    int n = en - st + 1;

    if(n == 1){
        out[st] = in[seq[st]];
        return ;
    }
    calculate(st , st + n/2 - 1);
    calculate(st + n/2 , en);

    for(int i = st; i < st + n/2; i++){
        my_complex tmp = out[i], omega = clc_omega(i - st, n);

        out[i + n/2] = complex_multiplication(out[i + n/2], omega);

        out[i] = complex_addation(out[i], out[i + n/2]);

        out[i + n/2] = complex_multiplication(out[i + n/2], {-1,0});
        out[i + n/2] = complex_addation(tmp, out[i + n/2]);
    }
}


int main()
{

    cout << "Enter the number of N-points:\n";
    cin >> n;

    cout<<"Enter the sequence x(n):\n";
    for(int i = 0; i < n; i++){
        cin >> in[i].real;
        v.push_back(i);
    }

    seq = generate_seq(v);
    calculate();

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
