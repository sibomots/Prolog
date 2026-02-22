#include <SWI-cpp2.h>
#include <iostream>

int main(int argc, char **argv) {
    // Initialize the Prolog engine
    PlEngine e(argc, argv);

    try {
        PlTermv av(0);
        PlQuery q("main", av);

        if (q.next_solution()) {
            std::cout << "Prolog 'main' completed successfully." << std::endl;
        } else {
            std::cerr << "Prolog 'main' failed." << std::endl;
        }

    } catch (const PlException& ex) {
        // Captures Prolog-side errors (e.g., syntax errors in file)
        std::cerr << ex.what() << std::endl;
        return 1;
    }

    return 0;
}

