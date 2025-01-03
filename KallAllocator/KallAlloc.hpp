#include <iostream>
#include <mutex>
namespace KAL 
{
    union header_t
{
    struct 
    {
        size_t size;
        unsigned is_free;
        union header_t *next;
    } s;
    char stub[16];

};


typedef union header_t header_t;


header* head,tail;


    class Kalloc
    {
    private:
         
        std::mutex* mtx;
        header* getFree(size_t size)
        {
            unique_ptr<curr>= head;
            while(curr)
            {
                if(curr->s.is_free && curr->s.size>=size)
                    return curr;
                cur=curr->s.next;
            }
            return nullptr;
        }
    public: 
        Kalloc(): mtx(new std::mutex) {}
        void* operator ()(size_t size);

    };
}