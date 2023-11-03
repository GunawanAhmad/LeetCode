/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */



var twoSum = function(nums, target) {
    let hashTable = [];
    let out_arr = [];
    for(let i = 0; i < nums.length; i++) {
        for(let j = 0; j < hashTable.length; j++) {
            if(nums[i] + hashTable[j].value == target) {
                out_arr  =  [hashTable[j].index, i]
            }
        }
        hashTable.push({
            value: nums[i],
            index: i
        })
    }
    return out_arr;
};

let nums = [2,7,11,15]
let target = 9

console.log(twoSum(nums, target));
