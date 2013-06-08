/*
 * btCom.c
 *
 *  Created on: 06.05.2013
 *      Author: Sascha Steffen
 */
#include "btCom.h"
#include <termios.h>
#include <sys/signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define BAUDRATE B9600
static const char* COM_PORT="/dev/rfcomm0";

/*
 * old/new port settings
 */
static struct termios  newtio;

static bool connected = false;

static int handle;

int btWriteBytes(const char* data,  unsigned int len) {
	if(!connected) return -1;
	int writtenBytes=write(handle, data, len);
	if(writtenBytes < 0){
		printf("Writing failed with error code: %d\n", errno);
		btDisconnect();
	}
	return writtenBytes;
}

int btReadBytes(char* data,  unsigned int maxLen) {
	int readBytes;
	//check if connected
	if(!connected) return -1;

		//Do the read
		readBytes=read(handle, data, maxLen);
		if(readBytes <= 0){
			int err=errno;
            if(err>0 && err != EAGAIN)
			{
				printf("Reading failed with error code: %d\n", err);
				btDisconnect();
				return -1;
			}
	}
	return readBytes;
}

/*
 * Most of this was copied from:
 * http://stackoverflow.com/questions/6947413/how-to-open-read-and-write-from-serial-port-in-c
 */
bool btConnect() {
	const char* adr=COM_PORT;
	handle=open(adr, O_RDWR | O_NOCTTY);
	if(handle < 0)
	{
		printf("Connection failed with error code: %d\n", errno);
		return false;
	} else {

        memset(&newtio, 0, sizeof newtio);
        if (tcgetattr (handle, &newtio) != 0)
        {
                printf("error %d from tcgetattr", errno);
                btDisconnect();
                return false;
        }
		cfsetospeed(&newtio, BAUDRATE);
		cfsetispeed(&newtio, BAUDRATE);
		newtio.c_cflag &= ~CSIZE;
		newtio.c_cflag |= CS8;     // 8-bit chars
        // disable IGNBRK for mismatched speed tests; otherwise receive break
        // as \000 chars
        newtio.c_iflag &= ~IGNBRK;         // ignore break signal
        newtio.c_lflag = 0;                // no signaling chars, no echo,
                                        // no canonical processing
        newtio.c_oflag = 0;                // no remapping, no delays

        newtio.c_cc[VMIN]  = 0;            // read  blocks-> non-blocking
        newtio.c_cc[VTIME] = 2;            // small read timeout

        newtio.c_iflag &= ~(IXON | IXOFF | IXANY); // shut off xon/xoff ctrl
        newtio.c_iflag &= ~ICRNL;

        newtio.c_cflag |= (CLOCAL | CREAD);// ignore modem controls,
                                        // enable reading
        newtio.c_cflag &= ~(PARENB | PARODD);      // shut off parity
        newtio.c_cflag |= 0;//No Parity
        newtio.c_cflag &= ~CSTOPB; //1 stop bit
        newtio.c_cflag &= ~CRTSCTS;
		tcflush(handle, TCIFLUSH);

        if (tcsetattr (handle, TCSANOW, &newtio) != 0)
        {
                printf("error %d from tcsetattr", errno);
                btDisconnect();
                return false;
        }
		connected=true;
		return true;
	}
}

bool btDisconnect()
{
	connected=false;

	if(close(handle) == 0)
		return true;
	else{
		printf("error %d on close.", errno);
		return false;
	}

}

int btReadLine(char* data, unsigned int maxLen){
	int readChars=0, result;
	char read;
    while(readChars< maxLen)
	{
		result=btReadBytes(&read,1);
		if(result > 0){//only increment read chars, if data was read
			if(read == '\n')//EOL reached
			{
				break;
			}
			data[readChars]=read;
			readChars++;
		} else if(result < 0){ //error
			return -1;
		}
	}
	data[readChars-1]='\0';//terminate string
	return readChars;
}
