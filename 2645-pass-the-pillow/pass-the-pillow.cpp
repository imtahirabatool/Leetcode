class Solution {
public:
    int passThePillow(int n, int time) {
        int start=1, count=0, dir=1;

        while(count!=time){
            if(start==n){
                dir=-1;
            }else if(start==1){
                dir=1;
            }
            start+=dir;
            count++;
        }
        return start;
    }
}; 