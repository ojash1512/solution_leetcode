class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()){
            return {};
        }
        vector<int> order;
        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;

        while(top <= bottom && left <= right){
            for(int col = left;col<=right;col++){
                order.push_back(matrix[top][col]);
            }
            top++;
            for(int row = top; row <= bottom;row++){
                order.push_back(matrix[row][right]);
            }
            right--;
            if(top<=bottom){
                for(int col = right;col>=left;col--){
                    order.push_back(matrix[bottom][col]);
                }
                bottom--;
            }
            if(left<=right){
                for(int row = bottom; row>=top;row--){
                    order.push_back(matrix[row][left]);
                }
                left++;
            }
        }
        return order;
    }
};