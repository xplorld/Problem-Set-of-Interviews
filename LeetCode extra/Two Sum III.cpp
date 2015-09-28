/*
Design and implement a TwoSum class. It should support the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

For example,
add(1); add(3); add(5);
find(4) -> true
find(7) -> false
 */

class TwoSum {
    private:
    unordered_map<int, int> m;
public:

    // Add the number to an internal data structure.
	void add(int number) {
	    ++m[number];
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
	    for (auto it = m.begin(); it != m.end(); ++it) {
	        if (value == 2 * it->first) {
	            if (it->second >= 2) return true;
	        } else {
	            if (m.find(value - it->first) != m.end()) {
	                return true;
	            }
	        }
	    }
	    return false;
	}
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);
