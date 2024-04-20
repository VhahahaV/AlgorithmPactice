//
// Created by CZQ on 2024/4/9.
//
#include "bits/stdc++.h"
using namespace std;
double a,b,c,d;

double func(double x){
    return a* pow(x,3)+b* pow(x,2)+c* x+d;
}
double search(double start, double end , double step){
    double prev = func(start);
    for(double i = start + step ; i <= end ; i += step){
        double current = func(i);
        if (current*prev<=0)
            return i-step;
    }
}

int main(){
    cin >> a >> b >> c >> d;
    if (a < 0)
        a*=-1,b*=-1,c*=-1,d*=-1;
//   跟在100~-100
//设置精度
    vector<double> steps = {1,0.01,0.001};
    double f1 = -100,f2,f3;
    for(int i = 0; i < steps.size() ; i++){
        double step = steps[i];
        f1 = search(f1,100,step);
        f2 = search(f1+step,100,step);
        f3 = search(f2+step,100,step);

    }

    cout << fixed << setprecision(2) << f1 <<" "<< f2 <<" "<< f3;


    return 0;
}