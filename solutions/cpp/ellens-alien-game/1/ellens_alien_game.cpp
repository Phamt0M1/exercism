#include <array>
using namespace std;

namespace targets {
    class Alien {
    private :
        int health;
    public :
        int x_coordinate;
        int y_coordinate;
        bool shield;
        Alien(int x, int y) {
            x_coordinate = x;
            y_coordinate = y;
            health = 3;
        }
        int get_health() const {
            return health;
        }
        bool hit() {
            if (shield == true) {
                return false;
            }else if (health > 0) {
                health--;
            }
            return true;
        }
        bool is_alive() const {
            if (health == 0) {
                return false;
            }
            return true;
        }
        bool teleport(int x_new, int y_new) {
            x_coordinate = x_new;
            y_coordinate = y_new;
            return true;
        }
        bool collision_detection(const Alien& other) const {
            return (x_coordinate == other.x_coordinate) && (y_coordinate == other.y_coordinate);
        }
        
    };
}