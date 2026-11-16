#include <iostream>
#include <utility>

class IntBox {
private:
    int* value;

public:
    IntBox() : value(new int(0)) {}  // Default constructor.
    IntBox(int number) : value(new int(number)) {}  // Parameterized.

    // 1. Copy constructor: allocate a separate integer (deep copy).
    IntBox(const IntBox& other)
        : value(other.value ? new int(*other.value) : nullptr) {}

    // 2. Move constructor: transfer ownership and empty the source.
    IntBox(IntBox&& other) noexcept : value(other.value) {
        other.value = nullptr;
    }

    // 3. Copy assignment: replace this object's value with a deep copy.
    IntBox& operator=(const IntBox& other) {
        if (this != &other) {
            int* replacement = other.value ? new int(*other.value) : nullptr;
            delete value;
            value = replacement;
        }
        return *this;
    }

    // 4. Move assignment: release old data, then take ownership.
    IntBox& operator=(IntBox&& other) noexcept {
        if (this != &other) {
            delete value;
            value = other.value;
            other.value = nullptr;
        }
        return *this;
    }

    // 5. Destructor: release the owned integer; delete nullptr is safe.
    ~IntBox() {
        delete value;
    }

    void set(int number) {
        if (value) {
            *value = number;
        } else {
            value = new int(number);
        }
    }

    void show(const char* label) const {
        std::cout << label << ": ";
        if (value) {
            std::cout << *value << "\n";
        } else {
            std::cout << "empty (safe moved-from state)\n";
        }
    }
};

int main() {
    std::cout << "Name: Yash Sharma\n";
    std::cout << "Roll No: E25B000411\n";

    IntBox empty;
    empty.show("Default object");
    IntBox original(10);
    IntBox copied(original);
    copied.set(20);
    original.show("Original after copy change");
    copied.show("Copy-constructed object");

    IntBox moved(std::move(copied));
    moved.show("Move-constructed object");
    copied.show("Source after move construction");

    IntBox assigned;
    assigned = original;
    assigned.set(30);
    original.show("Original after assignment change");
    assigned.show("Copy-assigned object");

    IntBox moveAssigned(99);
    moveAssigned = std::move(assigned);
    moveAssigned.show("Move-assigned object");
    assigned.show("Source after move assignment");
    assigned.set(40);
    assigned.show("Moved-from object reused");
    return 0;
}
