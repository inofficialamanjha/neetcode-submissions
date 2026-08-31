class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int s = 0;
        int e = m*n - 1;

        while(s<=e) {
            int mid = s + (e-s)/2;
            auto [x, y] = getMatrixIndices(m, n, mid);

            if (matrix[x][y]==target) {
                return true;
            } else if (matrix[x][y] < target) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        return false;
    }

    pair<int, int> getMatrixIndices(int m, int n, int index) {
        int x = index/n;
        int y = index%n;
        return {x, y};
    }
};
