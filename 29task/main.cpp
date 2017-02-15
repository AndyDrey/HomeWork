#include <iostream>
#include <string>
#include <memory>

#include "event.h"
#include "eventlistener.h"
#include "eventmanager.h"

using namespace std;


struct FileLogger : EventListener
{
    void notify(const Event& ev) override
    {
        cout << __PRETTY_FUNCTION__ << endl;
        cout << ev.getDescription() << endl;
    }
};

struct ConnectionMgr : EventListener
{
    void notify(const Event& ev) override
    {
        cout << __PRETTY_FUNCTION__ << endl;
        cout << ev.getDescription() << endl;
    }
};


struct EventHandler : EventListener
{
    void notify(const Event& ev) override
    {
        cout << __PRETTY_FUNCTION__ << endl;
        cout << ev.getDescription() << endl;
    }
};


int main(int argc, char *argv[])
{
    shared_ptr<EventListener> evListener1 = make_shared<FileLogger>();
    shared_ptr<EventListener> evListener2 = make_shared<ConnectionMgr>();
    shared_ptr<EventListener> evListener3 = make_shared<EventHandler>();
    Event ev("Some Error");

    cout << "=================================Add Listeners===================================="<<endl;
    EventManager::getInstance().addListener(evListener1);
    EventManager::getInstance().addListener(evListener2);
    EventManager::getInstance().addListener(evListener3);
    cout << "=================================Add copy of listener===================================="<<endl;
    EventManager::getInstance().addListener(evListener1);
    cout << "=================================Publish Event===================================="<<endl;
    EventManager::getInstance().publishEvent(ev);
    cout << "=================================Remove Listener===================================="<<endl;
    EventManager::getInstance().removeListener(evListener3);
    cout << "=================================Publish Event===================================="<<endl;
    EventManager::getInstance().publishEvent(ev);
    return 0;
}
