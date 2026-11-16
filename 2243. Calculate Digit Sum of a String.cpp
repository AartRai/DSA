//https://leetcode.com/problems/calculate-digit-sum-of-a-string/description/?envType=daily-question&envId=2026-11-16

// 1. Create an empty temp string to store the current group of digits and a result string to store the sum of each group.
// 2. Traverse the original string character by character.
// 3. Append each digit to temp and simultaneously calculate its sum.
// 4. Whenever the length of temp becomes equal to k, convert the sum into a string and append it to result.
// 5. Reset temp and sum to process the next group.
// 6. After traversing the string, if any digits remain in temp, append their sum to result.
// 7. Update the original string with result and repeat the process.
// 8. Return the final string when its length becomes less than or equal to k.
  
// Time Complexity: (O(n)) overall.
// Space Complexity: (O(n)) for storing intermediate strings.

class Solution {
public:
    string digitSum(string s, int k) {
        while(s.length() > k){
            string temp="";
            string result="";
            int sum=0;

            for(int i=0;i<s.length();i++){
                temp+=s[i];
                sum+=s[i] -'0';

                if(temp.length()==k){
                    result+=to_string(sum);

                    temp="";
                    sum=0;
                }
                
            }
            if(temp.length() > 0) {
                result += to_string(sum);
            }

            s = result;
        }
        return s;
    }
};
