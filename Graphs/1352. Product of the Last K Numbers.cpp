//https://leetcode.com/problems/product-of-the-last-k-numbers/description/?envType=daily-question&envId=2026-11-23



// 1. We maintain a prefix vector to store the cumulative product of numbers added so far.
// 2. Initially, the vector contains 1, which acts as a base value for calculating products.
// 3. In the add(num) function:
//    - If num == 0, reset the prefix vector to {1} because the product of any sequence containing zero is zero.
//    - Otherwise, multiply the current prefix product (prefix.back()) by num and push the result into the vector.
// 4. In the getProduct(k) function:
//    - Let n be the size of the prefix vector.
//    - If k >= n, return 0 because a zero exists in the last k numbers.
//    - Otherwise, calculate the product of the last k numbers 

// 5. This allows us to answer each product query in constant time without multiplying all k elements again.
// Complexity Analysis
// Operation	Time Complexity
// add(num)	O(1)
// getProduct(k)	O(1)

// - Time Complexity: O(1) per operation.
// - Space Complexity: O(n), where n is the number of elements added since the last zero (worst case: all added elements).

  
class ProductOfNumbers {
public:
vector<int> prefix{1};
    ProductOfNumbers() {
    
    }
    
    void add(int num) {
        if (num == 0)
            prefix = {1}; 
        else
            prefix.push_back(prefix.back() * num);
    }
    
    int getProduct(int k) {
        int n = prefix.size();
        if (k >= n)  
            return 0;
        return prefix[n - 1] / prefix[n - 1 - k];
    }
};
