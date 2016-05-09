#include "ofApp.h"

using namespace ofxCv;
using namespace cv;
//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(30);
	camera.initGrabber(ofGetWidth(), ofGetHeight());
	tracker.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
	camera.update();
	if (camera.isFrameNew()) {
		tracker.update(toCv(camera));
	}

	leftEyeWidth = ofDist(tracker.getImagePoint(42).x, tracker.getImagePoint(42).y, tracker.getImagePoint(45).x, tracker.getImagePoint(45).y);
	leftEyeHeight = ofDist(tracker.getImagePoint(44).x, tracker.getImagePoint(44).y, tracker.getImagePoint(46).x, tracker.getImagePoint(46).y);
	leftEyeWidth = ofDist(tracker.getImagePoint(36).x, tracker.getImagePoint(36).y, tracker.getImagePoint(39).x, tracker.getImagePoint(39).y);
	leftEyeHeight = ofDist(tracker.getImagePoint(37).x, tracker.getImagePoint(37).y, tracker.getImagePoint(41).x, tracker.getImagePoint(41).y);

	prevLeft = leftEyeHeight;
	prevRight = rightEyeHeight;
}

//--------------------------------------------------------------
void ofApp::draw(){
	camera.draw(0, 0);
	//tracker.draw(true);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (tracker.getImagePoint(42).x == 0) {
		ofSaveFrame();
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
