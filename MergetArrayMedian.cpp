/*Description

Suppose two ascending sorted arrays are given. These two arrays are merged into one. Find a median of the obtained array.
By definition, a median of the array with ascending numbers that contains n elements is the (int(n/2)+1)-st element.
For example, the median of the array {1, 2, 3, 4, 5} is 3, the median of {1, 2, 3, 4, 5, 6} is 4.

Input
     1. Quantity n_1 of the members in the first array, a positive integer.
     2. Four positive integers S_1, A_1, B_1, M_1. Using numbers S_1, A_1, B_1, M_1, the following pseudocode will generate the first array.
X_1[0] = S_1
for i = 1 to n_1-1:
S_1 = (A_1 * S_1 + B_1) mod M_1
X_1[i] = X_1[i-1] + S_1
     3. Quantity n_2  of the members in the second array, a positive integer.
     4. Four positive integers S_2, A_2, B_2, M_2. Using numbers S_2, A_2, B_2, M_2, the following pseudocode will generate the second array.
X_2[0] = S_2
for i = 1 to n_2-1:
S_2 = (A_2 * S_2 + B_2) mod M_2
 X_2[i] = X_2[i-1] + S_2
*/

#include <iostream>
#include <vector>

int findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) 
{

    int n = nums1.size();
    int m = nums2.size();
    int mid = (n + m) / 2;
    bool isEven = (n + m) % 2 == 0;
    int i = 0, j = 0, l = -1, curr;
    int prev = n > 0 ? nums1[0] : nums2[0];
    curr = prev;
    while (i < n && j < m) 
    {
        prev = curr;
        if (nums1[i] < nums2[j]) 
        {
            curr = nums1[i];
            i++;
        }
        else 
        {
            curr = nums2[j];
            j++;
        }
        l++;
        if (l == mid) 
        {
            return curr;
        }
    }


    while (i < n) {
        prev = curr;
        curr = nums1[i];
        i++;
        l++;
        if (l == mid) {
            return curr;
        }
    }


    while (j < m) {
        prev = curr;
        curr = nums2[j];
        j++;
        l++;
        if (l == mid) {
            return curr;
        }
    }
    return 0.0;
}

void inpVector(int n, std::vector<int>& X)
{
    int S{};
    int A{};
    int B{};
    int M{};
    std::cin >> S >> A >> B >> M;
    X[0] = S;
    for (int i{ 1 }; i <= n - 1; ++i)
    {
        S = (A * S + B) % M;
        X[i] = (X[i - 1] + S);
    }
}

int main()
{
    int n_1{};
    std::cin >> n_1;
    std::vector<int> X_1(n_1);
    inpVector(n_1, X_1);
    int n_2{};
    std::cin >> n_2;
    std::vector<int> X_2(n_2);
    inpVector(n_2, X_2);
    std::cout<<findMedianSortedArrays(X_1, X_2);
}
