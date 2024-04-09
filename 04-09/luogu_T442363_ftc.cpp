#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;
using ll = long long;
using loc_t = pair<int, int>;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, P; cin >> n >> P;
    vector<loc_t> poses(P);
    for(int p=0; p<P; p++){
        auto& dstPose = poses.at(p);
        cin >> dstPose.first >> dstPose.second;
    }
    vector<ll> dists(P+1, 0);
    for(int p=1; p<=P; p++){// make dists
        auto currentPos = poses.at(p%P);
        auto previousPos = poses.at(p-1);
        if(currentPos.first == previousPos.first){
            dists[p] = dists[p-1] + abs(currentPos.second-previousPos.second);
        } else {
            dists[p] = dists[p-1] + abs(currentPos.first-previousPos.first);
        }
    }
    ll totalDist = dists.back();

    map<int, vector<pair<loc_t, int>>> horizontal, vertical;
    for(int p=0; p<P; p++){
        int nextP = (p+1)%P;
        auto currentPos = poses.at(p);
        auto nextPos = poses.at(nextP);
        if(currentPos.first == nextPos.first){// vertical
            int yMin = min(currentPos.second, nextPos.second);
            int yMax = max(currentPos.second, nextPos.second);
            vertical.insert(pair<int, vector<pair<loc_t, int>>>(currentPos.first, {}));
            vertical[currentPos.first].emplace_back(make_pair(make_pair(yMin, yMax), p));
        } else {// horizontal
            int xMin = min(currentPos.first, nextPos.first);
            int xMax = max(currentPos.first, nextPos.first);
            horizontal.insert(pair<int, vector<pair<loc_t, int>>>(currentPos.second, {}));
            horizontal[currentPos.second].emplace_back(make_pair(make_pair(xMin, xMax), p));
        }
    }
    for(auto & iter : horizontal){
        sort(iter.second.begin(), iter.second.end());
    }
    for(auto & iter : vertical){
        sort(iter.second.begin(), iter.second.end());
    }

    auto findBeaconByPos = [&](const loc_t pos)->int{
        static auto cmp = [](const pair<loc_t,int>& min_max, const int& coordinate)->bool{
            return min_max.first.first <= coordinate;
        };
        static auto searchBiggestLeq = [&](vector<pair<loc_t, int>>::iterator begin, vector<pair<loc_t, int>>::iterator end, int val)
                ->vector<pair<loc_t, int>>::iterator{
            while (begin != end){
                auto mid = begin + (begin - end) / 2;
                if(cmp(*mid, val)){
                    begin = mid + 1;
                } else {
                    end = mid;
                }
            }
            return begin - 1;
        };
        {// find vertical
            auto iter=vertical.find(pos.first);
            if(iter != vertical.end()){
                auto& lines = iter->second;
                int coordinate = pos.second;
                auto dstLine = searchBiggestLeq(lines.begin(), lines.end(), coordinate);
                if(dstLine != lines.end()) {
                    auto &dstRange = dstLine->first;
                    if (coordinate >= dstRange.first && coordinate <= dstRange.second) {
                        return dstLine->second;
                    }
                }
            }
        }
        {// find horizontal
            auto iter=horizontal.find(pos.second);
            if(iter != horizontal.end()){
                auto& lines = iter->second;
                int coordinate = pos.first;
                auto dstLine = searchBiggestLeq(lines.begin(), lines.end(), coordinate);
                if(dstLine != lines.end()) {
                    auto &dstRange = dstLine->first;
                    if (coordinate >= dstRange.first && coordinate <= dstRange.second) {
                        return dstLine->second;
                    }
                }
            }
        }
        throw runtime_error("RE");
    };
    auto findDistByPAndLoc = [&](int p, loc_t pos)->ll{
        auto pPos = poses.at(p);
        if(pPos.first == pos.first){
            return dists.at(p) + abs(pPos.second - pos.second);
        } else{
            return dists.at(p) + abs(pPos.first - pos.first);
        }
    };
    while(n--){
        int sx, sy, tx, ty;
        cin >> sx >> sy >> tx >> ty;
        auto s = make_pair(sx, sy);
        auto t = make_pair(tx, ty);
        int ps = findBeaconByPos(s);
        int pt = findBeaconByPos(t);
        auto ds = findDistByPAndLoc(ps, s);
        auto dt = findDistByPAndLoc(pt, t);
        auto d = abs(ds-dt);
        d = min(d, totalDist-d);
        cout << d << '\n';
    }
    return 0;
}