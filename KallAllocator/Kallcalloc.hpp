#include "KallAlloc.hpp"
namespace KAL
{
    class KallCalloc:public Kalloc
    {
    public:
        void* operator()(size_t num, size_t nsize);
    }
}