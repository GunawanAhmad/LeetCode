/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function (x) {
    //123 mod 100  = 23 //arr1 = [23]
    // 123 - 23 = 100   //arr2=[100]
    // 23 mod 10 = 3 //arr1=[23, 3]
    // 23 - 3 = 20 //arr2=[100, 20]
    //20 mod 1 = 0 //arr1=[23,3,0]
    //3 - 0 = 3 //arr2=[100,20,3]
    if (x < 0) return false;
    if (x > 2147483647) return false;
    if (x === 0) return true;
    let zeroCount = 1000000000;
    let arrOfSub = []; //array of modulo operation
    let arrOfMod = []; //array of substraction after modulo operation
    arrOfMod.push(x);
    for (let i = 0; i < 10; i++) {
        let arrLength = arrOfMod.length - 1;
        let modResult = arrOfMod[arrLength] % zeroCount;
        let substractionResult = arrOfMod[arrLength] - modResult;
        arrOfSub.push(substractionResult / zeroCount);
        arrOfMod.push(modResult);
        zeroCount = zeroCount / 10;
    }

    let isNonZero = false;
    let contentLength = 1,
        middleArr = 0,
        midIndex = 0;
    for (let i = 0; i < arrOfSub.length; i++) {
        if (arrOfSub[i] != 0) isNonZero = true;
        if (isNonZero) {
            contentLength = arrOfSub.length - i;
            middleArr = Math.ceil(contentLength / 2);
            midIndex = arrOfSub.length - middleArr;
            break;
        }
    }

    if (contentLength % 2 != 0) {
        //loop to right and left

        let leftCounter = midIndex - 1;
        let rigtCounter = midIndex + 1;
        while (rigtCounter != arrOfSub.length) {
            if (arrOfSub[rigtCounter] != arrOfSub[leftCounter]) {
                return false;
            }
            rigtCounter++;
            leftCounter--;
        }
    } else {
        let leftCounter = midIndex - 1;
        let rigtCounter = midIndex;
        while (rigtCounter != arrOfSub.length) {
            if (arrOfSub[rigtCounter] != arrOfSub[leftCounter]) {
                return false;
            }
            rigtCounter++;
            leftCounter--;
        }
    }
    return true;
};

let check = isPalindrome(0);
console.log(check);

//0,0,0,0,0,1,2,2,2,3
//index = 5
//length = 9
//contentLength= 4
//middleArr = 2
//midIndex = length - middleArr
//            9 - 2 = 7

//1,2,3,4

//121 ->
