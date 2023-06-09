#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Mountain class to store mountain details
class Mountain {
private:
    string name;
    string country;
    int elevation;

public:
    // Default constructor
    Mountain() {
        name = "";
      
        country = "";
      
        elevation = 0;
    }

    // Parameterized constructor
    Mountain(string name, string country, int elevation) {
        this->name = name;
      
        this->country = country;
      
        this->elevation = elevation;
    }

    // Setter methods
    void setName(string name) {
        this->name = name;
    }

    void setCountry(string country) {
        this->country = country;
    }

    void setElevation(int elevation) {
        this->elevation = elevation;
    }

    // Getter methods
    string getName() {
        return name;
    }

    string getCountry() {
        return country;
    }

    int getElevation() {
        return elevation;
    }

    // Convert elevation from feet to meters with the given formula
    double toMeters(double elevationInFeet) {
        double FEET_TO_METER = 1 / 3.2808;
        return elevationInFeet * FEET_TO_METER;
    }
};

// Function to find the index of the mountain with the minimum elevation
int minElevation(Mountain mountains[]) {
    int minIndex = 0;
    for (int i = 0; i < 7; i++) {
        if (mountains[i].getElevation() < mountains[minIndex].getElevation()) {
            minIndex = i;
        }
    }
    return minIndex;
}

int main() {
    Mountain mountains[7];
    mountains[0] = Mountain("Chimborazo", "Ecuador", 20549);
    mountains[1] = Mountain("Matterhorn", "Switzerland", 14692);
    mountains[2] = Mountain("Olympus", "Greece (Macedonia)", 9573);
    mountains[3] = Mountain("Everest", "Nepal", 29029);
    mountains[4] = Mountain("Mount Marcy - Adirondacks", "United States", 5344);
    mountains[5] = Mountain("Mount Mitchell - Blue Ridge", "United States", 6684);
    mountains[6] = Mountain("Zugspitze", "Switzerland", 9719);

    cout << left << setw(20) << "Mountain Name" << setw(20) << "          Country" << setw(15) << "         Elevation(ft)" << setw(20) << " Elevation (meters)" << endl;
    cout << "---------------------------------------------------------------------------------" << endl;
    for (Mountain mountain : mountains) {
        cout << setw(30) << mountain.getName() << setw(20) << mountain.getCountry() << setw(15) << mountain.getElevation() << setw(20) << mountain.toMeters(mountain.getElevation()) << endl;
    }

    int smallest = minElevation(mountains); // Index of the mountain with the smallest elevation

    cout << "\nElevation of the shortest mountain:" << endl;
    cout << "Name: " << mountains[smallest].getName() << endl;
    cout << "Country: " << mountains[smallest].getCountry() << endl;
    cout << "Elevation (ft): " << mountains[smallest].getElevation() << endl;

    return 0;
}
