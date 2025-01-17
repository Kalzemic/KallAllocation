#include "KallAlloc.hpp"
#include <unistd.h>
#include <mutex>





void* KAL::Kalloc::operator ()(size_t size)
{
    size_t total_size;
    void* block;
    header_t* header;
    if(!size)
        return nullptr;
    std::unique_lock<std::mutex> locker{mtx};
    header=getFree(size);
    if(header)
    {
        header->s.is_free;
        return (void*)header+1;
    }
    total_size = sizeof(header_t) +size;
    block= sbrk(total_size);
    if(block== (void*)-1)
        return nullptr;
    header= (header_t*)block;
    header->s.size= size;
    header->s.next= nullptr;
    head->s.is_free=0;
    if(!head)
        head=header;
    if(tail)
        tail->s.next= header;
    tail=header;
    return (void*) (header+1);
}


