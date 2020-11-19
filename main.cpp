#include <iostream>
#include <vector>
using namespace std;

void sort_insert(vector<int> & vec_in, int insert) {
    if (vec_in.empty()) {
        vec_in.insert(vec_in.begin(),insert);
    }
    for (int x = 0; x < vec_in.size(); x++) {
        if (vec_in[x] >= insert) {
            vec_in.insert(vec_in.begin() + x,insert);
        }
    }
}

class elevator {
    public:
        void up_button(int floor) {
            if (state == 0) {
                stops.push_back(floor);
            }
            else if (state == -1) {
                queue.push_back(floor);
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
    return 0;
}