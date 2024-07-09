//
// Created by VhahahaV on 2024/7/7.
//
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void Elimination(vector<double> &a , vector<double> &b , int k){
//    a 消元 b
    auto val = b[k] / a[k];
    for(int i = k ; i < b.size() ; i++){
        b[i] = b[i] - val * a[i];
    }
}

void Normalization(vector<double> &b , int k){
    auto val = b[k];
    for(int i = k ; i < b.size() ; i++){
        b[i] /= val;
    }
}

void display(const vector<vector<double>> &a){
    cout << fixed << setprecision(2);
    for(const auto & i : a){
        cout << i.back() << endl;
    }
}

//void 

int main(){
    int n;
    cin >>n;
    vector<vector<double>> mat(n , vector<double>(n+1));
    for(int i = 0 ; i <  n ; i++)
        for(int j = 0 ; j < n+1 ; j++)
            cin >> mat[i][j];

//    1
    for(int i = 0 ; i <  n ; i++){
        int k = i+1;
        while(mat[i][i] == 0 && k < n){
            swap(mat[i],mat[k]);
            k++;
        }
        if(mat[i][i] == 0){
            cout << "No Solution";
            return 0;
        }
        for(int j = i+1 ; j < n ; j++){
            Elimination(mat[i],mat[j],i);
        }
    }

//    2
    for(int i = n-1; i>=0 ; i--){
        Normalization(mat[i],i);
        for(int j = i-1 ; j>=0 ; j--){
            Elimination(mat[i] , mat[j] , i);
        }
    }

    display(mat);

    return 0;
}