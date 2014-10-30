//
//  jackson.cpp
//  pianoScreenV
//
//  Created by John Choi on 4/9/14.
//
//

#include <iostream>
#include "jackson.h"



jackson::jackson(int whatKey)
{
    keyColor[0] = ofColor::fromHex(0x0DA88E);
    keyColor[1] = ofColor::fromHex(0x005444);
    keyColor[2] = ofColor::fromHex(0x126294);
    keyColor[3] = ofColor::fromHex(0x004466);
    keyColor[4] = ofColor::fromHex(0xD8E20A);
    keyColor[5] = ofColor::fromHex(0x551587);
    keyColor[6] = ofColor::fromHex(0x2C0B4C);
    keyColor[7] = ofColor::fromHex(0xE20741);
    keyColor[8] = ofColor::fromHex(0x931139);
    keyColor[9] = ofColor::fromHex(0xED830F);
    keyColor[10] = ofColor::fromHex(0xA55B11);
    keyColor[11] = ofColor::fromHex(0x43A30C);
    keyColor[12] = ofColor::fromHex(0xBA1460);
    keyColor[13] = ofColor::fromHex(0x68103C);
    keyColor[14] = ofColor::fromHex(0x2D3B3D);
    keyColor[15] = ofColor::fromHex(0x754175);
    keyColor[16] = ofColor::fromHex(0x7F4A0B);
    
    // 10 circles will create the worm
    for(int i=0;i<wormNo;i++){
    wormTrace[i].set(ofGetWidth()/2, ofGetHeight()/2,0);
    }
    lifespan=100;
    
    //what key the user press.
    pressedKey = whatKey;
    
    r = ofRandom(PI*2);
    spd = ofRandom(3,6);

}

void jackson::update(){
    
    for (int i=0;i<wormNo-1;i++){
        wormTrace[i] = wormTrace[i+1];
    }
    
    wormTrace[wormNo-1].x +=sin(r)*spd;
    wormTrace[wormNo-1].y +=cos(r)*spd;
    r += ofRandom(-PI/10,PI/10);
    
    if(wormTrace[0].x<-15 ||wormTrace[0].x>ofGetWidth()+15 ||wormTrace[0].y<-15 || wormTrace[0].y>ofGetHeight()+15){
    lifespan =0;
    }
    
    
    vecX = wormTrace[wormNo-1].x - wormTrace[wormNo-2].x;
    vecY = wormTrace[wormNo-1].y - wormTrace[wormNo-2].y;
    float hypotenuse = powf ((vecX*vecX + vecY*vecY), 0.5);
    vecX = vecX/hypotenuse;
    vecY = vecY/hypotenuse;
    
    
    
    
}

void jackson::draw(){
    
    
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    for(int j=0;j<wormNo;j++){
        ofSetColor(keyColor[pressedKey],ofMap(j, 0, wormNo-1, 0, 250));
        //ofCircle(wormTrace[j].x,wormTrace[j].y, ofMap(j, 0, wormNo-1, 1,10));
        for (int i=0; i<int(ofMap(j, 0, wormNo, wormNo/3, 0)); i++) {
            ofSetColor(keyColor[pressedKey],ofMap(j, 0, wormNo-1, 0, 250));
            ofCircle(wormTrace[j].x-vecX*ofRandom(-i, i),wormTrace[j].y-vecY*ofRandom(-i, i), 1);//ofMap(j, 0, wormNo-1, 1,3));
        }
    }
    noiseX+=0.1;
    //make it beautiful??? or not!! let's do it!!
//    ofEnableBlendMode(OF_BLENDMODE_ADD);
//    for(int i=1;i<wormNo;i++){
//        for(int j=0;j<wormNo-1;j++){
//        ofSetColor(255,ofRandom(10));
//        ofLine(wormTrace[i].x+ofRandom(-5,5),wormTrace[i].y,wormTrace[j].x,wormTrace[j].y);
//        }
//    }
    //ofSetColor(255,100);
    //ofLine(ofGetWidth()/2,ofGetHeight()/2,wormTrace[wormNo-1].x,wormTrace[wormNo-1].y);
}

