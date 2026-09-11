class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        bool firstRowZero = false;
        bool firstColumnZero = false;

        // Check if the first row is zero
        for(int j=0; j<n; j++) {
            if (matrix[0][j]==0) {
                firstRowZero = true;
                break;
            }
        }

        // Check if the first column is zero
        for(int i=0; i<m; i++) {
            if (matrix[i][0]==0) {
                firstColumnZero = true;
                break;
            }
        }

        // Use those first row and first columns as markers for the inner matrix
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                if (matrix[i][j]==0) {
                    matrix[0][j] = 0; // Row marker
                    matrix[i][0] = 0; // Column marker
                }
            }
        }

        // Using the markers convert the inner matrix to zero
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                if (matrix[0][j]==0 || matrix[i][0]==0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Now finally settle the first rows and columns
        if (firstRowZero) {
            for(int j=0; j<n; j++) {
            matrix[0][j]=0;
        }
        }

        // Check if the first column is zero
        if (firstColumnZero) {
for(int i=0; i<m; i++) {
            matrix[i][0]=0;
                
        }
        }
        
    }
};
