//https://leetcode.com/problems/stone-removal-game/description/?envType=daily-question&envId=2026-11-26

class Solution {
public:
    bool canAliceWin(int n) {
       int k=10;
        bool alice=true;

        while(n>=k){
            n-=k;
            k--;
            alice=!alice;
        }
        return !alice;
    }
};
