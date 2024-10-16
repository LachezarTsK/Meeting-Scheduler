
#include <vector>
using namespace std;

class Solution {
    
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots_firstPerson, vector<vector<int>>& slots_secondPerson, int duration) const {

        auto smallerStartingTimeOnTop = [](const auto& x, const auto& y) {return x[0] < y[0];};
        sort(slots_firstPerson.begin(), slots_firstPerson.end(), smallerStartingTimeOnTop);
        sort(slots_secondPerson.begin(), slots_secondPerson.end(), smallerStartingTimeOnTop);

        int index_first = 0;
        int index_second = 0;

        while (index_first < slots_firstPerson.size() && index_second < slots_secondPerson.size()) {

            int maxStart = max(slots_firstPerson[index_first][0], slots_secondPerson[index_second][0]);
            int minEnd = min(slots_firstPerson[index_first][1], slots_secondPerson[index_second][1]);
            if (minEnd - maxStart >= duration) {
                return vector<int>{maxStart, maxStart + duration};
            }

            if (slots_firstPerson[index_first][1] < slots_secondPerson[index_second][1]) {
                ++index_first;
            } else {
                ++index_second;
            }
        }
        return vector<int>();
    }
};
