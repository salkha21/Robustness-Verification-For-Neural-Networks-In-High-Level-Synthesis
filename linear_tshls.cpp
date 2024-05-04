
#include "linear.h"

using namespace std;

int main() {    

    float v61[11] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};

    float v62 = 0.0;

        // Call the forward function
    forward(v61, v62);

    // Print the value of the float variable after the function call
    cout << "Value of v62 after function call: " << v62 << endl;

    return 0;

}

