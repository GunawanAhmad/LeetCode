/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function (nums, val) {
    let index;
    let count = 0;
    for (index = 0; index < nums.length; index++) {
        if (nums[index] == val) {
            shiftElm(index, nums);
            count++;
            index--;
        }
    }
    return index - count;
};

function shiftElm(index, nums) {
    for (let i = index; i < nums.length; i++) {
        nums[i] = nums[i + 1];
    }
}

let nums = [3, 2, 2, 3];
let res = removeElement(nums, 3);
console.log(res);

// find the matching val in nums
// then shift the rest of the nums to the left by the amount of 1
