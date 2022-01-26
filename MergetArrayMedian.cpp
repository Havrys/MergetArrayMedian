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
