#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetLogLevel(OF_LOG_VERBOSE);
    
    files.allowExt("mov");
    files.listDir("/Users/gameover/Desktop/vjMedia/trains01/"); // put a video path here with several video files in a folder
    
    video1.loadMovie(files.getPath(ofRandom(files.numFiles())));
    video2.loadMovie(files.getPath(ofRandom(files.numFiles())));
    
    ofAddListener(video1.threadedVideoEvent, this, &testApp::threadedVideoEvent);
    ofAddListener(video2.threadedVideoEvent, this, &testApp::threadedVideoEvent);
}

//--------------------------------------------------------------
void testApp::update(){
    video1.update();
    video2.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(255, 255, 255);
    video1.draw(0, 0, video1.getWidth(), video1.getHeight());
    video2.draw(video1.getWidth(), 0, video2.getWidth(), video2.getHeight());
    
    ofSetColor(0, 255, 0);
    int duration1 = video1.getDuration();
    int duration2 = video2.getDuration();
    ofDrawBitmapString("FPS: " + ofToString(ofGetFrameRate()) + " duration vid1: " + ofToString(duration1) + " duration vid2: " + ofToString(duration2), 20, ofGetHeight() - 20);
}

//--------------------------------------------------------------
void testApp::threadedVideoEvent(ofxThreadedVideoEvent & event){
    ofLogVerbose() << "VideoEvent:" << event.eventTypeAsString << "for" << event.path;
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    switch (key) {
        case '1':
            video1.loadMovie(files.getPath(ofRandom(files.numFiles())));
            break;
        case '2':
            video2.loadMovie(files.getPath(ofRandom(files.numFiles())));
            break;
        case '3':
            video1.loadMovie(files.getPath(ofRandom(files.numFiles())));
            video2.loadMovie(files.getPath(ofRandom(files.numFiles())));
            break;
        case '4':
            video1.setPaused(true);
            break;
        case '5':
            video1.setFrame(0);
            video1.setPaused(false);
            break; 
        default:
            break;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    video1.setFrame(video1.getTotalNumFrames() * (float)x/ofGetWidth());
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