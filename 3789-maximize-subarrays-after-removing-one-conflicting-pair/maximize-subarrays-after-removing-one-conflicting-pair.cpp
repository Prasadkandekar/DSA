#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        long long adjusted_n = n + 1LL; // Using long long to prevent overflow
        // Sort conflictingPairs based on the maximum of the pair
        sort(conflictingPairs.begin(), conflictingPairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return max(a[0], a[1]) < max(b[0], b[1]);
        });
        // Append a dummy pair [adjusted_n, adjusted_n] to flush out the tail
        conflictingPairs.push_back({(int)adjusted_n, (int)adjusted_n});
        
        long long maxDiff = 0;
        long long maxLeft = 0;
        long long remain = 0;
        long long maxAlterLeft = 0;
        long long altRemain = 0;
        
        for (const auto& pair : conflictingPairs) {
            long long left = min(pair[0], pair[1]);
            long long right = max(pair[0], pair[1]);
            
            if (left > maxLeft) {
                maxDiff = max(maxDiff, (maxAlterLeft - maxLeft) * (adjusted_n - right) + (remain - altRemain));
                altRemain = remain;
                maxAlterLeft = maxLeft;
                remain += (left - maxLeft) * (adjusted_n - right);
                maxLeft = left;
            } else if (left > maxAlterLeft) {
                altRemain += (left - maxAlterLeft) * (adjusted_n - right);
                maxAlterLeft = left;
            }
        }
        
        return (adjusted_n - 1LL) * adjusted_n / 2LL - remain + maxDiff;
    }
};