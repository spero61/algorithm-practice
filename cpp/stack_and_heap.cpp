// a program to determine which way do the stack and the heap (free store) grows

#include <iostream>

// to check static storage
int global01 = 2022;
int global02 = 7;
int global03 = 29;

void growth_direction(int* address01, int* address02, const char* name = "this one") {
    if ((address02 - address01) > 0)             // if address of the variable assigned later has higher address than the previous one
        std::cout << name << " grows upward\n";  // grows to larger addresses
    else
        std::cout << name << " grows downward\n";
}

int main() {
    try {
        // static storage check
        std::cout << "static storage:\n"
                  << "address of global01: " << &global01 << '\n'
                  << "address of global02: " << &global02 << '\n'
                  << "address of global03: " << &global03 << "\n\n";

        // stack growth determination
        int stack01 = 2022;
        int stack02 = 7;
        int stack03 = 29;

        std::cout << "stack addresses:\n"
                  << "address of stack01: " << &stack01 << '\n'
                  << "address of stack02: " << &stack02 << '\n'
                  << "address of stack03: " << &stack03 << "\n\n";

        // heap growth determination using array on the free store
        int* heap_arr = new int[3]{2022, 7, 29};

        std::cout << "heap addresses:\n"
                  << "address of heap_arr[0]: " << &heap_arr[0] << '\n'
                  << "address of heap_arr[1]: " << &heap_arr[1] << '\n'
                  << "address of heap_arr[2]: " << &heap_arr[2] << "\n\n";

        // print results
        std::cout << "Result:\n";
        growth_direction(&global01, &global02, "Static storage");
        growth_direction(&stack01, &stack02, "Stack");
        growth_direction(&heap_arr[0], &heap_arr[1], "Heap");

        delete[] heap_arr;

        return 0;
    } catch (std::exception& e) {
        std::cerr << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "...Exception Occurred\n";
        return 2;
    }
}

// https://stackoverflow.com/questions/4560720/why-does-the-stack-address-grow-towards-decreasing-memory-addresses
/* 
-- higher address(e.g., 0xFFFF) --

(Stack)
  ↓


  ↑
(Heap)

(Static Storage)

-- lower address(e.g., 0x0000) --
*/