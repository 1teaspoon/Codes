//
//  rgb.h
//  Project3
//
//  Created by Jason Alan Fries on 9/20/13.
//  Copyright (c) 2013 Jason Alan Fries. All rights reserved.
//

#ifndef RGB_H
#define RGB_H

#include <iostream>
#include <math.h>

struct rgb {
    
    double r;
    double g;
    double b;
    
    rgb() : r(0), g(0), b(0) {}
    rgb(double r, double g, double b) : r(r), g(g), b(b) {}

};

// Modifed from http://paulbourke.net/texture_colour/colourspace/
//
// Return a RGB colour value given a scalar v in the range [vmin,vmax]
// In this case each colour component ranges from 0 (no contribution) to
// 1 (fully saturated), modifications for other ranges is trivial.
// The colour is clipped at the end of the scales if v is outside
// the range [vmin,vmax]
rgb color_map(double v, double vmin, double vmax)
{
    rgb c(1.0,1.0,1.0); // white
    double dv;
    
    if (v < vmin)
        v = vmin;
    if (v > vmax)
        v = vmax;
    dv = vmax - vmin;
    
    if (v < (vmin + 0.25 * dv)) {
        c.r = 0;
        c.g = 4 * (v - vmin) / dv;
    } else if (v < (vmin + 0.5 * dv)) {
        c.r = 0;
        c.b = 1 + 4 * (vmin + 0.25 * dv - v) / dv;
    } else if (v < (vmin + 0.75 * dv)) {
        c.r = 4 * (v - vmin - 0.5 * dv) / dv;
        c.b = 0;
    } else {
        c.g = 1 + 4 * (vmin + 0.75 * dv - v) / dv;
        c.b = 0;
    }
    
    return( c );
}

#endif
