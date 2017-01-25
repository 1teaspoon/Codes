//
//  main.cpp
//  Homework 02
//  Author: Jiahui Wang
//  Created by Jiahui Wang on 10/19/16.
//  Copyright © 2016 Apple Inc. All rights reserved.

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include "complex.h"
#include "lodepng.h"
#include "rgb.h"


// struct for storing command line argument values
struct Arguments {
    int width;
    int height;
    int color_depth;
    int max_itr;
    const char * filename;
    double zoom;
    double origin[2];
    Complex c;
};

// Function prototypes
int julia_recursive( Complex & z, const Complex & c,int max_itr, const double radius2=2 );
unsigned int parse_args(int argc, const char * argv[], Arguments & args);
void print_usage();

int main(int argc, const char * argv[]) {
    
    // parse command line arguments
    Arguments args;
    if ( !parse_args( argc, argv, args ) ) {
        print_usage();
        return 0;
    }
    

    // TODO: allocate our dynamic array of pixels (width x height x 4)
    // use the variable name "img"
    int size = args.width*args.height*4;
    unsigned char * img = new unsigned char [size];
    
    // TODO: Loop through all pixels in the image
     for (int x=0; x<args.width; x++  ) {
         for ( int y=0; y<args.height; y++ ) {
     
     // create a complex number for this specific pixel
     // by transforming coordinates to range [-1,1]
             double a;
             double b;
             a = 1.5 * (x - args.width * 0.5) / (0.5 * args.zoom * args.width);
             b = (y - args.height * 0.5) / (0.5 * args.zoom * args.height);
             
             Complex z(a,b);    //store the current pixel info in complex number z
             
     //TODO: Complete either the iterative version or recursive version
     // recursive version
             int esc_t = julia_recursive(z, args.c, args.max_itr,2); //calculate the escape time
         
     // 1D array offset, map escape time to rgb color
             int offset = args.color_depth * (y * args.width + x);
             rgb color = color_map(esc_t, 0, args.max_itr);
             
             img[ offset + 0 ] = color.r * (esc_t % 256);
            
             img[ offset + 1 ] = color.g * (esc_t % 256);
             
             img[ offset + 2 ] = color.b * (esc_t % 256);
             
             img[ offset + 3 ] = 255;
             
         }
     }
    
    // write out PNG file
     std::cout << "Writing fractal to " << args.filename << std::endl;
     unsigned int error = lodepng::encode(args.filename, img, args.width, args.height);
    
       if (error) {
        std::cout << "ERROR: Failed to save png to " << args.filename << std::endl; //print error message
       }
    
       delete [] img; //delete dynamic image array
    
    return 0;
}

// parse command line arguments and return a stuct of parameter values
unsigned int parse_args(int argc, const char * argv[], Arguments & args) {
    
    // defaults
    args.zoom = 1.0;
    //args.zoom = 40.0;
    args.origin[0] = args.origin[1] = 0;
    args.max_itr = 256;
    args.color_depth = 4;                           // bytes per pixel
    args.c = Complex(-0.7,0.27);
    //args.c = Complex(-0.8,0.156);
    
    //TODO: parse command line arguments
    switch ( argc ) {
        case 7:
            args.zoom = std::atoi(argv[6]);
            
        case 6:
            args.c = Complex(std::atof(argv[4]),std::atof(argv[5]));
        case 4:
            args.width = std::atoi(argv[1]);
            args.height = std::atoi(argv[2]);
            args.filename = argv[3];
            
            break;
        default:
            return 0;   // command line parsing failure
    }
    
    return 1; // command line parsing success
}

//TODO: complete the recursive version or the iterative version
// recursive version
int julia_recursive( Complex & z, const Complex & c, int max_itr, const double radius2 ){
    int itr = 0;
    Complex z1;
    Complex z2;
    double magnitude;
    do{                         //calculate Zn+1 = Zn^2+c
        z1 = z.operator*(z);
        z2 = z1.operator+(c);
        z = z2;
        magnitude = z2.magnitude();
        itr++;
    }while(itr<max_itr && magnitude < radius2);//check if itration time reaches maximum or distance to origin greater than threshold
    
    return itr;
}

// show command line options
void print_usage()
{
    std::cerr << "Usage: " << "fractal <width> <height> <filename> optional: <ca> <cb> <zoom>";
    std::cerr << std::endl;
}
