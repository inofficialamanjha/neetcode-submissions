class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int high = nums.size() - 1;
        int low = 0;

        quicksort(nums, low, high);

        return nums;
    }

    void quicksort(vector<int>& nums, int low, int high) {
        if (low >= high) {
            return;
        }

        int partition = partitionArray(nums, low, high);

        quicksort(nums, low, partition - 1);
        quicksort(nums, partition + 1, high);
    }

    int partitionArray(vector<int>& nums, int low, int high) {
        int partitionKey = nums[high];

        int currIndex = low - 1;

        for (int i = low; i < high; i++) {
            if (nums[i] < partitionKey) {
                currIndex++;
                swap(nums[currIndex], nums[i]);
            }
        }

        currIndex++;
        swap(nums[currIndex], nums[high]);

        return currIndex;
    }
};