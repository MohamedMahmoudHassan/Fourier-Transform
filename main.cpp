#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+5;
const double pi=acos(-1);

int n;
bool pre_clc[N*N];

struct my_complex{
    double real, img;
}in[N], out[N], omega[N*N];

my_complex complex_addation(my_complex x, my_complex y){
    return {x.real + y.real, x.img + y.img};
}

my_complex complex_multiplication(my_complex x, my_complex y){
    double real = x.real * y.real - x.img * y.img;
    double img = x.real * y.img + x.img * y.real;
    return {real, img};
}

double circular_functions(double angle, int type){
    while(angle >= 360)
        angle -= 360;
    if(type == 1){
        if(angle == 90 || angle == 270)
            return 0;
        else
            return cos(angle * pi / 180);
    }
    if(angle == 180)
        return 0;
    return -sin(angle * pi / 180);
}

my_complex clc_omega(int c){
    c %= n;
    if(pre_clc[c])
        return omega[c];
    pre_clc[c] = 1;

    double angle = 360.0 * c / n;
    return omega[c] = {circular_functions(angle, 1), circular_functions(angle, 0)};
}

void p_real(int i){
    if(!out[i].real)
        return ;
    cout << out[i].real;
}

void p_sign(int i){
    if(!out[i].real || !out[i].img)
        return ;
    cout << (out[i].img >= 0 ? " + " : " - ");
}

void p_img(int i){
    if(!out[i].img)
        return ;
    if(!out[i].real)
        cout << out[i].img;
    else
        cout << abs(out[i].img);
    cout<<'i';
}

void print_omegas(){
    for(int i = 0; i <= n*n; i++){
        if(pre_clc)
            cout << i << ' ' << omega[i].real << ' ' << omega[i].img << endl;
    }
}

int main()
{

    cout << "Enter the number of N-points:\n";
    cin >> n;

    cout<<"Enter the sequence x(n):\n";
    for(int i = 0; i < n; i++)
        cin >> in[i].real;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            my_complex omega = clc_omega(i * j);
            my_complex term = complex_multiplication(omega, in[j]);

            out[i] = complex_addation(out[i], term);
        }
    }

    print_omegas();
    cout << "X[K] = {";
    for(int i = 0; i < n; i++){
        p_real(i);
        p_sign(i);
        p_img(i);
        cout << (i < n-1 ? ", " : "}\n") ;
    }
    return 0;
}
