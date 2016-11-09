#include "node.h"

bool node::operator < (const node& nodo)const{
    return (priority>nodo.getPriority());
}

