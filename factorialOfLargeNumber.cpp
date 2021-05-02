class Solution {
public:
    vector<int> factorial(int N){
        vector<int> result = {1};
        int resSize = 1;
        // using the general formula 5!= 5 * 4 * 3 * 2 * 1
        for (int i = 2; i <= N; i++){
            resSize = multiply(result, i, resSize);
        }
        //reversing the array to get the correct representation
        int i = 0;
        int j = result.size() - 1;
        while (i < j){
            int temp = result[i];
            result[i] = result[j];
            result[j] = temp;
            i++;
            j--;
        }
        return result;
    }
    int multiply(vector<int> & result, int x, int resSize){
        int carry = 0, prod;
        for (int i = 0; i < resSize; i++){
            prod = result[i] * x + carry;
            result[i] = prod % 10; // storing the last digit
            carry = prod / 10; // keeping the rest as carry
        }
        while (carry){
            result.push_back(carry % 10);
            resSize += 1;
            carry = carry / 10; // to avoid float we need int division
        }
        return resSize;
    }
};
