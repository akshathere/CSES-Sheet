#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, r;
    cin >> n >> r;

    vector<pair<int,int>> points(n);
    for (int i = 0; i < n; i++)
        cin >> points[i].first >> points[i].second;
    map<pair<int,int>, pair<int,int>> cellToCenter;

    vector<pair<int,int>> circles;

    int covered = 0;

    for (auto& [px, py] : points) {
        bool foundCircle = false;
        for (int dx = -1; dx <= 1 && !foundCircle; dx++) {
            for (int dy = -1; dy <= 1 && !foundCircle; dy++) {
                // Candidate cell
                int cx = (int)floor((double)px / r) + dx;
                int cy = (int)floor((double)py / r) + dy;
                pair<int,int> cell = {cx, cy};

                if (cellToCenter.count(cell)) {
                    auto [ox, oy] = cellToCenter[cell];
                    long long dist2 = (long long)(px - ox)*(px - ox)
                                    + (long long)(py - oy)*(py - oy);
                    if (dist2 <= (long long)r * r) {
                        covered++;
                        foundCircle = true;
                    }
                }
            }
        }

        if (!foundCircle) {
            int cx = (int)floor((double)px / r);
            int cy = (int)floor((double)py / r);
            pair<int,int> cell = {cx, cy};
            cellToCenter[cell] = {px, py};
            circles.push_back({px, py});
            covered++;
        }
    }

    cout << circles.size() << "\n";
    for (auto& [x, y] : circles)
        cout << x << " " << y << "\n";

    return 0;
}