#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetFrameRate(30);
    _application = new Application();
    
}

//--------------------------------------------------------------
void testApp::update(){
    _application->update();
}

//--------------------------------------------------------------
void testApp::draw(){
    
    _application->draw();
    
}
//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == 'q'){
        delete _application;
        _application = new Application();
        return;
    }
    _application->keyPressed(key);
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    _application->keyReleased(key);
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){
    
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