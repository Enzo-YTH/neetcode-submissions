class Solution {
public:
    int getSum(int a, int b) {
        // a =  100
        // b =  111
        // c = 1011
        //xor=  011
        //& =   100
        
        // a =  011
        // b = 1000
        //xor= 1011
        // & = 0
        int ad = a & b;
        int xr = a ^ b;
        if (!ad) return xr; 

        return getSum((a ^ b), (a & b) << 1);
    }
};
