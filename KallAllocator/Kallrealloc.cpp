#include "Kallrealloc.hpp"
#include <cstring>

KAL::Kallrealloc::operator()(void* block, size_t size)
{
    KAL::Kalloc kalloc();
    KAL::KallFree free();
    header_t* header;
    void*  ret;
    if(!block || !size)
        return kalloc(size);
    header= (header_t*)block -1;
    if(header->s.size >=size)
        return block;
    ret=kalloc(size);
    if(ret)
    {
        std::memcpy(ret,block,header->s.size);
        KAL::free(block);
    }
    return ret;
}