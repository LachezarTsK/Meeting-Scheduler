
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution {

    public List<Integer> minAvailableDuration(int[][] slots_firstPerson, int[][] slots_secondPerson, int duration) {

        Arrays.sort(slots_firstPerson, (x, y) -> x[0] - y[0]);
        Arrays.sort(slots_secondPerson, (x, y) -> x[0] - y[0]);
        int index_first = 0;
        int index_second = 0;

        while (index_first < slots_firstPerson.length && index_second < slots_secondPerson.length) {

            int maxStart = Math.max(slots_firstPerson[index_first][0], slots_secondPerson[index_second][0]);
            int minEnd = Math.min(slots_firstPerson[index_first][1], slots_secondPerson[index_second][1]);
            if (minEnd - maxStart >= duration) {
                return List.of(maxStart, maxStart + duration);
            }

            if (slots_firstPerson[index_first][1] < slots_secondPerson[index_second][1]) {
                ++index_first;
            } else {
                ++index_second;
            }
        }
        return new ArrayList<>();
    }
}
