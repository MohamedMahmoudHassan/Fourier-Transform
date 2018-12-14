#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+5;
const double pi=acos(-1);

int n;

struct my_complex{
    double real, img;
}in[N], out[N];

string sign(int i){
    return out[i].img >= 0 ? " + ":" - ";
}

int main()
{
    cout << "Enter the number of N-points:\n";
    cin >> n;

    cout<<"Enter the sequence x(n):\n";
    for(int i=0; i<n; i++)
        cin >> in[i].real;

    cout << "X[K] = {";
    for(int i=0; i<n; i++)
        cout << out[i].real << sign(i) << out[i].img << (i<n-1 ? ", ":"}\n") ;

    return 0;
}
