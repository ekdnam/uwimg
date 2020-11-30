#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "image.h"

    /**
     * Returns the clamped pixel coordinates
    * Args:
    *   1. im: struct containing the image data in the form of a float matrix
    *   2. x: int value which specifies the x coordinate of the pixel
    *   3. y: int value which specifies the y coordinate of the pixel
    *   4. c: int value which specifies the #channel
    * returns:
    *   pointer to an int arrray having the clamped values
    */
int* return_clamped_values(image im, int x, int y, int c){

    int correct_pos[3];
    if(x < 0){
        correct_pos[0] = 0;
    }
    if(x > im.w){
        correct_pos[0] = im.w - 1;
    }
    if(y < 0){
        correct_pos[1] = 0;
    }
    if(y > im.h){
        correct_pos[1] = im.h - 1;
    }
    if(c < 0){
        correct_pos[2] = 0;
    }
    if(c > im.c){
        correct_pos[2] = im.c - 1;
    }
    return correct_pos;
}

float get_pixel(image im, int x, int y, int c)
{
    // TODO Fill this in
    int *xyz;
    xyz = return_clamped_values(im, x, y, c);
    x = xyz[0];
    y = xyz[1];
    c = xyz[2];
    // as matrices are stored in the row-major for in C
    // we are accessing individual elements of image in a similar fashion
    float pixel = im.data[x + y*im.w + c*im.h*im.w];
    return pixel;
}

void set_pixel(image im, int x, int y, int c, float v)
{
    // TODO Fill this in
    int *xyz;
    xyz = return_clamped_values(im, x, y, c);
    x = xyz[0];
    y = xyz[1];
    c = xyz[2];
    im.data[x + y*im.w + c*im.h*im.w] = v;

}

image copy_image(image im)
{
    image copy = make_image(im.w, im.h, im.c);
    // TODO Fill this in
    return copy;
}

image rgb_to_grayscale(image im)
{
    assert(im.c == 3);
    image gray = make_image(im.w, im.h, 1);
    // TODO Fill this in
    return gray;
}

void shift_image(image im, int c, float v)
{
    // TODO Fill this in
}

void clamp_image(image im)
{
    // TODO Fill this in
}


// These might be handy
float three_way_max(float a, float b, float c)
{
    return (a > b) ? ( (a > c) ? a : c) : ( (b > c) ? b : c) ;
}

float three_way_min(float a, float b, float c)
{
    return (a < b) ? ( (a < c) ? a : c) : ( (b < c) ? b : c) ;
}

void rgb_to_hsv(image im)
{
    // TODO Fill this in
}

void hsv_to_rgb(image im)
{
    // TODO Fill this in
}
