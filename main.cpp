#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct queue_obj {  //Stuct for members of queue
    queue_obj(bool up_in, int floor_in) {
        up = up_in;
        floor = floor_in;
    }
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

void queue_insert(vector<queue_obj> & queue_in, int insert,bool up_in) {
    queue_in.push_back(queue_obj(up_in,insert));
    sort(queue_in.begin(),queue_in.end(),comp_queue());
}

class person {
    public:
        person (int start_in,int dest_in) {
            start_floor = start_in;
            destination = dest_in;
            set_button_press();
        }
        int start_floor;
        int destination;
        bool button_press; //1 for up, 0 for down
        void set_button_press() {
            if (start_floor > destination) {
                button_press = 0;
            }
            else {
                button_press = 1;
            }
        }
};

class elevator {
    public:
        void up_button(int floor_in) {
            if (state == 0) {
                sorting_insert(stops, floor_in);
            }
            else if (state == -1) {
                queue_insert(queue, floor_in,0);
            }
            else if (state == 1) {
                if (floor_in > current_floor) {
                    sorting_insert(stops, floor_in);
                }
                else {
                   queue_insert(queue, floor_in,1); 
                }
            }
        }

        void down_button(int floor_in) {
            if (state == 0) {
                sorting_insert(stops, floor_in);
            }
            else if (state == 1) {
                queue_insert(queue, floor_in,1);
            }
            else if (state == -1) {
                if (floor_in < current_floor) {
                    sorting_insert(stops, floor_in);
                }
                else {
                   queue_insert(queue, floor_in,0); 
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
        vector<queue_obj> queue;  //List of stops elvator cannot yet take
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