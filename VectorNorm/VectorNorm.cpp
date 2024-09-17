#include <iostream>
#include <cmath>

struct Vector3 {
    float x, y, z;

    Vector3 operator+(const Vector3& other) {
        return {x + other.x, y + other.y, z + other.z};
    }

    Vector3 operator-(const Vector3& other) {
        return {x - other.x, y - other.y, z - other.z};
    }

    float magnitude() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    Vector3 normalize() const {
        float mag = magnitude();
        if (mag == 0) {
            return {0, 0, 0};
        }
        return {x / mag, y / mag, z / mag};
    }

    void print() const {
        std::cout << "Vektor(" << x << ", " << y << ", " << z << ")\n";
    }
};

int main() {
    Vector3 ninjaPos = {0, 0, 0};

    Vector3 targetPos = {5, 0, 10};

    Vector3 direction = targetPos - ninjaPos;

    std::cout << "Orijinal Vektor: ";
    direction.print();

    Vector3 normalizedDirection = direction.normalize();

    std::cout << "Normalize Edilmis Vektor: ";
    normalizedDirection.print();

    return 0;
}
