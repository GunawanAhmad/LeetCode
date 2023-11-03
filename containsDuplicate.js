/**
 * @param {number[]} nums
 * @return {boolean}
 */


var containsDuplicate = function(nums) {
 let HashObj = {}
 let check = false;
  for (let i = 0; i < nums.length; i++) {
    const element = nums[i];
    if (HashObj[element] !== undefined) {
      check = true;
      break;
    } else {
      HashObj[element] = element;
    }
  }
  return check;
};

var check = containsDuplicate([0,4,5,0,3,6]);
console.log(check)
