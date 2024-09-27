#include <iostream>
#include <unordered_map>
#include <queue>
#include <deque>

using namespace std;

void unethical_queue_simulation() {
    int test_case = 1;

    while (true) {
        int t;
        cin >> t; 

        if (t == 0) break;

        unordered_map<int, int> group_map; 
        unordered_map<int, deque<int>> group_queues; 
        queue<int> overall_queue; 
        unordered_map<int, bool> in_queue; 

        for (int i = 0; i < t; ++i) {
            int group_size, leader;
            cin >> group_size;

            for (int j = 0; j < group_size; ++j) {
                int person;
                cin >> person;

                if (j == 0) leader = person;
                group_map[person] = leader;  
            }
        }

        cout << "Scenario #" << test_case << endl;
        test_case++;

        string command;

        while (cin >> command) {
            if (command == "STOP") {
                cout << endl;  
                break;
            }
            else if (command == "ENQUEUE") {
                int person;
                cin >> person;
                int group = group_map[person]; 

                if (!in_queue[group]) {
                    overall_queue.push(group);  
                    in_queue[group] = true;     
                }

                group_queues[group].push_back(person);

            }
            else if (command == "DEQUEUE") {
                int group = overall_queue.front();
                int person = group_queues[group].front();
                group_queues[group].pop_front(); 

                cout << person << endl;

                if (group_queues[group].empty()) {
                    overall_queue.pop();
                    in_queue[group] = false; 
                }
            }
        }
    }
}

int main() {
    unethical_queue_simulation();
    return 0;
}
