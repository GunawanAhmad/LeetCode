/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    let commonPrefix = '';
    let prefixList = [];
    if(strs.length < 1) return '';
    if(strs.length < 2) return strs[0];
    let firstStr = strs[0]

    //loop through the first word to extract all the prefix
    for (let i = 0; i < firstStr.length; i++) {
      prefixList.push(firstStr.substring(0, i + 1))
    }


    //loop throught the second and next word 
    let listCommonPrefixOnEachWord = []
    for (let i = 1; i < strs.length; i++) {
      let word = strs[i];
      let longestLength = 0

      //loop throught the word
      let isPrefixExist = false
      for (let j = 0; j < word.length; j++) {

        
          let prefix = word.substring(0, j + 1);

          //loop throught the prefix list
          for (let l = 0; l < prefixList.length; l++) {

            if(prefix == prefixList[l] && prefix.length > longestLength) {
              isPrefixExist = true;
              commonPrefix = prefixList[l];
              longestLength = prefix.length;
            }

          }
      }

      if(!isPrefixExist) return ''

      listCommonPrefixOnEachWord.push(commonPrefix);
    }

    //find the longet common prefix in the list of prefix in all word
    let longestCommonPrefix = listCommonPrefixOnEachWord[0];
    if(listCommonPrefixOnEachWord.length > 1) {
      for (let i = 1; i < listCommonPrefixOnEachWord.length; i++) {
        if(listCommonPrefixOnEachWord[i].length < longestCommonPrefix.length) {
          longestCommonPrefix = listCommonPrefixOnEachWord[i]
        }
      }
    }
      

    return longestCommonPrefix;
};


let test = longestCommonPrefix(["aa","aa","a"])
console.log(test);