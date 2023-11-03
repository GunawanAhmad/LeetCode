/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
  let l1Sum = BigInt(0);
  let l2Sum = BigInt(0);
  let index = BigInt(1);
  while (l1 || l2) {
    if(l1) {
      l1Sum = l1Sum + (BigInt(l1.val) * index);
      l1 = l1.next;
    }
    if(l2) {
      l2Sum = l2Sum + (BigInt(l2.val) * index);
      l2 = l2.next;
    }
    index = index * BigInt(10);
  }

  let returnObj = null;
  let totalSum = BigInt(l1Sum + l2Sum);

  if(totalSum == 0) {
    return {
      val: 0,
      next: null
    }
  } 

  let remainingNumber = BigInt(totalSum);

  while (remainingNumber > 0) {
    let digit = remainingNumber % BigInt(10);

    if(!returnObj) {
      returnObj = {};
      returnObj.val = digit;
      returnObj.next = null;
    } else {
      let tempObj = returnObj;
      while(tempObj.next != null) {
        tempObj = tempObj.next;
      }

      tempObj.next = {
        val: digit,
        next: null
      }
    }
    remainingNumber = remainingNumber / BigInt(10);
  }

  return returnObj;
};



const l1Test = {
  val: 1,
  next: {
    val: 4,
    next: {
      val: 3,
      next: null
    }
  }
}

const l2Test = {
  val: 5,
  next: {
    val: 6,
    next: {
      val: 4,
      next: null
    }
  }
}

const l1Test2 = {
  val: 0,
  next: null
}

const l2Test2 = {
  val: 0,
  next: null
}


const l1Test3 = {
  val: 9,
  next: {
    val: 9,
    next: {
      val: 9,
      next: {
        val: 9,
        next: {
          val: 9,
          next: {
            val: 9,
            next: {
              val: 9,
              next: null
            }
          }
        }
      }
    }
  }
}

const l2Test3 = {
  val: 9,
  next: {
    val: 9,
    next: {
      val: 9,
      next: {
        val: 9,
        next: null
      }
    }
  }
}


const l1Test4 = {
  val: 1,
  next: {
    val: 0,
    next: {
      val: 0,
      next: {
        val: 0,
        next: {
          val: 0,
          next: {
            val: 0,
            next: {
              val: 1,
              next: null
            }
          }
        }
      }
    }
  }
}

const l2Test4 = {
  val: 5,
  next: {
    val: 6,
    next: {
      val: 4,
      next: null
    }
  }
}



const res = addTwoNumbers(l1Test4, l2Test4);
console.log(res);



