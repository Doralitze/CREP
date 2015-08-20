#include "dimension.hpp"

Dimension::Dimension()
{
    //constructor
}

Dimension::~Dimension()
{
    //destructor
}

Dimension& Dimension::operator=(const Dimension& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
