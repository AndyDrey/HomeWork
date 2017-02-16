#include "eventmanager.h"
#include <algorithm>
#include <iostream>
using namespace std;

EventManager& EventManager::getInstance()
{
    static EventManager inst;
    return inst;
}

void EventManager::publishEvent(const Event& ev)
{
    for(auto it = m_listeners.begin(); it!= m_listeners.end(); it++){
        if(auto tmp = it->lock()){
            tmp->notify(ev);
        }
    }
}

void EventManager::addListener(shared_ptr<EventListener>& listener)
{
    bool check = any_of(m_listeners.begin(), m_listeners.end(), [&](weak_ptr<EventListener>l)
    {
            return listener == l.lock();
});
    if(!check){
        m_listeners.push_back(listener);
        cout << "Added" << endl;
    }
    else{
        cout << "You can`t add a copy!!!" << endl;
    }
}

void EventManager::removeListener(shared_ptr<EventListener>& listener)
{
    m_listeners.erase(remove_if(m_listeners.begin(), m_listeners.end(), [&](weak_ptr<EventListener>l){
                          return listener == l.lock();
                      }), m_listeners.end());
    cout << "Removed" << endl;
}
