#include "FormatTime.h"


string converterIntToStr(int temp_nuber){
    stringstream convert;
    if(!(convert << temp_nuber))
        return "0";
    return convert.str();
}


string FormatTime::formatTime(double t_total){
    int d = 0, 
        h = 0, 
        m = 0, 
        s = 0,
        aux = (int) t_total;

    string result_time;

    if (aux >= 86400) {
        d = aux/86400;
        aux = aux % 86400;
    }

    if (aux >= 3600){
        h = aux/3600;
        aux = aux % 3600;
    }

    if(aux >= 60){
        m = aux/60;
        aux = aux % 60;
    }
    s = aux;
    result_time =  converterIntToStr(d) + " : ";
    result_time += converterIntToStr(h) + " : ";
    result_time += converterIntToStr(m) + " : ";
    result_time += converterIntToStr(s);
    return result_time;
}



