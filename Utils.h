#ifndef _Utils_h
#define _Utils_h

// convert String to Double
double toDouble(String value){
    char floatbuf[32]; // make this at least big enough for the whole string
    value.toCharArray(floatbuf, sizeof(floatbuf));
    float f = atof(floatbuf);
    return (double)f;
}

#endif
