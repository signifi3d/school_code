/*************************
 * NAME: Blake Eakin
 * ASSIGNMENT: Lab 4
 * SOURCES: None
 *************************/

 #include <iostream>

void hanoi(const int curr, const int src, const int dst, const int extra);

int main() {

    int disk_count = 0;

    std::cout << "Blake Eakin" << std::endl;
    
    std::cout << "Enter how many disks: ";
    std::cin >> disk_count;

    //Input checking
    if (disk_count <= 0) {
        std::cerr << "Invalid number of disks." << std::endl;
        return 1;
    }

    std::cout << std::endl << "RECURSION:" << std::endl;

    hanoi(disk_count, 1, 2 ,3);

    return 0;
}

void hanoi(const int curr, const int src, const int dst, const int extra) {
    if (curr == 1) { //If it reached the top of the stack then move it
        std::cout << "moved disk from " << src << " to " << dst << std::endl;
    }
    else { //Move top disks, then the desired disk, then move them back on top
        hanoi(curr-1, src, extra, dst);
        std::cout << "moved disk from " << src << " to " << dst << std::endl;
        hanoi(curr-1, extra, dst, curr);
    }
    
}
