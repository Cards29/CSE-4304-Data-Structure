#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;
using vi = vector<ll>;

double count_lb, count_qb, count_dh;

ll hash_lb(ll x, ll table_size, vector<ll>& v) {
    double lf;
    // if the index is empty
    if (v[x % table_size] == -1) {
        v[x % table_size] = x;
        count_lb++;
        lf = count_lb / table_size;
        cout << "Inserted : Index-" << x % table_size << " (L.F = " << lf << " )" << endl;
        return x % table_size;
    }
    // if not, we do linear probing
    cout << "Collision: Index-" << x % table_size << endl;
    ll count = (table_size + 2) / 2, i;
    for (i = 1;v[(x + i) % table_size] != -1 && count--;i++) {
        cout << "Collision: Index-" << (x + i) % table_size << endl;
    }
    // if there is still collision
    if (count == -1) { cout << "Input Abandoned" << endl;  return -1; }
    // if we found an empty index after linear probing
    v[(x + i) % table_size] = x;
    count_lb++;
    lf = count_lb / table_size;
    cout << "Inserted : Index-" << (x + i) % table_size << " (L.F = " << lf << " )" << endl;
    return (x + i) % table_size;
}

ll hash_qb(ll x, ll table_size, vector<ll>& v) {
    double lf;
    // if the index is empty
    if (v[x % table_size] == -1) {
        v[x % table_size] = x;
        count_qb++;
        lf = count_qb / table_size;
        cout << "Inserted : Index-" << x % table_size << " (L.F = " << lf << " )" << endl;
        return x % table_size;
    }
    // if not, we do quadratic probing
    cout << "Collision: Index-" << x % table_size << endl;
    ll count = (table_size + 2) / 2, i;
    for (i = 1; count-- && v[(x + (i * i)) % table_size] != -1; i++) {
        cout << "Collision: Index-" << (x + (i * i)) % table_size << endl;
    }
    // if there is still collision
    if (count == -1) { cout << "Input Abandoned" << endl;  return -1; }
    // if we found an empty index after linear probing
    v[(x + (i * i)) % table_size] = x;
    count_qb++;
    lf = count_qb / table_size;
    cout << "Inserted : Index-" << (x + (i * i)) % table_size << " (L.F = " << lf << " )" << endl;
    return (x + (i * i)) % table_size;
}

ll hash2(ll x) {
    return 7 - (x % 7);
}

ll double_hash(ll x, ll table_size, vector<ll>& v) {
    cout << "Double hash\n";
    double lf;
    // if the index is empty
    if (v[x % table_size] == -1) {
        v[x % table_size] = x;
        count_dh++;
        lf = count_dh / table_size;
        cout << "Inserted : Index-" << x % table_size << " (L.F = " << lf << " )" << endl;
        return x % table_size;
    }
    // if not, we do double hashing
    cout << "Collision: Index-" << x % table_size << endl;
    ll count = (table_size + 2) / 2, i;
    // cout << (x + (i * hash2(x))) << endl;
    for (i = 1; count-- && v[(x + (i * hash2(x))) % table_size] != -1; i++) {
        cout << "Collision: Index-" << (x + (i * hash2(x))) % table_size << endl;
    }
    // if there is still collision
    if (count == -1) { cout << "Input Abandoned" << endl;  return -1; }
    // if we found an empty index after linear probing
    v[(x + (i * hash2(x))) % table_size] = x;
    count_dh++;
    lf = count_dh / table_size;
    cout << "Inserted : Index-" << (x + (i * hash2(x))) % table_size << " (L.F = " << lf << " )" << endl;
    return (x + (i * hash2(x))) % table_size;
}

int main() {
    // cout << fixed;
    ll choice, N, Q;
    cin >> choice >> N >> Q;

    if (choice == 1) {
        vi v(N, -1);
        while (Q--) {
            ll x;
            cin >> x;
            hash_lb(x, N, v);
        }
    }
    else if (choice == 2) {
        vi v(N, -1);
        while (Q--) {
            ll x;
            cin >> x;
            hash_qb(x, N, v);
        }
    }
    else if (choice == 3) {
        vi v(N, -1);
        while (Q--) {
            ll x;
            cin >> x;
            double_hash(x, N, v);
        }
    }

    return 0;
}