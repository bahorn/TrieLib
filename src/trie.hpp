#pragma once

#include <vector>
#include <map>

namespace Trie {
    template <typename K, typename T, typename M>
    class Trie {
        public:
            Trie();
            K name;
            T value;
            M meta;
            void add(K name, T value);
            void del(K name);
            Trie<K, T, M> * get(K key);
            std::vector<K> list();
        private:
            std::map<K, Trie<K, T, M>> values;
    };
    /* Because of how templates are implemented in most compilers,
     * these have to be defined here.
     */
    template <typename K, typename T, typename M> inline
    Trie<K, T, M>::Trie()
    {

    }
    /* add in a new child trie */
    template <typename K, typename T, typename M> inline void 
    Trie<K, T, M>::add(K name, T value)
    {
        Trie<K, T, M> temp;
        temp.name = name;
        temp.value = value;
        temp.meta = meta;
        this->values.insert(std::make_pair(name, temp));
    }

    /* remove a child from the trie */
    template <typename K, typename T, typename M> inline void
    Trie<K, T, M>::del(K name)
    {
        this->values.erase(name);
    }

    /* Obtain the child trie */
    template <typename K, typename T, typename M> inline Trie<K, T, M> *
    Trie<K, T, M>::get(K key)
    {
        return &(this->values[key]);
    }

    /* returns all the keys as a vector */
    template <typename K, typename T, typename M> inline std::vector<K>
    Trie<K, T, M>::list()
    {
        std::vector<K> output;
        for (auto const& keyname: this->values) {
            output.push_back(keyname.first);
        }
        return output;
    }
};
