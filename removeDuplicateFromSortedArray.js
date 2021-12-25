/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function (nums) {
    let compared = null;
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] == compared) {
            nums.splice(i, 1);
            i--;
        }
        compared = nums[i];
    }
    console.log(nums);
};

let arr = [1, 1, 2];
removeDuplicates(arr);
