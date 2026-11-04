class Solution {
public:
    int cntBit(int a){
        int cnt =0;
        while(a>0){
            if(a%2==1)cnt++;
            a/=2;
        }
        return cnt;
    }
    int calculateScore(int a, int b) {
        if(cntBit(a)>=cntBit(b)){
            return cntBit(a)*cntBit(b);
        }
        else{
            return cntBit(b)/cntBit(a);
        }

    }
};