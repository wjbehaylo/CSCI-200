#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int vector_size = nums.size();

        for (int i= 0; i < vector_size; i++){
            for (int j = 0; j<vector_size;j++){
                if ((j != i) && (nums.at(i)==nums.at(j)) && (abs(i-j) <= k)) {
                    return true;
                }
                if (j == (vector_size-1) && i == (vector_size-1)){
                    return false;
                }
            } 
        }
    return false;}


    };

int main(int argc, char* argv[]){
    Solution m;
    
    bool output = m.containsNearbyDuplicate(argv[],argc);
    if (output) {
        cout<<"true"; 
        return 0;
    }
    cout << "false";
    return 0;
}