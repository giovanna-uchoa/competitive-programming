#include <bits/stdc++.h>
using namespace std;

struct monster {
    long long attack;
    set<int> ties;
};

struct group {
    long long damage = 0;
    set<int> banned_monsters;

    group(long long attack, const set<int>& banned) {
        damage = attack;
        banned_monsters = banned;
    };
};

int main() {
    int t, n;
    cin >> t;
    
    while (t--) {
        cin >> n;
        
        vector<monster> monsters(n);
        long long t_damage = 0;

        // monster attack
        for (int j = 0; j < n; j++) {
            cin >> monsters[j].attack;
            t_damage += monsters[j].attack;
        }
        
        // edges
        for (int j = 0; j < n-1; j++) {
            int u, v;
            cin >> u >> v;
            u--; v--; // 0-based index
            
            monsters[u].ties.insert(v);
            monsters[v].ties.insert(u);
        }
        
        vector<group> attack_groups;

        // monsters partition
        for (int j = 0; j < n; j++) {
            bool added = false;

            for (auto &g : attack_groups) {
                if (g.banned_monsters.find(j) == g.banned_monsters.end()) {
                    // if not banned, add to group
                    g.damage += monsters[j].attack;
                    g.banned_monsters.insert(monsters[j].ties.begin(), monsters[j].ties.end());
                    added = true;
                    break;
                }
            }

            // if not added, creates a new group
            if (!added) {
                attack_groups.emplace_back(monsters[j].attack, monsters[j].ties);
            }
        }

        sort(attack_groups.begin(), attack_groups.end(), [](const group &x, const group &y) {
            return x.damage > y.damage;
        });

        long long t_total_damage = t_damage;
        for (const auto& g : attack_groups) {
            t_damage -= g.damage;
            t_total_damage += t_damage;
        }

        cout << t_total_damage << endl;
    }
   
}