//
// IO.hpp
//

#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <stdint.h>
#include <stdio.h>

#include "IO.hpp"

class SocketClient {
private:
    int sockfd;

public:
    SocketClient() : sockfd(-1) {}
    bool connectServer(char* serverIp, int port);

    void send(char* sendData, int sendDataLength) { ::send(sockfd, sendData, sendDataLength, 0); }
    void recv(char* recvBuffer, int sizeOfRecvBuffer) { ::recv(sockfd, recvBuffer, sizeOfRecvBuffer, 0); }

    void close() { ::close(sockfd); }
};

bool SocketClient::connectServer(char* serverIp, int port)
{
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd <0) 
    {
        return false;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(serverIp);

    connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
    
    return true;
}

class ElevatorIo {
private:
    uint32_t outputState;
    uint32_t inputState;
    char recvBuffer[8];
	char sendBuffer[8];

    SocketClient client;

public:
    ElevatorIo() : outputState(0), inputState(0), client() { }

    bool initialize() {
        char addr[] = "127.0.0.1";
        return client.connectServer(addr, 3000);
    }

    void finalize() { client.close(); }

	void liftMotorForwardOn() { outputState |= 1; outputState &= ~2; }
	void liftMotorReverseOn() { outputState |= 2; outputState &= ~1; }
	void liftMotorOff() { outputState &= ~(1 + 2); }
	void doorMotorForwardOn() { outputState |= 4; outputState &= ~8; }
	void doorMotorReverseOn() { outputState |= 8; outputState &= ~4; }
	void doorMotorOff() { outputState &= ~(4 + 8); }
	void upstairCallButtonLampOn() { outputState |= 16; }
	void upstairCallButtonLampOff() { outputState &= ~16; }
	void downstairCallButtonLampOn() { outputState |= 32; }
	void downstairCallButtonLampOff() { outputState &= ~32; }
	void upstairRequestButtonLampOn() { outputState |= 64; }
	void upstairRequestButtonLampOff() { outputState &= ~64;}
	void downstairRequestButtonLampOn() { outputState |= 128; }
	void downstairRequestButtonLampOff() { outputState &= ~128; }

	bool isLiftOnUpstair() { return inputState & 1; }
	bool isLiftOnDownstair() { return inputState & 2; }
	bool isDoorOpen() { return inputState & 4; }
	bool isDoorClose() { return inputState & 8; }
	bool isUpstairCallButtonPressed() { return inputState & 16; }
	bool isDownstairCallButtonPressed() { return inputState & 32; }
	bool isUpstairRequestButtonPressed() { return inputState & 64; }
	bool isDownstairRequestButtonPressed() { return inputState & 128; }

    void tick() {
        snprintf(sendBuffer, sizeof(sendBuffer), "%d", outputState);
        client.send(sendBuffer, strlen(sendBuffer));

        for (int i = 0; i < 8; i++)
        {
            recvBuffer[i] = 0;
        }

        client.recv(recvBuffer, sizeof(recvBuffer));
        sscanf(recvBuffer, "%d", &inputState);
        // inputState = (uint32_t)(recvBuffer[0] - '0');  // ToDo
    }
};

ElevatorIo io;

bool IO_initialize()
{
    return io.initialize();
}

void IO_finalize()
{
    io.finalize();
}

void IO_tick()
{
	io.tick();
}

void IO_liftMotorForwardOn()
{
	io.liftMotorForwardOn();
}

void IO_liftMotorReverseOn()
{
	io.liftMotorReverseOn();
}

void IO_liftMotorOff()
{
	io.liftMotorOff();
}

bool IO_isLiftOnUpstair()
{
	return io.isLiftOnUpstair();
}

bool IO_isLiftOnDownstair()
{
	return io.isLiftOnDownstair();
}

void IO_doorMotorForwardOn()
{
	io.doorMotorForwardOn();
}

void IO_doorMotorReverseOn()
{
	io.doorMotorReverseOn();
}

void IO_doorMotorOff()
{
	io.doorMotorOff();
}

bool IO_isDoorOpen()
{
	return io.isDoorOpen();
}

bool IO_isDoorClose()
{
	return io.isDoorClose();
}

bool IO_isUpstairCallButtonPressed()
{
	return io.isUpstairCallButtonPressed();
}

void IO_upstairCallButtonLampOn()
{
	io.upstairCallButtonLampOn();
}

void IO_upstairCallButtonLampOff()
{
	io.upstairCallButtonLampOff();
}

bool IO_isDownstairCallButtonPressed()
{
	return io.isDownstairCallButtonPressed();
}

void IO_downstairCallButtonLampOn()
{
	io.downstairCallButtonLampOn();
}

void IO_downstairCallButtonLampOff()
{
	io.downstairCallButtonLampOff();
}

bool IO_isUpstairRequestButtonPressed()
{
	return io.isUpstairRequestButtonPressed();
}

void IO_upstairRequestButtonLampOn()
{
	io.upstairRequestButtonLampOn();
}

void IO_upstairRequestButtonLampOff()
{
	io.upstairRequestButtonLampOff();
}

bool IO_isDownstairRequestButtonPressed()
{
	return io.isDownstairRequestButtonPressed();
}

void IO_downstairRequestButtonLampOn()
{
	io.downstairRequestButtonLampOn();
}

void IO_downstairRequestButtonLampOff()
{
	io.downstairRequestButtonLampOff();
}

// End of File

