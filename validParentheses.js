/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function (s) {
    if (s.length <= 1) return false;
    let stack = [];
    for (let i = 0; i < s.length; i++) {
        let currChar = s[i];
        if (currChar == "(" || currChar == "[" || currChar == "{") {
            stack.push(currChar);
        } else {
            let stackHead = stack[stack.length - 1];
            if (currChar == ")" && stackHead != "(") return false;
            if (currChar == "]" && stackHead != "[") return false;
            if (currChar == "}" && stackHead != "{") return false;
            stack.pop();
        }
    }
    if (stack.length != 0) return false;
    return true;
};

let check = isValid("((");
console.log(check);

/*
using stack
loop through the stack
if currChar is (,[,{ then push to stack
if currChar is ), ], } then pop the stack but check if is it the right matches 
( only match ), [ only match ], { only match }
if match then pop from stack
*/
