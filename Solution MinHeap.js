
/**
 * @param {number[][]} slots_firstPerson
 * @param {number[][]} slots_secondPerson
 * @param {number} duration
 * @return {number[]}
 */
var minAvailableDuration = function (slots_firstPerson, slots_secondPerson, duration) {

    /*
     One Priority Queue is applied for both persons, since as per the problem statement, 
     overlap of time slots is possible only between the time slots of different persons.
     */
    const {MinPriorityQueue} = require('@datastructures-js/priority-queue');
    const minHeap = new MinPriorityQueue({compare: (x, y) => x.start - y.start});
    fill_minHeap(minHeap, slots_firstPerson, duration);
    fill_minHeap(minHeap, slots_secondPerson, duration);

    while (minHeap.size() > 1) {
        let first = minHeap.dequeue();
        let second = minHeap.front();
        if (second.start + duration <= first.end) {
            return [second.start, second.start + duration];
        }
    }
    return [];
};

/**
 * @param {number} start
 * @param {number} end
 */
function SlotCoveringDuration(start, end) {
    this.start = start;
    this.end = end;
}

/**
 * @param {MinPriorityQueue of SlotCoveringDuration} minHeap
 * @param {number[][]} slots
 * @param {number} duration
 * @return {void}
 */
function fill_minHeap(minHeap, slots, duration) {
    for (let slot of slots) {
        if (slot[1] - slot[0] >= duration) {
            minHeap.enqueue(new SlotCoveringDuration(slot[0], slot[1]));
        }
    }
}
