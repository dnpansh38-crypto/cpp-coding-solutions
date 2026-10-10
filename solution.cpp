
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<ll, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K, Q;
    cin >> K >> Q;

    priority_queue<P, vector<P>, greater<P>> pq;
    vector<ll> load(K + 1, 0);

    for (int i = 1; i <= K; i++) {
        pq.push({0, i});
    }

    unordered_map<int, pair<int, ll>> active;
    active.reserve(Q * 2);

    while (Q--) {
        int type, id;
        cin >> type >> id;

        if (type == 1) {
            ll d;
            cin >> d;

            while (!pq.empty() && pq.top().first != load[pq.top().second]) {
                pq.pop();
            }

            int channel = pq.top().second;
            pq.pop();

            load[channel] += d;
            pq.push({load[channel], channel});

            active[id] = {channel, d};

            cout << channel << '\n';
        } else {
            auto it = active.find(id);
            int channel = it->second.first;
            ll d = it->second.second;

            load[channel] -= d;
            active.erase(it);

            pq.push({load[channel], channel});

            cout << channel << ' ' << load[channel] << '\n';
        }
    }

    return 0;
}
