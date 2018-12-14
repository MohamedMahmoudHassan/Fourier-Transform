#include <bits/stdc++.h>

using namespace std;

const double pi=acos(-1);

struct my_complex{
    double real, img;

    double magnitude(){
        double v = real * real + img * img;
        return sqrt(v);
    }

    double phase(){
        if(!real)
            return 90;

        if(!img)
            return 0;

        return atan(img / real) * 180 / pi;
    }
};

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

my_complex clc_omega(int c, bool pre_clc[], my_complex omega[], int n){

    c %= n;
    if(pre_clc[c])
        return omega[c];

    pre_clc[c] = 1;

    double angle = 360.0 * c / n;
    return omega[c] = {circular_functions(angle, 1), circular_functions(angle, 0)};
}

void p_real(my_complex x){
    if(!x.real)
        return ;
    cout << x.real;
}

void p_sign(my_complex x){
    if(!x.real || !x.img)
        return ;
    cout << (x.img >= 0 ? " + " : " - ");
}

void p_img(my_complex x){
    if(!x.img)
        return ;
    if(!x.real)
        cout << x.img;
    else
        cout << abs(x.img);
    cout<<'j';
}

