class Solution {
public:

    vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int upperBound = 0;
        int lowerBound = m - 1;
        int leftBound = 0;
        int rightBound = n - 1;

        int i = 0;
        int j = 0;

        vector<int> spiral;
        int currentDirection = 0;

        while (upperBound <= lowerBound && leftBound <= rightBound) {

            spiral.push_back(matrix[i][j]);

            int next_i = i + directions[currentDirection][0];
            int next_j = j + directions[currentDirection][1];

            if (next_i < upperBound || next_i > lowerBound ||
                next_j < leftBound || next_j > rightBound) {

                // We are about to cross a boundary
                if (currentDirection == 0) {
                    upperBound++;
                }
                else if (currentDirection == 1) {
                    rightBound--;
                }
                else if (currentDirection == 2) {
                    lowerBound--;
                }
                else {
                    leftBound++;
                }

                currentDirection = (currentDirection + 1) % 4;

                next_i = i + directions[currentDirection][0];
                next_j = j + directions[currentDirection][1];
            }

            i = next_i;
            j = next_j;
        }

        return spiral;
    }
};