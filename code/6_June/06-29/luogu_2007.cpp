//
// Created by VhahahaV on 2024/6/29.
//
#include <iostream>

#include <vector>

using namespace std;

int main(){
    string ops;
    cin >> ops;
    vector<vector<int>> Mat(6,vector<int>(9));
    auto handleString = [&](string str,int offset,vector<int> &vec){
        for(int i = 0 ; i < 3 ;i++){
            vec[offset+i] = (str[i]-'0');
        }
    };
    for(int i = 0 ; i < 6 ; i++){
        string up,mid,down;
        auto &vec = Mat[i];
        cin >> up >> mid >> down;
        handleString(up,0,vec);
        handleString(mid,3,vec);
        handleString(down,6,vec);
    }
    auto display = [&](){
        for(int i = 0 ; i < 6 ; i++){
//            cout << "mat :" << i << endl;
            for(int k = 0 ; k < 9 ; k+=3){
                cout << Mat[i][k] << Mat[i][k+1] << Mat[i][k+2] << endl;
            }
        }
    };
    auto swapCol = [&](vector<int> &a , vector<int> &b){
        for(int i = 2 ; i < 9 ; i+=3){
            swap(a[i],b[i]);
        }
    };
    auto swapRow = [&](vector<int> &a , vector<int> &b){
        for(int i = 0 ; i < 3 ; i+=1){
            swap(a[i],b[i]);
        }
    };
//    逆时针
    auto Rotation1 = [&](vector<int> &vec){
        vector<int> tmp(9);
        for(int i = 2 ; i < 9 ; i+=3){
            tmp[i/3] = vec[i];
        }
        for(int i = 1 ; i < 9 ; i+=3){
            tmp[i/3+3] = vec[i];
        }
        for(int i = 0 ; i < 9 ; i+=3){
            tmp[i/3+6] = vec[i];
        }
        vec = tmp;
    };
    auto Rotation2 = [&](vector<int> &vec){
        vector<int> tmp(9);
        for(int i = 0 ; i < 3 ; i+=1){
            tmp[2+i*3] = vec[i];
        }
        for(int i = 3 ; i < 6 ; i+=1){
            tmp[1+(i-3)*3] = vec[i];
        }
        for(int i = 6 ; i < 9 ; i+=1){
            tmp[(i-6)*3] = vec[i];
        }
        vec = tmp;
    };
//前、后、左、右、上、下
    auto Operation1 = [&](){
//        0<-5 5<-1 1<-4 4<-0
        auto &vec0 = Mat[0];
        auto &vec1= Mat[1];
        auto &vec4 = Mat[4];
        auto &vec5 = Mat[5];
        swapCol(vec0,vec5);
        swapCol(vec5,vec1);
        swapCol(vec1,vec4);
        Rotation2(Mat[3]);
    };

    auto Operation2 = [&](){
//        0->5 5->1 1->4 4->0
        auto &vec0 = Mat[0];
        auto &vec1= Mat[1];
        auto &vec4 = Mat[4];
        auto &vec5 = Mat[5];
        swapCol(vec5,vec0);
        swapCol(vec0,vec4);
        swapCol(vec4,vec1);
        Rotation1(Mat[3]);

    };
    auto Operation3 = [&](){
//        0->5 5->1 1->4 4->0
        auto &vec0 = Mat[0];
        auto &vec1= Mat[1];
        auto &vec2 = Mat[2];
        auto &vec3 = Mat[3];
        swapRow(vec3,vec0);
        swapRow(vec0,vec2);
        swapRow(vec2,vec1);
        Rotation2(Mat[4]);
    };
    auto Operation4 = [&](){
        auto &vec0 = Mat[0];
        auto &vec1= Mat[1];
        auto &vec2 = Mat[2];
        auto &vec3 = Mat[3];
        swapRow(vec0,vec3);
        swapRow(vec3,vec1);
        swapRow(vec1,vec2);
        Rotation1(Mat[4]);
    };

    for(auto op : ops){
        int i = op-'0';
        switch (i) {
            case 1:
                Operation1();

                break;
            case 2:
                Operation2();
                break;
            case 3:
                Operation3();
                break;
            case 4:
                Operation4();
                break;
        }
    }

    display();


    return 0;
}

