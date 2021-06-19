/**
 * @param {string} s
 * @return {number}
 */

function findPreviousChar(j, i, str) {
  let check = false;
  let temp = j;
  while (j > i && !check) {
    if (str[temp] == str[j - 1]) {
      check = true;
    }
    j--;
  }
  return check;
}

var lengthOfLongestSubstring = function (s) {
  let max = 0;
  for (let i = 0; i < s.length; i++) {
    let check = true;
    let j = i + 1;
    let tmp = 1;
    while (check && j < s.length) {
      let prev = findPreviousChar(j, i, s);
      if (prev) {
        check = false;
      } else {
        j++;
        tmp++;
      }
    }

    if (tmp > max) {
      max = tmp;
    }
  }
  return max;
};

// aab

let a = lengthOfLongestSubstring("");
console.log(a);
