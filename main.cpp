#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct queue_obj {  //Stuct for members of queue
    queue_obj(bool up_in, int floor_in) {
        up = up_in; //If the elvator is going up (false for down)
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

void sorting_insert(vector<int> & vec_in, int insert) { //Sorts elevator stops by floor
    vec_in.push_back(insert);
    sort(vec_in.begin(),vec_in.end());
}

void queue_insert(vector<queue_obj> & queue_in, int insert,bool up_in) {    //Sorts elevator queue by floor
    queue_in.push_back(queue_obj(up_in,insert));
    sort(queue_in.begin(),queue_in.end(),comp_queue());
}

class clock {   //Keeps track of time   //Need to add elevator travel time
    public:
        double get_time() {   //Returns time on clock
            return time;
        }
        void add_time(double time_in) { //Adds time to clock
            time += time_in;
        }
        void open_close_door() {
            time += 6;  //It takes 6 sec for the door to open and then close (assuming person is very quick getting in and closing door)
        }
    private:
        double time;
};

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
        void up_button(int floor_in) {  //Adds person to stops if they are in the same direction as the elvator; adds them to queue if they are not on the way of the elvator
            if (state == 0) {
                sorting_insert(stops, floor_in);
            }
            else if (state == -1) { //Needs work
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

        void down_button(int floor_in) {    //Adds person to stops if they are in the same direction as the elvator; adds them to queue if they are not on the way of the elvator
            if (state == 0) {
                sorting_insert(stops, floor_in);
            }
            else if (state == 1) {  //Needs work
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

        void pers_bttn_prs (person person_in) {
            if (person_in.button_press) {
                up_button(person_in.start_floor);
            }
            else {
                down_button(person_in.start_floor);
            }
        }

        void move_elevator(clock clock_in) {    //Needs work
            int up = 0;
            int down = 0;
            if (stops.empty() && queue.empty()) {
                extreme_floor = 0;
                state = 0;
            }
            else if (stops.empty()) {
                for (int i = 0; i < queue.size(); i++) {
                    if (queue[i].up) {
                        up++;
                    }
                    else {
                        down++;
                    }
                }
                if (up > down) {
                    state = 1;
                    current_floor = queue[0].floor;
                    //Travel time here
                    clock_in.open_close_door();
                    extreme_floor =  queue[queue.size() - 1].floor;
                }
                else {
                    state = -1;
                    current_floor = queue[queue.size() - 1].floor;
                    //Travel time here
                    clock_in.open_close_door();
                    extreme_floor = queue[0].floor;
                }
            }
            else {
                if (state == 1) {
                    
                }
            }
        }

        // void everyone_off (person person_in) {
            // for (int i = 0; i < occupants.size(); i++)
                // if (person_in.destination == current_floor) {
                    // occupants.erase(occupants.begin() + i);
        
        void everyone_off (person person_in) {
          for (int i = 0; i < occupants.size(); i++)
            if (person_in.destination == current_floor) {
              occupants.erase(std::remove(occupants.begin(), occupants.end(), i), occupants.end());
            } // Added function, maybe works??

    private:
        int current_floor;  //Shows where elevator is
        vector<int> stops;  //List of stops elevator must make
        vector<queue_obj> queue;  //List of stops elvator cannot yet take
        vector<person> occupants; //People in elevator
        int extreme_floor;  //Furthest floor from elevator
        int state; //UP = 1;DOWN = -1;REST = 0
};

class Building {
    public:
        void press_buttons() {
            for (int i = 0; i < people_in_queue.size(); i++) {
                for (int j = 0; j < people_in_queue[i].size(); j++) {
                    building_elevator.pers_bttn_prs(people_in_queue[i][j]);
                }
            }
        }
    private:
        elevator building_elevator;
        clock master_clock;
        vector<vector<person>> people_in_queue; //Queue of people getting on elevator
        vector<vector<person>> people_out_queue;    //Queue of people after getting off elevator
};

//when an elevator arrives at a floor iterate through occupants to make sure everyone gets off at the floor if they can
//make sure multiple instances of the same floor do not occur in stops

class scheduler {

};

int main() {
    // vector<queue_obj> test_queue;    //Queue insert test block
    // queue_insert(test_queue,5,1);
    // queue_insert(test_queue,-15,1);
    // queue_insert(test_queue,3,1);
    // queue_insert(test_queue,20,1);
    // queue_insert(test_queue,17,1);
    // for (int i = 0; i < test_queue.size(); i++) {
    //     cout << test_queue[i].floor << endl;
    // }
    return 0;
}