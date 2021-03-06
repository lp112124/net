//
// Created by Administrator on 2018/11/28.
//

#include "event_handler.h"
#include "event.h"
#include "event_demultiplexer.h"

class Reactor {
public:
    static Reactor& get_instance();
    int regist(EventHandler* handler, Event evt);
    void remove(EventHandler* handler);
    void dispatch(int timeout = 0);

private:
    Reactor();
    ~Reactor();
    Reactor(const Reactor&);
    Reactor& operator=(const Reactor&);

private:
    static Reactor reactor;
    EventDemultiplexer* _demultiplexer;
    std::map<Handle, EventHandler*> _handlers;
};


