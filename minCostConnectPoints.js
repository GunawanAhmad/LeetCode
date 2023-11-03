/**
 * @param {number[][]} points
 * @return {number}
 */
var minCostConnectPoints = function(points) {
  let sortedEdge = []
  for(let i=0; i < points.length; i++) {
    for(let j=i + 1; j < points.length; j++) {
      let distance = manhattanDistance(points[i][0], points[i][1], points[j][0], points[j][1]);
      let new_data = {
        indefOfNodeA: i,
        indexOfNodeB: j,
        distance: distance
      };
      insertToSortedArr(sortedEdge, new_data);
    }
  }

  const sets = [];

  for (let i = 0; i < sortedEdge.length; i++) {

  }

  return sortedEdge;
};

function manhattanDistance(x1,y1,x2,y2) {
  return Math.abs(x1 - x2) + Math.abs(y1 - y2);
}

function insertToSortedArr(arr, data) {
  let index = 0;
  while(index < arr.length && arr[index].distance < data.distance) {
    index = index + 1;
  }
  arr.splice(index, 0, data);
}

const res= minCostConnectPoints([[0,0],[2,2],[3,10],[5,2],[7,0]]);
console.log(res)
