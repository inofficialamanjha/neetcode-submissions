class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> visited;

        // n is not visited
        while(visited.count(n)==0) {
            int s = sumDigitSquare(n);
            // cout<<n<<" "<<s<<endl;
            if (s==1) {
                return true;
            } else {
                visited.insert(n);
                n = s;
            }
        }

        return false;
    }

    int sumDigitSquare(int n) {
        int sum = 0;
        while(n!=0) {
            sum += (n%10)*(n%10);
            n = n/10;
        }
        return sum; 
    }
};
