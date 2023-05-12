#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <cstddef>
#include <termio.h>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <iostream>
#include "dbform.hpp"
#include "Serial.hpp"
#include <sys/poll.h>
#include <pthread.h>


// int _getch(void) {
//     int ch;
//     struct termios buf;
//     struct termios save;

//     tcgetattr(0, &save);
//     buf = save;

//     buf.c_lflag &= ~(ICANON | ECHO);
//     buf.c_cc[VMIN] = 1;
//     buf.c_cc[VTIME] = 0;

//     tcsetattr(0, TCSAFLUSH, &buf);

//     ch = getchar();

//     tcsetattr(0,TCSAFLUSH, &save);

//     return ch;
// }; 대신 수신 확인하는 함수 ! 리턴값은? 

// void EventFunction(std::condition_variable* cv, std::mutex* mtx, bool& MainFlag, bool& EventFlag) {
//     std::unique_lock<std::mutex> locker(*mtx);
//     std::cout << "Start Polling" << "\n";

//     /** 메인함수 */

//     MainFlag = true;
//     cv->notify_one();

//     cv->wait(locker, [&]() { return EventFlag; });
//     serial();
// };

// int main() 
// {
//     Db db(); //db생성 - 이미 있을때는 open하도록 변경


//     bool MainFlag = false, EventFlag = false;
//     std::condition_variable cv;
//     std::mutex mtx;

//     std::thread EventThread(EventFunction, &cv, &mtx, std::ref(MainFlag), std::ref(EventFlag));

//     {
//         std::unique_lock<std::mutex> locker(mtx);
//         cv.wait(locker, [&]() { return MainFlag; });
//     }

//     std::cout << "go polling go" <<"\n";
//     check_event();
//     std::cout << "no punk" << std::endl;

//     EventFlag = true;
//     cv.notify_one();

//     EventThread.join();

//     MainFlag = false;
//     EventFlag = false;
//     cv.notify_all();

// }

int main() {
    serial();
}