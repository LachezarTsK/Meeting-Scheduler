
#include <vector>
using namespace std;

class Solution {

    struct SlotCoveringDuration {
        int start{};
        int end{};
        SlotCoveringDuration(int start, int end) : start {start}, end {end} {}
    };

    inline static auto smallerStartingTimeOnTop = [](const SlotCoveringDuration& first, const SlotCoveringDuration& second) 
    {
        return first.start > second.start;
    };
    
    /*
     One Priority Queue is applied for both persons, since as per the problem statement, 
     overlap of time slots is possible only between the time slots of different persons.
     */
    typedef priority_queue<SlotCoveringDuration, vector<SlotCoveringDuration>, decltype(smallerStartingTimeOnTop)> MinHeap;


public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots_firstPerson, vector<vector<int>>& slots_secondPerson, int duration) {

        MinHeap minHeap(smallerStartingTimeOnTop);
        fill_minHeap(minHeap, slots_firstPerson, duration);
        fill_minHeap(minHeap, slots_secondPerson, duration);

        while (minHeap.size() > 1) {
            SlotCoveringDuration first = minHeap.top();
            minHeap.pop();
            SlotCoveringDuration second = minHeap.top();
            if (second.start + duration <= first.end) {
                return vector<int>{second.start, second.start + duration};
            }
        }
        return vector<int>();
    }

private:
    void fill_minHeap(MinHeap& minHeap, const vector<vector<int>>& slots, int duration) {
        for (const auto& slot : slots) {
            if (slot[1] - slot[0] >= duration) {
                minHeap.push(SlotCoveringDuration(slot[0], slot[1]));
            }
        }
    }
};
