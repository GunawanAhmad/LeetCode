var twoSum = function (nums, target) {
    let hashTable = [];
    for (let i = 0; i < nums.length; i++) {
        let check = false;
        let indexFound = 0;
        for (let j = 0; j < hashTable.length; j++) {
            if (target - nums[i] == hashTable[j][0]) {
                check = true;
                indexFound = hashTable[j][1];
            }
        }
        if (!check) {
            hashTable.push([nums[i], i]);
        } else {
            return [i, indexFound];
        }
    }
};

let res = twoSum([3, 2, 4], 6);
console.log(res);
