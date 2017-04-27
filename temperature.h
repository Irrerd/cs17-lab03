//
// Created by u211-04 on 27.04.2017.
//

#pragma once
#include <iostream>
enum Scale{
    Celsius = 'C',
    Farengheit = 'F',
    Kelvin = 'K',
};
struct temperature{
    Scale scale;
    double value;
};
std::istream & operator >>(std::istream & in, temperature& t);
temperature convert (const temperature& from, Scale scale);
bool  operator<(temperature& lhs, temperature& rhs);
bool  operator>(temperature& lhs, temperature& rhs);


