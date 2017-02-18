#include <iostream>
#include <list>
#include <algorithm>
#include <cassert>
using namespace std;

template<typename K, typename V>
class LRUCache
{
    list<pair<K, V>> m_cache;
    const size_t m_maxSize;
public:
    LRUCache(size_t max_size) : m_maxSize(max_size){};
    // put value by key
    void Put(const K& key, const V& value){
        if (m_cache.size() < m_maxSize)
        {
            m_cache.push_front({ key, value });
        }
        else
        {
            m_cache.pop_back();
            m_cache.push_front({ key, value });
        }
    }

    // Retrieves an entry from the cache that has been cached before
    // using put(). Returns the cached entry. Throws exception,
    // if there is no entry with the key K
    const V& Get(const K& key){
        auto it = std::find_if(m_cache.begin(), m_cache.end(),
                               [key](std::pair<K, V> const &b) {
                return b.first == key;
    });
        if (it != m_cache.end()){
            pair<K, V> tmp = *it;
            m_cache.push_front({ tmp.first, tmp.second });
            m_cache.erase(it);
            return m_cache.begin()->second;
        }
        else{
            throw out_of_range("Can`t find value by this key");
        }
    }

    // Checks presence of the value by the given key
    bool Exists(const K& key){
        auto it = std::find_if(m_cache.begin(), m_cache.end(),
                               [key](std::pair<K, V> const &b) {
                return b.first == key;
    });
        if (it != m_cache.end()){
            pair<K, V> tmp = *it;
            m_cache.push_front({ tmp.first, tmp.second });
            m_cache.erase(it);
            return true;
        }
        else {
            return false;
        }
    };

    // Clears all the entries in the cache
    void Clear(){
        m_cache.clear();
    }

    // Returns size
    size_t Size() const {
        return m_cache.size();
    }
};

int main(){
    LRUCache<int, string> cache(3);
    assert(cache.Size() == 0);
    cache.Put(1, "111");
    assert(cache.Size() == 1);
    cache.Put(2, "222");
    cache.Put(3, "333");
    assert(cache.Size() == 3);
    cache.Exists(1);
    bool exception_thrown = false;
    try
    {
        cache.Get(4);
    }
    catch (exception& ex)
    {
        exception_thrown = true;
    }
    assert(exception_thrown == true);
    cache.Get(2);
    assert(cache.Get(2) == "222");
    cache.Get(1);
    assert(cache.Get(1) == "111");
    cache.Put(4, "444");
    assert(cache.Size() == 3);
    exception_thrown = false;
    try
    {
        cache.Get(3);
    }
    catch (exception& ex)
    {
        exception_thrown = true;
    }
    assert(exception_thrown == true);
    cout << "All asserts successfully passed" << endl;
    return 0;
}
