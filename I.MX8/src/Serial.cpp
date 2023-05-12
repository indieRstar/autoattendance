#include <termios.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/signal.h>
#include <sys/types.h>
#include <sys/poll.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>
#include "Serial.hpp"

 std::basic_string<uint8_t> serial()
{ 
    std::basic_string<uint8_t> ID;
    int fd = open("/dev/ttyUSB12", O_RDWR | O_NOCTTY);
    if (fd < 0) {
        throw;
    }

    int ndx;
    int cnt;
    struct pollfd *poll_events;
    int ttyfd;
    int poll_state;
    int transfer_byte(int from, int to, int is_control);//poll 통신에 쓸까봐 남겨둠
    
    struct termios oldtio = { 0 };
    struct termios newtio = { 0 };
    tcgetattr(fd, &oldtio);

    newtio.c_cflag = B115200 | CS8 | CLOCAL | CREAD;
    newtio.c_iflag = 0;
    newtio.c_oflag = 0;
    newtio.c_lflag = 0;
    newtio.c_cc[VTIME] = 0;
    newtio.c_cc[VMIN] = 0;
    tcflush(fd, TCIOFLUSH);
    tcsetattr(fd, TCSANOW, &newtio);
    fcntl(fd, F_SETFL, O_NONBLOCK);

    
    unsigned char buffer[10] = {0};
    int ret = read(fd, buffer, sizeof(buffer));
    if (ret > 0) {
        for (int i = 0; i < 10; ++i) {
            printf("Receive %02x", buffer[i]); // 프린트만됨, db로 받아야함 
            ID[i] = buffer[i];
        }


        if (buffer[0] == 0xFF) { return 0; };
    } else {
        //아두이노로 실패성공여부 보내는 코드
        printf("else");
        usleep(1000 * 50);
    }

    printf("close");
    close(fd);
    return ID;


}

int check_event() {
    int ndx;
    int cnt;
    struct pollfd poll_events;
    int poll_state;


    int fd = open("/dev/ttyUSB12", O_RDWR | O_NOCTTY);
    if (fd < 0) {
        throw;
    }

    struct termios oldtio = { 0 };
    struct termios newtio = { 0 };
    tcgetattr(fd, &oldtio);

    newtio.c_cflag = B115200 | CS8 | CLOCAL | CREAD;
    newtio.c_iflag = 0;
    newtio.c_oflag = 0;
    newtio.c_lflag = 0;
    newtio.c_cc[VTIME] = 0;
    newtio.c_cc[VMIN] = 0;
    tcflush(fd, TCIOFLUSH);
    tcsetattr(fd, TCSANOW, &newtio);
    fcntl(fd, F_SETFL, FNDELAY);

    poll_events.fd = fd;
    poll_events.events = POLLIN | POLLERR;
    poll_events.revents = 0;

    poll_state = poll( (struct pollfd*)&poll_events, 1, 100);

    return (poll_state > 0 && poll_events.revents & POLLIN);
}

// std::basic_string<uint8_t> register() {
//     node에서 요청 들어왔을때 아두이노에서 값 요청하고 전송하는 역할 
// }