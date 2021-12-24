/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function (height) {
  let leftBar = 0;
  let rightBar = height.length - 1;
  let maxArea = 0;
  while (leftBar < rightBar) {
    let area = calculateArea(
      height[leftBar],
      height[rightBar],
      leftBar,
      rightBar
    );
    if (area > maxArea) maxArea = area;
    if (height[rightBar] <= height[leftBar]) rightBar--;
    else if (height[rightBar] > height[leftBar]) leftBar++;
  }
  return maxArea;
};

function calculateArea(leftBar, rightBar, leftIndex, rightIndex) {
  let distance = rightIndex - leftIndex;
  let area;
  if (leftBar <= rightBar) area = distance * leftBar;
  else if (leftBar > rightBar) area = distance * rightBar;
  return area;
}

let height = [1, 2, 4, 3];
console.log(maxArea(height));
