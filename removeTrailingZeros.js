/**
 * @param {string} num
 * @return {string}
 */
var removeTrailingZeros = function(num) {
  let arr = [];
  let found  = false;
  for (let i = num.length - 1; i >= 0; i--) {
    if(found) {
      arr.unshift(num[i])
    } else {
      if(num[i] !== '0') {
        found = true
        arr.unshift(num[i])
      }
    }
  }
  return arr.join('');
};


let a = removeTrailingZeros('51230100');
console.log(a);