//
// Created by u211-04 on 27.04.2017.
//
#include <iostream>
#include "temperature.h"

std::istream & operator >>(std::istream & in, temperature& t){
    in>>t.value;
    char symbol;
    in>>symbol;
    switch (symbol){
    case 'K':
        t.scale = Kelvin;
        break;
    case 'C':
        t.scale = Celsius;
        break;
    case 'F':
        t.scale = Farengheit;
        break;
    }
    return in;
}

temperature convert (const temperature& from, Scale scale) {
    double kelvin;
    switch (from.scale){
    case Kelvin:
        kelvin = from.value;
        break;
    case Farengheit:
        kelvin = (from.value - 32)/1,8 + 273,15;
        break;
    case Celsius:
        kelvin = from.value + 273,15;
        break;
    }
    temperature result;
    result.scale = scale;
    switch (scale){
    case Kelvin:
        result.value = kelvin;
        break;
    case Farengheit:
        result.value = kelvin + 273,15;
        break;
    case Celsius:
        result.value = 1,8*kelvin + 32 ;
        break;
    }
    return result;
}


bool  operator<(temperature& lhs, temperature& rhs){
    lhs = convert(lhs, rhs.scale);
    return lhs.value < rhs.value;
}

bool  operator>(temperature& lhs, temperature& rhs){
    lhs = convert(lhs, rhs.scale);
    return lhs.value > rhs.value;
}

