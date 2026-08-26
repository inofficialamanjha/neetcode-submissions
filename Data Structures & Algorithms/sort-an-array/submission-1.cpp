class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

private:
    void quickSort(vector<int>& nums, int low, int high) {
        if (low >= high)
            return;

        int pivot = partition(nums, low, high);

        quickSort(nums, low, pivot - 1);
        quickSort(nums, pivot + 1, high);
    }

    int partition(vector<int>& nums, int low, int high) {
        int randomIndex = low + rand() % (high - low + 1);
        swap(nums[randomIndex], nums[high]);

        int pivot = nums[high];
        int index = low;

        for (int i = low; i < high; i++) {
            if (nums[i] < pivot) {
                swap(nums[i], nums[index]);
                index++;
            }
        }

        swap(nums[index], nums[high]);

        return index;
    }
};