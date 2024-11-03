#include <iostream>
#include <string>

using namespace std;

class Reservoir {
private:
    string name;
    string type;
    int width;
    int length;
    int maxDepth;

public:
    Reservoir() : name("Unknown"), type("Unknown"), width(0), length(0), maxDepth(0) {}

    Reservoir(const string& name, const string& type, int width, int length, int maxDepth)
        : name(name), type(type), width(width), length(length), maxDepth(maxDepth) {}

    Reservoir(const Reservoir& other)
        : name(other.name), type(other.type), width(other.width), length(other.length), maxDepth(other.maxDepth) {}

    Reservoir& operator=(const Reservoir& other) {
        if (this != &other) {
            name = other.name;
            type = other.type;
            width = other.width;
            length = other.length;
            maxDepth = other.maxDepth;
        }
        return *this;
    }

    ~Reservoir() {}

    int calculateVolume() const {
        return width * length * maxDepth;
    }

    int calculateSurfaceArea() const {
        return width * length;
    }

    bool isSameType(const Reservoir& other) const {
        return type == other.type;
    }

    bool compareSurfaceArea(const Reservoir& other) const {
        return calculateSurfaceArea() > other.calculateSurfaceArea();
    }

    void compareAndPrintSurfaceArea(const Reservoir& other) const {
        if (isSameType(other)) {
            if (compareSurfaceArea(other)) {
                cout << name << " has a larger surface area than " << other.name << ".\n";
            }
            else {
                cout << other.name << " has a larger surface area than " << name << ".\n";
            }
        }
        else {
            cout << name << " and " << other.name << " are of different types, comparison is not valid.\n";
        }
    }

    void setName(const string& newName) { name = newName; }
    void setType(const string& newType) { type = newType; }
    void setWidth(int newWidth) { width = newWidth; }
    void setLength(int newLength) { length = newLength; }
    void setMaxDepth(int newMaxDepth) { maxDepth = newMaxDepth; }

    string getName() const {
        return name;
    }
    string getType() const {
        return type;
    }
    int getWidth() const {
        return width;
    }
    int getLength() const {
        return length;
    }
    int getMaxDepth() const {
        return maxDepth;
    }
};

int main() {
    Reservoir lake("Baikal", "Lake", 2000, 5000, 1637);
    Reservoir pond("Garden Pond", "Pond", 50, 30, 3);

    cout << "\nReservoirs are " << (lake.isSameType(pond) ? "of the same type." : "of different types.") << endl;

    lake.compareAndPrintSurfaceArea(pond);

}
