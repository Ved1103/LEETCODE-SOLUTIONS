/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let newarr=[];
    let i = 0;
    for(x of arr){
        if(fn(x,i)) newarr.push(x);
        i++;
    }
    return newarr;
};