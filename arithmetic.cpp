//an = a + (n-1)d
class Solution{
public:
    int inSequence(int a, int b, int c){
        // code here
        if (c == 0){
            if (a == b){
                return 1;
                
            }
            else {
                return 0;
            }
            
        }
        else {
            if ((b - a)/c < 0){
                return 0;
            }
            if((b-a) % c == 0) {
                return 1;
            }
            else {
                return 0;
            }
        }
    }
};
