/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function(haystack, needle) {
  let needleLength = needle.length;
  for(let i = 0; i < haystack.length; i++) {
    let substring = haystack.substring(i, i + needleLength);
    if(substring == needle) {
      return i;
    }
  }
  return -1;
};


const res = strStr("leetcode", "leeto")
console.log(res)
