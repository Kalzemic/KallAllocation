#include "KallFree.hpp"

void KAL::KallFree::operator ()(void* block)
{
    void* programbreak;
    if(!block)
        return;
    unique_lock<mutex> lock{mtx};
    header= (header_t*)block-1;
    programbreak= sbrk(0);

    if((char*)block + header->s.size == programbreak)
    {
        if(head==tail)
            head=tail=nullptr;
        else
        {
            while(tmp)
            {
                if(tmp->s.next == tail)
                {
                    tmp->s.next=NULL;
                    tail=tmp;
                }
                tmp=tmp->s.next;
            }
        }
        sbrk(o-sizeof(header_t)- header->s.size);
        return;
    }
    header->s.is_free=1;
}