const num = 214748364;

var reverse = function (x) {
  let zeroCount = 1000000000;
  let resArr = [];
  let arr = [];
  arr.push(x);
  for (let i = 0; i < 10; i++) {
    let d = arr.length - 1;
    let tempRest = arr[d] % zeroCount;
    let result = arr[d] - tempRest;
    resArr.push(result);
    arr.push(tempRest);
    zeroCount = zeroCount / 10;
  }
  let findZero = false;
  resArr.forEach((i) => {
    if (i != 0) {
      findZero = true;
    }
    if (findZero) {
      zeroCount = zeroCount * 10;
    }
  });

  let zeroCountDiv = 1;

  let hasil = 0;
  for (var i = resArr.length - 1; i >= 0; i--) {
    let hasilTemp = (resArr[i] * zeroCount) / zeroCountDiv;
    zeroCount = zeroCount / 10;
    zeroCountDiv = zeroCountDiv * 10;
    hasil = hasilTemp + hasil;
  }
  if (hasil > 2147483647 || hasil < -2147483648) {
    return 0;
  }
  return hasil;
};

let res = reverse(num);
console.log(res);
