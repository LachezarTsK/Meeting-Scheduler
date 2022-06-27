
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;

public class Solution {

    private record SlotCoveringDuration(int start, int end) {}

    public List<Integer> minAvailableDuration(int[][] slots_firstPerson, int[][] slots_secondPerson, int duration) {

        /*
        One Priority Queue is applied for both persons, since as per the problem statement, 
        overlap of time slots is possible only between the time slots of different persons.
         */
        PriorityQueue<SlotCoveringDuration> minHeap = new PriorityQueue<>((x, y) -> x.start - y.start);
        fill_minHeap(minHeap, slots_firstPerson, duration);
        fill_minHeap(minHeap, slots_secondPerson, duration);

        while (minHeap.size() > 1) {
            SlotCoveringDuration first = minHeap.poll();
            SlotCoveringDuration second = minHeap.peek();
            if (second.start + duration <= first.end) {
                return List.of(second.start, second.start + duration);
            }
        }
        return new ArrayList<>();
    }

    private void fill_minHeap(PriorityQueue<SlotCoveringDuration> minHeap, int[][] slots, int duration) {
        for (int[] slot : slots) {
            if (slot[1] - slot[0] >= duration) {
                minHeap.offer(new SlotCoveringDuration(slot[0], slot[1]));
            }
        }
    }
}
