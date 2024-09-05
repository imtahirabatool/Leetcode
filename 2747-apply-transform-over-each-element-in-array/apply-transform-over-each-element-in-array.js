/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function (arr, fn) {
    const result = [];
    arr.forEach(function (element, ele) {
        result.push(fn(element, ele));
    });
    return result;
};