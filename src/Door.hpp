//
// Door.hpp
//

#ifndef __DOOR_HPP__
#define __DOOR_HPP__

class DoorEventListener
{
public:
    DoorEventListener() {}
    virtual ~DoorEventListener() {}

    virtual void notifyDoorOpened() {};
    virtual void notifyDoorClosed() {};
};

class Door
{
private:
    DoorEventListener* listener;
    enum
    {
        closed,
        opened,
        closing,
        opening
    } state;
    int count;

    static const int waitClosingCount = 300;

public:
    Door(DoorEventListener* listener) : listener(listener), state(closed), count(0) {}
    ~Door() {}

    void open();
    void tick();
};

#endif

