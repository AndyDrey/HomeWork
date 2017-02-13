#include <iostream>
#include <thread>
#include <future>
#include <condition_variable>
#include <cstddef>
#include <iostream>
#include <mutex>
#include <queue>
#include <random>
#include <thread>
#include <algorithm>
#include <chrono>
#include <ostream>
#include <sstream>

#include <cstdlib>
#include <ctime>
using namespace std;

template<typename T, size_t N>
class RingBuffer
{
    array<T, N> m_data;

    std::mutex mtx;
    std::condition_variable cond;

    typedef unsigned long long tSize;

    unsigned long long m_start = 0;
    unsigned long long m_end = 0;

    bool empty_unsafe() const
    {
        return (m_start == m_end);
    }

    bool full_unsafe() const
    {
        return (N == (m_start - m_end));
    }

public:

    size_t size() const
    {
        return N;
    }

    size_t count() const
    {
        return m_start - m_end;
    }

    bool empty() const
    {
        lock_guard<mutex> lock(mtx);
        return empty_unsafe();
    }

    bool full() const
    {
        lock_guard<mutex> lock(mtx);
        return full_unsafe();
    }

    void push_back(const T& elem)
    {
        unique_lock<mutex> lock(mtx);
        while (full_unsafe())
        {
            cond.wait(lock);
        }

        tSize start = m_start%N;
        m_data[start] = elem;
        ++m_start;
    }

    T& front()
    {
        unique_lock<mutex> lock(mtx);
        while (empty_unsafe())
        {
            cond.wait(lock);
        }

        return m_data[m_end%N];
    }

    void pop_front()
    {
        unique_lock<mutex> lock(mtx);
        if (!empty_unsafe())
        {
            ++m_end;
            cond.notify_one();
        }
    }

};


int main(int argc, char *argv[])
{
    const size_t N = 20;
    RingBuffer<int, N> ringBuffer;
    thread pusher{[&]()
                  {
            int counter = 100;
            while(counter)
            {
                ringBuffer.push_back(--counter);
                cout << "push value: " << counter << endl;
            }
                  }};

    thread poper{[&]()
                 {
            int value;
            while(value)
            {
                value = ringBuffer.front();
                ringBuffer.pop_front();
                cout << "read value: " << value << endl;
                std::chrono::milliseconds timeout(200);
                std::this_thread::sleep_for(timeout);
            }
                 }};

    poper.join();
    pusher.join();


    cout << "Completed!" << endl;
    return 0;
}
