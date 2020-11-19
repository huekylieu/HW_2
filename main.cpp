#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct queue_obj {  //Stuct for members of queue
    bool up;
    int floor;
};

struct comp_queue {     //Compares queue members
    inline bool operator() (const queue_obj& queue1, const queue_obj& queue2) {
        return (queue1.floor < queue2.floor);
    }
};

void sorting_insert(vector<int> & vec_in, int insert) {
    vec_in.push_back(insert);
    sort(vec_in.begin(),vec_in.end());
}

class elevator {
    public:
        void up_button(int floor_in) {
            if (state == 0) {
                sorting_insert(stops, floor_in);
            }
            else if (state == -1) {
                sorting_insert(queue, floor_in);
            }
            else if (state == 1) {
                if (floor_in > current_floor) {
                    sorting_insert(stops, floor_in);
                }
                else {
                   sorting_insert(queue, floor_in); 
                }
            }
        }

        void down_button(int floor_in) {
            if (state == 0) {
                sorting_insert(stops, floor_in);
            }
            else if (state == 1) {
                sorting_insert(queue, floor_in);
            }
            else if (state == -1) {
                if (floor_in < current_floor) {
                    sorting_insert(stops, floor_in);
                }
                else {
                   sorting_insert(queue, floor_in); 
                }
            }
        }

        void move_elevator() {
            if (stops.empty() && queue.empty()) {
                extreme_floor = 0;
                state = 0;
            }
            else if (stops.empty()) {

            }
        }

    private:
        int current_floor;  //Shows where elevator is
        vector<int> stops;  //List of stops elevator must make
        vector<int> queue;  //List of stops elvator cannot yet take
        int extreme_floor;  //Furthest floor from elevator
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