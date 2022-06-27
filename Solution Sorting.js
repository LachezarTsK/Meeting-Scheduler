
/**
 * @param {number[][]} slots_firstPerson
 * @param {number[][]} slots_secondPerson
 * @param {number} duration
 * @return {number[]}
 */
var minAvailableDuration = function (slots_firstPerson, slots_secondPerson, duration) {
    slots_firstPerson.sort((x, y) => x[0] - y[0]);
    slots_secondPerson.sort((x, y) => x[0] - y[0]);
    let index_first = 0;
    let index_second = 0;

    while (index_first < slots_firstPerson.length && index_second < slots_secondPerson.length) {

        let maxStart = Math.max(slots_firstPerson[index_first][0], slots_secondPerson[index_second][0]);
        let minEnd = Math.min(slots_firstPerson[index_first][1], slots_secondPerson[index_second][1]);
        if (minEnd - maxStart >= duration) {
            return [maxStart, maxStart + duration];
        }

        if (slots_firstPerson[index_first][1] < slots_secondPerson[index_second][1]) {
            ++index_first;
        } else {
            ++index_second;
        }
    }
    return [];
};
