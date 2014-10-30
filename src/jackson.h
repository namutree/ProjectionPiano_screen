//
//  jackson.h
//  pianoScreenV
//
//  Created by John Choi on 4/9/14.
//
//

#ifndef __pianoScreenV__jackson__
#define __pianoScreenV__jackson__

#include <iostream>
#include "ofMain.h"

#define wormNo 60

class jackson
{
public:
    jackson(int whatKey);
    void draw();
    void update();
    

    int lifespan;
    
    ofColor keyColor[17];
    
    int pressedKey;
    
    
    // 20 circles will create the worm
    ofPoint wormTrace[wormNo];

    
    // initial angle
    float r;
    
    //initial speed
    float spd;
    
    float vecX;
    float vecY;
    float noiseX;
    

};

#endif /* defined(__pianoScreenV__jackson__) */


