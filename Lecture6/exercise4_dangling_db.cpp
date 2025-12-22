#include <iostream>
#include <string>
#include <vector>

struct Student {
    int id;
    std::string name;
};

/**
 * @brief Sets up the student database.
 * * THIS FUNCTION CONTAINS A CRITICAL FLAW.
 * It returns a pointer to memory on its own STACK.
 */
std::vector<Student> setup_database() {
    // 'student_db' is a LOCAL ARRAY. It lives on the STACK.
    std::vector<Student> student_db = {
        {201, "David"},
        {202, "Eve"}
    };
    std::cout << "Inside setup_database():" << std::endl;
    std::cout << "  'student_db' array is at address: " << &student_db[0] << std::endl;

    // We return a pointer to the first element
    return student_db;

} // 'student_db' is DESTROYED here. The stack memory is reclaimed.

int main() {
    std::cout << "Calling setup_database()..." << std::endl;
    std::vector<Student> db = setup_database();
    
    std::cout << "\nIn main():" << std::endl;
    std::cout << "  p_db pointer holds address: " << &db[0] << std::endl;

    // DANGER: We are dereferencing a DANGLING POINTER.
    // The memory at p_db is no longer valid.
    // This is Undefined Behavior!
    std::cout << "  Accessing dangling pointer... " << std::endl;
    std::cout << "  Found student: " << db[0].name << std::endl; // CRASH or GARBAGE

    // TASK: 
    // 1. Explain why this code is broken. Because is redirecting to a dangling pointer
    // 2. Fix it. The best fix is to change 'setup_database' to return
    //    a 'std::vector<Student>' by value and update 'main' accordingly.
    if (!db.empty()){
        std::cout << "Found student:" << db[0].name << std::endl;
    }
    
    return 0;
}