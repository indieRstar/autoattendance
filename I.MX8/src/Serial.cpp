#include <termios.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/signal.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <errno.h>
#include "Serial.hpp"

int serial(int argc, char** argv)
{
    int fd = open("/dev/ttyS0", O_RDWR | O_NOCTTY);
    if (fd < 0) {
        return -1;
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

    while(true) {
        unsigned char buffer[1024] = {0};
        int ret = read(fd, buffer, sizeof(buffer));
        if (ret > 0) {
            for (int i = 0; i < ret; ++i) {
                printf("Receive %02x", buffer[i]);
            }

            if (buffer[0] == 0xFF) {
                break;
            }
        } else {
            usleep(1000 * 50);
        }

    }
    close(fd);
    return 0;


}

