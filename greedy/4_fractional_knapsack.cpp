#include <bits/stdc++.h> 

bool comp(pair<int,int> a, pair<int,int> b){
    double x = (double)a.second/a.first;
    double y = (double)b.second/b.first;
    if(x<y) return false;
    return true;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(),items.end(),comp);
    double val=0;
    int i=0;
    while(w>0){
        if(w>=items[i].first){
            val+=items[i].second;
            w-=items[i].first;
            i++;
        }
        else {
            val += (double) (w*items[i].second)/items[i].first;
            break;
        }
    }   
    return val;

}
