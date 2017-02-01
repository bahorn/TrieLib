#include <functional>
#include <string>
#include <iostream>

#include "src/trie.hpp"

/* quick example class for handling extra data */
class
metadata
{
    public:
        int somethingA;
        int somethingB;    
};

void
example()
{
    std::cout << "hello world!" << std::endl;
}

int
main()
{
    /* Create our Trie
     * The template parameters are the following:
     * > Key Datatype for lookup
     * > Datatype for the value
     * > an extra datatype for user defined datatypes.
     */
    Trie::Trie<std::string, std::function<void(void)>, metadata> exampleTrie;
    std::cout << "Adding two children to the root." << std::endl;
    exampleTrie.add("test", example);
    exampleTrie.add("lol", example);
    exampleTrie.del("test");
    std::cout << "List the keys we added to the root:" << std::endl;
    for(auto const& l: exampleTrie.list())
        std::cout << "> " << l << std::endl;
    std::cout << "Changing the childrens meta objects:" << std::endl;
    for(auto const& l: exampleTrie.list()) {
        /* access the object. */
        auto child = *exampleTrie.get(l);
        /* Change it */
        child.meta.somethingA = 1337;
        std::cout << "somethingA: " << child.meta.somethingA << std::endl;
        /* run it */
        std::cout << "Running this childs function:" << std::endl;
        child.value();
    }
}
