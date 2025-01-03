#include "KallAlloc.hpp"
namespace KAL
{
    class Kallrealloc:public Kalloc
    {
    public:
        void* operator()(void* block, size_t size);
    }
}