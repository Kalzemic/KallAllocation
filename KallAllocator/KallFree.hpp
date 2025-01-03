#include "KallAlloc.hpp"
namespace KAL
{
    class KallFree: public Kalloc
    {
    public:
        void operator () (void* block);

    }
}