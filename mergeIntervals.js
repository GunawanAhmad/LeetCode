/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
var merge = function (intervals) {
  intervals = insertionSort(intervals);
  for (let i = 0; i < intervals.length - 1; i++) {
    let isOverlap = true;
    let j = i + 1;
    while (isOverlap && j < intervals.length) {
      if (intervals[j][0] <= intervals[i][1]) {
        mergeArray(intervals, intervals[i], intervals[j], i, j);
      } else {
        isOverlap = false;
      }
    }
  }
  return intervals;
};

function mergeArray(arr, arr1, arr2, idx1, idx2) {
  arr.splice(idx1, 1);
  let item1 = arr1[0];
  let item2;
  if (arr1[1] >= arr2[1]) item2 = arr1[1];
  else item2 = arr2[1];
  if (idx2 > idx1) {
    arr.splice(idx2 - 1, 1);
  } else {
    arr.splice(idx2, 1);
  }
  arr.splice(idx1, 0, [item1, item2]);
}

function insertionSort(inputArr) {
  let n = inputArr.length;
  for (let i = 1; i < n; i++) {
    // Choosing the first element in our unsorted subarray
    let current = inputArr[i];
    // The last element of our sorted subarray
    let j = i - 1;
    while (j > -1 && current[0] < inputArr[j][0]) {
      inputArr[j + 1] = inputArr[j];
      j--;
    }
    inputArr[j + 1] = current;
  }
  return inputArr;
}
var items = [
  [1, 4],
  [0, 7],
];

console.log(merge(items));
