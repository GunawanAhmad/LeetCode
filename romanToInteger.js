/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function (s) {
    let romanHash = new Map([
        ["I", 1],
        ["V", 5],
        ["X", 10],
        ["L", 50],
        ["C", 100],
        ["D", 500],
        ["M", 1000],
        ["IV", 4],
        ["IX", 9],
        ["XL", 40],
        ["XC", 90],
        ["CD", 400],
        ["CM", 900],
    ]);

    let result = 0;
    let integer;
    for (let i = 0; i < s.length; i++) {
        if (romanHash.get(s[i] + s[i + 1])) {
            integer = romanHash.get(s[i] + s[i + 1]);
            i++;
        } else {
            integer = romanHash.get(s[i]);
        }
        result += integer;
    }
    return result;
};

romanToInt("MCMXCIV");

// store the roman to hashmap
// loop through the roman input
// inside the loop find the matching character in the hash
// if the match char is 2 then increase the i to skip the next char
// add to the result after finding the integer
// then return the result
