/**
 *  * @param {Function} fn
 *   * @return {Object}
 *    */
Array.prototype.groupBy = function (fn) {
	const res = {};
	this.forEach(e => {
		const key = fn(e);
		if (res[key] == undefined) {
			res[key] = [e];
		} else {
			res[key].push(e);
		}
	})
	return res;
};

/**
 *  * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 *   */
array = [{"id":"1"},{"id":"1"},{"id":"2"}]
fn = function (item) { return item.id; }

console.log(array.groupBy(fn))