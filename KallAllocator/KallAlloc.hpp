#include <iostream>
#include <mutex>
namespace KAL 
{
    typedef union header_t
{
    struct 
    {
        size_t size;
        unsigned is_free;
        union header_t *next;
    } s;
    char stub[16];

};


 union header_t *head;
 union header_t* tail;




    class Kalloc
    {
    private:
         
        std::mutex mtx;
        header_t* getFree(size_t size)
        {
            header_t* curr=head;
            while(curr)
            {
                if(curr->s.is_free && curr->s.size>=size)
                    return curr;
                curr=curr->s.next;
            }
            return nullptr;
        }
    public: 
        Kalloc(): mtx() {}
        void* operator ()(size_t size);

    };
}