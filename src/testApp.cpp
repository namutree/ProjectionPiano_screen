#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    // seting up port
    receiver.setup(PORT);
}

// write our boolean remove function
bool shouldRemove(jackson &p){
    if(p.lifespan == 0 )return true;
    else return false;
}

//--------------------------------------------------------------
void testApp::update(){
    ofBackground(0, 0, 0);
    
    while(receiver.hasWaitingMessages()){
        ofxOscMessage m;
        receiver.getNextMessage(&m);
        if (m.getAddress() == "/piano/60")
            keyBoardPush[0] = m.getArgAsInt32(0);
        else if (m.getAddress() == "/piano/61")
            keyBoardPush[1] = m.getArgAsInt32(0);
        else if (m.getAddress() == "/piano/62")
            keyBoardPush[2] = m.getArgAsInt32(0);
        else if (m.getAddress() == "/piano/63")
            keyBoardPush[3] = m.getArgAsInt32(0);
        else if (m.getAddress() == "/piano/64")
            keyBoardPush[4] = m.getArgAsInt32(0);
        else if (m.getAddress() == "/piano/65")
            keyBoardPush[5] = m.getArgAsInt32(0);
        else if (m.getAddress() == "/piano/66")
            keyBoardPush[6] = m.getArgAsInt32(0);
        else if (m.getAddress() == "/piano/67")
            keyBoardPush[7] = m.getArgAsInt32(0);
        else if (m.getAddress() == "/piano/68")
            keyBoardPush[8] = m.getArgAsInt32(0);
        else if (m.getAddress() == "/piano/69")
            keyBoardPush[9] = m.getArgAsInt32(0);
        else if (m.getAddress() == "/piano/70")
            keyBoardPush[10] = m.getArgAsInt32(0);
        else if (m.getAddress() == "/piano/71")
            keyBoardPush[11] = m.getArgAsInt32(0);
        else if (m.getAddress() == "/piano/72")
            keyBoardPush[12] = m.getArgAsInt32(0);
        else if (m.getAddress() == "/piano/73")
            keyBoardPush[13] = m.getArgAsInt32(0);
        else if (m.getAddress() == "/piano/74")
            keyBoardPush[14] = m.getArgAsInt32(0);
        else if (m.getAddress() == "/piano/75")
            keyBoardPush[15] = m.getArgAsInt32(0);
        else if (m.getAddress() == "/piano/76")
            keyBoardPush[16] = m.getArgAsInt32(0);
    }
    
    
    for (int i=0; i <17; i++) {
        keyBoardPushT[i][0]=keyBoardPushT[i][1];
        keyBoardPushT[i][1]=keyBoardPush[i];
        
        if(keyBoardPushT[i][1] - keyBoardPushT[i][0] == 1){
            dots.push_back(jackson(i));
           keyBoardPush[i] =0;
            
        }else
            keyBoardPush[i]=0;
    }


    //ofRemove(dots,shouldRemove);

}



//--------------------------------------------------------------
void testApp::draw(){
    
   
    for(int i = 0; i < dots.size(); i++){
        dots[i].update();
        dots[i].draw();
//        for(int j=0;j<dots.size();j++){
//            ofEnableBlendMode(OF_BLENDMODE_ADD);
//            ofSetColor(20);
//            if(i != j){
//            ofLine(dots[i].wormTrace[9].x, dots[i].wormTrace[9].y, dots[j].wormTrace[9].x, dots[j].wormTrace[9].y);
//            }
//        }
    }
    if(dots.size()>170 ){
        dots.erase(dots.begin(),dots.begin()+3);
    }
   
    //ofSetColor(255,255,255);
    //ofCircle(ofGetWidth()/2, ofGetHeight()/2, testA);

    cout << dots.size() << endl;
}


//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
