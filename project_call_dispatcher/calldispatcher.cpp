#include "calldispatcher.h"
#include <algorithm>
#include <object.h>
CallDispatcher::CallDispatcher()
{
    //...
}

void CallDispatcher::connect(Object *sender, const std::string& signal, Object *receiver, const std::string& slot)
{
    m_map.insert({{sender, signal},{receiver, slot}});
}

void CallDispatcher::disconnect(Object *sender, const std::string& signal, Object *receiver, const std::string& slot)
{
    auto it = m_map.find({sender, signal});
    if(it != m_map.end()){
        for(;it != m_map.end(); ++it){
            if(it->second.first == receiver && it->second.second == slot){
                m_map.erase(it);
                break;
            }
        }
    }
}

void CallDispatcher::sendSignal(Object *sender, const std::string& signal)
{
    auto it = m_map.find({sender, signal});
    if(it != m_map.end()){
        for (; it != m_map.end(); ++it){
            if(it->first.first == sender && it->first.second == signal){
                std::pair<Object*, std::string> tmp = it->second;
                tmp.first->dispatchMethod(tmp.second);
            }
        }
    }
}
