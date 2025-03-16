#include <iostream>
#include <Windows.h>

class smart_array {
private:
    int* data;
    size_t capacity;
    size_t size;

 
    void resize() {
        capacity *= 2;
        int* new_data = new int[capacity];

        for (size_t i = 0; i < size; ++i) {
            new_data[i] = data[i];
        }

        delete[] data;
        data = new_data;
    }

public:
    smart_array(size_t initial_capacity) : capacity(initial_capacity), size(0) {
        if (initial_capacity == 0) {
            throw std::invalid_argument("®мкость массива не может быть равна 0.");
        }
        data = new int[capacity];
    }

    smart_array(const smart_array& other) : capacity(other.capacity), size(other.size) {
        data = new int[capacity];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    smart_array& operator=(const smart_array& other) {
        if (this != &other) {
            delete[] data;

            capacity = other.capacity;
            size = other.size;
            data = new int[capacity];
            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    ~smart_array() {
        delete[] data;
    }

    void add_element(int value) {
        if (size >= capacity) {
            resize();
        }
        data[size++] = value;
    }

    int get_element(size_t index) const {
        if (index >= size) {
            throw std::out_of_range("»ндекс выходит за пределы массива.");
        }
        return data[index];
    }

    size_t getSize() const {
        return size;
    }

    size_t getCapacity() const {
        return capacity;
    }
};

int main() {
    SetConsoleOutputCP(1251);
    try {
        smart_array arr(5);

        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);

        smart_array new_array(2);
        new_array.add_element(44);
        new_array.add_element(34);

        arr = new_array;

        std::cout << "Ёлементы массива arr:" << std::endl;
        for (size_t i = 0; i < arr.getSize(); ++i) {
            std::cout << arr.get_element(i) << " ";
        }
        std::cout << std::endl;

        std::cout << "Ёлементы массива new_array:" << std::endl;
        for (size_t i = 0; i < new_array.getSize(); ++i) {
            std::cout << new_array.get_element(i) << " ";
        }
        std::cout << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}