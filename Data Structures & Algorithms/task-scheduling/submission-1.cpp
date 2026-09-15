class Solution {
public:
    struct Task {
        int count;
        char name;
    };

    struct Compare {
        bool operator()(const Task& a, const Task& b) {
            return a.count < b.count; // max heap by count
        }
    };

    unordered_map<int, vector<Task>> cooldown;

    int leastInterval(vector<char>& tasks, int n) {
        int cycle = 0;
        vector<int> taskCounters(26,0);

        for(int i=0; i<tasks.size(); i++) {
            taskCounters[tasks[i]-'A']++;
        }

        priority_queue<Task, vector<Task>, Compare> maxHeap;

        for(int i=0; i<26; i++) {
            if (taskCounters[i]>0) {
                maxHeap.push({taskCounters[i], (char)(i+'A')});
                // cout<<i+'A'<<" "<<taskCounters[i]<<endl;
            }
        }

        while(!maxHeap.empty() || !cooldown.empty()) {
            cycle++;

            // Remove elements from cooldown
            if (cooldown.count(cycle)) {
                // cout<<"Hit Cooldown at cycle : "<<cycle<<"; ";
                for(auto& t: cooldown[cycle]) {
                    maxHeap.push(t); // push the task to maxHeap
                    // cout<<"Retreiving task "<<t.name<<" with count "<<t.count<<endl;
                }
                cooldown.erase(cycle);
            }

            if (!maxHeap.empty()) {
                // Then pick the top
                Task top = maxHeap.top();
                maxHeap.pop();

                // cout<<"Current Cycle : "<<cycle<<"; and processing element "<<top.name<<endl;

                // Check if the task had more counters, if yes put it in cooldown
                if (top.count>1) {
                    cooldown[cycle + n + 1].push_back({top.count-1, top.name});
                }
            }
        }

        return cycle;
    }
};
