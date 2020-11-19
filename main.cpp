#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void sorting_insert(vector<int> & vec_in, int insert) {
    vec_in.push_back(insert);
    sort(vec_in.begin(),vec_in.end());
}

class elevator {
    public:
        void up_button(int floor) {
            if (state == 0) {
                sorting_insert(stops,floor);
            }
            else if (state == -1) {
                sorting_insert(queue,floor);
            }
            else if (state == 1) {
                if (floor > current_floor) {
                    sorting_insert(stops,floor);
                }
                else {
                   sorting_insert(queue,floor); 
                }
            }
        }

        void down_button(int floor) {
            if (state == 0) {
                sorting_insert(stops,floor);
            }
            else if (state == 1) {
                sorting_insert(queue,floor);
            }
            else if (state == -1) {
                if (floor < current_floor) {
                    sorting_insert(stops,floor);
                }
                else {
                   sorting_insert(queue,floor); 
                }
            }
        }

    private:
        int current_floor;
        vector<int> stops;
        vector<int> queue;
        int extreme_floor;
        int state; //UP = 1;DOWN = -1;REST = 0
};

int main() {
    bool another = 1;
    int put_in;
    vector<int> sorting;
    while (another) {
        cout << "Put in val";
        cin >> put_in;
        sorting_insert(sorting,put_in);
        cout << "Another: ";
        cin >> another;
    }
    
    for (int x = 0; x < sorting.size(); x++) {
        cout << sorting[x] << endl;
    }
    return 0;
}