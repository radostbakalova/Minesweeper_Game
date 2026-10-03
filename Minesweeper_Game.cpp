#include <iostream>
#include "Board.h"

int main() {
    Board b(10, 10, 20);
    b.reveal(2, 3);
    b.display();
}
