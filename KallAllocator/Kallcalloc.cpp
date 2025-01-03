#include "Kallcalloc.hpp"
#include <cstring>
void* KAL::KallCalloc::operator()(size_t num, size_t nsize)
{
    size_t size;
    void* block;
    (if!num || !nsize)
        return nullptr;
    size=num* nsize;
    if(nsize!= size/num)
        return nullptr;
    KAL::Kalloc kalloc();
    block=kalloc(size);
    if(!block)
        return nullptr;
    std::memset(block,0,size);
    return block;
}