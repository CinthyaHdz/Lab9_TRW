#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;

    vector<int> leftMax(n), rightMax(n);
    int water = 0;

    // Construimos leftMax
    leftMax[0] = height[0];
    for (int i = 1; i < n; ++i)
        leftMax[i] = max(leftMax[i - 1], height[i]);

    // Construimos rightMax
    rightMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; --i)
        rightMax[i] = max(rightMax[i + 1], height[i]);

    // Calculamos agua atrapada
    for (int i = 0; i < n; ++i)
        water += min(leftMax[i], rightMax[i]) - height[i];

    return water;
}

int main() {
    vector<int> height = {4,2,0,3,2,5};
    cout << "Agua atrapada: " << trap(height) << " unidades" << endl;

    return 0;
}
