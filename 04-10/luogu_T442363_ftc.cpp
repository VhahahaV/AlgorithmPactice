#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;
using ll = long long;
using loc_t = pair<int, int>;

int main(){
    constexpr int MAX_XY = 1000;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, P; cin >> n >> P;
    vector<loc_t> poses(P);
    for(int p=0; p<P; p++){
        auto& dstPose = poses.at(p);
        cin >> dstPose.first >> dstPose.second;
    }
    vector<loc_t> points(2*n);
    vector<map<int, vector<int>>> verticalBucket(MAX_XY+1), horizontalBucket(MAX_XY+1);
    auto addToVerticalBucket = [&verticalBucket](const loc_t& pos, int idx)->void{
        auto x = pos.first;
        auto y = pos.second;
        auto& bucket = verticalBucket.at(x);
        auto insertPos = bucket.find(y);
        if(insertPos == bucket.end()){
            bucket.insert(make_pair(y, vector<int>{idx}));
        } else{
            insertPos->second.emplace_back(idx);
        }
    };
    auto addToHorizontalBucket = [&horizontalBucket](const loc_t& pos, int idx)->void{
        auto x = pos.first;
        auto y = pos.second;
        auto& bucket = horizontalBucket.at(y);
        auto insertPos = bucket.find(x);
        if(insertPos == bucket.end()){
            bucket.insert(make_pair(x, vector<int>{idx}));
        } else{
            insertPos->second.emplace_back(idx);+
        }
    };
    // put points to bucket
    for (int i=0; i<n; i++){
        int sIdx = 2*i, tIdx = 2*i+1;
        loc_t& s = points.at(sIdx);
        loc_t& t = points.at(tIdx);
        cin >> s.first >> s.second >> t.first >> t.second;
        addToVerticalBucket(s, sIdx);
        addToHorizontalBucket(s, sIdx);
        addToVerticalBucket(t, tIdx);
        addToHorizontalBucket(t, tIdx);
    }
    ll prevDist = 0;
    vector<ll> pointDists(2*n);
    for(int p=1; p<=P; p++){// make dists
        auto currentPos = poses.at(p%P);
        auto previousPos = poses.at(p-1);
        if(currentPos.first == previousPos.first){
            // vertical
            int x = currentPos.first;
            int yMin = min(currentPos.second, previousPos.second);
            int yMax = max(currentPos.second, previousPos.second);
            auto& bucket = verticalBucket.at(x);
            for(auto iter=bucket.lower_bound(yMin); iter!=bucket.end()&&iter->first<=yMax; iter++){
                for(auto pointIdx: iter->second){
                    pointDists.at(pointIdx) = prevDist+ abs(points.at(pointIdx).second-previousPos.second);
                }
            }
            prevDist += (yMax-yMin);
        } else {
            // horizontal
            int y = currentPos.second;
            int xMin = min(currentPos.first, previousPos.first);
            int xMax = max(currentPos.first, previousPos.first);
            auto& bucket = horizontalBucket.at(y);
            for(auto iter=bucket.lower_bound(xMin); iter!=bucket.end()&&iter->first<=xMax; iter++) {
                for (auto pointIdx: iter->second) {
                    pointDists.at(pointIdx) = prevDist + abs(points.at(pointIdx).first - previousPos.first);
                }
            }
            prevDist += (xMax-xMin);
        }
    }
    for(int i=0; i<n; i++){
        int sIdx = 2*i, tIdx = 2*i+1;
        auto d = abs(pointDists.at(sIdx)-pointDists.at(tIdx));
        d = min(d, prevDist-d);
        cout << d << '\n';
    }
    return 0;
}