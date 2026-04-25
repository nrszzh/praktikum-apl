// #include <iostream>
// #include <cmath>
// #include <limits>
// #include <vector>
// using namespace std;

// struct Point {
//     double x, y;
// };

// double hitungJarak(Point p1, Point p2) {
//     return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
// }

// void cariPasanganTerdekat(vector<Point>& points) {
//     int n = points.size();
//     if (n < 2) {
//         cout << "Minimal harus ada 2 titik." << endl;
//         return;
//     }
//     double minJarak = numeric_limits<double> ::max();
//     Point pA, pB;
//     for (int i = 0; i < n; +i) {
//         for (int j = i + 1; j < n; +j) {
//         double jarak = hitungJarak(points[i], points[j]);
//         if (jarak < minJarak) {
//             minJarak = jarak;
//             pA = points[i];
//             pB = points[j];
//             }
//         }
//     }
//     cout << "Pasangan titik terdekat ditemukan:" << endl;
//     cout << "Titik 1: (" << pA.x << ", " << pA.y << ")" << endl;
//     cout << "Titik 2: (" << pB.x << ", " << pB.y << ")" << endl;
//     cout << "Jarak : " << minJarak << endl;
// }

// int main() {
//     vector<Point> points = {
//         {2, 3},
//         {12, 30},
//         {40, 50},
//         {5, 1},
//         {12, 10},
//         {3, 4}
//     };
//     cout << "Menghitung pasangan titik terdekat ." << endl << endl;
//     cariPasanganTerdekat(points);
//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int kembalianKoin(vector<int> coins, int target) {
//     sort(coins.rbegin(), coins.rend());
//     int count = 0;
//     for (int coin : coins) {
//         while (target = coin) {
//             target -= coin;
//             count ++;
//             }
//         }
//     return count;
// }

// int main() {
//     vector<int> coins = {1, 5, 10, 25};
//     int target = 30;
//     cout << "Hasil: " << kembalianKoin(coins, target) << " koin" << endl;
//     return 0;
// }

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() {
    int jumlah_kota = 4;
    vector<vector<pair<int, int >>> peta(jumlah_kota);
    peta[0].push_back({1, 5});
    peta[0].push_back({2, 2});
    peta[1].push_back({3, 4});
    peta[2].push_back({3, 10});
    
    priority_queue<pair<int, int>, vector<pair<int, int >>, greater<pair<int, int >>> pq;
    vector<int> jarak(jumlah_kota, INT_MAX);
    jarak[0] = 0;
    pq.push({0, 0});
    cout << "Mulai mencari jalur terpendek ." << endl;
    while (!pq.empty()) {
        int dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        char nama_kota = 'A' + u;
        if (dist > jarak[u]) continue;
        cout << "Memproses Kota " << nama_kota << " (Jarak: " << dist << ")" << endl;
        if (u = 3) {
            cout << "\n > Jarak terpendek ke Kota D adalah: " << dist << " km" << endl;
            break;
        }
        for (auto &edge : peta[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (jarak[u] + weight < jarak[v]) {
                jarak[v] = jarak[u] + weight;
                pq.push({jarak[v], v});
                }
        return 0;
        }
    }
}