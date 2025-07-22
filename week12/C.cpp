#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n, m; 
    cin >> n >> m;
	
	vector<vector<int>> events(m+1);
    
    for(int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        events[l].push_back(0);
		events[r].push_back(1);
    }
	
    int actives = 0;
	vector<int> ans = {};
    for(int i = 1; i <= m; i++) {
		auto events_x = events[i];

        // Count the number of starting intervals at this point
        for(auto event : events_x) 
            if(event == 0) actives++;
	
        if (actives == 0) ans.push_back(i);

        // Count the number of ending intervals at this point
		for(auto event : events_x) 
            if(event == 1) actives--;
	}

	cout << ans.size() << endl;
    if (ans.size() > 0) {
        for (auto x : ans)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}