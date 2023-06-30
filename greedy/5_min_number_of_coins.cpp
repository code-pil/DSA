#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    // Write your code here
    int coin=0;
    int coins[] = {1000,500,100,50,20,10,5,2,1};
    for(auto ele : coins){
        coin += amount/ele;
        amount = amount%ele;
    }
    return coin;
}

