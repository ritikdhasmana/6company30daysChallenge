class Solution {
public:
    bool winnerOfGame(string colors) {
        int cnta=0,cntb=0,ta=0,tb=0;
        for(int i=0;i<colors.size();i++){
            if(colors[i]=='A'){
                cntb += max(0,tb-2);
                tb=0;
                ta++;
            }else{
                cnta += max(0,ta-2);
                ta=0;
                tb++;
            }
        }
        cnta += max(0,ta-2);
        cntb += max(0,tb-2);
         // cout<<cnta<<" "<<cntb<<endl;
        return cnta>cntb;
    }
};