#include "Array.hpp"
#include "LinkedList.hpp"

#include <chrono>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

class Timer {
public:
    Timer() { mClockState = CLOCK_UNSTARTED; }
    void startClock() { mStartTime = std::chrono::high_resolution_clock::now(); mClockState = CLOCK_RUNNING; }
    void stopClock() { mEndTime = std::chrono::high_resolution_clock::now(); mClockState = CLOCK_STOPPED; }
    double elapsedTime() { 
        if(mClockState == CLOCK_UNSTARTED) { return 0.f; }
        if(mClockState == CLOCK_RUNNING) {
            mEndTime = std::chrono::high_resolution_clock::now();
        }
        return std::chrono::duration<double>(mEndTime - mStartTime).count(); 
    }
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> mStartTime;
    std::chrono::time_point<std::chrono::high_resolution_clock> mEndTime;
    unsigned short mClockState;
    const short CLOCK_UNSTARTED = 0;
    const short CLOCK_RUNNING = 1;
    const short CLOCK_STOPPED = 2;
};

void run_timed_tests(List<int>* const pList, const int SIZE, const string LABEL) {
    cout << setw(15) << left << LABEL << flush;

    Timer timer;
    timer.startClock();
    for(unsigned int i = 0; i < SIZE; i++) {
        pList->insert(i, i);
    }
    timer.stopClock();
    cout << setw(14) << right << timer.elapsedTime() << "s" << flush;

    timer.startClock();
    for(unsigned int i = 0; i < SIZE; i++) {
        pList->get(i);
    }
    timer.stopClock();
    cout << setw(14) << right << timer.elapsedTime() << "s" << flush;

    timer.startClock();
    for(unsigned int i = 0; i < SIZE; i++) {
        pList->set(i, SIZE-i);
    }
    timer.stopClock();
    cout << setw(14) << right << timer.elapsedTime() << "s" << flush;

    timer.startClock();
    for(unsigned int i = 0; i < SIZE; i+=2) {
        pList->remove(0);
    }
    timer.stopClock();
    cout << setw(14) << right << timer.elapsedTime() << "s" << endl;
}

int main() {
    const int TEST_SIZE = 100000;

    cout << setw(15) << left << "List Type";
    cout << setw(15) << right << "Insert";
    cout << setw(15) << right << "Read";
    cout << setw(15) << right << "Write";
    cout << setw(15) << right << "Delete" << endl;

    cout << fixed << setprecision(3);

    List<int> *pList = new Array<int>();
    run_timed_tests(pList, TEST_SIZE, "Array");
    delete pList;

    pList = new LinkedList<int>();
    run_timed_tests(pList, TEST_SIZE, "Linked List");
    delete pList;

    return 0;
}