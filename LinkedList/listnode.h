#ifndef LISTNODE_H_INCLUDED
#define LISTNODE_H_INCLUDED

#include "ItemType.h"

class ListNodeClass
{
private:
    ItemType Info;
    ListNodeClass * Next;
public:
    ListNodeClass(const ItemType & Item, ListNodeClass * NextPtr = NULL):
        Info(Item), Next(NextPtr) {};
    void GetInfo(ItemType & Theinfo) const;
friend class ListClass;
};

typedef ListNodeClass * ListNodePtr;

#endif // LISTNODE_H_INCLUDED
